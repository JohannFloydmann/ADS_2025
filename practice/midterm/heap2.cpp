#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> heap(n);
    for (int i = 0; i < n; i++)
    {
        cin >> heap[i];
    }
    make_heap(heap.begin(), heap.end());
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int ind, plus;
        cin >> ind >> plus;
        ind--;
        int curr = ind;
        heap[ind]+=plus;
        while(curr > 0){
            int parent = (curr - 1)/2;
            if (heap[parent] < heap[curr])
            {
                swap(heap[parent], heap[curr]);
                curr = parent;
            }
            else break;
        }
        cout << curr+1 << endl;
    }

    for(int element : heap){
        cout << element << ' ';
    }
    
    return 0;
}