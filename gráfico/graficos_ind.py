import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# --- Passo 1: Carregar e Preparar os Dados ---
try:
    df = pd.read_csv('resultados.csv', header=0)
except FileNotFoundError:
    print("Erro: O arquivo 'resultados.csv' não foi encontrado.")
    print("Certifique-se de que o arquivo está na mesma pasta que este script.")
    exit()

# Pega a lista de todos os algoritmos únicos presentes no arquivo CSV
lista_de_algoritmos = df['algoritmo'].unique()

plt.style.use('seaborn-v0_8-whitegrid')

# --- Passo 2: Loop para criar um gráfico para cada algoritmo ---

for algoritmo in lista_de_algoritmos:
    print(f"Gerando gráfico para: {algoritmo}...")

    # Filtra o DataFrame para obter dados apenas do algoritmo atual
    df_algoritmo = df[df['algoritmo'] == algoritmo].copy().dropna()

    # Se não houver dados válidos para este algoritmo, pula para o próximo
    if df_algoritmo.empty:
        print(f"  -> Aviso: Não foram encontrados dados válidos para {algoritmo}. Gráfico não gerado.")
        continue

    # Cria uma nova figura e eixos para cada gráfico
    fig, ax = plt.subplots(figsize=(10, 7))

    # Plota os dados reais do algoritmo
    ax.plot(df_algoritmo['n'], df_algoritmo['tempo'], marker='o', linestyle='-', label='Curva Real')

    # --- Passo 3: Adicionar a Curva Teórica Correta ---

    ultimo_n = df_algoritmo['n'].iloc[-1]
    ultimo_tempo = df_algoritmo['tempo'].iloc[-1]
    n_teorico = np.linspace(df_algoritmo['n'].min(), ultimo_n, 100)

    # Verifica o nome do algoritmo para decidir qual curva teórica desenhar
    if 'Sort' in algoritmo: # Para BubbleSort e InsertionSort
        constante_c = ultimo_tempo / (ultimo_n**2)
        tempo_teorico = constante_c * (n_teorico**2)
        ax.plot(n_teorico, tempo_teorico, linestyle='--', color='red', label='Curva Esperada - O(n^2)')
    
    elif 'Sequential' in algoritmo:
        constante_c = ultimo_tempo / ultimo_n
        tempo_teorico = constante_c * n_teorico
        ax.plot(n_teorico, tempo_teorico, linestyle='--', color='red', label='Curva Esperada - O(n)')

    elif 'Binary' in algoritmo:
        n_log_teorico = np.linspace(max(2, df_algoritmo['n'].min()), ultimo_n, 100) # log(n) precisa de n > 1
        constante_c = ultimo_tempo / np.log2(ultimo_n)
        tempo_teorico = constante_c * np.log2(n_log_teorico)
        ax.plot(n_log_teorico, tempo_teorico, linestyle='--', color='red', label='Curva Esperada - O(log n)')

    # --- Passo 4: Personalizar e Salvar o Gráfico ---
    ax.set_title(f'Análise de Complexidade: {algoritmo}', fontsize=16)
    ax.set_xlabel('Tamanho da Entrada (n)', fontsize=12)
    ax.set_ylabel('Tempo de Execução (microssegundos)', fontsize=12)
    ax.legend()
    ax.grid(True)
    
    # Salva o gráfico com um nome de arquivo dinâmico
    nome_arquivo = f'grafico_{algoritmo}.png'
    plt.savefig(nome_arquivo)
    print(f"  -> Gráfico '{nome_arquivo}' salvo com sucesso.")

# plt.show() # Descomente esta linha se quiser que os gráficos apareçam na tela no final