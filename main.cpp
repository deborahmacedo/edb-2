#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include "bubblesort.hpp"
#include "insertionsort.hpp"
#include "busca_sequencial.hpp"
#include "busca_binaria.hpp"
#include "comparar.hpp"
using namespace std;


void pooularVetorComValoresAleatorios(int arr[], int n, int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);

    for (int i = 0; i < n; i++) {
        arr[i] = dis(gen);
    }
}


int main(){
    
    int array_tempo_insertion[10];
    int array_tempo_bubble[10];
    int array_tempo_busca_sequencial[10];
    int array_tempo_busca_binaria[10];

    std::cout << "algoritmo,n,tempo" << std::endl;
        //POPULAR VETOR
        std::vector<int> tamanhos = {10000, 20000, 30000, 40000, 50000, 60000,70000, 80000, 90000, 100000};
       for(int j = 0; j < 10; ++j) {

        int tamanho = tamanhos[j]; // Tamanho do vetor

        int vetor[tamanho];
        pooularVetorComValoresAleatorios(vetor, tamanho, 1, 1000000); // Intervalo dos valores

        std::vector<int> insertion_avarage_times;
        std::vector<int> bubble_avarage_times;
        std::vector<int> busca_sequencial_avarage_times;
        std::vector<int> busca_binaria_avarage_times;

        
        for(int i = 0; i < 5; ++i) { 

            //INSERTION SORT
            auto start_insertion = std::chrono::high_resolution_clock::now();
            InsertionSort(vetor, tamanho);
            auto end_insertion = std::chrono::high_resolution_clock::now();
            auto duration_insertion = std::chrono::duration_cast<std::chrono::microseconds>(end_insertion - start_insertion);
            insertion_avarage_times.push_back(duration_insertion.count());



            //BUBBLE SORT
            pooularVetorComValoresAleatorios(vetor, tamanho, 1, 1000000);
            auto start_bubble = std::chrono::high_resolution_clock::now();
            BubbleSort(vetor, tamanho);
            auto end_bubble = std::chrono::high_resolution_clock::now();
            auto duration_bubble = std::chrono::duration_cast<std::chrono::microseconds>(end_bubble - start_bubble);
            bubble_avarage_times.push_back(duration_bubble.count());



            //Busca sequencial 
            int vetor1[tamanho];
            pooularVetorComValoresAleatorios(vetor1, tamanho, 1, 1000000);
            random_device rd;   
            std::mt19937 gen(rd());
            int x = std::uniform_int_distribution<>(1, 1000000)(gen); // Número a ser buscado

            auto start_busca_sequencial = std::chrono::high_resolution_clock::now();
            int result = BuscaSequencial(vetor, tamanho, x);
            auto end_busca_sequencial = std::chrono::high_resolution_clock::now();
            auto duration_busca_sequencial = std::chrono::duration_cast<std::chrono::microseconds>(end_busca_sequencial - start_busca_sequencial);
            busca_sequencial_avarage_times.push_back(duration_busca_sequencial.count());



            // Busca binária
            int y = std::uniform_int_distribution<>(1, 1000000)(gen);
            int vetor_ordenado[tamanho];
            std::copy(vetor, vetor + tamanho, vetor_ordenado); // Copia o vetor original
            InsertionSort(vetor_ordenado, tamanho); // Ordena a cópia

            int num_repeticoes = 1;
            int result2;
            auto start_busca_binaria = std::chrono::high_resolution_clock::now();
            for (int rep = 0; rep < num_repeticoes; ++rep) {
                result2 = BuscaBinaria(vetor_ordenado, tamanho, y);
            }
            auto end_busca_binaria = std::chrono::high_resolution_clock::now();
            auto duration_busca_binaria = std::chrono::duration_cast<std::chrono::nanoseconds>(end_busca_binaria - start_busca_binaria);

            busca_binaria_avarage_times.push_back(duration_busca_binaria.count() / num_repeticoes);
        }

        auto insertion_average = 0;
        auto bubble_average = 0;
        auto busca_sequencial_average = 0; 
        auto busca_binaria_average = 0;

        for(int i = 0; i < 5; ++i) { 
            insertion_average += insertion_avarage_times[i];
            bubble_average += bubble_avarage_times[i];
            busca_sequencial_average += busca_sequencial_avarage_times[i];
            busca_binaria_average += busca_binaria_avarage_times[i];
        }

        //std::cout << "---------------------------------------------------------------------------------------------------\n";
        std::cout << "\nInsertionSort," << tamanho << ", " << insertion_average / 5 << std::endl;
        std::cout << "\nBubbleSort," << tamanho << ", " << bubble_average / 5 << std::endl;
        std::cout << "\nSequentialSearch," << tamanho << ", " << busca_sequencial_average / 5 << std::endl;
        std::cout << "\nBinarySearch," <<  tamanho << ", " << busca_binaria_average / 5 << std::endl;
        std::cout << "\n"; 
        //std::cout << "\033[36mVetor com essa quantidade de elementos: \033[0m" << tamanhos[j] << std::endl;

        array_tempo_insertion[j] = insertion_average / 5;
        array_tempo_bubble[j] = bubble_average / 5;
        array_tempo_busca_sequencial[j] = busca_sequencial_average / 5;
        array_tempo_busca_binaria[j] = busca_binaria_average / 5; 
    }
    comparar(tamanhos.data(), array_tempo_insertion);
    comparar(tamanhos.data(), array_tempo_bubble);
    comparar(tamanhos.data(), array_tempo_busca_sequencial);
    comparar(tamanhos.data(), array_tempo_busca_binaria);

    return 0;
}
