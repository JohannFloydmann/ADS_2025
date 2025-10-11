#include <iostream>

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int* L = new int[n1];
    int* R = new int[n2];
    
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    
    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void generateLevelOrder(int sorted[], int result[], int start, int end, int idx) {
    if (start > end) return;
    
    int mid = (start + end) / 2;
    result[idx] = sorted[mid];
    
    generateLevelOrder(sorted, result, start, mid - 1, 2 * idx + 1);
    generateLevelOrder(sorted, result, mid + 1, end, 2 * idx + 2);
}

int main() {
    int N;
    std::cin >> N;
    int size = (1 << N) - 1;
    
    int* arr = new int[size];
    int* result = new int[size];
    
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
        result[i] = 0;
    }
    
    // Sort
    mergeSort(arr, 0, size - 1);
    
    // Generate level order
    generateLevelOrder(arr, result, 0, size - 1, 0);
    
    // Output
    for (int i = 0; i < size; i++) {
        std::cout << result[i];
        if (i < size - 1) std::cout << " ";
    }
    std::cout << std::endl;
    
    delete[] arr;
    delete[] result;
    return 0;
}
