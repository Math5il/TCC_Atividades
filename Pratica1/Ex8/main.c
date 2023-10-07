#include <stdio.h>

int main() {
    float peso_atual, novo_peso;

    printf("Digite o peso atual da pessoa (em quilogramas): ");
    scanf("%f", &peso_atual);

    novo_peso = peso_atual * 1.15; // 15% de aumento

    printf("Se a pessoa engordar 15%%, o novo peso será de %.2f quilogramas.\n", novo_peso);

    novo_peso = peso_atual * 0.80; // 20% de diminuição

    printf("Se a pessoa emagrecer 20%%, o novo peso será de %.2f quilogramas.\n", novo_peso);

    return 0;
}
