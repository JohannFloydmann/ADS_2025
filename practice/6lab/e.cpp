#include <iostream>
using namespace std;

void merge(int *arr, int beg, int mid, int end){
    int left_len = mid - beg + 1;
    int right_len = end - mid;
    int* left = new int[left_len];
    int* right = new int[right_len];
    
    for (int i = 0; i < left_len; i++)
    {
        left[i] = arr[beg + i];
    }
    for (int i = 0; i < right_len; i++)
    {
        right[i] = arr[mid + 1 + i];
    }
    
    int i = 0;
    int j = 0;
    int k = beg;
    while(k <= end){
        if ((i < left_len) && (j >= right_len || 
            left[i] > right[j]))
        {
            arr[k] = left[i];
            i++;
            k++;
        }
        else{
            arr[k] = right[j];
            k++;
            j++;
        }
    }

    delete[] left;
    delete[] right;
}

void merge_sort_rec(int *arr, int beg, int end){
    if (beg < end)
    {
        int mid = (beg + end)/2;
        merge_sort_rec(arr, beg, mid);
        merge_sort_rec(arr, mid+1, end);
        merge(arr, beg, mid, end);
    }
}

void merge_sort(int *arr, int len){
    merge_sort_rec(arr, 0, len-1);
}


int main(){
    int r, c;
    cin >> r >> c;
    int arr[c][r];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[j][i];
        }
    }

    for (int i = 0; i < c; i++)
    {
        merge_sort(arr[i], r);
    }
    
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << arr[j][i] << ' ';
        }
        cout << endl;
    }

    
    return 0;
}