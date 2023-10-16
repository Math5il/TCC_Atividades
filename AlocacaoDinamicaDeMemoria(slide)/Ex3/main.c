#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Veiculo {
    char chassi[20];
    char marca[50];
    char modelo[50];
    double preco;
};

struct Veiculo *alocarMemoria(int n) {
    struct Veiculo *veiculos = (struct Veiculo *)malloc(n * sizeof(struct Veiculo));
    if (veiculos == NULL) {
        printf("Falha na aloca��o de mem�ria.\n");
        exit(1);
    }
    return veiculos;
}

void preencherVetor(struct Veiculo *veiculos, int n) {
    for (int i = 0; i < n; i++) {
        printf("Digite o n�mero do chassi do ve�culo %d: ", i + 1);
        scanf("%s", veiculos[i].chassi);
        getchar();

        printf("Digite a marca do ve�culo %d: ", i + 1);
        fgets(veiculos[i].marca, sizeof(veiculos[i].marca), stdin);
        veiculos[i].marca[strcspn(veiculos[i].marca, "\n")] = '\0'; // Remover o '\n'

        printf("Digite o modelo do ve�culo %d: ", i + 1);
        fgets(veiculos[i].modelo, sizeof(veiculos[i].modelo), stdin);
        veiculos[i].modelo[strcspn(veiculos[i].modelo, "\n")] = '\0'; // Remover o '\n'

        printf("Digite o pre�o do ve�culo %d: ", i + 1);
        scanf("%lf", &veiculos[i].preco);
        getchar(); // Consumir o caractere de nova linha pendente no buffer
    }
}

void imprimirVetor(struct Veiculo *veiculos, int n) {
    printf("Ve�culos:\n");
    for (int i = 0; i < n; i++) {
        printf("Chassi: %s\n", veiculos[i].chassi);
        printf("Marca: %s\n", veiculos[i].marca);
        printf("Modelo: %s\n", veiculos[i].modelo);
        printf("Pre�o: %.2lf\n", veiculos[i].preco);
        printf("\n");
    }
}

int main() {
    int n;
    printf("Digite o n�mero de ve�culos: ");
    scanf("%d", &n);
    getchar(); // Consumir o caractere de nova linha pendente no buffer

    // Aloca��o de mem�ria para o vetor de estruturas Ve�culo
    struct Veiculo *veiculos = alocarMemoria(n);

    // Preenchimento do vetor de estruturas Ve�culo com dados do usu�rio
    preencherVetor(veiculos, n);

    // Impress�o do vetor de estruturas Ve�culo
    imprimirVetor(veiculos, n);

    // Realoca��o de mem�ria para um tamanho maior
    int novo_tamanho = n + 5;
    veiculos = (struct Veiculo *)realloc(veiculos, novo_tamanho * sizeof(struct Veiculo));
    if (veiculos == NULL) {
        printf("Falha na realoca��o de mem�ria.\n");
        return 1;
    }

    // Preenchimento dos elementos adicionais ap�s a realoca��o
    preencherVetor(veiculos + n, novo_tamanho - n);

    // Impress�o do vetor de estruturas Ve�culo ap�s a realoca��o
    imprimirVetor(veiculos, novo_tamanho);

    // Liberar a mem�ria alocada
    free(veiculos);

    return 0;
}
