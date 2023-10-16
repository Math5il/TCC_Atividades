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
        printf("Falha na alocação de memória.\n");
        exit(1);
    }
    return veiculos;
}

void preencherVetor(struct Veiculo *veiculos, int n) {
    for (int i = 0; i < n; i++) {
        printf("Digite o número do chassi do veículo %d: ", i + 1);
        scanf("%s", veiculos[i].chassi);
        getchar();

        printf("Digite a marca do veículo %d: ", i + 1);
        fgets(veiculos[i].marca, sizeof(veiculos[i].marca), stdin);
        veiculos[i].marca[strcspn(veiculos[i].marca, "\n")] = '\0'; // Remover o '\n'

        printf("Digite o modelo do veículo %d: ", i + 1);
        fgets(veiculos[i].modelo, sizeof(veiculos[i].modelo), stdin);
        veiculos[i].modelo[strcspn(veiculos[i].modelo, "\n")] = '\0'; // Remover o '\n'

        printf("Digite o preço do veículo %d: ", i + 1);
        scanf("%lf", &veiculos[i].preco);
        getchar(); // Consumir o caractere de nova linha pendente no buffer
    }
}

void imprimirVetor(struct Veiculo *veiculos, int n) {
    printf("Veículos:\n");
    for (int i = 0; i < n; i++) {
        printf("Chassi: %s\n", veiculos[i].chassi);
        printf("Marca: %s\n", veiculos[i].marca);
        printf("Modelo: %s\n", veiculos[i].modelo);
        printf("Preço: %.2lf\n", veiculos[i].preco);
        printf("\n");
    }
}

int main() {
    int n;
    printf("Digite o número de veículos: ");
    scanf("%d", &n);
    getchar(); // Consumir o caractere de nova linha pendente no buffer

    // Alocação de memória para o vetor de estruturas Veículo
    struct Veiculo *veiculos = alocarMemoria(n);

    // Preenchimento do vetor de estruturas Veículo com dados do usuário
    preencherVetor(veiculos, n);

    // Impressão do vetor de estruturas Veículo
    imprimirVetor(veiculos, n);

    // Realocação de memória para um tamanho maior
    int novo_tamanho = n + 5;
    veiculos = (struct Veiculo *)realloc(veiculos, novo_tamanho * sizeof(struct Veiculo));
    if (veiculos == NULL) {
        printf("Falha na realocação de memória.\n");
        return 1;
    }

    // Preenchimento dos elementos adicionais após a realocação
    preencherVetor(veiculos + n, novo_tamanho - n);

    // Impressão do vetor de estruturas Veículo após a realocação
    imprimirVetor(veiculos, novo_tamanho);

    // Liberar a memória alocada
    free(veiculos);

    return 0;
}
