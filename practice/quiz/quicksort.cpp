#include <iostream>
using namespace std;
int partition(int *arr, int beg, int end){
    int pivot = arr[end];
    int i = beg;
    for (int j = beg; j < end; j++)
    {
        if(arr[j] >= pivot){
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[end]);
    return i;
}

void quickSort(int *arr, int beg, int end){
    if(beg < end){
        int part = partition(arr, beg, end);
        quickSort(arr, beg, part-1);
        quickSort(arr, part+1, end);
    }
}

int main(){
    int n = 10;
    int arr[n] = {5, 6, 9, 2, 3, 5, 46, 1, 2, 0};
    quickSort(arr, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }

    return 0;
}