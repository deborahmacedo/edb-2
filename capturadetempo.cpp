#include <iostream>
#include "contador.hpp"
#include "bubblesort.h"
// exemplo: busca linear

int main() {
    int arr1[1000];
    for (int i = 0; i < 1000; i++) arr1[i] = 1000 - i;

    int arr2[1000];
    for (int i = 0; i < 1000; i++) arr2[i] = i;

    // medir ordenação
    auto tempo_sort = contador_tempo(bubble_sort, arr1, 1000);
    std::cout << "Tempo Bubble Sort: " << tempo_sort / 1000.0 << " microssegundos\n";

    // medir busca
    auto tempo_busca = contador_tempo(busca_linear, arr2, 1000, 750);
    std::cout << "Tempo Busca Linear: " << tempo_busca << " ns\n";

    return 0;
}
