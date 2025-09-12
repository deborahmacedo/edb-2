#include <iostream>
#include <vector>
#include "bubblesort.hpp"
#include "insertion_sort.hpp"
#include <chrono>

int main(){
    
    //INSERTION SORT

    int arr[] = {64, 34, 25, 12, 22, 11, 90, 1 ,3 ,6 ,8 ,1, 3838, 10203, 203, 123, 456, 789, 100, 5, 78};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    std::cout << "Começando a contar o tempo do Insertion Sort..." << std::endl;
    auto start_insertion = std::chrono::high_resolution_clock::now();
    InsertionSort(arr, n);
    auto end_insertion = std::chrono::high_resolution_clock::now();
    std::cout << "\nFinalizando a contagem do tempo do Insertion Sort..." << std::endl;
    auto duration_insertion = std::chrono::duration_cast<std::chrono::milliseconds>(end_insertion - start_insertion);

    std::cout << "\nTempo de execução do Insertion Sort: " << duration_insertion.count() << " milissegundos" << std::endl;

    //BUBBLE SORT
    int arr2[] = {64, 34, 25, 12, 22, 11, 100, 5, 1, 78};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    
    std::cout << "\nComeçando a contar o tempo do Bubble Sort..." << std::endl;
    auto start_bubble = std::chrono::high_resolution_clock::now();
    BubbleSort(arr2, n2);
    auto end_bubble = std::chrono::high_resolution_clock::now();
    std::cout << "\nFinalizando a contagem do tempo do Bubble Sort..." << std::endl;
    auto duration_bubble = std::chrono::duration_cast<std::chrono::milliseconds>(end_bubble - start_bubble);

    std::cout << "\nTempo de execução do Bubble Sort: " << duration_bubble.count() << " milissegundos" << std::endl;
  

    
    return 0;
}
