#pragma once

class Sequence
{
public:
    // default constructor
    // post: creates an array of size 2 and assigns to ptr,
    // set maximum size to 2 and current size to 0
    Sequence();

    // copy constructor
    // param: a const Sequence object reference
    // post: creates a deep copy of the param object
    Sequence(const Sequence &s);

    // destructor
    // post: deallocates the array pointer ptr
    ~Sequence();

    // overloaded assignment operator
    // param: a const Sequence object reference
    // post: deallocates dynamic memory associated with the calling object's original array
    // creates and returns a deep copy of the param object, verify the self-assignment condition
    Sequence &operator=(const Sequence &s);

    // pre: array has enough space for insertion, else it needs need to create enough space first
    // param: a double value to be inserted in next index of the arr
    // post: value is inserted to the available index
    void insert(double val);

    // pre: Sequence's arr has enough space for insertion, else it needs need to create enough space first
    // param: a double arr to be inserted and the numbers of values stored in the arr
    // post: a list of numbers are added into the Sequence's arr
    void insert(double *arr, int size);

    // pre: if Sequnce's arr current size is not 0
    // param: a double value to be found inside the Sequnce's arr
    // post: return numbers of values found inside the Sequnce's arr
    int find(double value) const;

    // Accessor method
    // post: return current size of the Sequence's arr
    int size() const;

    // pre: the calling object's arr current size not equals to 0
    // post: return sum of the values in the calling object
    double sum() const;

    // pre: the calling object's arr current size not equals to 0
    // post: return avg of the values in the calling object
    double mean() const;

    // pre: the calling object's arr current size not equals to 0
    // post: return median of the values in the calling object
    double median() const;

    // pre: the calling object's arr current size not equals to 0
    // post: returns a double equal to the standard deviation of the values in the sequence
    double stddev() const;

    // pre: cannot modify calling object and param
    // param: a const Sequence object reference
    // post:  returns a Sequence object that contains the contents of the
    // calling object followed by the contents of its constant Sequence reference parameter;
    Sequence concatenate(const Sequence &s) const;

    // my own print method
    // void print(Sequence &s) const;

private:
    // point to an array of doubles
    double *ptr;

    // current size of the array
    int currentSize;

    // maximum size of the array
    int maxSize;

    // deep copy of const sequence object reference
    void copySequence(const Sequence &s);
};