#include <stdio.h>

int main() {
    // Declara��o das vari�veis
    float salario_minimo, salario_funcionario, quantidade_salarios;

    // Solicita ao usu�rio que insira o valor do sal�rio m�nimo
    printf("Digite o valor do sal�rio m�nimo: ");
    scanf("%f", &salario_minimo);

    // Solicita ao usu�rio que insira o valor do sal�rio do funcion�rio
    printf("Digite o valor do sal�rio do funcion�rio: ");
    scanf("%f", &salario_funcionario);

    // Calcula a quantidade de sal�rios m�nimos que o funcion�rio recebe
    quantidade_salarios = salario_funcionario / salario_minimo;

    // Apresenta o resultado na tela
    printf("O funcion�rio recebe %.2f sal�rios m�nimos.\n", quantidade_salarios);

    return 0;
}
