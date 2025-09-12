#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include "bubblesort.hpp"
#include "insertionsort.hpp"
#include "busca_sequencial.hpp"
#include "busca_binaria.hpp"


void pooularVetorComValoresAleatorios(int arr[], int n, int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);

    for (int i = 0; i < n; i++) {
        arr[i] = dis(gen);
    }
}


int main(){

    std::cout << "algoritmo,n,tempo_medio" << std::endl;
        //POPULAR VETOR
       for(int j = 0; j < 5; ++j) { 
        std::vector<int> tamanhos = {10000, 20000, 50000, 80000, 100000};
        int tamanho = tamanhos[j]; // Tamanho do vetor

        int vetor[tamanho];
        pooularVetorComValoresAleatorios(vetor, tamanho, 1, 100000); // Intervalo dos valores
        //std::cout << "\nVetor populado com valores aleatórios." << std::endl;

        std::vector<int> insertion_avarage_times;
        std::vector<int> bubble_avarage_times;
        std::vector<int> busca_sequencial_avarage_times;
        std::vector<int> busca_binaria_avarage_times;

        
        for(int i = 0; i < 5; ++i) { 

            //INSERTION SORT

            //int arr[] = {64, 34, 25, 12, 22, 11, 90, 1 ,3 ,6 ,8 ,1, 3838, 10203, 203, 123, 456, 789, 100, 5, 78};
            //int n = sizeof(arr)/sizeof(arr[0]);
            //std::cout << "---------------------------------------------------------------------------------------------------\n";
            //std::cout << "Starting Insertion Sort timing:..." << std::endl;
            auto start_insertion = std::chrono::high_resolution_clock::now();
            InsertionSort(vetor, tamanho);
            auto end_insertion = std::chrono::high_resolution_clock::now();
            //std::cout << "\nFinished Insertion Sort timing:..." << std::endl;
            auto duration_insertion = std::chrono::duration_cast<std::chrono::microseconds>(end_insertion - start_insertion);

            //std::cout << "\nInsertionSort," << tamanho << "," << duration_insertion.count() << std::endl;

            
            insertion_avarage_times.push_back(duration_insertion.count());



            //BUBBLE SORT
            //int arr2[] = {64, 34, 25, 12, 22, 11, 100, 5, 1, 78};
            //int n2 = sizeof(arr2)/sizeof(arr2[0]);
            
            //std::cout << "---------------------------------------------------------------------------------------------------\n";
            //std::cout << "\nStarting Bubble Sort timing:..." << std::endl;
            auto start_bubble = std::chrono::high_resolution_clock::now();
            BubbleSort(vetor, tamanho);
            auto end_bubble = std::chrono::high_resolution_clock::now();
            //std::cout << "\nFinished Bubble Sort timing:..." << std::endl;
            auto duration_bubble = std::chrono::duration_cast<std::chrono::microseconds>(end_bubble - start_bubble);

            //std::cout << "\nBubble Sort execution time: " << duration_bubble.count() << " microseconds" << std::endl;
        
            
            bubble_avarage_times.push_back(duration_bubble.count());

            //Busca sequencial 
            //int arr3[] = {2, 3, 4, 10, 40, 65, 34, 76, 54, 65, 99, 8, 5, 4, 3, 21};
            //int n3 = sizeof(arr3)/sizeof(arr3[0]);
            //std::cout << "---------------------------------------------------------------------------------------------------\n";   
            int x = 9987;
            //std ::cout << "\nStarting Sequential Search timing:..." << std::endl;
            auto start_busca_sequencial = std::chrono::high_resolution_clock::now();
            int result = BuscaSequencial(vetor, tamanho, x);
            //std::cout << "\nElement found at position: " << result << std::endl;
            auto end_busca_sequencial = std::chrono::high_resolution_clock::now();
            //std::cout << "\nFinished Sequential Search timing:..." << std::endl;
            auto duration_busca_sequencial = std::chrono::duration_cast<std::chrono::microseconds>(end_busca_sequencial - start_busca_sequencial);
            //std::cout << "\nSequential Search timing: " << duration_busca_sequencial.count() << " microsegundos" << std::endl;

            busca_sequencial_avarage_times.push_back(duration_busca_sequencial.count());

            //Busca binária
            //int arr4[] = {2, 3, 4, 10, 40, 65, 34, 76, 54, 65, 99, 8, 5, 4, 3, 21};
            //int n4 = sizeof(arr4)/sizeof(arr4[0]);
            //std::cout << "---------------------------------------------------------------------------------------------------\n";
            int y = 999;
            InsertionSort(vetor, tamanho); //ordenar 
            //std ::cout << "\nStarting Binary Search timing..." << std::endl;
            auto start_busca_binaria = std::chrono::high_resolution_clock::now();
            int result2 = BuscaBinaria(vetor, tamanho, y);
            //std::cout << "\nElement found at position: " << result2 << std::endl;
            auto end_busca_binaria = std::chrono::high_resolution_clock::now();
            //std::cout << "\nFinished Binary Search timing..." << std::endl;
            auto duration_busca_binaria = std::chrono::duration_cast<std::chrono::microseconds>(end_busca_binaria - start_busca_binaria);
            //std::cout << "\nBinary Search execution time: " << duration_busca_binaria.count() << " microseconds" << std::endl;   

            busca_binaria_avarage_times.push_back(duration_busca_binaria.count());
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
        std::cout << "\nInsertionSort," << tamanho << "," << insertion_average / 5 << std::endl;
        std::cout << "\nBubbleSort," << tamanho << "," << bubble_average / 5 << std::endl;
        std::cout << "\nSequentialSearch," << tamanho << "," << busca_sequencial_average / 5 << std::endl;
        std::cout << "\nBinarySearch," <<  tamanho << "," << busca_binaria_average / 5 << std::endl;
        std::cout << "\n"; 
        //std::cout << "\033[36mVetor com essa quantidade de elementos: \033[0m" << tamanhos[j] << std::endl;
    }
    return 0;
}
