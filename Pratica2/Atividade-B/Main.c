#include <stdio.h>


int elementoNoVetor(int vetor[], int tamanho, int elemento) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == elemento) {
            return 1; // Elemento encontrado no vetor
        }
    }
    return 0; 
}


void gerarConjuntoA(char *nome_arquivo, int conjuntoA[], int *tamanhoA) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo %s.\n", nome_arquivo);
        return;
    }

    int elemento;
    *tamanhoA = 0;

    while (fscanf(arquivo, "%d", &elemento) == 1) {
        if (!elementoNoVetor(conjuntoA, *tamanhoA, elemento)) {
            conjuntoA[*tamanhoA] = elemento;
            (*tamanhoA)++;
        }
    }

    fclose(arquivo);
}


void gerarConjuntoB(char *nome_arquivo, int conjuntoB[], int *tamanhoB) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo %s.\n", nome_arquivo);
        return;
    }

    int elemento;
    *tamanhoB = 0;


    while (fscanf(arquivo, "%d", &elemento) == 1);

    while (fscanf(arquivo, "%d", &elemento) == 1) {
        if (!elementoNoVetor(conjuntoB, *tamanhoB, elemento)) {
            conjuntoB[*tamanhoB] = elemento;
            (*tamanhoB)++;
        }
    }

    fclose(arquivo);
}


void exibirConjunto(int conjunto[], int tamanho, char *nome_conjunto) {
    printf("%s: { ", nome_conjunto);
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", conjunto[i]);
    }
    printf("}\n");
}


void armazenarConjuntoNoArquivo(char *nome_arquivo, int conjunto[], int tamanho) {
    FILE *arquivo = fopen(nome_arquivo, "a");
    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo %s.\n", nome_arquivo);
        return;
    }

    for (int i = 0; i < tamanho; i++) {
        fprintf(arquivo, "%d ", conjunto[i]);
    }
    fprintf(arquivo, "\n");

    fclose(arquivo);
}

int main() {
    char nome_arquivo[] = "sequencias.txt";
    int conjuntoA[100]; 
    int tamanhoA;
    int conjuntoB[100]; 
    int tamanhoB;

    gerarConjuntoA(nome_arquivo, conjuntoA, &tamanhoA);
    gerarConjuntoB(nome_arquivo, conjuntoB, &tamanhoB);

    exibirConjunto(conjuntoA, tamanhoA, "Conjunto A");
    exibirConjunto(conjuntoB, tamanhoB, "Conjunto B");

    armazenarConjuntoNoArquivo(nome_arquivo, conjuntoA, tamanhoA);
    armazenarConjuntoNoArquivo(nome_arquivo, conjuntoB, tamanhoB);

    return 0;
}
