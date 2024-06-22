#ifndef QARR_H
#define QARR_H
#include "2105067_1_a.h"
template <typename T>
class Queue
{
    int rear, front;
    List<T> list;

public:
    Queue();
    bool isfull();
    bool isEmpty();
    void enqueue(T item);
    void dequeue();
    int length();
    T Front();
    T back();
    void clear();

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
    void print();

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
};

#include "2105067_1_a_queue.cpp"
#endif