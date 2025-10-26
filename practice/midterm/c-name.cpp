#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;

    vector<int> a;
    for(int i = 0; i<n ; i++) { 
        int b;
        cin >> b;
        a.push_back(b);
    }
    


    auto it = lower_bound(a.begin(), a.end(), q);
    if( it != a.end() && *it == q) { 
        cout << it - a.begin() + 1 << endl;
    } else { 
        cout << -1 << endl;
    }
}