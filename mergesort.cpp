#include <iostream>
#include <vector>
#include "algorithms.h"


// merge pseudocode : merge two halves of an array
// get an array of n elements
// get left, mid and right
// create two temporary arrays to hold the left and right halves of the original array
// copy the elements of the left half into the first temporary array
// copy the elements of the right half into the second temporary array
// 

#include <iostream>
#include "algorithms.h"

void merge(int arr[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArr[n1];
    int rightArr[n2];

    for (int i = 0; i < n1; i++){
        leftArr[i] = arr[left + i];
    }

    for (int j =0; j <n2; j++){
        rightArr[j] = arr[mid+1+j];
    }

    int i = 0, j = 0, k = left;

    while (i<n1 && j<n2){
        if (leftArr[i] <= rightArr[j]){
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1){
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j<n2){
        arr[k] = rightArr[j];
        j++;
        k++;    
    }
}

void mergesort(int arr[], int left, int right){
    if (left < right){
        int mid = (right + left) / 2;

        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}



// int main(){
//     printf("Enter the number of elements in the array: ");
//     int n;
//     std::cin >> n;
//     int arr[n];
//     printf("Enter the elements of the array: ");
//     for (int i = 0; i < n; i++){
//         std::cin >> arr[i];
//     }

//     printf("Enter the value of k: ");
//     int k;
//     std::cin >> k;


//     mergesort(arr, 0, n - 1);
    
//     printf("The kth smallest element in the array is: %d\n", arr[k - 1]);
//     return 0;
// }
