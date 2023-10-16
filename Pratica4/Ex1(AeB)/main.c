#include <stdio.h>
#include <string.h>

int tamanhoRecursivo(char *str) {
    if (*str == '\0') {
        return 0;
    }
    return 1 + tamanhoRecursivo(str + 1);
}

void inverteRecursivo(char *str, char *output, int *index) {
    if (*str == '\0') {
        return;
    }
    inverteRecursivo(str + 1, output, index);
    output[(*index)++] = *str;
}

int main() {
    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }

    char string[1000];
    fscanf(inputFile, "%s", string);
    fclose(inputFile);

    FILE *outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        return 1;
    }


    int tamanho = tamanhoRecursivo(string);
    fprintf(outputFile, "Tamanho: %d\n", tamanho);


    char reversed[1000];
    int index = 0;
    inverteRecursivo(string, reversed, &index);
    reversed[index] = '\0';
    fprintf(outputFile, "Reverso: %s\n", reversed);

    fclose(outputFile);

    return 0;
}
