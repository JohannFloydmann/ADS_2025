#include <iostream>
using namespace std;

int partition(int *arr, int beg, int end){
    int pivot = arr[end];
    int i = beg;
    for (int j = beg; j < end; j++)
    {
        if (arr[j] <= pivot)
        {
            swap(arr[j], arr[i]);
            i++;
        }
    }
    swap(arr[i], arr[end]);
    return i;
}

int rand_partition(int *arr, int beg, int end){
    srand(time(NULL));
    int pivot_index = beg + (rand()%(end-beg+1));
    if (pivot_index != end)
    {
        swap(arr[pivot_index], arr[end]);
    }

    int i = beg;
    for (int j = beg; j < end; j++)
    {
        if (arr[j] <= arr[end])
        {
            swap(arr[i], arr[j]);
            i++;
        }
        
    }
    swap(arr[i], arr[end]);
    return i;
}

void quickSort(int *arr, int low, int high){
    if(low<high){
        int pivot_index = rand_partition(arr, low, high);
        quickSort(arr, low, pivot_index-1);
        quickSort(arr, pivot_index+1, high);
    }
}

int main(){
    int arr[] = {5, 6, 3, 1, 2, 8, 9};

    quickSort(arr, 0, 7-1);

    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << ' ';
    }
    

    return 0;
}