#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

string toBinary(int num){
    string bin = "";
    while(num > 0){
        bin.push_back('0' + num%2);
        num/=2;
    }
    reverse(bin.begin(), bin.end());
    return bin;
}

int main(){
    int n;
    cin >> n;
    stack<char> st;
    string bin = toBinary(n);
    st.push(bin[0]);
    for (int i = 1; i < bin.length(); i++)
    {
        if (st.top() == '1' && bin[i] == '0')
        {
            st.pop();
        }
        else{
            st.push(bin[i]);
        }
        
    }

    cout << st.empty();
    
    return 0;
}