#include "Sequence.h"
#include <algorithm>
#include <cmath>

// #include <iostream>
// using namespace std;

// default constructor
// post: creates an array of size 2 and assigns to ptr,
// set maximum size to 2 and current size to 0
Sequence::Sequence()
{
    maxSize = 2;
    ptr = new double[maxSize];
    currentSize = 0;
}

// copy constructor
// param: a const Sequence object reference
// post: creates a deep copy of the param object
Sequence::Sequence(const Sequence &s)
{
    copySequence(s);
}

// destructor
// post: deallocates the array pointer ptr
Sequence::~Sequence()
{
    delete[] ptr;
}

// overloaded assignment operator
// param: a const Sequence object reference
// post: deallocates dynamic memory associated with the calling object's original array
// creates and returns a deep copy of the param object, verify the self-assignment condition
Sequence &Sequence::operator=(const Sequence &s)
{
    if (this != &s)
    {
        delete[] ptr;
        copySequence(s);
    }
    return *this;
}

// pre: Sequence's arr has enough space for insertion, else it needs need to create enough space first
// param: a double value to be inserted in next index of the arr
// post: value is inserted to the available index inside the arr
void Sequence::insert(double val)
{
    if (currentSize == maxSize)
    {
        maxSize = maxSize * 2;
        double *temp = ptr;

        ptr = new double[maxSize];

        for (int i = 0; i < currentSize; i++)
        {
            ptr[i] = temp[i];
        }

        delete[] temp;
    }

    ptr[currentSize] = val;
    currentSize++;
}

// pre: Sequence's arr has enough space for insertion, else it needs need to create enough space first
// param: a double arr to be inserted and the numbers of values stored in the arr
// post: a list of numbers are added into the Sequence's arr
void Sequence::insert(double *arr, int size)
{
    // consider three special cases
    // Sequence's arr current size: 0, arr size: 1
    // Sequence's arr current size: 1, arr size: 0
    // Sequence's arr current size: 1, arr size: 1
    if (currentSize == 0 && size == 1)
    {
        ptr[0] = arr[0];
        currentSize = 1;
    }
    else if (currentSize == 1 && size == 0)
    {
        // do nothing
    }
    else if (currentSize == 0 && size == 0)
    {
        // do nothing
    }
    else
    {
        if (currentSize + size > maxSize)
        {
            maxSize = currentSize + size;
            double *temp = ptr;

            ptr = new double[maxSize];

            for (int i = 0; i < currentSize; i++)
            {
                ptr[i] = temp[i];
            }

            delete temp;
        }

        int count = 0;

        for (int i = currentSize; i < maxSize; i++)
        {
            ptr[i] = arr[i - currentSize];
            count++;
        }

        currentSize = currentSize + count;
    }
}

// pre: if Sequnce's arr current size is not 0
// param: a double value to be found inside the Sequnce's arr
// post: return numbers of values found inside the Sequnce's arr
int Sequence::find(double value) const
{
    int count = 0;

    for (int i = 0; i < currentSize; i++)
    {
        if (ptr[i] == value)
        {
            count++;
        }
    }

    return count;
}

// Accessor method
// post: return current size of the Sequence's arr
int Sequence::size() const
{
    return currentSize;
}

// pre: the calling object's arr current size not equals to 0
// post: return sum of the values in the calling object
double Sequence::sum() const
{
    double sum = 0.0;

    if (currentSize != 0)
    {
        for (int i = 0; i < currentSize; i++)
        {
            sum += ptr[i];
        }
    }

    return sum;
}

// pre: the calling object's arr current size not equals to 0
// post: return avg of the values in the calling object
double Sequence::mean() const
{
    if (currentSize != 0)
    {
        return sum() / currentSize;
    }
    else
    {
        return 0.0;
    }
}

// pre: the calling object's arr current size not equals to 0
// post: return median of the values in the calling object
double Sequence::median() const
{
    if (currentSize != 0)
    {
        // sort the list
        std::sort(ptr, ptr + currentSize);

        // if currentSize is even, median is the average of two middle numbers
        // if currentSize is odd, median is the middle one
        if (currentSize % 2)
        {
            return (ptr[currentSize / 2] + ptr[currentSize / 2 + 1]) / 2;
        }
        else
        {
            return ptr[currentSize / 2 + 1];
        }
    }
    else
    {
        return 0.0;
    }
}

// pre: the calling object's arr current size not equals to 0
// post: returns a double equal to the standard deviation of the values in the sequence
double Sequence::stddev() const
{
    if (currentSize != 0)
    {
        double summation = 0.0;
        double avg = mean();

        for (int i = 0; i < currentSize; i++)
        {
            summation += pow(ptr[i] - avg, 2);
        }

        return sqrt(summation / currentSize);
    }
    else
    {
        return 0.0;
    }
}

// pre: cannot modify calling object and param
// param: a const Sequence object reference
// post:  returns a Sequence object that contains the contents of the
// calling object followed by the contents of its constant Sequence reference parameter
Sequence Sequence::concatenate(const Sequence &s) const
{
    Sequence combinedSeq;

    if (currentSize == 0 && s.currentSize == 1)
    {
        combinedSeq.ptr[0] = s.ptr[0];
        combinedSeq.currentSize = 1;
    }
    else if (currentSize == 1 && s.currentSize == 0)
    {
        combinedSeq.ptr[0] = ptr[0];
        combinedSeq.currentSize = 1;
    }
    else if (currentSize == 0 && s.currentSize == 0)
    {
        // do nothing
    }
    else
    {
        combinedSeq.maxSize = currentSize + s.currentSize;
        double *temp = combinedSeq.ptr;
        combinedSeq.ptr = new double[maxSize];
        delete temp;

        int count = 0;

        for (int i = 0; i < combinedSeq.maxSize; i++)
        {
            if (i < currentSize)
            {
                combinedSeq.ptr[i] = ptr[i];
            }
            else
            {
                combinedSeq.ptr[i] = s.ptr[i - currentSize];
            }

            count++;
        }

        combinedSeq.currentSize += count;
    }

    return combinedSeq;
}

// helper function performs a deep copy of const sequence object reference
void Sequence::copySequence(const Sequence &s)
{
    maxSize = s.maxSize;
    currentSize = s.currentSize;

    ptr = new double[maxSize];
    for (int i = 0; i < currentSize; ++i)
    {
        ptr[i] = s.ptr[i];
    }
}

// my own print method
// void Sequence::print(Sequence &s) const
// {
//     cout << "array: ";
//     for (int i = 0; i < s.maxSize; i++)
//     {
//         if (i != s.maxSize - 1)
//         {
//             cout << s.ptr[i] << ",";
//         }
//         else
//         {
//             cout << s.ptr[i];
//         }
//     }

//     cout << endl;

//     cout << "currentSize: " << s.currentSize << endl;
//     cout << "maxSize: " << s.maxSize << endl;
// }