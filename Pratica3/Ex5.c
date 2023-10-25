#include <stdio.h>
#include <string.h>

#define MAX_CIDADES 4

typedef struct GrafoRotulado {
    int n;
    int matriz[MAX_CIDADES][MAX_CIDADES];
    char cidades[MAX_CIDADES][20];
} GrafoRotulado;

void inicializarGrafo(GrafoRotulado* grafo) {
    grafo->n = MAX_CIDADES;
    for (int i = 0; i < grafo->n; i++) {
        for (int j = 0; j < grafo->n; j++) {
            grafo->matriz[i][j] = 0;
        }
    }
    strcpy(grafo->cidades[0], "CidadeA");
    strcpy(grafo->cidades[1], "CidadeB");
    strcpy(grafo->cidades[2], "CidadeC");
    strcpy(grafo->cidades[3], "CidadeD");
}

void inserirDistancia(GrafoRotulado* grafo, char cidade1[20], char cidade2[20], int distancia) {
    int index1 = -1, index2 = -1;

    for (int i = 0; i < grafo->n; i++) {
        if (strcmp(grafo->cidades[i], cidade1) == 0) {
            index1 = i;
        }
        if (strcmp(grafo->cidades[i], cidade2) == 0) {
            index2 = i;
        }
    }

    if (index1 != -1 && index2 != -1) {
        grafo->matriz[index1][index2] = distancia;
        grafo->matriz[index2][index1] = distancia;
    }
}

int encontrarDistancia(GrafoRotulado* grafo, char cidade1[20], char cidade2[20]) {
    int index1 = -1, index2 = -1;

    for (int i = 0; i < grafo->n; i++) {
        if (strcmp(grafo->cidades[i], cidade1) == 0) {
            index1 = i;
        }
        if (strcmp(grafo->cidades[i], cidade2) == 0) {
            index2 = i;
        }
    }

    if (index1 != -1 && index2 != -1) {
        return grafo->matriz[index1][index2];
    }

    return 0;
}

int main() {
    GrafoRotulado grafo;
    inicializarGrafo(&grafo);

    inserirDistancia(&grafo, "CidadeA", "CidadeB", 10);
    inserirDistancia(&grafo, "CidadeA", "CidadeC", 15);
    inserirDistancia(&grafo, "CidadeB", "CidadeD", 5);

    printf("Distância entre CidadeB e CidadeC: %d\n", encontrarDistancia(&grafo, "CidadeB", "CidadeC"));

    return 0;
}
