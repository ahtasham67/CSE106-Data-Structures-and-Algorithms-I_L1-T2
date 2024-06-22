#include <iostream>
#include <string>
#include "Arr.cpp"
//#include "LL.cpp"
int main()
{
    int X, Y, Z;
    cin >> X; // number of cars
    cin >> Y; // number of garages
    cin >> Z; // number of parking spots in a garage
    List g[Y + 1];

    for (int j = 0; j < Y; j++)
    {
        int garagenum;
        cin >> garagenum;
        g[garagenum].init();
    }

    //int reqcount = 0;
    for (int i = 1; i < Y + 1; i++)
    {
        g[i].print();
        cout << "\n";
    }
    while (1)
    {
        int flag = 0;
        string command;
        cin >> command;
        if (command == "req")
        {
            for (int i = 1; i <= Y; i++)
            {
                if (g[i].Length())
                {
                    flag = 1;
                    g[i].moveToStart();
                    // cout<<g[i].getvalue();
                    int min = g[i].getvalue();
                    int minIndex = 0;
                    // int movingpos=0;

                    for (int k = g[i].currpos(); k < g[i].Length(); k++)
                    {
                        if (min > g[i].getvalue())
                        {
                            min = g[i].getvalue();
                            minIndex = g[i].currpos();
                        }
                        g[i].next();
                    }
                    g[i].moveToPos(minIndex);
                    // g[i].next();
                    g[i].remove();
                    g[i].moveToStart();
                    break;
                }
            }
            if (flag)
            {

                for (int i = 1; i <= Y; i++)
                {
                    g[i].print();
                    cout << "\n";
                }
            }
            else
            {
                cout << "no cars in the garage" << endl;
            }
        }

        else if (command == "ret")
        {
            int carnum;
            cin >> carnum;
            int isEmpty = 0;
            int isFull = 0;
            int i;
            for (i = Y; i >= 1; i--)
            {
                if (g[i].Length() == Z)
                {
                    isFull = 1;
                }
                else
                {
                    isFull = 0;
                    break;
                }
            }
            if (isFull)
            {
                cout << "All garages are full" << endl;
            }
            else
            {
                for (int j = Y; j >= 1; j--)
                {
                    if (g[j].Length() == 0)
                    {
                        // g[j].moveToStart();
                        g[j].insert(carnum);
                        // g[j].next();
                        break;
                    }
                    else if (g[j].Length() < Z)
                    {
                        g[j].moveToStart();
                        // cout<<g[i].getvalue();
                        int max = g[j].getvalue();
                        int maxIndex = 0;
                        // int movingpos=0;
                        for (int k = g[j].currpos(); k < g[j].Length(); k++)
                        {
                            if (max < g[j].getvalue())
                            {
                                max = g[j].getvalue();
                                maxIndex = g[j].currpos();
                            }
                            g[j].next();
                        }
                        g[j].moveToPos(maxIndex);
                        g[j].next();
                        g[j].insert(carnum);
                        g[j].moveToStart();
                        break;
                    }
                    else if (g[j].Length() >= Z)
                    {
                        continue;
                    }
                }
            }

            for (int n = 1; n <= Y; n++)
            {
                g[n].print();
                cout << "\n";
            }
        }
        else if (command == "end")
        {
            break;
            exit(0);
        }
    }
    return 0;
}