#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> z_function(string &s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;
    int n = s.size();
    
    vector<int> z = z_function(s);
    
    int count = 0;
    int max_x = (n - 1) / 2;
    
    for (int x = 1; x <= max_x; x++) {
        if (z[x] >= x) {
            count++;
        }
    }
    
    cout << count << "\n";
    
    return 0;
}