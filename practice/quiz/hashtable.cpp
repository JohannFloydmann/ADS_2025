#include <iostream>
using namespace std;

class Node
{
public:
    Node *next;
    int data;

    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};
class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        head = nullptr;
    }
    void insert(int x)
    {
        Node *newNode = new Node(x);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node *curr = head;
        while (curr->next != nullptr)
        {
            curr = curr->next;
        }

        curr->next = newNode;
    }
    Node *search(int x)
    {
        Node *curr = head;
        while (curr != nullptr)
        {
            if (curr->data == x)
            {
                return curr;
            }
            else
            {
                curr = curr->next;
            }
        }
        return nullptr;
    }
};

class HashTable
{
public:
    LinkedList *arr;
    int size;
    HashTable(int n)
    {
        size = n;
        arr = new LinkedList[n];
    }
    int hash(int x)
    {
        return x % size;
    }
    void insert(int x)
    {
        arr[hash(x)].insert(x);
    }
    bool search(int x)
    {
        return arr[hash(x)].search(x) != nullptr;
    }
};

int main()
{
    HashTable ht(10);
    for (int i = 0; i < 10; i++)
    {
        ht.insert(rand()%10);
    }
    cout << ht.search(1);
    return 0;
}