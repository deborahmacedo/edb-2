#include <iostream>
#include <chrono>
#include "insertion_sort.h"

int main() {
    using namespace std;
    using namespace std::chrono;
    //-----------------------//
    // Exemplo
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    auto start = steady_clock::now();
    INSERTIONSORT(arr, n); // chama a função 
    auto end = steady_clock::now();

    auto result =  duration_cast<microseconds>(end - start);

    cout << result.count();
    return 0;


}
