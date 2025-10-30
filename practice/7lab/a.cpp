#include <iostream>
using namespace std;

void merge(string *arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    string leftArr[n1], rightArr[n2];
    
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        if (leftArr[i].length() <= rightArr[j].length()) {
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

void mergeSortRecursive(string *arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSortRecursive(arr, left, mid);
        mergeSortRecursive(arr, mid + 1, right);
        
        merge(arr, left, mid, right);
    }
}

void mergeSort(string *arr, int size) {
    mergeSortRecursive(arr, 0, size - 1);
}

int main(){
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string arr[50];
        int j = 0;
        string temp;
        while (cin >> temp)
        {
            arr[j] = temp;
            j++;

            if (cin.peek() == '\n') {
                break;
            }
        }
        mergeSort(arr, j);
        for (int k = 0; k < j; k++)
        {
            cout << arr[k] << ' ';
        }
        cout << endl;
    }
        
    return 0; 
}