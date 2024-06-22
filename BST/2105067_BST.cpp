#include <iostream>
#include<fstream>
#include <string>
using namespace std;
ofstream outputFile; // Declare outputFile as a global variable

template <typename T>
class Node
{
public:
    T data;
    Node *left;
    Node *right;
    Node() {}
    Node(T val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
    Node(T val, Node *linkLeft, Node *LinkRight)
    {
        data = val;
        left = linkLeft;
        right = LinkRight;
    }
};
template <typename T>
class BST
{
private:
    Node<T> *root;
    // Node<T> *current;
    Node<T> *insert(Node<T> *current, T val)
    {

        // base class
        if (current == nullptr)
        {
            return new Node<T>(val);
        }
        // if value is greater than data in the root then insert it in the right subtree
        if (val > current->data)
        {
            current->right = insert(current->right, val);
            // return;
        }
        // if value is less than data in the root then insert it in the left subtree
        else if (val < current->data)
        {
            current->left = insert(current->left, val);
        }
        return current;
    }

    void print(Node<T> *current)
    {
        if (current == nullptr)
        {
            outputFile << "";
            return;
        }
        // Node<T> *currPrint = root;
        // outputFile<<"(";
        outputFile << current->data;
        if (current->left != nullptr || current->right != nullptr)
        {
            outputFile << "(";
            print(current->left);
            outputFile << ",";
            print(current->right);
            outputFile << ")";
        }
        // outputFile<<")";
    }
    Node<T>* getMinNode(Node<T> *current)
    {
        if (current == nullptr)
            return current;
        while (current->left != nullptr)
        {
            current = current->left;
        }
        return current;
    }

    Node<T>* getMaxNode(Node<T> *current)
    {
        if (current == nullptr)
            return current;
        while (current->right != nullptr)
        {
            current = current->right;
        }
        return current;
    }
    Node<T> *DeleteFromBST(Node<T> *current, T val)
    { // base case
        if (current == nullptr)
            return current;
        // if matches
        if (current->data == val)
        {
            // 0 child
            if (current->left == nullptr && current->right == nullptr)
            {
                delete current;
                return nullptr;
            }

            // 1 child
            // left child
            if (current->left != nullptr && current->right == nullptr)
            {
                Node<T> *temp = current->left;
                delete current;
                return temp;
            }
            // right child
            if (current->left == nullptr && current->right != nullptr)
            {
                Node<T> *temp = current->right;
                delete current;
                return temp;
            }
            // 2 child
            if (current->left != nullptr && current->right != nullptr)
            {
                //T minVal = getMinVal(current->right);
                //finding the minimum value Node from the right subtree
                Node<T>* minNode=getMinNode(current->right);
                current->data = minNode->data;
                current->right = DeleteFromBST(current->right, minNode->data);
                return current;
            }
        }
        // left subtree
        else if (current->data > val)
        {
            current->left = DeleteFromBST(current->left, val);
            return current;
        }
        // right subtree
        else
        {
            current->right = DeleteFromBST(current->right, val);
            return current;
        }
        return current;
    }
    bool search(Node<T> *current, T val)
    {
        // base cases
        if (current == nullptr)
            return false;
        if (current->data == val)
            return true;

        // search in the right subtree
        if (val > current->data)
        {
            return search(current->right, val);
        }
        else if (val < current->data)
        {
            return search(current->left, val);
        }
        return false;
    }

    void inOrder(Node<T> *current)
    {
        // base class
        if (current == nullptr)
        {
            return;
        }
        inOrder(current->left);
        outputFile << current->data << " ";
        inOrder(current->right);
    }

    void preOrder(Node<T> *current)
    {
        // base class
        if (current == nullptr)
        {
            return;
        }
        outputFile << current->data << " ";
        preOrder(current->left);
        preOrder(current->right);
    }

    void postOrder(Node<T> *current)
    {
        // base class
        if (current == nullptr)
        {
            return;
        }
        postOrder(current->left);
        postOrder(current->right);
        outputFile << current->data << " ";
    }

public:
    BST<T>()
    {
        root = nullptr;
    }
    void insert(T val)
    {
        root = insert(root, val);
    }
    void print()
    {
        print(root);
        // outputFile << endl;
    }
    bool find(T val)
    {
        return search(root, val);
    }
    void Delete(T val)
    {
        DeleteFromBST(root, val);
    }
    void inOrder()
    {
        inOrder(root);
    }
    void preOrder()
    {
        preOrder(root);
    }
    void postOrder()
    {
        postOrder(root);
    }
};

