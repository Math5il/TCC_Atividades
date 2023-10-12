#include <stdio.h>

void calcularProdutoCartesianoBxA(int A[], int tamA, int B[], int tamB, const char *arquivo) {
    FILE *arquivoSaida = fopen(arquivo, "a");
    if (arquivoSaida == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    fprintf(arquivoSaida, "Produto Cartesiano B x A:\n");

    for (int i = 0; i < tamB; i++) {
        for (int j = 0; j < tamA; j++) {
            fprintf(arquivoSaida, "(%d, %d) ", B[i], A[j]);
        }
        fprintf(arquivoSaida, "\n");
    }

    fclose(arquivoSaida);

    printf("Produto cartesiano calculado e armazenado no arquivo.\n");
}

int main() {
    int A[] = {1, 2, 3};
    int tamA = 3;
    int B[] = {10, 20};
    int tamB = 2;

    calcularProdutoCartesianoBxA(A, tamA, B, tamB, "conjuntos.txt");

    return 0;
}
