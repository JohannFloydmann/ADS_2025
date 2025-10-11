#include <iostream>
using namespace std;

class Heap
{
private:
    long long* arr;
    long long heapSize;
    long long arrSize;

    // helper:
    long long left(long long i)
    {
        return 2 * i + 1;
    }
    long long right(long long i)
    {
        return 2 * i + 2;
    }
    long long parent(long long i)
    {
        return (i - 1) / 2;
    }

public:
    Heap(long long heapSize)
    {
        this->heapSize = heapSize;
        this->arrSize = 1000000;
        this->arr = new long long[arrSize];
    }
    ~Heap()
    {
        delete[] arr;
    }

    void unHeapify(long long i)
    {
        if (i > 0 && arr[parent(i)] > arr[i])
        {
            swap(arr[parent(i)], arr[i]);
            unHeapify(parent(i));
        }
    }

    void heapify(long long i)
    {
        long long largestIndex = i;
        if (arr[left(i)] < arr[largestIndex] && left(i) < heapSize)
            largestIndex = left(i);
        if (arr[right(i)] < arr[largestIndex] && right(i) < heapSize)
            largestIndex = right(i);
        swap(arr[i], arr[largestIndex]);
        if (largestIndex != i)
        {
            heapify(largestIndex);
        }
    }

    void buildHeap(long long *arr, long long n){
        for (long long i = 0; i < n; i++)
        {
            insert(arr[i]);
        }
        
    }

    void insert(long long value)
    {
        heapSize++;
        arr[heapSize - 1] = value;
        unHeapify(heapSize - 1);
    }

    void changeValue(long long value, long long i)
    {
        if (value > arr[i])
            arr[i] = value;
            heapify(i);
        if (value < arr[i])
            arr[i] = value;
            unHeapify(i);
    }

    long long deleteRoot()
    {
        if (heapSize == 0)
            return 0;
        long long ans = arr[0];
        arr[0] = arr[heapSize - 1];
        heapSize--;
        if (heapSize > 0)
        {
            heapify(0);
        }
        return ans;
    }

    void printSorted(){
        while(heapSize > 0){
            cout << arr[0] << ' ';
            swap(arr[0], arr[heapSize-1]);
            heapSize--;
            heapify(0);
        }
    }
    long long getSize(){
        return heapSize;
    }

    long long getHead(){
        return arr[0];
    }

    void printHeap()
    {
        for (long long i = 0; i < heapSize; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Heap h(0);
    long long n, m;
    cin >> n >> m;
    long long arr[n];
    for (long long i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    h.buildHeap(arr, n);
    long long ans = 0;
    while(h.getHead() < m)
    {
        long long last = h.deleteRoot();
        if (h.getSize() <= 0)
        {
            ans = -1;
            break;
        }
        long long prelast =  h.deleteRoot();
        h.insert(last + 2*prelast);
        ans++;
    }
    
    cout << ans;

    return 0;
}