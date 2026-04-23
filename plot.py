import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# Carregar a base de dados
df = pd.read_csv('resultados.csv')

# Configurar o ambiente de plotagem (dois gráficos lado a lado)
fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(14, 6))

n_valores = df['n']
n_max = n_valores.iloc[-1]


# GRÁFICO 1: Busca Sequencial O(n)
ax1.plot(n_valores, df['tempo_busca'], marker='o', linewidth=2, color='red', label='Busca (Empírico)')

# Calcular a curva teórica O(n) ancorada no último ponto empírico
c_n = df['tempo_busca'].iloc[-1] / n_max
teorico_n = c_n * n_valores
ax1.plot(n_valores, teorico_n, linestyle='--', color='darkred', label='Teórico $O(n)$')

ax1.set_title('Busca Sequencial', fontsize=14, fontweight='bold')
ax1.set_xlabel('Tamanho da Entrada (n)', fontsize=12)
ax1.set_ylabel('Tempo de Execução (Segundos)', fontsize=12)
ax1.legend()
ax1.grid(True, linestyle=':', alpha=0.7)


# GRÁFICO 2: Quicksort O(n log n)
ax2.plot(n_valores, df['tempo_quick'], marker='s', linewidth=2, color='blue', label='Quicksort (Empírico)')

# Calcular a curva teórica O(n log n) ancorada no último ponto empírico
c_nlogn = df['tempo_quick'].iloc[-1] / (n_max * np.log2(n_max))
teorico_nlogn = c_nlogn * (n_valores * np.log2(n_valores))
ax2.plot(n_valores, teorico_nlogn, linestyle='--', color='darkblue', label='Teórico $O(n \log n)$')

ax2.set_title('Quicksort', fontsize=14, fontweight='bold')
ax2.set_xlabel('Tamanho da Entrada (n)', fontsize=12)
ax2.set_ylabel('Tempo de Execução (Segundos)', fontsize=12)
ax2.legend()
ax2.grid(True, linestyle=':', alpha=0.7)

# Ajustes e exportação
fig.suptitle('Análise Empírica de Complexidade de Algoritmos', fontsize=16, fontweight='bold', y=1.05)
plt.tight_layout()

# Salvar a imagem final
plt.savefig('grafico_resultados.png', dpi=300, bbox_inches='tight')
print("Análise visual concluída! A imagem 'grafico_resultados.png' foi gerada com sucesso.")