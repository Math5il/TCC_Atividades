#include <stdio.h>

void calcularProdutoCartesianoEArmazenar(int A[], int tamA, int B[], int tamB, const char *arquivo) {
    FILE *arquivoSaida = fopen(arquivo, "a");
    if (arquivoSaida == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    fprintf(arquivoSaida, "Produto Cartesiano A x B:\n");

    for (int i = 0; i < tamA; i++) {
        for (int j = 0; j < tamB; j++) {
            fprintf(arquivoSaida, "(%d, %d) ", A[i], B[j]);
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

    calcularProdutoCartesianoEArmazenar(A, tamA, B, tamB, "conjuntos.txt");

    return 0;
}
