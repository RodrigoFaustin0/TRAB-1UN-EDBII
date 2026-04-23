
# Análise Empírica de Complexidade de Algoritmos 

**Disciplina:** Estruturas de Dados Básicos II (EDB II)  
**Instituição:** Universidade Federal do Rio Grande do Norte (UFRN)  

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Python](https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=python&logoColor=white)

##  Objetivo
Este trabalho prático tem como objetivo implementar um programa capaz de avaliar empiricamente o tempo de execução de algoritmos de busca e ordenação. A partir dos tempos coletados, o projeto realiza uma comparação visual do crescimento do tempo de execução com suas respectivas funções assintóticas teóricas (Notação Big-O).

##  Arquitetura do Projeto
Para unir alta performance na execução com excelência na visualização gráfica, o projeto foi dividido em duas etapas (um mini pipeline de dados):
1. **Motor de Medição (C):** Executa os algoritmos, realiza as medições de tempo de CPU via `<time.h>` e exporta os dados brutos.
2. **Visualização (Python):** Consome os dados gerados utilizando `pandas` e plota os gráficos comparativos utilizando `matplotlib`.

##  Algoritmos Analisados
Foram escolhidos dois algoritmos com classes de complexidade distintas para evidenciar a diferença de escalabilidade:
* **Busca Sequencial:** Comportamento linear — $O(n)$
* **Quicksort:** Comportamento log-linear (caso médio) — $O(n \log n)$

##  Como Executar

### Pré-requisitos
Ter instalado em sua máquina:
* Compilador **GCC** (para rodar o código em C)
* **Python 3** e as bibliotecas de dados (`pip install pandas matplotlib numpy`)

### Passo a Passo

1. **Clone o repositório:**
   ```bash
   git clone https://github.com/RodrigoFaustin0/TRAB-1UN-EDBII.git
   cd TRAB-1UN-EDBII

2. **Compile e execute o gerador de dados**

## Autores
Rodrigo Faustino - [GitHub](https://github.com/RodrigoFaustin0)