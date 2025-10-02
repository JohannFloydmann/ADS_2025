#include <iostream>
using namespace std;

class Node
{
private:
    Node *parent;
    Node *left;
    Node *right;
    int data;
    int multi;

public:
    Node(int data)
    {
        parent = nullptr;
        left = nullptr;
        right = nullptr;
        this->data = data;
        this->multi = 1;
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
    int getMulti(){
        return multi;
    }
    void addMulti(){
        multi++;
    }
    void subMulti(){
        multi--;
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
            root = v;  
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
        while (curr != NULL && curr->getLeft() != NULL)
        {
            curr = curr->getLeft();
        }
        return curr;
    }

public:
    BST()
    {
        root = nullptr;
    }

    void insert(int newData)
    {
        Node *searchNode = searchByKey(newData);
        if(searchNode){
            searchNode->addMulti();
            return;
        }
        Node *newNode = new Node(newData);

        Node *x = root;
        Node *y = nullptr;

        while (x)
        {
            y = x;  
            if (newData < x->getData())
            {
                x = x->getLeft();
            }
            else
            {
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

    int getMulti(Node *node){
        if(!node)
            return 0;
        else
            return node->getMulti();
    }

    void inOrderTreeWalk(Node *n)
    {
        if (n)
        {
            inOrderTreeWalk(n->getLeft());
            cout << n->getData() << "(" << n->getMulti() << ") ";
            inOrderTreeWalk(n->getRight());
        }
    }

    void print()
    {
        inOrderTreeWalk(root);
        cout << endl;
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

    Node *searchByKey(int key)
    {
        Node *current = root;

        while (current != nullptr && current->getData() != key)
        {
            if (key < current->getData())
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

    void deleteNode(int key)  
    {
        Node *z = searchByKey(key);
        if (!z) return;  
        
        z->subMulti();
        if(z->getMulti() > 0) {
            return;  
        }

        
        if (z->getLeft() == NULL)
        {
            transplant(z, z->getRight());
        }
        else if (z->getRight() == NULL)
        {
            transplant(z, z->getLeft());
        }
        else
        {
            Node *y = minimum(z->getRight());
            if (y->getParent() != z) {
                transplant(y, y->getRight());
                y->setRight(z->getRight());
                y->getRight()->setParent(y);
            }
            transplant(z, y);
            y->setLeft(z->getLeft());
            y->getLeft()->setParent(y);
        }
        delete z;
    }
};

int main()
{
    int n;
    cin >> n;
    BST b;

    for (int i = 0; i < n; i++)
    {
        string command;
        int num;
        cin >> command >> num;
        
        if (command == "insert")
        {
            b.insert(num);
        }
        else if (command == "delete")
        {
            b.deleteNode(num); 
        }
        else if (command == "cnt")
        {
            cout << b.getMulti(b.searchByKey(num)) << endl;
        }
    }
}