#include <iostream>
using namespace std;

int sum(int *arr, int n) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += arr[i];
    }
    return s;
}

bool should_swap(int *row1, int *row2, int m) {
    int sum1 = sum(row1, m);
    int sum2 = sum(row2, m);
    
    if (sum1 > sum2) return true;
    if (sum1 < sum2) return false;
    
    for (int i = 0; i < m; i++) {
        if (row1[i] < row2[i]) return true;
        if (row1[i] > row2[i]) return false;
    }
    return false;
}

void merge(int **arr, int beg, int mid, int end, int m) {
    int left_len = mid - beg + 1;
    int right_len = end - mid;
    int **left = new int *[left_len];
    int **right = new int *[right_len];

    for (int i = 0; i < left_len; i++) {
        left[i] = arr[beg + i];
    }
    for (int i = 0; i < right_len; i++) {
        right[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = beg;
    
    while (i < left_len && j < right_len) {
        if (should_swap(left[i], right[j], m)) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < left_len) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < right_len) {
        arr[k] = right[j];
        j++;
        k++;
    }

    delete[] left;
    delete[] right;
}

void merge_sort_rec(int **arr, int beg, int end, int m) {
    if (beg < end) {
        int mid = (beg + end) / 2;
        merge_sort_rec(arr, beg, mid, m);
        merge_sort_rec(arr, mid + 1, end, m);
        merge(arr, beg, mid, end, m);
    }
}

void merge_sort(int **arr, int len, int m) {
    merge_sort_rec(arr, 0, len - 1, m);
}

int main() {
    int n, m;
    cin >> n >> m;
    
    int **arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[m];
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    
    merge_sort(arr, n, m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
    
    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    
    return 0;
}