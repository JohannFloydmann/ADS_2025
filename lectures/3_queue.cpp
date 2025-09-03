#include <iostream>
using namespace std;

class Stack{
    private:
        int* data;
        int top;
    public:
        Stack(int size){
            data = new int [size];
            top = -1;
        }

        ~Stack(){
            delete [] data;
        }

        void push(int value){
            top++;
            data[top] = value;
        }

        int pop(){
            top--;
            return data[top+1];
        }

        int empty(){
            return top == -1;
        }
};

int main() {
    Stack s(10);
    s.push(5);  
    s.push(10);
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    return 0;
}