#include <iostream>
using namespace std;

template <typename T>
class Stack {
private:
    T* data;
    int top;
    int capacity;

public:
    Stack(int size) {
        data = new T[size];
        capacity = size;
        top = -1;
    }

    ~Stack() {
        delete[] data;
    }

    void push(T value) {
        if (top >= capacity - 1) {
            cout << "Stack is full" << endl;
            return;
        }
        top++;
        data[top] = value;
    }

    T getTop(){
        return data[top];
    }

    T pop() {
        if (empty()) {
            cout << "Stack is empty" << endl;
            return T();
        }
        top--;
        return data[top + 1];
    }

    void print() {
        if (empty()) {
            return;
        }
        for (int i = top; i >= 0; i--) {
            cout << data[i] << endl;
        }
    }

    bool empty() {
        return top == -1;
    }
};

int main() {
    int num;
    cin >> num;
    int count = 0;
    Stack<string> s(1000);

    for (int i = 0; i < num; i++)
    {
        string name;
        cin >> name;
        while(name == s.getTop()){
            s.pop();
            count--;
        }
        s.push(name);
        count++;
    }

    cout << "All in all: " << count << endl;
    cout << "Students:" << endl;
    s.print();
    
    return 0;
}