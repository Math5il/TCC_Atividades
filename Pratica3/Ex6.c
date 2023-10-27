#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_CIDADES 4

int visited[MAX_CIDADES];

typedef struct GrafoRotulado {
  int n;
  int matriz[MAX_CIDADES][MAX_CIDADES];
  char cidades[MAX_CIDADES][20];
} GrafoRotulado;

void inicializarGrafo(GrafoRotulado *grafo) {
  grafo->n = MAX_CIDADES;
  for (int i = 0; i < grafo->n; i++) {
    for (int j = 0; j < grafo->n; j++) {
      grafo->matriz[i][j] = 0;
    }
  }
  strcpy(grafo->cidades[0], "CidadeA");
  strcpy(grafo->cidades[1], "CidadeB");
  strcpy(grafo->cidades[2], "CidadeC");
  strcpy(grafo->cidades[3], "CidadeD");
}

void inserirDistancia(GrafoRotulado *grafo, char cidade1[20], char cidade2[20],
                      int distancia) {
  int index1 = -1, index2 = -1;

  for (int i = 0; i < grafo->n; i++) {
    if (strcmp(grafo->cidades[i], cidade1) == 0) {
      index1 = i;
    }
    if (strcmp(grafo->cidades[i], cidade2) == 0) {
      index2 = i;
    }
  }

  if (index1 != -1 && index2 != -1) {
    grafo->matriz[index1][index2] = distancia;
  }
}

int encontrarDistanciaRecursiva(GrafoRotulado *grafo, int cidadeAtual,
                                int cidadeDestino) {
  if (cidadeAtual == cidadeDestino) {
    return 0;
  }

  int menorDistancia = INT_MAX;
  int distancia;

  for (int i = 0; i < grafo->n; i++) {
    if (grafo->matriz[cidadeAtual][i] != 0) {
      distancia = encontrarDistanciaRecursiva(grafo, i, cidadeDestino);
      if (distancia != INT_MAX) {
        distancia += grafo->matriz[cidadeAtual][i];
        if (distancia < menorDistancia) {
          menorDistancia = distancia;
        }
      }
    }
  }

  return menorDistancia;
}

int encontrarDistancia(GrafoRotulado *grafo, char cidade1[20],
                       char cidade2[20]) {
  int index1 = -1, index2 = -1;

  for (int i = 0; i < grafo->n; i++) {
    if (strcmp(grafo->cidades[i], cidade1) == 0) {
      index1 = i;
    }
    if (strcmp(grafo->cidades[i], cidade2) == 0) {
      index2 = i;
    }
  }

  if (index1 != -1 && index2 != -1) {
    int distancia = encontrarDistanciaRecursiva(grafo, index1, index2);
    if (distancia != INT_MAX) {
      return distancia;
    }
  }

  return -1;
}

bool temCicloRecursivo(GrafoRotulado *grafo, int cidadeAtual) {
  if (visited[cidadeAtual] == 1) {
    return true;
  }

  if (visited[cidadeAtual] == 2) {
    return false;
  }

  visited[cidadeAtual] = 1;

  for (int i = 0; i < grafo->n; i++) {
    if (grafo->matriz[cidadeAtual][i] != 0 && temCicloRecursivo(grafo, i)) {
      return true;
    }
  }

  visited[cidadeAtual] = 2;

  return false;
}

bool temCiclo(GrafoRotulado *grafo) {
  for (int i = 0; i < grafo->n; i++) {
    visited[i] = 0;
  }

  for (int i = 0; i < grafo->n; i++) {
    if (visited[i] == 0 && temCicloRecursivo(grafo, i)) {
      return true;
    }
  }

  return false;
}

int calcularGrauEntrada(GrafoRotulado *grafo, int index) {
  int grauEntrada = 0;
  for (int i = 0; i < grafo->n; i++) {
    if (grafo->matriz[i][index] != 0) {
      grauEntrada++;
    }
  }
  return grauEntrada;
}

int calcularGrauSaida(GrafoRotulado *grafo, int index) {
  int grauSaida = 0;
  for (int i = 0; i < grafo->n; i++) {
    if (grafo->matriz[index][i] != 0) {
      grauSaida++;
    }
  }
  return grauSaida;
}

int main() {
  GrafoRotulado grafo;
  inicializarGrafo(&grafo);

  inserirDistancia(&grafo, "CidadeA", "CidadeB", 10);
  inserirDistancia(&grafo, "CidadeA", "CidadeC", 15);
  inserirDistancia(&grafo, "CidadeB", "CidadeD", 5);
  inserirDistancia(&grafo, "CidadeD", "CidadeB", 5);

  printf("Distância entre CidadeB e CidadeC: %d\n",
         encontrarDistancia(&grafo, "CidadeA", "CidadeB"));

  // Calcular grau de entrada e saída para cada nó
  for (int i = 0; i < grafo.n; i++) {
    printf("Grau de entrada de %s: %d\n", grafo.cidades[i],
           calcularGrauEntrada(&grafo, i));
    printf("Grau de saída de %s: %d\n", grafo.cidades[i],
           calcularGrauSaida(&grafo, i));
  }

  if (temCiclo(&grafo)) {
    printf("O grafo possui ciclos.\n");
  } else {
    printf("O grafo não possui ciclos.\n");
  }

  return 0;
}
