#include <stdio.h>

void calcularIntersecaoEArmazenar(int A[], int tamA, int B[], int tamB, const char *arquivo) {
    int intersecao[100];
    int tamIntersecao = 0;

    for (int i = 0; i < tamA; i++) {
        for (int j = 0; j < tamB; j++) {
            if (A[i] == B[j]) {
                intersecao[tamIntersecao] = A[i];
                tamIntersecao++;
                break;
            }
        }
    }

    FILE *arquivoSaida = fopen(arquivo, "w");
    if (arquivoSaida == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    fprintf(arquivoSaida, "Interseção:\n");
    for (int i = 0; i < tamIntersecao; i++) {
        fprintf(arquivoSaida, "%d ", intersecao[i]);
    }

    fclose(arquivoSaida);

    printf("Interseção calculada e armazenada no arquivo.\n");
}

int main() {
    int A[] = {1, 2, 3, 4, 5};
    int tamA = 5;
    int B[] = {3, 4, 5, 6, 7};
    int tamB = 5;

    calcularIntersecaoEArmazenar(A, tamA, B, tamB, "conjuntos.txt");

    return 0;
}
