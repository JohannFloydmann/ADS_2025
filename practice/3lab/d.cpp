#include <iostream>
#include <algorithm>  
using namespace std;

int arraySize, numQueries;
long long numbers[100005];

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

    sort(numbers, numbers + arraySize);

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