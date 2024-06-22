#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>
#include <cctype>

template <class var>
class Stack
{
    int top;
    var *arr;
    int maxsize;

public:
    Stack()
    {
        top = 0;
        maxsize = 10;
        arr = new var[maxsize];
    }

    Stack(int memSize, int length)
    {
        maxsize = memSize;
        arr = new var[maxsize];
        top = 0;

        for (int i = 0; i < length; i++)
        {
            var n;
            std::cin >> n;
            arr[i] = n;
            top++;
        }
    }

    ~Stack()
    {
        delete[] arr;
    }

    void print()
    {
        if (top == 0)
        {
            std::cout << "<>" << std::endl;
            return;
        }
        std::cout << "<";
        for (int i = 0; i < top - 1; i++)
        {
            std::cout << arr[i] << ", ";
        }
        std::cout << arr[top - 1] << ">" << std::endl;
    }

    void push(var item)
    {
        if (top >= maxsize)
        {
            maxsize *= 2;
            var *newArr = new var[maxsize];
            for (int i = 0; i < top; i++)
            {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
        }
        arr[top++] = item;
    }

    var pop()
    {
        if (top == 0)
        {
            std::cout << "The stack is empty" << std::endl;
            return -1;
        }
        var removedItem = arr[top - 1];
        top--;
        return removedItem;
    }

    int Length()
    {
        return top;
    }

    void clear()
    {
        top = 0;
    }

    var topValue()
    {
        return arr[top - 1];
    }

    bool isEmpty()
    {
        return top == 0;
    }
};

#endif // STACK_H
