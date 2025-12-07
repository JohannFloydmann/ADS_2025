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

    T getData()
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
    }

    T getHead()
    {
        return head->data;
    }

    T getTail()
    {
        return tail->data;
    }

    void clear()
    {
        head = nullptr;
        tail = nullptr;
    }

    T delete_head()
    {
        if (head == nullptr)
        {
            return "error";
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
        Node<T> *prev_node = tail->getPrev();
        if (prev_node)
        {
            prev_node->setNext(nullptr);
        }
        else
        {
            head = nullptr;
        }
        T value = tail->data;
        delete tail;
        tail = prev_node;
        return value;
    }
    Node<T>* forward_search(T value)
    {
        Node<T> *curr = head;
        while (curr)
        {
            if (curr->getData() == value)
                return curr;
            else
                curr = curr->getNext();
        }
        return nullptr;
    }

    void print()
    {
        Node<T> *curr = head;
        while (curr)
        {
            cout << curr->getData() << ' ';
            curr = curr->getNext();
        }
        if (curr != head)
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

class HashTable
{
private:
    Linked_list<int> *arr;
    int size;

    int hash(int value)
    {
        return value % size;
    }

    int rolling_hashing(string s){
        int l = s.size();
        int h = (int)s[0]-((int)'a'-1);
        int pow = 26; 
        for (int i = 1; i<l;i++)
        {
            h = ((h*pow)%size+((int)s[i]-((int)'a'-1)))%size;
        }
        return h;
    }

public:
    HashTable(int m)
    {
        arr = new Linked_list<int>[m];
        size = m;
    }
    ~HashTable()
    {
        delete[] arr;
    }

    void insert(int value)
    {
        int h = hash(value);
        arr[h].insert_tail(value);
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            arr[i].print();
        }
    }

    Node<int> *search(int key)
    {
        int h = hash(key);
        return arr[h].forward_search(key);
    }
};

int main()
{
    srand(time(0));
    HashTable ht(10);
    for (int i = 0; i < 10; i++)
    {
        ht.insert(rand() % 10);
    }
    ht.print();
    cout << ht.search(5);

    return 0;
}