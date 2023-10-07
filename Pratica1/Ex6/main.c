#include <stdio.h>

int main() {
    // Declara��o da vari�vel para armazenar a temperatura em Celsius
    float temperatura_celsius, temperatura_fahrenheit;

    // Solicita ao usu�rio que insira a temperatura em Celsius
    printf("Digite a temperatura em graus Celsius: ");
    scanf("%f", &temperatura_celsius);

    // Calcula a temperatura em Fahrenheit usando a f�rmula
    temperatura_fahrenheit = (temperatura_celsius * 1.8) + 32;

    // Apresenta o resultado na tela
    printf("A temperatura em graus Fahrenheit �: %.2f\n", temperatura_fahrenheit);

    return 0;
}
