#include <stdio.h>
#include <math.h>
int main() {
    // Declara��o das vari�veis
    float raio;
    const float pi = 3.14159265359;
    printf("Digite o raio da esfera: ");
    scanf("%f", &raio);

    float comprimento = 2 * pi * raio;

    float area = pi * raio * raio;

    float volume = (3.0 / 4.0) * pi * pow(raio, 3);

    printf("O comprimento da esfera �: %.2f\n", comprimento);
    printf("A �rea da esfera �: %.2f\n", area);
    printf("O volume da esfera �: %.2f\n", volume);

    return 0;
}
