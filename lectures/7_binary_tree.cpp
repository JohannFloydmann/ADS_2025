#include <iostream>
using namespace std;



class Node{
    private:
        Node* parent;
        Node* left;
        Node* right;
        int data;
    public:
        Node(int data){
            parent = nullptr;
            left = nullptr;
            right = nullptr;
            this->data = data;
        }
        int getData(){
            return data;
        }

        void setLeft(Node* newLeft){
            left = newLeft;
        }
        void setRight(Node* newRight){
            right = newRight;
        }
        void setParent(Node* newParent){
            parent = newParent;
        }

        Node* getLeft(){
            return left;
        }
        Node* getRight(){
            return right;
        }
        Node* getParent(){
            return parent;
        }

};


class BST{
    private:
        Node* root;

        //helper:
        void transplant(Node* u, Node* v){
            Node* par = u->getParent(); 
            if(par == NULL){
                v = root;
            } else if(u == par->getLeft()){
                par->setLeft(v);
            } else{
                par->setRight(v);
            }
            if(v){
                v->setParent(par);
            }
        }

        Node* minimum(Node* pseudoroot){
            Node* curr = pseudoroot;
            Node* old_curr = NULL;
            while(curr!=NULL){
                old_curr = curr;
                curr = curr->getLeft();
            }

            return old_curr;
        }
    public:

        BST(){
            root = nullptr;
        }

        void insert(int newData){
            Node* newNode = new Node(newData);

            Node* x = root;
            Node* y = nullptr;

            while(x){
                if(x->getData()>newData){
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
                cout<<n->getData()<<" ";
                if(n->getParent())
                    cout<<n->getParent()->getData();
                cout<<endl;
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

        ~BST(){
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

        



        void deleteNode(Node* z){
            if(z->getLeft() == NULL){
                this->transplant(z,z->getRight());
            }
            else if(z->getRight() == NULL){
                this->transplant(z,z->getLeft());
            }
            else{
                Node* y = minimum(z->getRight());
                if(z->getRight()->getLeft() != NULL){
                    y->setRight(z->getRight());
                    z->getRight()->setParent(y);
                    y->getRight()->setParent(z->getRight());
                    this->transplant(y,y->getRight());
                }
                this->transplant(z,y);
                y->setLeft(z->getLeft());

            }
            delete z;
        }
};

int main(){
    
    BST b1;

    b1.insert(4);
    b1.insert(3);
    b1.insert(7);
    b1.insert(2);
    b1.insert(5);
    b1.insert(8);

    b1.print();

    cout<<endl;
    




}