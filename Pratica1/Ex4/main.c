#include <stdio.h>

int main() {
    // Declaração das variáveis
    float salario, novo_salario;

    // Solicita ao usuário que insira o salário atual
    printf("Digite o salário atual do funcionário: ");
    scanf("%f", &salario);

    // Calcula o novo salário com um aumento de 25%
    novo_salario = salario + (salario * 0.25);

    // Apresenta o resultado na tela
    printf("O novo salário do funcionário com aumento de 25%% é: %.2f\n", novo_salario);

    return 0;
}
