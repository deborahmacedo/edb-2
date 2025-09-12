#include <iostream>
#include <vector>
#include <chrono>


#include "insertion_sort.hpp"
#include "bubblesort.hpp"

// Bubble Sort
double medirTempoBubble(BubbleSort, int arr[], int n) {
    auto start = std::chrono::steady_clock::now();
    BubbleSort(arr, n);  // chama a função de ordenação
    auto end = std::chrono::steady_clock::now();

    return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
}

// Insertion Sort
double medirTempoInsertion(InsertionSort, int arr[], int n) {
    auto start = std::chrono::steady_clock::now();
    InsertionSort(arr, n);  // chama a função de ordenação
    auto end = std::chrono::steady_clock::now();

    return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
}
