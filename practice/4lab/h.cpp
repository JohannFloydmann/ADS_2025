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
    void setData(int key)
    {
        data = key;
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

    Node *getRoot()
    {
        return root;
    }

    void insert(int newData)
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
    }

    void countSums(Node *node, int &sum)
    {
        if (!node)
            return;
        countSums(node->getRight(), sum);

        sum += node->getData();
        node->setData(sum);
        countSums(node->getLeft(), sum);
    }

    void inOrderTreeWalk(Node *n)
    {
        if (n)
        {
            inOrderTreeWalk(n->getLeft());
            cout << n->getData() << " ";
            if (n->getParent())
                cout << n->getParent()->getData();
            cout << endl;
            inOrderTreeWalk(n->getRight());
        }
    }
    void inOrderPrint(Node *node)
    {
        if (!node)
            return;
        inOrderPrint(node->getRight());
        cout << node->getData() << " ";
        inOrderPrint(node->getLeft());
    }

    void print()
    {
        inOrderTreeWalk(root);
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
        b1.insert(temp);
    }
    int sum = 0;
    b1.countSums(b1.getRoot(), sum);
    b1.inOrderPrint(b1.getRoot());

    return 0;
}