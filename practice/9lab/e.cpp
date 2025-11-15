#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> computeLPS(string &s) {
    int n = s.size();
    vector<int> lps(n, 0);
    int len = 0;
    int i = 1;
    while (i < n) {
        if (s[i] == s[len]) {
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        string g;
        int K;
        cin >> g >> K;
        
        int n = g.size();
        if (K == 1) {
            cout << n << "\n";
            continue;
        }
        
        vector<int> lps = computeLPS(g);
        int p = lps[n - 1];
        int ans = n + (K - 1) * (n - p);
        cout << ans << "\n";
    }
    
    return 0;
}