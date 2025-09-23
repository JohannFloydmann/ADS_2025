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

    void insert_head(T value){
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

    T getHead(){
        return head->data;
    }

    T getTail(){
        return tail->data;
    }

    void clear(){
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

    void delete_tail(){
        if (tail == nullptr)
        {
            return "error";
        }
        Node<T> *prev_node = tail->getPrev(); 
        if (prev_node)
        {
            prev_node->setNext(nullptr);
        }
        else{
            head = nullptr;
        }
        T value = tail->data;
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
    // Test with integers
    Linked_list<int> int_list;
    int_list.insert_tail(1);
    int_list.insert_tail(2);
    int_list.insert_tail(3);
    cout << "Integer list: ";
    int_list.print(); // Output: 1 2 3

    // Test with strings
    Linked_list<string> str_list;
    str_list.insert_tail("hello");
    str_list.insert_tail("world");
    cout << "String list: ";
    str_list.print(); // Output: hello world

    // Test delete_head
    int_list.delete_head();
    cout << "Integer list after delete_head: ";
    int_list.print(); // Output: 2 3

    return 0;
}