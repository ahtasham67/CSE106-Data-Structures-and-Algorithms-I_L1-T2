#include <iostream>
#include <string>
// #include "2105067_1_ll.cpp"
#include "2105067_1_ll_queue.h"
using namespace std;

template <typename T>

Queue<T>::Queue()
{
    list.init();
    rear = list.Length() - 1;
    front = -1;
}
template <typename T>

void Queue<T>::enqueue(T item)
{
    rear++;
    list.moveToPos(rear);
    list.insert(item);
    if (front == -1)
    {
        front = 0;
    }
}

/*void dequeue()
{
    if (front == -1 || front > rear)
    {
        cout << "The queue is already empty!" << endl;
    }
    else
    {
        list.moveToPos(front);
        list.remove();
        front++;
    }
}*/
template <typename T>

void Queue<T>::dequeue()
{
    if (front == -1 || front > rear)
    {
        cout << "The queue is already empty!" << endl;
        return;
    }

    // list.moveToPos(front);
    // list.remove();
    list.moveToStart();
    list.remove();
    front++;

    if (front > rear)
    {
        front = -1;
        rear = list.Length() - 1;
    }
}

template <typename T>

int Queue<T>::length()
{
    return list.Length();
}
template <typename T>

T Queue<T>::Front()
{
    // list.moveToPos(front);
    list.moveToStart();
    return list.getvalue();
}

template <typename T>
T Queue<T>::back()
{
    // list.moveToPos(rear);
    list.moveToEnd();
    return list.getvalue();
}
template <typename T>

bool Queue<T>::isEmpty()
{
    return list.Length() == 0;
}
template <typename T>
void Queue<T>::clear()
{
    list.moveToStart();
    while (list.Length() > 0)
    {
        list.remove();
    }
    list.moveToStart();
    front = -1;
    rear = -1;
}
template <typename T>
void Queue<T>::print()
{
    if (isEmpty())
        cout << "<>" << endl;
    else
    {
        cout << "< ";
        list.moveToStart();
        for (int i = 0; i < list.Length(); i++)
        {
            cout << list.getvalue() << " ";
            list.next();
        }
        cout << ">" << endl;
    }
}
