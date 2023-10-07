#include <stdio.h>

int main() {
    // Declaração da variável para armazenar a temperatura em Celsius
    float temperatura_celsius, temperatura_fahrenheit;

    // Solicita ao usuário que insira a temperatura em Celsius
    printf("Digite a temperatura em graus Celsius: ");
    scanf("%f", &temperatura_celsius);

    // Calcula a temperatura em Fahrenheit usando a fórmula
    temperatura_fahrenheit = (temperatura_celsius * 1.8) + 32;

    // Apresenta o resultado na tela
    printf("A temperatura em graus Fahrenheit é: %.2f\n", temperatura_fahrenheit);

    return 0;
}
