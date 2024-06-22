#include<iostream>
#include"2105067_2_stack.h"
using namespace std;

int main(){
    Stack<int>stack;
        stack.print();
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
                    //cout << "Enter the item you want to push" << endl;
                    cin >> n;
                    stack.push(n);
                    stack.print();
                    // cout << "\n";
                    break;
                case 2: //  pop an item
                    cout << "Removed Item " << stack.topValue() << endl;
                    stack.pop();
                    stack.print();
                    // cout << "\n";
                    break;
                case 3:
                    stack.clear();
                    stack.print();
                    // cout << "\n";
                    break;
                case 4:
                    cout << stack.length() << endl;
                    // stack.print();
                    // cout << "\n";
                    break;
                case 5:
                    if (stack.topValue())
                        
                    cout << stack.topValue() << endl;
                    else cout << "-1" << endl;
                    // stack.print();
                    // cout << "\n";
                    break;
                case 6:
                    if (stack.isEmpty())
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