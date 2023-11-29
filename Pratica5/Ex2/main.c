#include <stdio.h>
#include <string.h>

// Função para verificar se a cadeia de entrada pertence à linguagem
int verificaCadeia(char *cadeia) {
    int estado = 0; // Estado inicial q0

    for (int i = 0; cadeia[i] != '\0'; i++) {
        if (estado == 0 && cadeia[i] == 'a') {
            estado = 1; // Vai para q1 após ler 'a' sem 'a' anterior
        } else if (estado == 1 && cadeia[i] == 'a') {
            return 0; // Rejeita se houver 'aa' consecutivos
        } else if (cadeia[i] == 'b') {
            estado = 0; // Permanece em q0 após ler 'b'
        }
    }

    return 1; // Aceita se não tiver 'aa' consecutivos em nenhum momento
}

int main() {
    char cadeia[100]; // Definindo um buffer para a cadeia
    printf("Digite a cadeia a ser verificada: ");
    scanf("%s", cadeia);

    if (verificaCadeia(cadeia)) {
        printf("A cadeia '%s' foi aceita pelo AFD.\n", cadeia);
    } else {
        printf("A cadeia '%s' foi rejeitada pelo AFD.\n", cadeia);
    }

    return 0;
}
