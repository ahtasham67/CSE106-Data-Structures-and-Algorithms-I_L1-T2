#include <iostream>
#include <string>
#include <cctype>
#include "header.cpp"
using namespace std;

int main()
{
    int choice;
    cout << "Enter your choice what type of stack you would like to constract?" << endl;
    cout << "1.int" << endl;
    cout << "2.char" << endl;
    cin >> choice;
    int X, K;
    cin >> X >> K;
    if (choice == 1)
    {
        Stack<int> arr(X, K);
        arr.print();
        for (int i = 0;; i++)
        {
            int Q; // number of queries
            cin >> Q;

            if (Q >= 0 && Q <= 6)
            {
                switch (Q)
                {
                case 0:
                    exit(0);
                    break;
                case 1: // push an item
                    int n;
                    cout << "Enter the item you want to push" << endl;
                    cin >> n;
                    arr.push(n);
                    arr.print();
                    // cout << "\n";
                    break;
                case 2: //  pop an item
                    cout << "Removed Item " << arr.pop() << endl;
                    arr.print();
                    // cout << "\n";
                    break;
                case 3:
                    arr.clear();
                    arr.print();
                    // cout << "\n";
                    break;
                case 4:
                    cout << arr.Length() << endl;
                    // arr.print();
                    // cout << "\n";
                    break;
                case 5:
                    if (arr.topValue())
                        
                    cout << arr.topValue() << endl;
                    else cout << "-1" << endl;
                    // arr.print();
                    // cout << "\n";
                    break;
                case 6:
                    if (arr.isEmpty())
                    {
                        cout << "The stack is empty" << endl;
                    }
                    else
                    {
                        cout << "The stack is not empty" << endl;
                    }
                    // cout << "\n";
                    break;
                }
            }
            else
            {
                cout << "Invalid input" << endl;
            }
        }
    }
    else if (choice == 2)
    {
        Stack<char> arr(X, K);
        arr.print();
        for (int i = 0;; i++)
        {
            int Q; // number of queries
            cin >> Q;

            if (Q >= 0 && Q <= 6)
            {
                switch (Q)
                {
                case 0:
                    exit(0);
                    break;
                case 1: // push an item
                    char n;
                    cout << "Enter the item you want to push" << endl;
                    cin >> n;
                    arr.push(n);
                    arr.print();
                    // cout << "\n";
                    break;
                case 2: //  pop an item
                    cout << "Removed Item " << arr.pop() << endl;
                    arr.print();
                    // cout << "\n";
                    break;
                case 3:
                    arr.clear();
                    arr.print();
                    // cout << "\n";
                    break;
                case 4:
                    cout << arr.Length() << endl;
                    ;
                    arr.print();
                    // cout << "\n";
                    break;
                case 5:
                    if (arr.topValue())
                        cout << arr.topValue() << endl;
                    else
                        cout << "-1" << endl;
                    // arr.print();
                    // cout << "\n";
                    break;
                case 6:
                    if (arr.isEmpty())
                    {
                        cout << "The stack is empty" << endl;
                    }
                    else
                    {
                        cout << "The stack is not empty" << endl;
                    }
                    // cout << "\n";
                    break;
                }
            }
            else
            {
                cout << "Invalid input" << endl;
            }
        }
    }

    return 0;
}