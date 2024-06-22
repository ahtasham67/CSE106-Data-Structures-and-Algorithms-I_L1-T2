#include <iostream>
#include <fstream>
using namespace std;
ofstream outputFile; // Declare outputFile as a global variable

template <typename T>
class priority_queue
{
    T *arr;
    int size;
    int maxsize;
    void max_heapify(T, int);

public:
    priority_queue();
    void Insert(T x);
    T FindMax();
    T ExtractMax();
    void IncreaseKey(int index, T newKey);
    void DecreaseKey(int index, T newKey);
    void Print();
    void Sort();
    ~priority_queue();
};
template <typename T>
priority_queue<T>::priority_queue()
{
    size = 0;
    maxsize = 1;
    arr = new int[maxsize];
}
template <typename T>
void priority_queue<T>::max_heapify(T index, int range)
{
    int leftChildIndex = 2 * index;
    int rightChildIndex = 2 * index + 1;
    int largerElement = index;

    if (leftChildIndex <= range && arr[leftChildIndex] > arr[largerElement])
    {
        largerElement = leftChildIndex;
    }
    if (rightChildIndex <= range && arr[rightChildIndex] > arr[largerElement])
    {
        largerElement = rightChildIndex;
    }
    if (largerElement != index)
    {
        swap(arr[index], arr[largerElement]);
        max_heapify(largerElement, range);
    }
}
template <typename T>
void priority_queue<T>::Insert(T x)
{
    size++;
    int index = size;
    if (size >= maxsize)
    {
        maxsize *= 2;
        int *newArr = new T[maxsize];
        for (int i = 0; i < size; i++)
        {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }
    arr[index] = x;

    while (index > 1)
    {
        int parent = index / 2;

        if (arr[parent] < arr[index])
        {
            swap(arr[parent], arr[index]);
            index = parent;
        }
        else
        {
            return;
        }
    }
}

template <typename T>
T priority_queue<T>::FindMax()
{
    if (size == 0)
    {
        outputFile << "No element in the heap" << endl;
        return -1;
    }
    return arr[1];
}

template <typename T>
T priority_queue<T>::ExtractMax()
{
    if (size < 1)
    {
        outputFile << "Heap underflow!" << endl;
        return -1;
    }
    T maxElement = arr[1];
    arr[1] = arr[size];
    size--;
    max_heapify(1, size);
    return maxElement;
}

template <typename T>
void priority_queue<T>::IncreaseKey(int index, T newKey)
{
    if (index > size)
    {
        outputFile << "Index is greater than heap size" << endl;
        return;
    }
    if (newKey <= arr[index])
    {
        outputFile << "New key is not larger than the previous key" << endl;
        return;
    }
    arr[index] = newKey;
    while (index > 1)
    {
        int parent = index / 2;

        if (arr[parent] < arr[index])
        {
            swap(arr[parent], arr[index]);
            index = parent;
        }
        else
        {
            break;
        }
    }
    outputFile << "Key increased!" << endl;
}

template <typename T>
void priority_queue<T>::DecreaseKey(int index, T newKey)
{
    if (index > size)
    {
        outputFile << "Index is greater than heap size" << endl;
        return;
    }
    if (newKey >= arr[index])
    {
        outputFile << "New key is not smaller than the previous key" << endl;
        return;
    }
    arr[index] = newKey;
    max_heapify(index, size);
    outputFile << "Key decreased!" << endl;
}

template <typename T>
void priority_queue<T>::Sort()
{
    int temp = size;
    while (size >= 2)
    {
        swap(arr[size], arr[1]);
        max_heapify(1, size - 1);
        size--;
    }

    outputFile << "No of elements: " << temp << endl;
    for (int i = 1; i <= temp; i++)
    {
        if ((i & (i - 1)) == 0)
        {
            if (i != 1)
                outputFile << endl;
            outputFile << arr[i] << "\t";
        }
        else
        {
            outputFile << arr[i] << "\t";
        }
    }
    outputFile << endl;
}

template <typename T>
void priority_queue<T>::Print()
{
    outputFile << "No of elements: " << size << endl;
    for (int i = 1; i <= size; i++)
    {
        if ((i & (i - 1)) == 0)
        {
            if (i != 1)
                outputFile << endl;
            outputFile << arr[i] << "\t";
        }
        else
        {
            outputFile << arr[i] << "\t";
        }
    }
    outputFile << endl;
}

template <typename T>
priority_queue<T>::~priority_queue()
{
    delete[] arr;
}
