#include <iostream>
using namespace std;

void insSort(int* arr, int size){
    int i;
    int key;
    for(int j = 1; j < size; j++){
        i = j - 1;
        key = arr[j];

        while(i>=0 && arr[i] > key){
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = key;
    }
}

int main() {
    int const n = 100;
    int arr[n] = {100, 99, 98, 97, 96, 95, 94, 93, 92, 91,
                   90, 89, 88, 87, 86, 85, 84, 83, 82, 81,
                   80, 79, 78, 77, 76, 75, 74, 73, 72, 71,
                   70, 69, 68, 67, 66, 65, 64, 63, 62, 61,
                   60, 59, 58, 57, 56, 55, 54, 53, 52, 51,
                   50, 49, 48, 47, 46, 45, 44, 43, 42, 41,
                   40, 39, 38, 37, 36, 35, 34, 33, 32, 31,
                   30, 29, 28, 27, 26, 25, 24, 23, 22, 21,
                   20, 19, 18, 17, 16, 15, 14, 13, 12 ,11,
                   10 ,9 ,8 ,7 ,6 ,5 ,4 ,3 ,2 ,1};

    insSort(arr, n);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}