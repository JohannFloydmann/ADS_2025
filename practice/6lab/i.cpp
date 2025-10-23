#include <iostream>
using namespace std;

void merge(string &arr, int beg, int mid, int end){
    int left_len = mid - beg + 1;
    int right_len = end - mid;
    string left = arr.substr(beg, left_len);
    string right = arr.substr(mid+1, right_len);
    
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
}

void merge_sort_rec(string &arr, int beg, int end){
    if (beg < end)
    {
        int mid = (beg + end)/2;
        merge_sort_rec(arr, beg, mid);
        merge_sort_rec(arr, mid+1, end);
        merge(arr, beg, mid, end);
    }
}

void merge_sort(string &arr){
    merge_sort_rec(arr, 0, arr.length()-1);
}

int main(){
    string str;
    cin >> str;

    merge_sort(str);
    
    cout << str;
    return 0;
}