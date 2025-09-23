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
        if (this->isEmpty())
        {
            return "error";
        }
        
        return head->data;
    }

    T getTail(){
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

    T delete_tail(){
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
    string s;
	Linked_list<string> lt;
   	while(cin >> s){
   		if(s == "add_front"){
   			string t;
   			cin >> t;
            lt.insert_head(t);
   			cout << "ok" << endl;
   		}
   		if(s == "add_back"){
   			string t;
   			cin >> t;
            lt.insert_tail(t);
   			cout << "ok" << endl;
   		}
   		if(s == "erase_front"){
   			cout << lt.delete_head() << endl;
   		}
   		if(s == "erase_back"){
   			cout << lt.delete_tail() << endl;
   		}
   		if(s == "front"){
   			cout << lt.getHead() << endl;
   		}
   		if(s == "back"){
   			cout << lt.getTail() << endl;
   		}
   		if(s == "clear"){
   			lt.clear();
   			cout << "ok" << endl;
   		}
   		if(s == "exit"){
   			cout << "goodbye" << endl;
   			break;
   		}

   		// cout << "hi" << endl;
   	}
    return 0;
}