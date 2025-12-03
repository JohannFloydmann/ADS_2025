#include <iostream>
#include <cmath>

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

    void remove_head(){
        if(!head->getNext()){
            head = NULL;
            tail = NULL;
        }
        else{
            head = head->getNext();
            head->setPrev(nullptr);
        }
    }

    void print(){
        Node* curr = head;

        while(curr){
            cout<<"->"<<curr->getData();
            curr = curr->getNext();
        }
        cout<<endl;
    }

    void reverse_print(){
        Node* curr = tail;

        while(curr){
            cout<<curr->getData()<<"->";
            curr = curr->getPrev();
        }
        cout<<endl;
    }

    Node* getHead(){
        return head;
    }

    Node* getTail(){
        return tail;
    }

    bool empty(){
        if(tail==NULL && head == NULL)
            return true;
        return false;
    }
};


class Graph{
    private:
        LinkedList* adjList;
        int size;//number of vertices
        int* pred;
        int* dist;
        bool* visited;
    public:
        Graph(int size){
            //declaration of attributes
            adjList = new LinkedList[size];
            pred = new int[size];
            dist = new int[size];
            visited = new bool[size];

            //initialization of attributes
            for (int i = 0; i < size; i++)
            {
                pred[i] = -1;
                dist[i] = INT_MAX;
                visited[i] = false;
            }
            this->size = size;
        }

        ~Graph(){
            delete[] adjList;
            delete[] pred;
            delete[] dist;
            delete[] visited;
        }

        void insertEdge(int from, int to){
            adjList[from].insert_tail(to);
            adjList[to].insert_tail(from);//because undirected graph
        }

        void print(){
            for (int i = 0; i < size; i++)
            {
                cout<<i<<":";
                adjList[i].print();
            } 
        }
        //breadth first search
        void bfs(int start){
            int neighbor;

            dist[start] = 0;
            visited[start] = true;

            LinkedList pseudoq;

            pseudoq.insert_tail(start);

            while(!pseudoq.empty()){
                //popping first element of the queue
                int to_pop = pseudoq.getHead()->getData();
                pseudoq.remove_head();

                //reasearch the popped virtices' neighbors

                Node* curr = adjList[to_pop].getHead();
                
                while(curr){
                    //this is inserted neighbor:
                    neighbor = curr->getData(); 
                    if(!visited[neighbor]){
                        //if not visited -- push the neighbor inside the queue
                        pseudoq.insert_tail(neighbor);

                        //change distance, predecessor and visited of the inserted neighbor
                        dist[neighbor] = dist[to_pop] + 1;
                        pred[neighbor] = to_pop;
                        visited[neighbor] = true;
                    }
                    curr = curr->getNext();
                }
            }
        }
        
        //check the predecessor and distance arrays:
        void printPreds(){
            //goes through every vertix and prints its attributes:
            for (int i = 0; i < size; i++)
            {
                cout<<i<<":("<<pred[i]<<";"<<dist[i]<<")"<<endl;
            }
            
        }

        void shortedPath(int finish){
            LinkedList reversed_path;
            for (int i = finish; i != -1; i = pred[i])
            {
                reversed_path.insert_tail(i);
            }
            reversed_path.reverse_print();
        }
};



int main(){
    Graph abc(6);

    abc.insertEdge(0,1);
    abc.insertEdge(1,5);
    abc.insertEdge(1,2);
    abc.insertEdge(2,4);
    abc.insertEdge(2,3);
    abc.insertEdge(3,4);

    abc.bfs(5);

    abc.shortedPath(4);
}