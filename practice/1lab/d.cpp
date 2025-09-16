    #include <iostream>
    using namespace std;

    class Stack{
        private:
            char* data;
            int top;
        public:
            bool empty;
            Stack(int size){
                data = new char [size];
                top = -1;
                empty = true;
            }

            ~Stack(){
                delete [] data;
            }

            void push(int value){
                empty = false;
                top++;
                data[top] = value;
            }

            char pop(){
                top--;
                if(top == -1){
                    empty = true;
                }
                return data[top+1];
            }

            char getTop(){
                return data[top];
            }
    };

    int main(){
        string s;
        cin >> s;

        Stack stack(s.length());

        for (int i = 0; i < s.length(); i++)
        {
            if (!stack.empty && s[i] == stack.getTop())
            {
                stack.pop();
            }
            else{
                stack.push(s[i]);
            }
            
        }
        
        cout << (stack.empty ? "YES" : "NO") << endl;

        return 0;
    }
