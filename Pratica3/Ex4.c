#include <stdio.h>

int sucessor(int x) {
    return x + 1;
}

int main() {
    int i;
    
    printf("Digite o valor de 'i': ");
    scanf("%d", &i);

    if (i < 0) {
        printf("O valor de 'i' deve ser não negativo.\n");
        return 1;
    }

    printf("Sequência MQ para i = %d:\n", i);

    for (int n = 0; n <= i; n++) {
        int m = 1;

        printf("[%d, %d] ", n, m);

        while (m < i + 1) {
            m = sucessor(m);
            printf("[%d, %d] ", n, m);
        }

        printf("\n");
    }

    return 0;
}
