#include "busca_binaria.h"

int BuscaBinaria(int arr[], int n, int x){
    int esquerda = 0;
    int direita = n -1;

    while(esquerda <= direita){
        int meio = (direita - esquerda)/2 + esquerda;
        if(arr[meio] == x){
            return meio;
        }
        else if(arr[meio] < x){
            esquerda = meio + 1;
        }else{
            direita = meio - 1;
        }
    }
    return -1;
}