#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
    int m, n;
    cin >> m >> n;
    multiset<int> arr;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr.emplace(temp);
    }
    for (auto it = arr.begin(); it != arr.end(); it++)
    {
        auto fn = arr.find(m-*it);
        if (arr.find(m-*it) != arr.end())
        {
            cout << min(*it, *fn) << ' ' <<  max(*it, *fn) << endl;
            break;
        }
        
    }
    
    
    return 0;
}