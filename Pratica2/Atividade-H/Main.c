#include <stdio.h>

void calcularDiferencaEArmazenar(int A[], int tamA, int B[], int tamB, const char *arquivo) {
    FILE *arquivoSaida = fopen(arquivo, "a");  // Abre o arquivo em modo de adição para não sobrescrever o conteúdo
    if (arquivoSaida == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    fprintf(arquivoSaida, "Diferenca A - B: ");

    for (int i = 0; i < tamA; i++) {
        int pertenceAeNaoB = 1;

        for (int j = 0; j < tamB; j++) {
            if (A[i] == B[j]) {
                pertenceAeNaoB = 0;
                break;
            }
        }

        if (pertenceAeNaoB) {
            fprintf(arquivoSaida, "%d ", A[i]);
        }
    }

    fprintf(arquivoSaida, "\n");

    fclose(arquivoSaida);

    printf("Diferenca calculada e armazenada no arquivo.\n");
}

int main() {
    int A[] = {1, 2, 3, 4, 5};
    int tamA = 5;
    int B[] = {3, 4, 5, 6, 7};
    int tamB = 5;

    calcularDiferencaEArmazenar(A, tamA, B, tamB, "conjuntos.txt");

    return 0;
}
