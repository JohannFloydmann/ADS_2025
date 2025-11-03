#include <iostream>
using namespace std;


class Node
{
private:
    int data;
    Node* prev;
    Node* next;
public:
    Node(int newData){
        data= newData;
        prev = NULL;
        next = NULL;
    }
    
    void setData(int newData){
        data = newData;
    }
    void setPrev(Node* newPrev){
        prev = newPrev;
    }
    void setNext(Node* newNext){
        next = newNext;
    }

    Node* getNext(){
        return next;
    }
    Node* getPrev(){
        return prev;
    }
    int getData(){
        return data;
    }
};


class LinkedList
{
private:
    Node* head;
    Node* tail;
public:
    
    LinkedList(){
        head = NULL;
        tail = NULL;
    }

    LinkedList(Node* startNode){
        head = startNode;
        tail = startNode;
    }

    ~LinkedList(){
        Node* curr = head;
        Node* old_curr = NULL;
        while(curr){
            old_curr = curr;
            curr = curr->getNext();
            delete old_curr;
        }
    }

    
    void insert_tail(int newData){
        Node* newNode = new Node(newData);
        if(head==NULL and tail==NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->setNext(newNode);
            newNode->setPrev(tail);
            tail = newNode;
        }
    }


    void print(){
        Node* curr = head;

        while(curr){
            cout<<curr->getData()<<"->";
            curr = curr->getNext();//i++
        }
    }

    void reverse_print(){
        Node* curr = tail;

        while(curr){
            cout<<curr->getData()<<endl;
            curr = curr->getPrev();
        }
    }

    void remove_node(Node* node){
        Node* next = node->getNext();
        Node* prev = node->getPrev();
        if(next==NULL && prev == NULL){
            tail = NULL;
            head = NULL;
            delete node;
        }
        else if(next == NULL && prev){
            tail = prev;
            prev->setNext(NULL);
            delete node;
        }
        else if(prev == NULL && next){
            head = next;
            next->setPrev(NULL);
            delete node;
        }
        else if(node==NULL){
            cout<<"nothing to delete"<<endl;
        }
    }

    

    int count(){
        int cnt = 0;
        Node* curr = head;
        while(curr){
            cnt++;
            curr = curr->getNext();
        }
        return cnt;
    }

    Node* forwardSearch(int key){
        Node* curr = head;
        while(curr){
            if(curr->getData()==key){
                return curr;
            }
            curr = curr->getNext();
        }
        return nullptr;
    }
};


class HashTable
{
private:
    LinkedList* arr;
    int size;
public:
    HashTable(int m){
        arr = new LinkedList[m];

        size = m;
    }
    ~HashTable(){
        delete[] arr;
    }

    int hash(int value){
        return value % size;
    }

    void insert(int value){
        int h = hash(value);

        arr[h].insert_tail(value);
    }

    void print(){
        for (int i = 0; i < size; i++)
        {
            arr[i].print();
            cout<<endl;
        }
    }


    //primary reason hash tables exist:

    Node* search(int key){
        int h = hash(key);
        
        return arr[h].forwardSearch(key);
    }


};


int main(){

    HashTable h1(10);

    h1.insert(99);
    h1.insert(83);
    h1.insert(73);

    cout<<h1.search(73);

    h1.print();
    
}