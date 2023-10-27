#include <stdio.h>


int sucessor(int x) {
    return x + 1;
}


void generateMQ(int n, int m, int i) {
  
    if (n <= i) {
        printf("[%d, %d] ", n, m);
        if (m < i + 1) {
            generateMQ(n, sucessor(m), i);
        } else {
            n = sucessor(n);
            m = sucessor(n);
            printf("\n");
            generateMQ(n, m, i);
        }
    }
}

int main() {
    int i;
    printf("Digite o valor de 'i': ");
    scanf("%d", &i);

    if (i < 0) {
        printf("O valor de 'i' deve ser não negativo.\n");
    } else {
        printf("Sequência MQ para i = %d:\n", i);
        generateMQ(0, 1, i);
    }

    return 0;
}
