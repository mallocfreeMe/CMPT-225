// insertion sort template function
// PARAM: an array of any type (a template variable),
// and an integer that records the size of the array
// PRE: arr is not nullptr and size is greater than 0
// POST: arr is sorted and return an integer that
// equals the number of times its barometer operation is executed

template <class T>
int insertionsort(T *arr, int size)
{
    int count = 0;

    if (arr && size > 0)
    {
        int count2 = 0;
        for (int i = 1; i < size; ++i)
        {
            T temp = arr[i];
            int pos = i;
            count2++;

            while (pos > 0 && arr[pos - 1] > temp)
            {
                arr[pos] = arr[pos - 1];
                pos--;
                count++;
            }
            arr[pos] = temp;
        }

        if (count2 > count)
        {
            count = count2;
        }
    }

    return count;
}

// swap template function for partition template function
// PARAM: two template reference variables
// POST: two template reference varibles' values are exchanged
template <class T>
void swap(T *a, T *b)
{
    T temp = *a;
    *a = *b;
    *b = temp;
}

// partition template function for quicksort
// PARAM: an array of any type (a template variable),
// and an array index starts from left side of the array
// and an array index starts from right side of the array
// and an integer reference value to count comparisons in its partition function
// and an integer reference value to count the case which comparisons are not executed
// POST: return an integer pivot index to the quicksortHelper template function which is in the right position
// this function is based on https://www.geeksforgeeks.org/quick-sort/
template <class T>
int partition(T *arr, int low, int high, int &comparisons)
{

    T pivot = arr[high]; // pivot
    int i = (low - 1);   // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            comparisons++;
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// quicksort template function helper
// PARAM: an array of any type (a template variable),
// and an array index starts from left side of the array
// and an array index starts from right side of the array
// and an integer reference value to count comparisons in its partition function
// and an integer reference value to count the case which comparisons are not executed
// POST: arr is sorted

template <class T>
void quicksortHelper(T *arr, int low, int high, int &comparisons)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high, comparisons);
        quicksortHelper(arr, low, pivot - 1, comparisons);
        quicksortHelper(arr, pivot + 1, high, comparisons);
    }
}

// quicksort template function
// PARAM: an array of any type (a template variable),
// and an integer that records the size of the array
// PRE: arr is not nullptr and size is greater than 0
// POST: arr is sorted and return an integer that
// equals the number of times its barometer operation is executed

template <class T>
int quicksort(T *arr, int size)
{
    int count = 0;

    if (arr && size > 0)
    {
        quicksortHelper(arr, 0, size - 1, count);
    }

    return count;
}

// mergesort template function helper
// PARAM: two integer indexes
// POST: return the smaller index from these two indexes
int min(int x, int y)
{
    return (x < y) ? x : y;
}

// mergesort template function helper
// PARAM: a sub array of any type (a template variable),
// and left side index of sub array,
// and middle side index of sub array,
// and right side index of sub array
// POST: merge the sub array [left to middile] and [middle to right]
// return the merge count values
// this function is based on https://www.geeksforgeeks.org/iterative-merge-sort/
template <class T>
int merge(T *arr, int l, int m, int r)
{
    int count = 0;

    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    T L[n1], R[n2];

    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }

    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;

    /* Merge the temp arrays back into arr[l..r]*/
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
        count++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    return count;
}

// mergesort template function
// param: an array of any type (a template variable),
// and an integer that records the size of the array
// pre: arr is not nullptr and size is greater than 0
// post: arr is sorted and return an integer that
// equals the number of times its barometer operation is executed
// this function is based on https://www.geeksforgeeks.org/iterative-merge-sort/
template <class T>
int mergesort(T *arr, int size)
{
    int count = 0;

    if (arr && size > 0)
    {
        for (int curr_size = 1; curr_size <= size - 1; curr_size = 2 * curr_size)
        {
            for (int left_start = 0; left_start < size - 1; left_start += 2 * curr_size)
            {
                int mid = min(left_start + curr_size - 1, size - 1);

                int right_end = min(left_start + 2 * curr_size - 1, size - 1);

                count = count + merge(arr, left_start, mid, right_end);
            }
        }
    }

    return count;
}

// shell sort template function
// PARAM: an array of any type (a template variable),
// and an integer that records the size of the array
// PRE: arr is not nullptr and size is greater than 0
// POST: arr is sorted and return an integer that
// equals the number of times its barometer operation is executed
// this function is based on https://www.geeksforgeeks.org/shellsort/
template <class T>
int shellsort(T *arr, int size)
{
    int count = 0;

    int count2 = 0;
    int count3 = 0;

    if (arr && size > 0)
    {
        for (int gap = size / 2; gap > 0; gap /= 2)
        {
            for (int i = gap; i < size; i += 1)
            {
                count2++;
                T temp = arr[i];

                int j;
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                {
                    count3++;
                    arr[j] = arr[j - gap];
                }

                arr[j] = temp;
            }
        }

        if (count2 >= count3)
        {
            count = count2;
        }
        else
        {
            count = count3;
        }
    }

    return count;
}