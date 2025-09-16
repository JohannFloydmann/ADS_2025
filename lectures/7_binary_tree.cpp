#include <iostream>
using namespace std;

class Node{
    private:
        int data;
        Node* left;
        Node* right;
        Node* parent;
    public:
        Node(int n){
            data = n;
        }

        int getData(){
            return data;
        }

        Node* getRight(){
            return right;
        }

        Node* getLeft(){
            return left;
        }

        Node* getParent(){
            return parent;
        }

        void setRight(Node* node){
            right = node;
        }

        void setLeft(Node* node){
            left = node;
        }

        void setParent(Node* node){
            parent = node;
        }
};

class BinaryTree{
    private:
        Node* root;
    public:
        BinaryTree(){
            root = nullptr;
        }
        void insert(int newData){
            Node* newNode = new Node(newData);

            Node* x = root;
            Node* y = nullptr;

            while(x){
                if(x->getData()<newData){
                    y = x;
                    x = x->getLeft();
                }
                else{
                    y = x;
                    x = x->getRight();
                }
            }
            
            if(y == nullptr){
                root = newNode;
            }
            else{
                if(newData<y->getData()){
                    y->setLeft(newNode);
                }
                else{
                    y->setRight(newNode);
                }
                newNode->setParent(y);
            }
        }

        void inOrderTreeWalk(Node* n){
            if(n){
                inOrderTreeWalk(n->getLeft());
                cout<<n->getData()<<" "<<n<<" ";
                inOrderTreeWalk(n->getRight());
            }
        }

        void print(){
            inOrderTreeWalk(root);
        }

        void clear(Node* n){
            if(n){
                clear(n->getLeft());
                clear(n->getRight());
                delete n;
            }
        }

        ~BinaryTree(){
            clear(root);
        }


        Node* search(int key){
            return check(key,root);
        }

        Node* check(int key, Node* curr){
            if(curr){
                if(curr->getData() == key){
                    return curr;
                }
                if(curr->getData()<key){
                    return check(key,curr->getRight());
                    cout<<"got here"<<endl;
                }
                else{
                    return check(key,curr->getLeft());
                }
            }
            return NULL;
        }
};


int main(){
    
    
    return 0;
}
