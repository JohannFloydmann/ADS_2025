#include <iostream>
using namespace std;
long long abs_val(long long n){
    return n >= 0 ? n : n * -1;
}

void merge(long long *arr, int beg, int mid, int end){
    int left_len = mid - beg + 1;
    int right_len = end - mid;
    long long* left = new long long[left_len];
    long long* right = new long long[right_len];
    
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
            left[i] < right[j]))
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

void merge_sort_rec(long long *arr, int beg, int end){
    if (beg < end)
    {
        int mid = (beg + end)/2;
        merge_sort_rec(arr, beg, mid);
        merge_sort_rec(arr, mid+1, end);
        merge(arr, beg, mid, end);
    }
}

void merge_sort(long long *arr, int len){
    merge_sort_rec(arr, 0, len-1);
}

int main(){
    unsigned int n;
    cin >> n;

    long long arr[n];
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr[i] = temp;
    }

    merge_sort(arr, n);
    long long minDiff = arr[n-1] - arr[0];
    for (int i = 1; i < n; i++)
    {
        long long diff = arr[i] - arr[i-1];
        if(diff < minDiff) {
            minDiff = diff;
        }
    }
    
    for (int i = 1; i < n; i++)
    {
        if(arr[i] - arr[i-1] == minDiff) {
            cout << arr[i-1] << ' ' << arr[i] << ' ';
        }
    }
    
    return 0;
}