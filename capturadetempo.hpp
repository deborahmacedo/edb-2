#ifndef CAPTURA_DE_TEMPO_HPP
#define CAPTURA_DE_TEMPO_HPP

#include <chrono>
#include <iostream>

// Contador de tempo para funções de ordenação que recebem (int arr[], int n)
template <typename Func>
auto contador_ordenacao(Func func, int arr[], int n) {
    auto start = std::chrono::steady_clock::now();
    func(arr, n);  // chama a função de ordenação
    auto end = std::chrono::steady_clock::now();

    return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
}

// Contador de tempo para funções de busca que recebem (int arr[], int n, int x)
template <typename Func>
auto contador_busca(Func func, int arr[], int n, int x) {
    auto start = std::chrono::steady_clock::now();
    func(arr, n, x);  // chama a função de busca
    auto end = std::chrono::steady_clock::now();

    return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
}

#endif 
