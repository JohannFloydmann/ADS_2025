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
        bool operator==(const Stack& other){
            if (top != other.top)
            {
                return false;
            }

            int i = top;
            while (i >= 0)
            {
                if(data[i] != other.data[i]){
                    return false;
                }
                i--;
            }
            return true;
            
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

        int getTop(){
            return data[top];
        }

        int empty(){
            return top == -1;
        }

        bool isEmpty(){
            if(top >= 0){
                return false;
            }
            else {
                return true;
            }
        }

        void print(){
            int i = top;
            while (top >= 0)
            {
                cout << data[i];
                i--;
            }
            cout << endl;
        }
        
};

int main() {
    int n;
    cin >> n;
    int out[n];

    Stack s(n);
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        out[i] = -1;
        do
        {
            if(s.isEmpty()){
                s.push(num);
                break;
            }
            else if (s.getTop() <= num){
                out[i] = s.getTop();
                s.push(num);
                break;
            }
            else s.pop();
        }while (true);

    }
    
    for (int i = 0; i < n; i++){
        cout << out[i] << ' ';
    }
    
    return 0;
}