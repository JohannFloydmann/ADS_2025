#include <iostream>
#include <stack>
using namespace std;


int main() {
    stack<int> st;
    while(true){
        string command;
        cin >> command;
        if (command == "q")
        {
            break;
        }
        else if (command == "add")
        {
            int x;
            cin >> x;
            st.push(x);
        }
        else if (command == "delete")
        {
            cout << st.pop() << " deleted\n";
        }
        else if (command == "getcur")
        {
            cout << st.top() << endl;
        }
        
    }
    return 0;
}