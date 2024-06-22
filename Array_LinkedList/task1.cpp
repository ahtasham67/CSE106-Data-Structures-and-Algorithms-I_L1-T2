#include <iostream>
#include <string>
#include "Arr.cpp"
// #include "LL.cpp"
using namespace std;

int main()
{
    int X, K;
    cin >> X >> K;
    List list(X, K, 2);
     //List list(X);
     list.print();
     cout<<"\n";

    for (int i = 0;; i++)
    {
        int Q; // number of queries
        cin >> Q;

        if (Q >= 0 && Q <= 10)
        {
            switch (Q)
            {
            case 0:
                exit(0);
                break;
            case 1: // insert an item
                int n;
                cout << "Enter the item you want to insert" << endl;
                cin >> n;
                list.insert(n);
                list.print();
                cout << "\n";
                break;
            case 2: //  remove an item
                cout << "Removed Item " << list.remove() << endl;
                list.print();
                cout << "\n";
                break;
            case 3: // move the current position to the start
                list.moveToStart();
                list.print();
                cout << "\n";
                break;
            case 4: // move the current position to the end
                list.moveToEnd();
                list.print();
                cout << "\n";
                break;
            case 5: // Move the current position one step left. No
                // change if already at the beginning.
                list.prev();
                list.print();
                cout << "\n";
                break;
            case 6: // Move the current position one step right. No
                // change if already at the end.
                list.next();
                list.print();
                cout << "\n";
                break;
            case 7: // Return the number of elements in the list.
                cout << "The length of the list " << list.Length() << endl;
                break;
            case 8: // Return the position (in the list) of currentElement.
                cout << "The current position " << list.currpos() << endl;
                break;
            case 9: // Set current position.
                int newpos;
                cout << "Enter new position" << endl;
                cin >> newpos;
                list.moveToPos(newpos);
                list.print();
                cout<<"\n";
                break;
            case 10: // Return the current element
                cout << "The current element is " << list.getvalue() << endl;
                //cout << "\n";
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