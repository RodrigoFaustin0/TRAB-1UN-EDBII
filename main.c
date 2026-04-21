#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ==========================================
// Busca Sequencial O(n)
// ==========================================
int buscaSequencial(int vetor[], int n, int chave) {
    for (int i = 0; i < n; i++) {
        if (vetor[i] == chave) {
            return i;
        }
    }
    return -1;
}

// ==========================================
// Quicksort O(n log n)
// ==========================================
int particionar(int vetor[], int inicio, int fim) {
    int pivo = vetor[fim];
    int i = (inicio - 1);

    for (int j = inicio; j <= fim - 1; j++) {
        if (vetor[j] < pivo) {
            i++;
            int auxiliar = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = auxiliar;
        }
    }
    int auxiliar = vetor[i + 1];
    vetor[i + 1] = vetor[fim];
    vetor[fim] = auxiliar;
    return (i + 1);
}

void quicksort(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int indice_particao = particionar(vetor, inicio, fim);
        quicksort(vetor, inicio, indice_particao - 1);
        quicksort(vetor, indice_particao + 1, fim);
    }
}

// ==========================================
// FUNÇÃO PRINCIPAL E MEDIÇÃO
// ==========================================
int main() {
    // Usando entradas grandes para evidenciar o tempo de execução
    int tamanhos[] = {100000, 200000, 300000, 400000, 500000, 600000, 700000, 800000, 900000, 1000000};
    int quantidade_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);

    FILE *arquivo_csv = fopen("resultados.csv", "w");
    if (!arquivo_csv) {
        printf("Erro ao criar arquivo CSV.\n");
        return 1;
    }
    
    // Cabeçalho do arquivo CSV
    fprintf(arquivo_csv, "n,tempo_busca,tempo_quick\n");
    printf("Iniciando o processamento dos algoritmos...\n");

    for (int i = 0; i < quantidade_tamanhos; i++) {
        int n = tamanhos[i];
        
        int *vetor_busca = (int*)malloc(n * sizeof(int));
        int *vetor_quick = (int*)malloc(n * sizeof(int));

        // Povoando vetores com dados 
        for(int j = 0; j < n; j++) {
            int valor_aleatorio = rand() % 100000;
            vetor_busca[j] = valor_aleatorio;
            vetor_quick[j] = valor_aleatorio; // Cópia exata para garantir boa comparação
        }

        // Buscar um valor negativo (pior caso: não existe no vetor)
        // Repetir 1000 vezes para o processador registrar um tempo bom
        clock_t tempo_inicio = clock();
        int repeticoes = 1000;
        for(int k = 0; k < repeticoes; k++) {
            buscaSequencial(vetor_busca, n, -1); 
        }
        clock_t tempo_fim = clock();
        double tempo_busca = (((double)(tempo_fim - tempo_inicio)) / CLOCKS_PER_SEC) / repeticoes;

        // Medição do Quicksort
        tempo_inicio = clock();
        quicksort(vetor_quick, 0, n - 1);
        tempo_fim = clock();
        double tempo_quick = ((double)(tempo_fim - tempo_inicio)) / CLOCKS_PER_SEC;

        // Gravando os dados
        fprintf(arquivo_csv, "%d,%f,%f\n", n, tempo_busca, tempo_quick);
        printf("Processado n = %d\n", n);

        free(vetor_busca);
        free(vetor_quick);
    }

    fclose(arquivo_csv);
    printf("Dados exportados com sucesso para 'resultados.csv'.\n");
    return 0;
}