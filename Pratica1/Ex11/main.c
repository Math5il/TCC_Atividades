#include <stdio.h>

int main() {
    int numero;
    printf("Digite um n�mero para calcular a tabuada: ");
    scanf("%d", &numero);
    printf("Tabuada de multiplica��o para %d:\n", numero);

    for (int i = 1; i <= 10; i++) {
        int resultado = numero * i;
        printf("%d x %d = %d\n", numero, i, resultado);
    }

    return 0;
}
