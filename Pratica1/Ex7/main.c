#include <stdio.h>

int main() {
    // Declaração das variáveis
    float salario_minimo, salario_funcionario, quantidade_salarios;

    // Solicita ao usuário que insira o valor do salário mínimo
    printf("Digite o valor do salário mínimo: ");
    scanf("%f", &salario_minimo);

    // Solicita ao usuário que insira o valor do salário do funcionário
    printf("Digite o valor do salário do funcionário: ");
    scanf("%f", &salario_funcionario);

    // Calcula a quantidade de salários mínimos que o funcionário recebe
    quantidade_salarios = salario_funcionario / salario_minimo;

    // Apresenta o resultado na tela
    printf("O funcionário recebe %.2f salários mínimos.\n", quantidade_salarios);

    return 0;
}
