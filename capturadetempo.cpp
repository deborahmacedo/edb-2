#include <iostream>
#include <vector>
#include <random>
#include <chrono>

#include "insertion_sort.hpp"
#include "bubblesort.hpp"
#include "busca_binaria.hpp"
#include "busca_sequencial.hpp"
#include "capturadetempo.hpp"

// Função para popular o vetor com números aleatórios entre min e max
void popularVetor(std::vector<int>& vetor, int min, int max) {
    unsigned seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937 gerador(seed);
    std::uniform_int_distribution<int> distribuicao(min, max);

    for (size_t i = 0; i < vetor.size(); ++i) {
        vetor[i] = distribuicao(gerador);
    }
}

int main() {
    int tamanho = 100;
    std::vector<int> meu_vetor(tamanho);

    // Popula o vetor com números aleatórios entre 1 e 100
    popularVetor(meu_vetor, 1, 100);

    // Imprime o vetor original
    std::cout << "Vetor populado: ";
    for (int num : meu_vetor) std::cout << num << " ";
    std::cout << std::endl;

    // Cria uma cópia do vetor para cada algoritmo (para garantir que todos recebam o mesmo array)
    std::vector<int> arr_insertion = meu_vetor;
    std::vector<int> arr_bubble    = meu_vetor;

    // Medir tempos de ordenação
    auto tempo_insertion = contador_ordenacao(InsertionSort, arr_insertion.data(), arr_insertion.size());
    auto tempo_bubble    = contador_ordenacao(BubbleSort, arr_bubble.data(), arr_bubble.size());

    std::cout << "Insertion Sort: " << std::chrono::duration_cast<std::chrono::microseconds>(tempo_insertion).count() << " microssegundos\n";
    std::cout << "Bubble Sort:    " << std::chrono::duration_cast<std::chrono::microseconds>(tempo_bubble).count() << " microssegundos\n";

    // Para busca, usar um vetor ordenado
    std::vector<int> vetor_ordenado = arr_insertion; // já está ordenado
    int x = 50; // elemento a buscar

    auto tempo_binaria     = contador_busca(BuscaBinaria, vetor_ordenado.data(), vetor_ordenado.size(), x);
    auto tempo_sequencial  = contador_busca(BuscaSequencial, vetor_ordenado.data(), vetor_ordenado.size(), x);

    std::cout << "Busca Binária:      " << std::chrono::duration_cast<std::chrono::microseconds>(tempo_binaria).count() << " microssegundos\n";
    std::cout << "Busca Sequencial:   " << std::chrono::duration_cast<std::chrono::microseconds>(tempo_sequencial).count() << " microssegundos\n";

    return 0;
}
