#include <stdio.h>
#include <string.h>

// Definição dos estados
enum State { q0, q1 };

// Função para verificar se a palavra é aceita
int isAccepted(char *input) {
  enum State currentState = q0;

  while (*input != '\0') {
    char symbol = *input;

    switch (currentState) {
    case q0:
      if (symbol == '0')
        currentState = q1;
      else if (symbol == '1')
        currentState = q1;
      break;
    case q1:
      if (symbol == '0')
        currentState = q0;
      else if (symbol == '1')
        currentState = q0;
      break;
    }

    input++;
  }

  return currentState == q0;
}

int main() {
  // Exemplos de uso

  char palavra[100] = "";
  char word1[100] = ""; // Palavra vazia

  printf("Digite uma string: ");
  scanf("%s", &palavra);

  strcpy(word1, palavra);

  if (isAccepted(word1))
    printf("%s aceita\n", word1);
  else
    printf("%s rejeitada\n", word1);

  return 0;
}
