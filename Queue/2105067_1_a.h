#ifndef ARRAY_H
#define ARRAY_H
template <typename T>
class List
{
    int curr;
    int maxlength;
    int length;
    // int currpos;
    T *arr;

public:
    List(int, int, int); // parameterized contructor to take input and
                         // allocation of memory
    List();
    void init();
    void print(); // output in one line the items of the list within angle bracket,
                  //  space separated identifying the current position using “|”
                  // as defined/shown in Table 1
    void insert(T);
    void takeInput();
    T remove();
    void moveToStart();
    void moveToEnd();
    void prev();
    void next();
    int Length();
    int currpos();
    void moveToPos(int);
    T getvalue();
    // void append(int);
    // int search(int);
    // void clear();
    void expandArray();
    int getmaxLength();
};

#include "2105067_1_a.cpp"

#endif