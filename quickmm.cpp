#include <iostream>
#include <vector>

int sort(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[right]);
    return i + 1;
}


int partition(int arr[], int left, int right, int k) {
   
}

int quickmm(int arr[], int left, int right, int k) {

}


int main() {
    printf("Enter the number of elements: ");
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    printf("Enter the value of kth smallest: ");
    int k;
    std::cin >> k;


    int left = 0, right = n - 1;
    int res = quickmm(arr.data(), left, right, k);
    printf("The %dth smallest element is: %d\n", k, res);
    return 0;
    
}