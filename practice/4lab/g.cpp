#include <iostream>
using namespace std;

class Node
{
private:
    Node *parent;
    Node *left;
    Node *right;
    int data;

public:
    Node(int data)
    {
        parent = nullptr;
        left = nullptr;
        right = nullptr;
        this->data = data;
    }
    int getData()
    {
        return data;
    }

    void setLeft(Node *newLeft)
    {
        left = newLeft;
    }
    void setRight(Node *newRight)
    {
        right = newRight;
    }
    void setParent(Node *newParent)
    {
        parent = newParent;
    }

    Node *getLeft()
    {
        return left;
    }
    Node *getRight()
    {
        return right;
    }
    Node *getParent()
    {
        return parent;
    }
};

class BST
{
private:
    Node *root;

    // helper:
    void transplant(Node *u, Node *v)
    {
        Node *par = u->getParent();
        if (par == NULL)
        {
            v = root;
        }
        else if (u == par->getLeft())
        {
            par->setLeft(v);
        }
        else
        {
            par->setRight(v);
        }
        if (v)
        {
            v->setParent(par);
        }
    }

    Node *minimum(Node *pseudoroot)
    {
        Node *curr = pseudoroot;
        Node *old_curr = NULL;
        while (curr != NULL)
        {
            old_curr = curr;
            curr = curr->getLeft();
        }

        return old_curr;
    }

public:
    BST()
    {
        root = nullptr;
    }
    Node *getRoot(){
        return root;
    }

    Node *insert(int newData)
    {
        Node *newNode = new Node(newData);

        Node *x = root;
        Node *y = nullptr;

        while (x)
        {
            if (x->getData() > newData)
            {
                y = x;
                x = x->getLeft();
            }
            else
            {
                y = x;
                x = x->getRight();
            }
        }

        if (y == nullptr)
        {
            root = newNode;
        }
        else
        {
            if (newData < y->getData())
            {
                y->setLeft(newNode);
            }
            else
            {
                y->setRight(newNode);
            }
            newNode->setParent(y);
        }
        return newNode;
    }

    pair<int, int> diameter(Node* node) {
        if (!node) return {0, 0};
        
        auto left = diameter(node->getLeft());
        auto right = diameter(node->getRight());
        
        int height = 1 + max(left.first, right.first);
        int diam = max(left.second, right.second);
        diam = max(left.first + right.first, diam);
        
        return {height, diam};
    }

    Node *searchByValue(int value)
    {
        Node *current = root;
        while (current != nullptr && current->getData() != value)
        {
            if (value < current->getData())
            {
                current = current->getLeft();
            }
            else
            {
                current = current->getRight();
            }
        }
        return current;
    }

    void clear(Node *n)
    {
        if (n)
        {
            clear(n->getLeft());
            clear(n->getRight());
            delete n;
        }
    }

    ~BST()
    {
        clear(root);
    }
};

int main()
{

    BST b1;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        Node *node = b1.searchByValue(temp);
        if (!node)
            Node *newNode = b1.insert(temp);
    }

    int maxDistance = b1.diameter(b1.getRoot()).second;
    cout << maxDistance+1 << endl;
}