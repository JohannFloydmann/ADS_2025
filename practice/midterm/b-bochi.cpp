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
            multiset<int>::iterator it = elements.begin();
            for (int i = 0; i < elements.size()-k; i++)
            {
                it++;
            }
            cout << *it << "\n";
        }
    }
    
    return 0;
}