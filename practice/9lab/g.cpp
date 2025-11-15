#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> computeLPS(string &pattern) {
    int n = pattern.size();
    vector<int> lps(n, 0);
    int len = 0;
    int i = 1;
    
    while (i < n) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int main() {
    string s;
    cin >> s;
    
    int n = s.size();
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    vector<int> lps = computeLPS(s);
    int p = lps[n - 1];
    int period = n - p;

    cout << period << endl;
    
    return 0;
}