#include "busca_binaria.hpp"

int BuscaBinaria(int arr[], int n, int y){
    int esquerda = 0;
    int direita = n -1;

    while(esquerda <= direita){
        int meio = (direita - esquerda)/2 + esquerda;
        if(arr[meio] == y){
            return meio;
        }
        else if(arr[meio] < y){
            esquerda = meio + 1;
        }else{
            direita = meio - 1;
        }
    }
    return -1;
}