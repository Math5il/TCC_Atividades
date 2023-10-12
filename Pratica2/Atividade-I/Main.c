#include <stdio.h>

void calcularDiferencaBmenosA(int A[], int tamA, int B[], int tamB, const char *arquivo) {
    FILE *arquivoSaida = fopen(arquivo, "a");
    if (arquivoSaida == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    fprintf(arquivoSaida, "Diferenca B - A: ");

    for (int i = 0; i < tamB; i++) {
        int pertenceBeNaoA = 1;

        for (int j = 0; j < tamA; j++) {
            if (B[i] == A[j]) {
                pertenceBeNaoA = 0;
                break;
            }
        }

        if (pertenceBeNaoA) {
            fprintf(arquivoSaida, "%d ", B[i]);
        }
    }

    fprintf(arquivoSaida, "\n");

    fclose(arquivoSaida);

    printf("Diferenca B - A calculada e armazenada no arquivo.\n");
}

int main() {
    int A[] = {1, 2, 3, 4, 5};
    int tamA = 5;
    int B[] = {3, 4, 5, 6, 7};
    int tamB = 5;

    calcularDiferencaBmenosA(A, tamA, B, tamB, "conjuntos.txt");

    return 0;
}
