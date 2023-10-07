#include <stdio.h>

int main() {

    int anoNascimento, anoAtual;

    printf("Digite seu ano de nascimento: ");
    scanf("%d", &anoNascimento);

    printf("Digite o ano atual: ");
    scanf("%d", &anoAtual);

    float idadeAtual = (anoAtual - anoNascimento);

    float idadeFuturo = (2050 - anoNascimento);

    // Apresenta o resultado na tela
    printf("A idade atual é: %2.f\n", idadeAtual);

    printf("A idade em 2050 será: %2.f\n", idadeFuturo);


    return 0;
}
