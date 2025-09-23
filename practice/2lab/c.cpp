#include <iostream>
using namespace std;

template <typename T>
class Node
{
private:
    Node<T> *next;
    Node<T> *prev;
    T data;

public:
    Node(T value)
    {
        next = nullptr;
        prev = nullptr;
        data = value;
    }

    void setNext(Node<T> *a)
    {
        next = a;
    }

    void setPrev(Node<T> *a)
    {
        prev = a;
    }

    Node<T> *getNext()
    {
        return next;
    }

    Node<T> *getPrev()
    {
        return prev;
    }

    T print()
    {
        return data;
    }
};

template <typename T>
class Linked_list
{
private:
    Node<T> *head;
    Node<T> *tail;

public:
    Linked_list()
    {
        head = nullptr;
        tail = nullptr;
    }
    Linked_list(T value)
    {
        Node<T> *first = new Node<T>(value);
        head = first;
        tail = first;
    }
    void insert_tail(T value)
    {
        if (head == nullptr && tail == nullptr)
        {
            Node<T> *first = new Node<T>(value);
            head = first;
            tail = first;
        }
        else
        {
            Node<T> *node = new Node<T>(value);
            tail->setNext(node);
            node->setPrev(tail);
            tail = node;
        }
    }

    void delete_head()
    {
        if (head == nullptr)
        {
            return; 
        }
        Node<T> *next_node = head->getNext(); 
        if (next_node)
        {
            next_node->setPrev(nullptr);
        }
        else
        {
            tail = nullptr; 
        }
        delete head; 
        head = next_node;
    }

    void print()
    {
        Node<T> *curr = head;
        while (curr)
        {
            cout << curr->print() << ' ';
            curr = curr->getNext();
        }
        cout << endl;
    }

    ~Linked_list()
    {
        Node<T> *curr = head;
        while (curr)
        {
            Node<T> *next = curr->getNext();
            delete curr;
            curr = next;
        }
    }
};

int main()
{
    int size;
    cin >> size;

    Linked_list<int> lt;
    for (int i = 0; i < size; i++)
    {
        int temp;
        cin >> temp;
        if (i%2==0)
        {
            lt.insert_tail(temp);
        }
    }
    
    lt.print();

    return 0;
}