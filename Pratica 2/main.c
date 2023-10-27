#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Função para ler uma sequência de números naturais a partir do teclado
void ler_sequencia(int sequencia[], int *n) {
    printf("Informe o tamanho da sequência: ");
    scanf("%d", n);

    printf("Informe os elementos da sequência:\n");
    for (int i = 0; i < *n; i++) {
        scanf("%d", &sequencia[i]);
    }
}

// Função para imprimir uma sequência
void imprimir_sequencia(int sequencia[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", sequencia[i]);
    }
    printf("\n");
}

// Função para armazenar uma sequência em um arquivo
void armazenar_sequencia_em_arquivo(int sequencia[], int n, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Não foi possível criar o arquivo.\n");
        exit(1);
    }

    fprintf(file, "%d\n", n);
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d ", sequencia[i]);
    }

    fclose(file);
}

// Função para ler uma sequência de números naturais de um arquivo
void ler_sequencia_do_arquivo(int sequencia[], int *n, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("O arquivo não existe.\n");
        exit(1);
    }

    fscanf(file, "%d", n);
    for (int i = 0; i < *n; i++) {
        fscanf(file, "%d", &sequencia[i]);
    }

    fclose(file);
}

// Função para remover elementos duplicados de uma sequência
void remover_duplicados(int sequencia[], int *n) {
    int temp[*n];
    int novoTamanho = 0;

    for (int i = 0; i < *n; i++) {
        bool duplicado = false;
        for (int j = 0; j < novoTamanho; j++) {
            if (sequencia[i] == temp[j]) {
                duplicado = true;
                break;
            }
        }
        if (!duplicado) {
            temp[novoTamanho++] = sequencia[i];
        }
    }

    for (int i = 0; i < novoTamanho; i++) {
        sequencia[i] = temp[i];
    }
    *n = novoTamanho;
}
// Função para calcular e imprimir a interseção de dois conjuntos
void calcular_e_imprimir_intersecao(int conjuntoA[], int nA, int conjuntoB[], int nB) {
    int intersecao[MAX_SIZE];
    int nIntersecao = 0;

    for (int i = 0; i < nA; i++) {
        for (int j = 0; j < nB; j++) {
            if (conjuntoA[i] == conjuntoB[j]) {
                intersecao[nIntersecao++] = conjuntoA[i];
                break;
            }
        }
    }

    printf("Interseção de A e B: ");
    imprimir_sequencia(intersecao, nIntersecao);

    armazenar_sequencia_em_arquivo(intersecao, nIntersecao, "sequences.txt");
}

int main() {
    int sequencia1[MAX_SIZE], sequencia2[MAX_SIZE];
    int n1, n2;

    ler_sequencia(sequencia1, &n1);
    ler_sequencia(sequencia2, &n2);

    armazenar_sequencia_em_arquivo(sequencia1, n1, "sequencia1.txt");
    armazenar_sequencia_em_arquivo(sequencia2, n2, "sequencia2.txt");

    printf("Sequências lidas e armazenadas em arquivos.\n");

    calcular_e_imprimir_intersecao(sequencia1, n1, sequencia2, n2);

    return 0;
}



