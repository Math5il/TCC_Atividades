#include <stdio.h>
#include <string.h>

// Função para verificar se a cadeia de entrada pertence à linguagem
int verificaCadeia(char *cadeia) {
    int estado = 0; // Estado inicial q0

    for (int i = 0; cadeia[i] != '\0'; i++) {
        switch (estado) {
            case 0: // q0
                if (cadeia[i] == '0') {
                    estado = 1; // Vai para q1
                } else {
                    return 0; // Rejeita se não começa com '0'
                }
                break;

            case 1: // q1
                if (cadeia[i] == '1') {
                    estado = 2; // Vai para q2
                } else {
                    return 0; // Rejeita se não segue com '1'
                }
                break;

            case 2: // q2
                if (cadeia[i] == '1') {
                    estado = 2; // Permanece em q2
                } else if (cadeia[i] == '0') {
                    estado = 3; // Vai para q3
                } else {
                    return 0; // Rejeita se não segue com '0' ou '1'
                }
                break;

            case 3: // q3
                if (cadeia[i] == '0' || cadeia[i] == '1') {
                    return 0; // Rejeita qualquer símbolo após q3
                }
                break;
        }
    }

    return estado == 3; // Retorna 1 se estiver no estado final q3
}

int main() {
    char cadeia[100]; // Definindo um buffer para a cadeia
    printf("Digite a cadeia(4 numeros, que podem ser 0 ou 1): ");
    scanf("%s", cadeia);

    if (verificaCadeia(cadeia)) {
        printf("A cadeia '%s' foi aceita pelo AFD.\n", cadeia);
    } else {
        printf("A cadeia '%s' foi rejeitada pelo AFD.\n", cadeia);
    }

    char cadeiaCorreta[] = "0110";

    if (verificaCadeia(cadeiaCorreta)) {
        printf("A cadeia '%s' foi aceita pelo AFD.\n", cadeiaCorreta);
    } else {
        printf("A cadeia '%s' foi rejeitada pelo AFD.\n", cadeiaCorreta);
    }

    return 0;
}

