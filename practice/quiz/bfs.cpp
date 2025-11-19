#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;
    Node* tail;
    
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    
    void insert_tail(int x) {
        Node* newNode = new Node(x);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    int remove_head() {
        int val = head->data;
        head = head->next;
        if (head == nullptr) tail = nullptr;
        return val;
    }
    
    bool empty() {
        return head == nullptr;
    }
    
    void print() {
        Node* curr = head;
        while (curr) {
            cout << "->" << curr->data;
            curr = curr->next;
        }
        cout << endl;
    }
};

class Graph {
public:
    LinkedList* adjList;
    int size;
    int* dist;
    int* pred;
    bool* visited;
    
    Graph(int n) {
        size = n;
        adjList = new LinkedList[n];
        dist = new int[n];
        pred = new int[n];
        visited = new bool[n];
        
        for (int i = 0; i < n; i++) {
            dist[i] = INT_MAX;
            pred[i] = -1;
            visited[i] = false;
        }
    }
    
    void insertEdge(int from, int to) {
        adjList[from].insert_tail(to);
        adjList[to].insert_tail(from);
    }
    
    void bfs(int start) {
        LinkedList queue;
        
        visited[start] = true;
        dist[start] = 0;
        queue.insert_tail(start);
        
        while (!queue.empty()) {
            int curr = queue.remove_head();
            
            Node* neighbor = adjList[curr].head;
            while (neighbor) {
                int next = neighbor->data;
                if (!visited[next]) {
                    visited[next] = true;
                    dist[next] = dist[curr] + 1;
                    pred[next] = curr;
                    queue.insert_tail(next);
                }
                neighbor = neighbor->next;
            }
        }
    }
    
    void shortestPath(int finish) {
        LinkedList path;
        for (int i = finish; i != -1; i = pred[i]) {
            path.insert_tail(i);
        }
        
        // Print reversed
        Node* curr = path.head;
        while (curr) {
            cout << curr->data;
            if (curr->next) cout << "->";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {
    Graph g(6);
    
    g.insertEdge(0, 1);
    g.insertEdge(1, 5);
    g.insertEdge(1, 2);
    g.insertEdge(2, 4);
    g.insertEdge(2, 3);
    g.insertEdge(3, 4);
    
    g.bfs(5);
    g.shortestPath(4);
    
    return 0;
}