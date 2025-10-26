#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    string s;
    cin >> s;
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if(!st.empty() && st.top() == s[i]) st.pop();
        else st.push(s[i]);
    }
    vector<char> output;
    while(st.empty() == false){
        output.push_back(st.top());
        st.pop();
    }
    reverse(output.begin(), output.end());
    for(auto it = output.begin(); it != output.end(); ++it){
        cout << *it;
    }
    return 0;
}