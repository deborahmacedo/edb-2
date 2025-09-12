#include <iostream>
#include <vector>
#include "bubblesort.hpp"
#include "insertionsort.hpp"
#include "busca_sequencial.hpp"
#include "busca_binaria.hpp"
#include <chrono>

int main(){
    
    //INSERTION SORT

    int arr[] = {64, 34, 25, 12, 22, 11, 90, 1 ,3 ,6 ,8 ,1, 3838, 10203, 203, 123, 456, 789, 100, 5, 78};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    std::cout << "Starting Insertion Sort timing:..." << std::endl;
    auto start_insertion = std::chrono::high_resolution_clock::now();
    InsertionSort(arr, n);
    auto end_insertion = std::chrono::high_resolution_clock::now();
    std::cout << "\nFinished Insertion Sort timing:..." << std::endl;
    auto duration_insertion = std::chrono::duration_cast<std::chrono::milliseconds>(end_insertion - start_insertion);

    std::cout << "\nInsertion Sort execution time: " << duration_insertion.count() << " milliseconds" << std::endl;

    //BUBBLE SORT
    int arr2[] = {64, 34, 25, 12, 22, 11, 100, 5, 1, 78};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    
    std::cout << "\nStarting Bubble Sort timing:..." << std::endl;
    auto start_bubble = std::chrono::high_resolution_clock::now();
    BubbleSort(arr2, n2);
    auto end_bubble = std::chrono::high_resolution_clock::now();
    std::cout << "\nFinished Bubble Sort timing:..." << std::endl;
    auto duration_bubble = std::chrono::duration_cast<std::chrono::milliseconds>(end_bubble - start_bubble);

    std::cout << "\nBubble Sort execution time: " << duration_bubble.count() << " milliseconds" << std::endl;
  
//Busca sequencial 
int arr3[] = {2, 3, 4, 10, 40, 65, 34, 76, 54, 65, 99, 8, 5, 4, 3, 21};
int n3 = sizeof(arr3)/sizeof(arr3[0]);
int x = 21;
std ::cout << "\nStarting Sequential Search timing:..." << std::endl;
auto start_busca_sequencial = std::chrono::high_resolution_clock::now();
int result = BuscaSequencial(arr3, n3, x);
std::cout << "\nElement found at position: " << result << std::endl;
auto end_busca_sequencial = std::chrono::high_resolution_clock::now();
std::cout << "\nFinished Sequential Search timing:..." << std::endl;
auto duration_busca_sequencial = std::chrono::duration_cast<std::chrono::milliseconds>(end_busca_sequencial - start_busca_sequencial);
std::cout << "\nSequential Search timing: " << duration_busca_sequencial.count() << " milissegundos" << std::endl;

//Busca binária
int arr4[] = {2, 3, 4, 10, 40, 65, 34, 76, 54, 65, 99, 8, 5, 4, 3, 21};
int n4 = sizeof(arr4)/sizeof(arr4[0]);
int y = 21;
InsertionSort(arr4, n4); //ordenar 
std ::cout << "\nStarting Binary Search timing..." << std::endl;
auto start_busca_binaria = std::chrono::high_resolution_clock::now();
int result2 = BuscaBinaria(arr4, n4, y);
std::cout << "\nElement found at position: " << result2 << std::endl;
auto end_busca_binaria = std::chrono::high_resolution_clock::now();
std::cout << "\nFinished Binary Search timing..." << std::endl;
auto duration_busca_binaria = std::chrono::duration_cast<std::chrono::milliseconds>(end_busca_binaria - start_busca_binaria);
std::cout << "\nBinary Search execution time: " << duration_busca_binaria.count() << " milliseconds" << std::endl;   




    return 0;
}
