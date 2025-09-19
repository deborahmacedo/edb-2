#include "insertionsort.hpp"
#include <iostream>
#include <vector>

void InsertionSort(int arr[], int n){
  for(int i = 1; i < n; i++){
    int j = i - 1;
    int chave = arr[i];

    while(j>= 0 && arr[j]> chave){
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = chave;
  }
  /*std::cout << "Vetor ordenado com Insertion Sort: " << std::endl;
    for (int i = 0; i < 20; i++) {
        std::cout << arr[i] << " ";
    }*/
}