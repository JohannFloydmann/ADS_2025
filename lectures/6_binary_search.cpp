#include <iostream>
using namespace std;

int binary_search(int* arr, int beg, int end, int key){
    int mid = (beg+end)/2;

    if(key == arr[mid]){
        return mid;
    }


    if (beg < end){
        if(key < arr[mid]){
            return binary_search(arr, beg, mid-1, key);
        }
        else{
            return binary_search(arr, mid+1, end, key);
        }
    }
    return INT_MIN;
}

int binary_search(int* arr, int key){
    int beg = 0;
    int end = sizeof(arr)-1;

    int mid = (beg+end)/2;

    if(key == arr[mid]){
        return mid;
    }


    if (beg < end){
        if(key < arr[mid]){
            return binary_search(arr, beg, mid-1, key);
        }
        else{
            return binary_search(arr, mid+1, end, key);
        }
    }
    return INT_MIN;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << binary_search(arr,  4);

    return 0;
}
