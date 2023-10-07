#include <stdio.h>
#include <math.h> // Importa a biblioteca math para usar a fun��o sqrt

int main() {
    // Declara��o das vari�veis
    float cateto1, cateto2, hipotenusa;

    // Solicita ao usu�rio que insira os valores dos catetos
    printf("Digite o valor do primeiro cateto: ");
    scanf("%f", &cateto1);

    printf("Digite o valor do segundo cateto: ");
    scanf("%f", &cateto2);

    // Calcula o valor da hipotenusa usando o Teorema de Pit�goras
    hipotenusa = sqrt(cateto1 * cateto1 + cateto2 * cateto2);

    // Apresenta o resultado na tela
    printf("O valor da hipotenusa �: %.2f\n", hipotenusa);

    return 0;
}
