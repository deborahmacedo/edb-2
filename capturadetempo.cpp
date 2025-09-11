#include <iostream>
#include "insertion_sort.hpp"
#include "capturadetempo.hpp"

int main() {
    int arr[] = {5,2,9,1,5,6,9,3,7,4,8};
    int n = sizeof(arr)/sizeof(arr[0]);

    auto tempo = contador(InsertionSort, arr, n);

    return 0;
}
