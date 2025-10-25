#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> heap(n);
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        heap.push_back(temp);
        push_heap(heap.begin(), heap.end());
    }
    
    
    
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int left = 2*i+1;
        int right = 2*i+2;
        if (left < n && right < n && heap[right] > heap[left])
        {
            count++;
        }
        
    }
    cout << count;

    return 0;
}