#ifndef CAPTURA_DE_TEMPO_HPP
#define CAPTURA_DE_TEMPO_HPP

#include <chrono>
#include <iostream>

template <typename Func>
auto contador(Func sortFunc, int arr[], int n) {
    auto start = std::chrono::steady_clock::now(); // marca início
    sortFunc(arr, n);                               // chama o algoritmo de ordenação
    auto end = std::chrono::steady_clock::now();   // marca fim

    auto duracao = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    return duracao.count(); // retorna tempo em microsegundos
}

#endif 
