#include <iostream>
using namespace std;

class Node
{
public:
    Node *parent;
    Node *left;
    Node *right;
    int data;
    Node(int newData)
    {
        this->data = newData;
        this->left = nullptr;
        this->right = nullptr;
        this->parent = nullptr;
    }
};

class BST
{
public:
    Node *root;
    BST()
    {
        root = nullptr;
    }
    int insert(int newData)
    {
        Node *newNode = new Node(newData);
        Node *x = root;
        Node *y = nullptr;
        int level = 0;
        while (x)
        {
            while (x != nullptr)
            {
                y = x;
                if (newData > x->data)
                {
                    x = x->right;
                }
                else
                {
                    x = x->left;
                }
                level++;
            }
        }
        if (!y)
        {
            root = newNode;
        }
        else
        {
            if (newData > y->data)
            {
                y->right = newNode;
            }
            else
            {
                y->left = newNode;
            }
        }
        return level;
    }
};

int main()
{
    BST bst;
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        sum += (temp - bst.insert(temp));
    }

    cout << sum;
    return 0;
}