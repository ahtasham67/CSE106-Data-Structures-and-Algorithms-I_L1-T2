#include <iostream>
// #include"2105067_2_stack.cpp"
#include "2105067_2_stack.h"
using namespace std;

template <typename T>
void Stack<T>::push(T item)
{
    while (!q1.isEmpty())
    {
        T val = q1.Front();
        q2.enqueue(val);
        q1.dequeue();
    }
    q1.enqueue(item);
    while (!q2.isEmpty())
    {
        T val = q2.Front();
        q1.enqueue(val);
        q2.dequeue();
    }
}
template <typename T>
void Stack<T>::pop()
{
    if (q1.isEmpty())
    {
        cout << "The stack is already empty" << endl;
        return;
    }
    q1.dequeue();
}
template <typename T>
int Stack<T>::length()
{
    return q1.length();
}
template <typename T>
void Stack<T>::clear()
{
    q1.clear();
}
template <typename T>
T Stack<T>::topValue()
{
    return q1.Front();
}
template <typename T>
bool Stack<T>::isEmpty()
{
    if (q1.isEmpty())
        return true;
    else
        return false;
}
template <typename T>
void Stack<T>::print()
{
    if (q1.isEmpty())
    {
        cout << "<>" << endl;
    }
    else
    {
        Queue<T> tempQueue;
        cout << "< ";
        while (!q1.isEmpty())
        {
            T val = q1.Front();
            cout << val << " ";
            tempQueue.enqueue(val);
            q1.dequeue();
        }
        cout << ">" << endl;

        // Restore the elements back to q1
        while (!tempQueue.isEmpty())
        {
            T val = tempQueue.Front();
            q1.enqueue(val);
            tempQueue.dequeue();
        }
    }
}
