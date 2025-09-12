#ifndef CAPTURA_DE_TEMPO_HPP
#define CAPTURA_DE_TEMPO_HPP

#include <chrono>

// Ordenação
template <typename Func>
long long contador_ordenacao(Func func, int arr[], int n) {
    auto start = std::chrono::steady_clock::now();
    func(arr, n);
    auto end = std::chrono::steady_clock::now();

    return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
}

// Busca
template <typename Func>
long long contador_busca(Func func, int arr[], int n, int x) {
    auto start = std::chrono::steady_clock::now();
    func(arr, n, x);
    auto end = std::chrono::steady_clock::now();

    return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
}

#endif
template <typename Func>
long long medirTempo(Func func, int arr[], int n) {
    auto start = std::chrono::steady_clock::now();
    func(arr, n);
    auto end = std::chrono::steady_clock::now();

    return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
}
