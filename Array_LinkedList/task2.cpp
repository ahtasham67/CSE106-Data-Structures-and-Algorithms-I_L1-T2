#include <iostream>
#include <string>
// #include "Arr.cpp"
#include "LL.cpp"
using namespace std;

void append(List &list, int num)
{
    int backToPos = list.currpos();
    list.moveToEnd();
    list.next();
    list.insert(num);
    list.moveToPos(backToPos);
}

void clear(List &list)
{
    list.moveToStart();
    while (list.Length() > 0)
    {
        list.remove();
    }
    list.moveToStart();
}

int search(List &list, int num)
{
    int prevPosition = list.currpos();
    list.moveToStart();

    for (int i = 0; i < list.Length(); i++)
    {
        if (list.getvalue() == num)
        {
            list.moveToPos(prevPosition);
            return i;
        }
        list.next();
    }

    list.moveToPos(prevPosition);
    return -1;
}

int main()
{
    int X, K;
    cin >> X >> K;
    // List list(X, K, 2);
    List list(X);

    list.print();
    cout << "\n";
    for (int i = 0;; i++)
    {
        int Q; // number of queries
        cin >> Q;

        if (Q >= 0 && Q <= 3)
        {
            switch (Q)
            {
            case 0:
                exit(0);
                break;
            case 2:
                int appendNum;
                cin >> appendNum;
                append(list, appendNum);
                list.print();
                cout << "\n";
                break;

            case 1:
                clear(list);
                list.print();
                cout << "\n";
                break;

            case 3:
                int searchval;
                cin >> searchval;
                cout << search(list, searchval) << endl;
                break;
            }
        }
        else
        {
            cout << "Invalid input" << endl;
        }
    }
    return 0;
}