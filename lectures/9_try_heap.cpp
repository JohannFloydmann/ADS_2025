#include <iostream>
using namespace std;

class Heap
{
private:
    int *arr;
    int heapSize;
    int arrSize;

    // helper:
    int left(int i)
    {
        return 2 * i + 1;
    }
    int right(int i)
    {
        return 2 * i + 2;
    }
    int parent(int i)
    {
        return (i - 1) / 2;
    }

public:
    Heap(int heapSize = 0, int arrSize = 2147483647)
    {
        this->heapSize = heapSize;
        this->arrSize = arrSize;
        this->arr = new int[arrSize];
    }
    ~Heap()
    {
        delete[] arr;
    }

    void unHeapify(int i)
    {
        if (i > 0 && arr[parent(i)] < arr[i])
        {
            swap(arr[parent(i)], arr[i]);
            unHeapify(parent(i));
        }
    }

    void heapify(int i)
    {
        int largestIndex = i;
        if (arr[left(i)] > arr[largestIndex] && left(i) < heapSize)
            largestIndex = left(i);
        if (arr[right(i)] > arr[largestIndex] && right(i) < heapSize)
            largestIndex = right(i);
        swap(arr[i], arr[largestIndex]);
        if (largestIndex != i)
        {
            heapify(largestIndex);
        }
    }

    void buildHeap(int *arr, int n){
        for (int i = 0; i < n; i++)
        {
            insert(arr[i]);
        }
        
    }

    void insert(int value)
    {
        heapSize++;
        arr[heapSize - 1] = value;
        unHeapify(heapSize - 1);
    }

    void changeValue(int value, int i)
    {
        if (value > arr[i])
            arr[i] = value;
        unHeapify(i);
        if (value < arr[i])
            arr[i] = value;
        heapify(i);
    }

    void deleteRoot()
    {
        if (heapSize == 0)
            return;
        arr[0] = arr[heapSize - 1];
        heapSize--;
        if (heapSize > 0)
        {
            heapify(0);
        }
    }

    void printSorted(){
        while(heapSize > 0){
            cout << arr[0] << ' ';
            swap(arr[0], arr[heapSize-1]);
            heapSize--;
            heapify(0);
        }
    }

    void printHeap()
    {
        for (int i = 0; i < heapSize; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Heap h(0);
    h.insert(1);
    h.printHeap();
    h.insert(2);
    h.printHeap();
    h.insert(0);
    h.printHeap();
    h.insert(4);
    h.printHeap();

    h.printSorted();

    return 0;
}