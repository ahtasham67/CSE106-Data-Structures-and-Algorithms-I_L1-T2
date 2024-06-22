#include <iostream>
using namespace std;
#include "2105067_1_ll.h"

template <typename T>
List<T>::List(T elementnum)
{
    head = NULL;
    temp = NULL;
    length = 0;
    currentpos = 0;
    for (int i = 0; i < elementnum; i++)
    {
        T num;
        cin >> num;
        insert(num);
        next();
    }
    moveToStart();
}
template <typename T>
List<T>::List() {}

template <typename T>
void List<T>::init()
{
    // T elementnum;
    // cin >> elementnum;
    head = NULL;
    temp = NULL;
    length = 0;
    currentpos = 0;
    /*for (int i = 0; i < elementnum; i++)
    {
        T num;
        cin >> num;
        insert(num);
        next();
    }*/
    moveToStart();
}

template <typename T>
void List<T>::insert(T item)
{
    Node<T> *newNode = new Node<T>(item, NULL);
    // newNode->data = item;
    // newNode->next = nullptr;

    if (head == NULL)
    {
        head = newNode;
        temp = head;
    }
    else if (currentpos == 0 && head != NULL)
    {
        newNode->next = head;
        head = newNode;
    }
    else if (head->next == NULL)
    {
        head->next = newNode;
    }
    /*else if(length==1 && head->next!=NULL)
      {
    newNode->next = temp->next;
    temp->next = newNode;
      }*/
    else
    {
        temp = head;
        for (int i = 1; i < currentpos; i++)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
    length++;
}

template <typename T>
T List<T>::remove()
{
    if (temp == NULL)
    {
        cout << "No element to remove." << endl;
        return T();
    }

    Node<T> *temp = head;
    T removedValue;

    if (currentpos == 0)
    {
        head = head->next;
        removedValue = temp->data;
        delete temp;
        temp = head;
    }
    else
    {
        for (int i = 1; i < currentpos; i++)
        {
            temp = temp->next;
        }
        Node<T> *removedNode = temp->next;
        removedValue = removedNode->data;
        temp->next = removedNode->next;
        delete removedNode;
    }

    length--;
    // Adjust the current position if it was pointing to the removed element
    if (currentpos >= length)
    {
        currentpos = length - 1;
    }
    return removedValue;
}
template <typename T>

void List<T>::moveToStart()
{
    temp = head;
    currentpos = 0;
}
template <typename T>
void List<T>::moveToEnd()
{
    currentpos = length - 1;
}
template <typename T>
void List<T>::prev()
{
    if (currentpos <= 0 || currentpos >= length)
    {
        cout << "Position is out of range!" << endl;
    }
    else
    {
        Node<T> *prevNode = head;
        for (int i = 0; i < currentpos - 1; i++)
        {
            prevNode = prevNode->next;
        }
        temp = prevNode;
        currentpos--;
    }
}
template <typename T>
void List<T>::next()
{
    if (currentpos < 0 || currentpos > length - 1)
    {
        cout << "position is out of range!" << endl;
    }
    else
    {
        if (temp->next != NULL)
        {
            temp = temp->next;
        }
        currentpos++;
    }
}
template <typename T>

int List<T>::Length()
{
    return length;
}
template <typename T>

int List<T>::currpos()
{

    return currentpos;
}
template <typename T>
void List<T>::moveToPos(int pos)
{
    currentpos = pos;
}
template <typename T>
T List<T>::getvalue()
{
    if (temp == NULL)
    {
        cout << "No element at current position." << endl;
        return -1;
    }

    Node<T> *node = head;
    for (int i = 0; i < currentpos; i++)
    {
        node = node->next;
    }
    return node->data;
}

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
