#include <iostream>

int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left -1;

    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
            
        }
    }

    std::swap(arr[i + 1], arr[right]);
    return i + 1;
}


int quickselect(int arr[], int left, int right, int k) {
    if (left <= right) {

        int pivotIndex = partition(arr, left, right);

        if (k == pivotIndex) {
            return arr[pivotIndex];
        } else if (k < pivotIndex) {
            return quickselect(arr, left, pivotIndex - 1, k);
        } else {
            return quickselect(arr, pivotIndex + 1, right, k);
        }

    }
    return -1;
}


// int main() {
//     printf("Enter the number of elements in the array: ");
//     int n;
//     scanf("%d", &n);
//     int arr[n];
//     printf("Enter the elements of the array: ");
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &arr[i]);
//     }

//     printf("Enter the value of k: ");
//     int k;
//     scanf("%d", &k);

//     // quickselect(arr, 0, n - 1, k);

//     printf("The kth smallest element in the array is: %d\n", quickselect(arr, 0, n - 1, k-1));

// }
