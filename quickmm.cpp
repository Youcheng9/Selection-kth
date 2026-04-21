#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include "algorithms.h"


int median(int arr[], int left, int right) {
    std::sort(arr + left, arr + right + 1);
    return arr[left + (right - left) / 2];
}

int partition(int arr[], int left, int right, int pivotValue) {
    int pivotIndex = left;
    for (int i = left; i <= right; ++i) {
        if (arr[i] == pivotValue) {
            pivotIndex = i;
            break;
        }
    }

    std::swap(arr[pivotIndex], arr[right]);

    int storeIndex = left;
    for (int i = left; i < right; ++i) {
        if (arr[i] < pivotValue) {
            std::swap(arr[storeIndex], arr[i]);
            ++storeIndex;
        }
    }

    std::swap(arr[storeIndex], arr[right]);
    return storeIndex;
}

int selectPivot(int arr[], int left, int right) {
    int n = right - left + 1;

    if (n <= 5) {
        return median(arr, left, right);
    }

    int group = (n + 4) / 5;
    std::vector<int> medians(group);

    for (int i = 0; i < group; ++i) {
        int groupLeft = left + i * 5;
        int groupRight = std::min(groupLeft + 4, right);
        medians[i] = median(arr, groupLeft, groupRight);
    }

    return selectPivot(medians.data(), 0, group - 1);
}

int quickmm(int arr[], int left, int right, int k) {
    if (left == right) {
        return arr[left];
    }

    int pivotValue = selectPivot(arr, left, right);
    int pivotIndex = partition(arr, left, right, pivotValue);

    if (pivotIndex == k) {
        return arr[pivotIndex];
    }

    if (k < pivotIndex) {
        return quickmm(arr, left, pivotIndex - 1, k);
    }

    return quickmm(arr, pivotIndex + 1, right, k);
}

// int main() {
//     std::printf("Enter the number of elements: ");
//     int n;
//     std::cin >> n;

//     std::vector<int> arr(n);
//     std::printf("Enter the elements: ");
//     for (int i = 0; i < n; ++i) {
//         std::cin >> arr[i];
//     }

//     std::printf("Enter the value of kth smallest: ");
//     int k;
//     std::cin >> k;

//     if (k < 1 || k > n) {
//         std::printf("Invalid k\n");
//         return 1;
//     }

//     int result = quickmm(arr.data(), 0, n - 1, k - 1);
//     std::printf("The %dth smallest element is: %d\n", k, result);
//     return 0;
// }
