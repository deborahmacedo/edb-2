#include <iostream>
#include <cmath>
using namespace std;

int comparar(int arr_tam[6], int arr_tempo[6]){
    double diferenca_log = 0, diferenca_lin = 0, diferenca_log_lin = 0, diferenca_quadr = 0, diferenca_cub = 0;

for (int i = 0; i < 5; i++) {
    int aumento = arr_tam[i+1] / arr_tam[i];

    // O(log n)
    double esperado = log2(arr_tam[i+1]) / log2(arr_tam[i]) * arr_tempo[i];
    diferenca_log += fabs((double)arr_tempo[i+1] / esperado - 1);

    // O(n)
    esperado = (double)arr_tam[i+1] / arr_tam[i] * arr_tempo[i];
    diferenca_lin += fabs((double)arr_tempo[i+1] / esperado - 1);

    // O(n log n)
    esperado = (double)arr_tam[i+1] * log2(arr_tam[i+1]) / (arr_tam[i] * log2(arr_tam[i])) * arr_tempo[i];
    diferenca_log_lin += fabs((double)arr_tempo[i+1] / esperado - 1);

    // O(n^2)
    esperado = pow((double)arr_tam[i+1] / arr_tam[i], 2) * arr_tempo[i];
    diferenca_quadr += fabs((double)arr_tempo[i+1] / esperado - 1);

    // O(n^3)
    esperado = pow((double)arr_tam[i+1] / arr_tam[i], 3) * arr_tempo[i];
    diferenca_cub += fabs((double)arr_tempo[i+1] / esperado - 1);
}

    
    int diferencas[5] = {
        diferenca_log,
        diferenca_lin,
        diferenca_log_lin,
        diferenca_quadr,
        diferenca_cub
    };

    int indice_menor = 0;
    int menor_valor = diferencas[0];
    for(int i = 1; i < 5; i++){
        if(diferencas[i] < menor_valor){
            menor_valor = diferencas[i];
            indice_menor = i;
        }
    }

    cout << "A complexidade do algoritmo é: ";
    switch (indice_menor){
        case 0: cout << "O(log n)" << endl; break;
        case 1: cout << "O(n)" << endl; break;
        case 2: cout << "O(n log n)" << endl; break;
        case 3: cout << "O(n^2)" << endl; break;
        case 4: cout << "O(n^3)" << endl; break;
    }   

    return indice_menor;
}
