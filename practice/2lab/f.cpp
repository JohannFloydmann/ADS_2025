#include <iostream>

using namespace std;

template <typename T>
class Node
{
private:
    Node<T> *next;
    Node<T> *prev;

public:
    T data;
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
    int size;

public:
    Linked_list()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    Linked_list(T value)
    {
        Node<T> *first = new Node<T>(value);
        head = first;
        tail = first;
        size = 1;
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
        size++;
    }

    void insert_head(T value)
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
            head->setPrev(node);
            node->setNext(head);
            head = node;
        }
        size++;
    }

    T getHead()
    {
        if (this->isEmpty())
        {
            return "error";
        }

        return head->data;
    }

    T getTail()
    {
        if (this->isEmpty())
        {
            return "error";
        }

        return tail->data;
    }

    bool isEmpty()
    {
        return head == nullptr && tail == nullptr;
    }

    void clear()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void insert(int number, int index)
    {
        Node<T> *curr = head;
        for (int stepCount = 0; stepCount < index; stepCount++)
        {
            curr = curr->getNext();
        }

        Node<T> *newNode = new Node<T>(number);

        if (index == 0)
        {
            newNode->setNext(curr);
            curr->setPrev(newNode);
            head = newNode;
        }
        else if (index == size)
        {
            newNode->setNext(curr);
            curr->setPrev(newNode);
            tail = newNode;
        }
        else
        {
            
            curr->getPrev()->setNext(newNode);
            newNode->setNext(curr);
            curr->setPrev(newNode);
        }
    }

    T delete_head()
    {
        if (head == nullptr)
        {
            return "error";
        }
        size--;
        Node<T> *next_node = head->getNext();
        if (next_node)
        {
            next_node->setPrev(nullptr);
        }
        else
        {
            tail = nullptr;
        }
        T value = head->data;
        delete head;
        head = next_node;
        return value;
    }

    T delete_tail()
    {
        if (tail == nullptr)
        {
            return "error";
        }
        size--;
        Node<T> *prev_node = tail->getPrev();
        if (prev_node)
        {
            prev_node->setNext(nullptr);
        }
        else
        {
            head = nullptr;
        }
        T value = tail->print();
        delete tail;
        tail = prev_node;
        return value;
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
    Linked_list<int> lt;

    cin >> size;

    for (int i = 0; i < size; i++)
    {
        int temp;
        cin >> temp;
        lt.insert_tail(temp);
    }

    int num, index;

    cin >> num >> index;

    lt.insert(num, index);
    lt.print();

    return 0;
}