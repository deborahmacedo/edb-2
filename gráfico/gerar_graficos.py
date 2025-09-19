import pandas as pd
import matplotlib.pyplot as plt
import numpy as np # NOVO: Importa a biblioteca NumPy para cálculos matemáticos

# --- Passo 1: Carregar e Preparar os Dados ---

try:
    df = pd.read_csv('resultados.csv', header=0)
except FileNotFoundError:
    print("Erro: O arquivo 'resultados.csv' não foi encontrado.")
    print("Certifique-se de que o arquivo está na mesma pasta que este script.")
    exit()

df_pivot = df.pivot_table(index='n', columns='algoritmo', values='tempo', aggfunc='mean')

algoritmos_ordenacao = ['BubbleSort', 'InsertionSort']
algoritmos_busca = ['SequentialSearch', 'BinarySearch']

plt.style.use('seaborn-v0_8-whitegrid')

# --- Passo 2: Gerar o Gráfico de ORDENAÇÃO com a curva O(n^2) ---

fig_ordenacao, ax_ordenacao = plt.subplots(figsize=(10, 7))

for algoritmo in algoritmos_ordenacao:
    ax_ordenacao.plot(df_pivot.index, df_pivot[algoritmo], marker='o', linestyle='-', label=f'Real - {algoritmo}')

# NOVO: Seção para calcular e plotar a curva teórica O(n^2)
# --------------------------------------------------------------------
# Pega o último ponto do InsertionSort para encontrar a constante 'c'
ultimo_n = df_pivot.index[-1]
ultimo_tempo_is = df_pivot['InsertionSort'].iloc[-1]
constante_c = ultimo_tempo_is / (ultimo_n**2)

# Cria uma sequência suave de valores de 'n' para uma curva bonita
n_teorico = np.linspace(df_pivot.index.min(), df_pivot.index.max(), 100)
# Calcula os valores de tempo teóricos
tempo_teorico_n2 = constante_c * (n_teorico**2)

# Plota a curva teórica
ax_ordenacao.plot(n_teorico, tempo_teorico_n2, linestyle='--', color='red', label='Esperado - O(n^2)')
# --------------------------------------------------------------------

ax_ordenacao.set_title('Análise de Complexidade: Algoritmos de Ordenação', fontsize=16)
ax_ordenacao.set_xlabel('Tamanho da Entrada (n)', fontsize=12)
ax_ordenacao.set_ylabel('Tempo de Execução (microssegundos)', fontsize=12)
ax_ordenacao.legend()
ax_ordenacao.grid(True)

plt.savefig('grafico_ordenacao_comparativo.png')
print("Gráfico 'grafico_ordenacao_comparativo.png' salvo com sucesso.")


# --- Passo 3: Gerar o Gráfico de BUSCA com as curvas O(n) e O(log n) ---

fig_busca, ax_busca = plt.subplots(figsize=(10, 7))

for algoritmo in algoritmos_busca:
    ax_busca.plot(df_pivot.index, df_pivot[algoritmo], marker='o', linestyle='-', label=f'Real - {algoritmo}')

# NOVO: Seção para calcular e plotar a curva teórica O(n) para a Busca Sequencial
# --------------------------------------------------------------------
ultimo_tempo_seq = df_pivot['SequentialSearch'].iloc[-1]
constante_c_n = ultimo_tempo_seq / ultimo_n
tempo_teorico_n = constante_c_n * n_teorico
ax_busca.plot(n_teorico, tempo_teorico_n, linestyle='--', color='red', label='Esperado - O(n)')
# --------------------------------------------------------------------

# NOVO: Seção para calcular e plotar a curva teórica O(log n) para a Busca Binária
# --------------------------------------------------------------------
# Usamos o penúltimo ponto para evitar log de 1, se for o caso, e para dar escala
ultimo_tempo_bin = df_pivot['BinarySearch'].iloc[-1]
# Evita log de zero ou números muito pequenos que podem dar resultados estranhos
n_log_teorico = np.linspace(df_pivot.index[df_pivot.index > 1].min(), df_pivot.index.max(), 100)
constante_c_log_n = ultimo_tempo_bin / np.log2(ultimo_n)
tempo_teorico_log_n = constante_c_log_n * np.log2(n_log_teorico)
ax_busca.plot(n_log_teorico, tempo_teorico_log_n, linestyle='--', color='green', label='Esperado - O(log n)')
# --------------------------------------------------------------------

ax_busca.set_title('Análise de Complexidade: Algoritmos de Busca', fontsize=16)
ax_busca.set_xlabel('Tamanho da Entrada (n)', fontsize=12)
ax_busca.set_ylabel('Tempo de Execução (microssegundos)', fontsize=12)
ax_busca.legend()
ax_busca.grid(True)

plt.savefig('grafico_busca_comparativo.png')
print("Gráfico 'grafico_busca_comparativo.png' salvo com sucesso.")


# --- Passo 4: Exibir os Gráficos ---
plt.show()