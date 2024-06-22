#include <iostream>
using namespace std;
#include "2105067_1_a.h"

template <typename T>
void List<T>::init()
{
    // T num;
    // cin >> num;
    curr = 0;
    length = 0;
    maxlength = 1;
    arr = new T[1];
    /*for (int i = 0; i < num; i++)
    {
        T n;
        cin >> n;
        arr[i] = n;
        // insert(n);
        // next();
        length++;
    }*/
    // cout<<"<>"<<endl;
}
template <typename T>
List<T>::List() {}
template <typename T>
List<T>::List(int initlen, int memsize, int currpos)
{
    curr = 0;
    length = 0;
    maxlength = memsize;
    arr = new T[maxlength];
    if (length < maxlength)
    {
        arr = new T[maxlength];
    }
    else if (length >= maxlength)
    {
        arr = new T[2 * maxlength];
    }
    for (int i = 0; i < initlen; i++)
    {
        int num;
        cin >> num;
        // arr[i] = num;
        insert(num);
        next();
    }
    moveToPos(currpos);
    // moveToStart();
}

/*List ::~List()
{
    delete[] arr;
}*/
template <typename T>
void List<T>::print()
{
    if (length == 0)
    {
        cout << "<>";
    }
    else
    {
        cout << "<";
        for (int i = 0; i < curr; i++)
        {
            /*if(i==curr){
                cout<<"| "<<arr[i]<<" ";
            }
            else*/
            cout << arr[i] << " ";
        }
        // cout << ">";
        cout << "| ";
        for (int i = curr; i < length; i++)
        {
            cout << arr[i] << " ";
        }
        cout << ">";
    }
}
template <typename T>
void List<T>::insert(T num)
{
    /*if (length < maxlength)
    {
        arr = new int[maxlength];
    }*/

    /*if (length >= maxlength)
    {
        arr = (int *)realloc(arr, 2 * maxlength * sizeof(int));
        maxlength = 2 * maxlength;
    }*/
    expandArray();
    for (int i = length; i > curr; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[curr] = num;
    length++;
}

template <typename T>
void List<T>::expandArray()
{
    if (length >= maxlength)
    {
        maxlength *= 2;
        int *newArr = new T[maxlength];
        for (int i = 0; i < length; i++)
        {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }
}

template <typename T>
T List<T>::remove()
{
    int removedItem;
    if (curr < 0 || curr > length)
    {
        cout << "No element" << endl;
        return T();
    }
    else
    {

        removedItem = arr[curr];
        for (int i = curr; i < length - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        if (curr == length - 1)
        {
            prev();
        }
        length--;
        return removedItem;
    }
}

template <typename T>
void List<T>::moveToStart()
{
    curr = 0;
}

template <typename T>
void List<T>::moveToEnd()
{
    curr = length - 1;
}

template <typename T>
void List<T>::prev()
{
    if (curr != 0)
        curr--;
}

template <typename T>
void List<T>::next()
{
    if (curr < length)
    {
        curr++;
    }
}

template <typename T>
int List<T>::getmaxLength()
{
    return maxlength;
}

template <typename T>
int List<T>::Length()
{
    return length;
}

template <typename T>
int List<T>::currpos()
{
    return curr;
}

template <typename T>
void List<T>::moveToPos(int pos)
{
    if (pos < 0 || pos > length)
    {
        cout << "position is out of range" << endl;
    }
    else
    {
        curr = pos;
    }
}

template <typename T>
T List<T>::getvalue()
{
    if (curr < 0 || curr > length)
    {
        cout << "No element" << endl;
        return -1;
    }
    else
    {
        return arr[curr];
    }
}
