#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<long long> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    
    long long min_d = *min_element(d.begin(), d.end());
    
    long long sum_d = 0;
    for (auto x : d) sum_d += x;
    
    sum_d -= min_d;
    
    long long total = (n - 1) * min_d + sum_d;
    
    cout << total << endl;
    return 0;
}