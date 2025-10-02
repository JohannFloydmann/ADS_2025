#include <iostream>
#include <algorithm>  
using namespace std;

int arraySize, numQueries;
long long numbers[100005];

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

int findLowerBound(long long arr[], int size, long long target) {
    int left = 0, right = size;
    while (left < right) {
        int mid = (left + right) / 2;
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int findUpperBound(long long arr[], int size, long long target) {
    int left = 0, right = size;
    while (left < right) {
        int mid = (left + right) / 2;
        if (arr[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int countInRange(long long arr[], int size, long long rangeStart, long long rangeEnd) {
    if (rangeStart > rangeEnd) return 0;
    int leftIndex = findLowerBound(arr, size, rangeStart);
    int rightIndex = findUpperBound(arr, size, rangeEnd);
    return rightIndex - leftIndex;
}

int main() {

    cin >> arraySize >> numQueries;
    for (int i = 0; i < arraySize; i++) {
        cin >> numbers[i];
    }

    mergeSort(numbers, arraySize, 0, arraySize-1);

    while (numQueries--) {
        long long left1, right1, left2, right2;
        cin >> left1 >> right1 >> left2 >> right2;

        int countFirstRange = countInRange(numbers, arraySize, left1, right1);
        int countSecondRange = countInRange(numbers, arraySize, left2, right2);

        int overlapCount = 0;
        if (max(left1, left2) <= min(right1, right2)) {
            overlapCount = countInRange(numbers, arraySize, max(left1, left2), min(right1, right2));
        }

        int totalCount = countFirstRange + countSecondRange - overlapCount;
        cout << totalCount << "\n";
    }

    return 0;
}