#include <iostream>
using namespace std;
void merge(long long *arr, int size, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    long long leftArr[size];
    long long rightArr[size];
    
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(long long *arr, int size, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, size, left, mid);
        mergeSort(arr, size, mid + 1, right);
        merge(arr, size, left, mid, right);
    }
}

int main() {
    int sheeps, minLen;
    cin >> sheeps >> minLen;
    long long sheepsArr[sheeps];
    for (int i = 0; i < sheeps; i++)
    {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        sheepsArr[i] = max(x2, y2);
    }
    mergeSort(sheepsArr, sheeps, 0, sheeps-1);
    cout << sheepsArr[minLen-1] << endl;
    
    
    return 0;
}