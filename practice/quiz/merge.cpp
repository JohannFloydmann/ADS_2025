#include <iostream>
using namespace std;

void merge(int *arr, int beg, int mid, int end){
    int left_len = mid-beg+1;
    int *left = new int[left_len];
    int right_len = end-mid;
    int *right = new int[right_len];

    for (int i = 0; i < left_len; i++)
    {
        left[i] = arr[beg + i];
    }
    for (int i = 0; i < right_len; i++)
    {
        right[i] = arr[mid + i + 1];
    }
    
    int i, j, k;
    i = j = 0;
    k = beg;
    while (k <= end)
    {
        if((i < left_len && left[i] > right[j]) || j >= right_len){
            arr[k] = left[i];
            i++;
            k++;
        }
        else{
            arr[k] = right[j];
            j++;
            k++;
        }
    }
    delete[] right;
    delete[] left;
}

void mergeSort(int *arr, int beg, int end){
    if (beg < end)
    {
        int mid = (beg + end)/2;
        mergeSort(arr, beg, mid);
        mergeSort(arr, mid+1, end);
        merge(arr, beg, mid, end);
    }
    
}

int main(){
    int n = 10;
    int arr[n] = {5, 6, 9, 2, 3, 5, 46, 1, 2, 0};
    mergeSort(arr, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    
    return 0;
}