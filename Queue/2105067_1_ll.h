#ifndef LL_H
#define LL_H

template <typename T>
struct Node
{
    T data;
    Node<T> *next;
    Node(T val, Node<T> *link)
    {
        data = val;
        next = link;
    }
};

template <typename T>
class List
{
private:
    Node<T> *head;
    Node<T> *curr;
    Node<T> *temp;
    int length;
    int currentpos;

public:
    List(T elementnum);

    List();
    void init();
    void insert(T item);
    T remove();
    void moveToStart();
    void moveToEnd();
    void prev();
    void next();
    int Length();
    int currpos();
    void moveToPos(int pos);
    T getvalue();

    /*void print()
    {
        if (length == 0)
        {
            cout << "<>";
        }
        else
        {
            Node<T> *temp2 = head;
            cout << "< ";
            int count = 0;
            while (temp2 != NULL)
            {
                if (count == currpos())
                {
                    cout << "| ";
                }
                cout << temp2->data << " ";
                temp2 = temp2->next;
                count++;
            }
            cout << " >";
        }
    }*/
};

#include "2105067_1_ll.cpp"

#endif
