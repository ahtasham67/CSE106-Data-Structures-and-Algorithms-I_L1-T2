#include <iostream>
#include "2105067_1_a_queue.h"
using namespace std;

template <typename T>
Queue<T>::Queue()
{
    list.init();
    rear = -1;
    front = -1;
}

template <typename T>
bool Queue<T>::isfull()
{
    if (front == 0 && rear == list.Length() - 1)
        return true;
    if (front == rear + 1)
        return true;
    if (rear - front + 1 == length())
        return true;
    return false;
}
template <typename T>
bool Queue<T>::isEmpty()
{
    return front == -1;
}
template <typename T>
void Queue<T>::enqueue(T item)
{
    if (isfull())
    {
        list.expandArray();
        rear = (rear + 1) % list.getmaxLength();
    }
    else if (isEmpty())
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % list.getmaxLength();
    }

    // list.moveToPos(rear);
    list.moveToEnd();
    list.next();
    list.insert(item);
}
template <typename T>
void Queue<T>::dequeue()
{
    if (isEmpty())
    {
        cout << "The queue is empty!" << endl;
        return;
    }

    // list.moveToPos(front);
    // list.remove();
    else
    {
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            // list.moveToPos(front);
            // list.remove();
            front = (front + 1) % list.getmaxLength();
        }
        return;
    }
}
template <typename T>
int Queue<T>::length()
{
    if (front == -1)
        return 0;
    else if (front <= rear)
        return rear - front + 1;
    else
        return list.Length() - front + rear + 1;
}
template <typename T>

T Queue<T>::Front()
{
    list.moveToPos(front);
    return list.getvalue();
}

template <typename T>
T Queue<T>::back()
{
    list.moveToPos(rear);
    return list.getvalue();
}

template <typename T>
void Queue<T>::clear()
{
    front = -1;
    rear = -1;
    list.init();
}

/* void print()
{
 if (isEmpty())
 {
     cout << "<>" << endl;
 }
 else
 {
     cout << "<";
     int i = front;
     while (true)
     {
         list.moveToPos(i);
         cout << list.getvalue() << " ";

         if (i == rear)
             break;

         i = (i + 1) % list.Length();
     }
     cout << ">" << endl;
 }
}*/
template <typename T>
void Queue<T>::print()
{
    if (isEmpty())
        cout << "<>" << endl;
    else
    {
        cout << "<";
        for (int i = front;; i = (i + 1) % list.Length())
        {
            if (i == rear)
            {
                list.moveToPos(i);
                cout << list.getvalue();
                break;
            }
            list.moveToPos(i);
            cout << list.getvalue() << " ";
            // if (i == rear)
            //   break;
        }
        // cout << back() << " ";
        cout << ">" << endl;
    }
}
/*void print()
    {
        if (isEmpty())
            cout << "<>" << endl;
        else
        {
            cout << "<";
            for (int i = front; i != rear+1; i = (i + 1) % list.Length())
            {
                list.moveToPos(i);
                cout << list.getvalue() << " ";
            }
            cout << back() << " ";
            cout << ">" << endl;
        }
    }*/
