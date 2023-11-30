#include <stdio.h>
#include <string.h>

int afd(char *str) {
    int state = 0; // estado inicial

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '0') {
            if (state == 0)
                state = 1;
            else if (state == 1)
                state = 2;
        }
        else if (str[i] == '1') {
            if (state == 1)
                state = 1;
            else if (state == 2)
                state = 2;
        }
    }

    if (state == 2)
        return 1; // Aceita a palavra
    else
        return 0; // N�o aceita a palavra
}

int main() {
    char str[100];
    printf("Digite a palavra: ");
    scanf("%s", str);

    if (afd(str))
        printf("A palavra '%s' � aceita.\n", str);
    else
        printf("A palavra '%s' nao � aceita.\n", str);

    return 0;
}
