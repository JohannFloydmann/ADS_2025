#include <iostream>
#include <vector>
using namespace std;

vector<int> makeLps(string &pattern) {
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
    string a, b;
    cin >> a >> b;
    
    vector<int> lps_b = makeLps(b);
    
    int i = 0, j = 0;
    int reps = 1;
    int max_reps = (b.length() / a.length()) + 3;
    
    while (reps <= max_reps) {
        for (int k = 0; k < a.length(); k++) {
            while (j > 0 && a[k] != b[j]) {
                j = lps_b[j - 1];
            }
            if (a[k] == b[j]) {
                j++;
                if (j == b.length()) {
                    cout << reps;
                    return 0;
                }
            }
        }
        reps++;
    }
    
    cout << -1;
    return 0;
}