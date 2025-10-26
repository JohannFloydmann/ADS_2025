#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    
    int n, k;
    cin >> n >> k;
    
    multiset<int> elements;
    
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        elements.insert(num);
        
        if (elements.size() < k) {
            cout << "Bocchi\n";
        } else {
            auto it = elements.begin();
            advance(it, elements.size() - k);
            cout << *it << "\n";
        }
    }
    
    return 0;
}