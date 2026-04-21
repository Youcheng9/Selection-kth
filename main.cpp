
#include <chrono>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include <sstream>
#include <random>
#include <cmath>


#include "algorithms.h"

double avgTime(double times[]) {
    double sum = 0;
    for (int i = 0; i < 10; ++i) {
        sum += times[i];
    }

    sum = sum - *std::min_element(times, times + 10) - *std::max_element(times, times + 10);
    return sum / 8.0;
}

int main() {
    int n;
    std::cout << "Enter power of 2 for array size: ";
    std::cin >> n;

    n = std::pow(2, n); // Convert to actual array size

    std::vector<int> input(n);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 100);

    for (int i = 0; i < n; ++i) {
        input[i] = dist(gen);
    }

    // std::cout << "Generated array: ";
    // for (int i = 0; i < n; ++i) {
    //     std::cout << input[i] << " ";
    // }
    // std::cout << "\n";

    int k;
    std::cout << "Enter the value of k: ";
    std::cin >> k;

    if (k < 1 || k > n) {
        std::cout << "Invalid k. It must be between 1 and " << n << ".\n";
        return 1;
    }


    std::vector<int> arr1 = input;
    std::vector<int> arr2 = input;
    std::vector<int> arr3 = input;

    int res1, res2, res3;

    double time1[10];
    double time2[10];
    double time3[10];

    for (int i = 0; i < 10; ++i) {
        std::vector<int> arr1 = input;
        auto start1 = std::chrono::high_resolution_clock::now();
        mergesort(arr1.data(), 0, n - 1);
        res1 = arr1[k - 1];
        auto end1 = std::chrono::high_resolution_clock::now();

        time1[i] = std::chrono::duration<double, std::micro>(end1 - start1).count();


        // for quickselect
        std::vector<int> arr2 = input;
        auto start2 = std::chrono::high_resolution_clock::now();
        res2 = quickselect(arr2.data(), 0, n - 1, k - 1);
        auto end2 = std::chrono::high_resolution_clock::now();
        time2[i] = std::chrono::duration<double, std::micro>(end2 - start2).count();

        // for quickmm
        std::vector<int> arr3 = input;
        auto start3 = std::chrono::high_resolution_clock::now();
        res3 = quickmm(arr3.data(), 0, n - 1, k - 1);
        auto end3 = std::chrono::high_resolution_clock::now();
        time3[i] = std::chrono::duration<double, std::micro>(end3 - start3).count();
    }

    double avgTime1 = avgTime(time1);
    double avgTime2 = avgTime(time2);
    double avgTime3 = avgTime(time3);

    std::cout << std::fixed << std::setprecision(9);
    std::cout << "\nResults:\n";
    std::cout << "========================================\n";
    std::cout << "Mergesort - kth smallest element: " << res1 << "\n";
    std::cout << "Average time taken by mergesort:  " << avgTime1 << " microseconds\n";
    std::cout << "========================================\n";
    std::cout << "Quickselect - kth smallest element: " << res2 << "\n";
    std::cout << "Average time taken by quickselect:  " << avgTime2 << " microseconds\n";
    std::cout << "========================================\n";
    std::cout << "Quickmm - kth smallest element: " << res3 << "\n";
    std::cout << "Average time taken by quickmm:  " << avgTime3 << " microseconds\n";

    return 0;
}
