#ifndef TASK2_H
#define TASK2_H

#include "2105067_1_ll_queue.h"

template <typename T>
class Stack
{
    Queue<T> q1;
    Queue<T> q2;

public:
    void push(T item);
    void pop();
    int length();
    void clear();
    T topValue();
    bool isEmpty();
    void print();
};
#include "2105067_2_stack.cpp"
#endif