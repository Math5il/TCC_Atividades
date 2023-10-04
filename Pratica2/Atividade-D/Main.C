#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void calcularConjuntoPotencia(int conjunto[], int tamanho, FILE *arquivo) {
  int totalSubconjuntos = pow(2, tamanho);
  for (int i = 0; i < totalSubconjuntos; i++) {
    fprintf(arquivo, " { ");
    for (int j = 0; j < tamanho; j++) {
      if (i & (1 << j)) {
        printf("%d ", conjunto[j]);
        fprintf(arquivo, "%d ", conjunto[j]);
      }
    }
    printf("\n");
    fprintf(arquivo, "} \n");
  }
}

int main() {
  int conjuntoA[] = {1, 2}; // Exemplo de conjunto A
  int tamanhoA = sizeof(conjuntoA) / sizeof(conjuntoA[0]);

  int conjuntoB[] = {3, 4, 5}; // Exemplo de conjunto B
  int tamanhoB = sizeof(conjuntoB) / sizeof(conjuntoB[0]);

  FILE *arquivo = fopen("conjunto_potencia.txt", "w");

  if (arquivo == NULL) {
    fprintf(stderr, "Erro ao abrir o arquivo.");
    return 1;
  }

  printf("Conjunto potência de A:\n");
  fprintf(arquivo, "Conjunto potência de A \n\n");
  calcularConjuntoPotencia(conjuntoA, tamanhoA, arquivo);

  fprintf(arquivo, "\n\n");

  printf("Conjunto potência de B:\n");
  fprintf(arquivo, "Conjunto potência de B \n\n");
  calcularConjuntoPotencia(conjuntoB, tamanhoB, arquivo);

  fclose(arquivo);
  return 0;
}