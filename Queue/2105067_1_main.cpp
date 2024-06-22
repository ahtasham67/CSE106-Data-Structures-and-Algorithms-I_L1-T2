
 #include "2105067_1_ll_queue.h"
//#include "2105067_1_a_queue.h"
int main()
{
    Queue<int> q;
    //  Queue<char> q;
    q.print();
    for (int i = 0;; i++)
    {
        int Q; // number of queries
        cin >> Q;

        if (Q >= 0 && Q <= 7)
        {
            switch (Q)
            {
            case 0:
                exit(0);
                break;
            case 1: // push an item
                int n;
                //cout << "Enter the item you want to enqueue" << endl;
                cin >> n;
                q.enqueue(n);
                q.print();
                // cout << "\n";
                break;
            case 2: //  pop an item
                q.dequeue();
                q.print();
                // cout << "\n";
                break;
            case 3:
                cout << q.length() << endl;
                // arr.print();
                // cout << "\n";
                break;
            case 4:
                q.clear();
                q.print();
                // cout << "\n";
                break;
            case 5:
                cout << q.Front() << endl;
                // arr.print();
                // cout << "\n";
                break;
            case 6:
                cout << q.back() << endl;
                // arr.print();
                // cout << "\n";
                break;
            case 7:
                if (q.isEmpty())
                {
                    cout << "The queue is empty" << endl;
                }
                else
                {
                    cout << "The queue is not empty" << endl;
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
    return 0;
}