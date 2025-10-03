#include <iostream>
using namespace std;

class Node {
public:
    Node* left;
    Node* right;
    Node* parent;
    int data;
    
    Node(int data) {
        this->data = data;
        left = right = parent = nullptr;
    }
};

int main() {
    int n;
    cin >> n;
    

    Node* nodes[1001] = {nullptr};
    nodes[1] = new Node(1);  
    
    int levelCount[1001] = {0};
    levelCount[0] = 1; 
    
    int maxWidth = 1;
    
    for (int i = 0; i < n - 1; i++) {
        int parent, child, position;
        cin >> parent >> child >> position;
        
        if (nodes[child] == nullptr) {
            nodes[child] = new Node(child);
        }
        
        if (position == 0) {
            nodes[parent]->left = nodes[child];
        } else {
            nodes[parent]->right = nodes[child];
        }
        nodes[child]->parent = nodes[parent];
        
        int level = 0;
        Node* current = nodes[child];
        while (current != nodes[1]) {  
            level++;
            current = current->parent;
        }
        
        levelCount[level]++;
        if (levelCount[level] > maxWidth) {
            maxWidth = levelCount[level];
        }
    }
    
    cout << maxWidth << endl;
    
    for (int i = 1; i <= 1000; i++) {
        if (nodes[i] != nullptr) {
            delete nodes[i];
        }
    }
    
    return 0;
}