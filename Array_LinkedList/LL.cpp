#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int val, Node *link)
    {
        data = val;
        next = link;
    }
};

class List
{
private:
    Node *head;
    Node *curr;
    Node *temp;
    int length;
    int currentpos;

public:
    List(int elementnum)
    {
        head = NULL;
        temp = NULL;
        length = 0;
        currentpos = 0;
        for (int i = 0; i < elementnum; i++)
        {
            int num;
            cin >> num;
            insert(num);
            next();
        }
        moveToStart();
    }
    List() {}
    void init()
    {
        int elementnum;
        cin >> elementnum;
        head = NULL;
        temp = NULL;
        length = 0;
        currentpos = 0;
        for (int i = 0; i < elementnum; i++)
        {
            int num;
            cin >> num;
            insert(num);
            next();
        }
        moveToStart();
    }
    void insert(int item)
    {
        Node *newNode = new Node(item, NULL);
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

    int remove()
    {
        if (temp == NULL)
        {
            cout << "No element to remove." << endl;
            return -1;
        }

        Node *temp = head;
        int removedValue;

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
            Node *removedNode = temp->next;
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

    void moveToStart()
    {
        temp = head;
        currentpos = 0;
    }

    void moveToEnd()
    {
        currentpos = length - 1;
    }

    void prev()
    {
        if (currentpos <= 0 || currentpos >= length)
        {
            cout << "Position is out of range!" << endl;
        }
        else
        {
            Node *prevNode = head;
            for (int i = 0; i < currentpos - 1; i++)
            {
                prevNode = prevNode->next;
            }
            temp = prevNode;
            currentpos--;
        }
    }

    void next()
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

    int Length()
    {
        return length;
    }

    int currpos()
    {

        return currentpos;
    }

    void moveToPos(int pos)
    {
        currentpos = pos;
    }

    int getvalue()
    {
        if (temp == NULL)
        {
            cout << "No element at current position." << endl;
            return -1;
        }

        Node *node = head;
        for (int i = 0; i < currentpos; i++)
        {
            node = node->next;
        }
        return node->data;
    }

    void print()
    {
        if (length == 0)
        {
            cout << "<>";
        }
        else
        {
            Node *temp2 = head;
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
    }
    
};
