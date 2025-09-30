#include <iostream>
using namespace std;

class Heap
{
private:
    int *arr;
    int heap_size;
    int arr_size;

    // helper:
    int left(int i)
    {
        return i * 2 + 1;
    }
    int right(int i)
    {
        return i * 2 + 2;
    }
    int parent(int i)
    {
        return (i - 1) / 2;
    }

public:
    // empty array
    Heap(int heap_size, int arr_size)
    {
        arr = new int[arr_size];
        this->arr_size = arr_size;
        this->heap_size = heap_size;
    }

    // if we have an array
    Heap(int *user_arr, int heap_size, int arr_size)
    {
        arr = user_arr;
        this->arr_size = arr_size;
        this->heap_size = heap_size;
    }

    ~Heap()
    {
        delete[] arr;
    }

    void print()
    {
        for (int i = 0; i < heap_size; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }

    void heapify(int i)
    {
        if (i < heap_size - 1 && right(i) < heap_size)
        {

            int largest_index = i; // between i and its children
            if (arr[left(i)] > arr[largest_index])
            {
                largest_index = left(i);
            }
            if (arr[right(i)] > arr[largest_index])
            {
                largest_index = right(i);
            }
            if (largest_index != i)
            {
                swap(arr[largest_index], arr[i]);
            }

            heapify(largest_index);
        }
    }

    void buildHeap()
    {
        for (int i = (heap_size - 2) / 2; i >= 0; i--)
        {
            heapify(i);
        }
    }

    void heapSort()
    {
        buildHeap();
        int max_value = arr[0];
        while (heap_size > 0)
        {
            swap(arr[0], arr[heap_size - 1]);
            heap_size--;
            heapify(0);
        }
    }

    void unheapify(int i)
    {
        if (i > 0)
        {
            if (arr[parent(i)] < arr[i])
            {
                swap(arr[parent(i)], arr[i]);
            }
            unheapify(parent(i));
        }
    }

    void insert(int n){
        heap_size++;
        arr[heap_size-1] = n;
        unheapify(heap_size-1);
    }

    void del(int i){
        arr[i] = INT_MIN;
        heapify(i);
        heap_size--;
    }
};

int main()
{
    int arr[7] = {1, 2, 4, 3, 5, 8, 9};

    Heap h1(arr, 7, 7);
    
    h1.buildHeap();
    h1.insert(10);
    h1.heapSort();
    h1.print();

    return 0;
}