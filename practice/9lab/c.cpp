#include <iostream>
#include <string>
using namespace std;

int main() {
    string T, A;
    cin >> T >> A;
    
    int n = T.size();
    
    for (int k = 1; k <= n; k++) {
        if (A == T.substr(n - k) + T.substr(0, n - k)) {
            cout << k << endl;
            return 0;
        }
    }
    
    cout << -1 << endl;
    return 0;
}