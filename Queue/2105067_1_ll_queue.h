#ifndef QLL_H
#define QLL_H
#include "2105067_1_ll.h"
template <typename T>
class Queue
{
    int rear;
    int front;
    List<T> list;

public:
    Queue();
    void enqueue(T item);

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

    void dequeue();
    int length();
    T Front();
    T back();
    bool isEmpty();
    void clear();
    void print();
};

#include "2105067_1_ll_queue.cpp"
#endif