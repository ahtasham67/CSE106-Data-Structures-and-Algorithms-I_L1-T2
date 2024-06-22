#include <iostream>
using namespace std;

class List
{
    int curr;
    int maxlength;
    int length;
    // int currpos;
    int *arr;

public:
    List(int, int, int); // parameterized contructor to take input and
                         // allocation of memory
    List();
    void init();
    void print(); // output in one line the items of the list within angle bracket,
                  //  space separated identifying the current position using “|”
                  // as defined/shown in Table 1
    void insert(int);
    void takeInput();
    int remove();
    void moveToStart();
    void moveToEnd();
    void prev();
    void next();
    int Length();
    int currpos();
    void moveToPos(int);
    int getvalue();
    //void append(int);
    //int search(int);
    //void clear();
};
void List ::init()
{
    int num;
    cin >> num;
    curr = 0;
    length = 0;
    maxlength = num + 1;
    arr = new int[num + 1];
    for (int i = 0; i < num; i++)
    {
        int n;
        cin >> n;
        arr[i] = n;
        // insert(n);
        // next();
        length++;
    }
}

List ::List() {}
List ::List(int initlen, int memsize, int currpos)
{
    curr = 0;
    length = 0;
    maxlength = memsize;
    arr = new int[maxlength];
    if (length < maxlength)
    {
        arr = new int[maxlength];
    }
    else if (length >= maxlength)
    {
        arr = new int[2 * maxlength];
    }
    for (int i = 0; i < initlen; i++)
    {
        int num;
        cin >> num;
        // arr[i] = num;
        insert(num);
        next();
    }
    moveToPos(currpos);
    // moveToStart();
}

/*List ::~List()
{
    delete[] arr;
}*/
void List ::print()
{
    if (length == 0)
    {
        cout << "<>";
    }
    else
    {
        cout << "<";
        for (int i = 0; i < curr; i++)
        {
            /*if(i==curr){
                cout<<"| "<<arr[i]<<" ";
            }
            else*/
            cout << arr[i] << " ";
        }
        // cout << ">";
        cout << "| ";
        for (int i = curr; i < length; i++)
        {
            cout << arr[i] << " ";
        }
        cout << ">";
    }
}
void List ::insert(int num)
{
    /*if (length < maxlength)
    {
        arr = new int[maxlength];
    }*/
    if (length >= maxlength)
    {
        arr = (int *)realloc(arr, 2 * maxlength * sizeof(int));
        maxlength = 2 * maxlength;
    }
    for (int i = length; i > curr; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[curr] = num;
    length++;
}

int List ::remove()
{
    int removedItem;
    if (curr < 0 || curr > length)
    {
        cout << "No element" << endl;
        return -1;
    }
    else
    {

        removedItem = arr[curr];
        for (int i = curr; i < length - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        if (curr == length - 1)
        {
            prev();
        }
        length--;
        return removedItem;
    }
}

void List ::moveToStart()
{
    curr = 0;
}

void List ::moveToEnd()
{
    curr = length - 1;
}

void List ::prev()
{
    if (curr != 0)
        curr--;
}

void List ::next()
{
    if (curr < length)
    {
        curr++;
    }
}

int List ::Length()
{
    return length;
}

int List ::currpos()
{
    return curr;
}
void List ::moveToPos(int pos)
{
    if (pos < 0 || pos > length)
    {
        cout << "position is out of range" << endl;
    }
    else
    {
        curr = pos;
    }
}

int List ::getvalue()
{
    if (curr < 0 || curr > length)
    {
        cout << "No element" << endl;
        return -1;
    }
    else
    {
        return arr[curr];
    }
}

