#include <stdio.h>

int main() {
    // Declara��o das vari�veis
    float salario, novo_salario;

    // Solicita ao usu�rio que insira o sal�rio atual
    printf("Digite o sal�rio atual do funcion�rio: ");
    scanf("%f", &salario);

    // Calcula o novo sal�rio com um aumento de 25%
    novo_salario = salario + (salario * 0.25);

    // Apresenta o resultado na tela
    printf("O novo sal�rio do funcion�rio com aumento de 25%% �: %.2f\n", novo_salario);

    return 0;
}
