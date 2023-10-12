#include <stdio.h>

void lerSequencia(int sequencia[], int tamanho) {
    printf("Digite a sequência de números naturais:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &sequencia[i]);
    }
}

void apresentarSequencia(int sequencia[], int tamanho) {
    printf("Sequência digitada:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", sequencia[i]);
    }
    printf("\n");
}

void salvarSequenciaEmArquivo(int sequencia[], int tamanho, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    for (int i = 0; i < tamanho; i++) {
        fprintf(arquivo, "%d ", sequencia[i]);
    }

    fclose(arquivo);
    printf("Sequência salva em %s.\n", nomeArquivo);
}

int main() {
    int tamanho1, tamanho2;

    printf("Digite o tamanho da primeira sequência: ");
    scanf("%d", &tamanho1);

    printf("Digite o tamanho da segunda sequência: ");
    scanf("%d", &tamanho2);

    int sequencia1[tamanho1];
    int sequencia2[tamanho2];

    lerSequencia(sequencia1, tamanho1);
    lerSequencia(sequencia2, tamanho2);

    apresentarSequencia(sequencia1, tamanho1);
    apresentarSequencia(sequencia2, tamanho2);

    salvarSequenciaEmArquivo(sequencia1, tamanho1, "sequencia1.txt");
    salvarSequenciaEmArquivo(sequencia2, tamanho2, "sequencia2.txt");

    return 0;
}
