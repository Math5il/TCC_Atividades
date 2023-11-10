#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Questão A

void lerSequencia(int sequencia[], int tamanho) {
    printf("Digite a sequência de números naturais:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &sequencia[i]);
    }
}

void apresentarSequencia(int sequencia[], int tamanho) {
    printf("Sequência digitada:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", sequencia[i]);
    }
    printf("\n");
}

void salvarSequenciaEmArquivo(int sequencia[], int tamanho, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    for (int i = 0; i < tamanho; i++) {
        fprintf(arquivo, "%d ", sequencia[i]);
    }

    fclose(arquivo);
    printf("Sequência salva em %s.\n", nomeArquivo);
}

//Quetão B

void lerSequenciasDoArquivo(const char *nomeArquivo, int vetorA[], int *tamanhoA, int vetorB[], int *tamanhoB) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    // Ler tamanho e elementos do primeiro vetor
    fscanf(arquivo, "%d", tamanhoA);
    for (int i = 0; i < *tamanhoA; i++) {
        fscanf(arquivo, "%d", &vetorA[i]);
    }

    // Ler tamanho e elementos do segundo vetor
    fscanf(arquivo, "%d", tamanhoB);
    for (int i = 0; i < *tamanhoB; i++) {
        fscanf(arquivo, "%d", &vetorB[i]);
    }

    fclose(arquivo);
}

//Questão C


void lerSequenciasDoArquivoC(const char *nomeArquivo, int conjuntoA[], int *tamanhoA, int conjuntoB[], int *tamanhoB) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", nomeArquivo);
        return;
    }

    int elemento;
    *tamanhoA = 0;
    *tamanhoB = 0;

    // Lê elementos para o conjunto A até encontrar -1
    while (fscanf(arquivo, "%d", &elemento) == 1 && elemento != -1) {
        conjuntoA[*tamanhoA] = elemento;
        (*tamanhoA)++;
    }

    // Lê elementos para o conjunto B até o final do arquivo
    while (fscanf(arquivo, "%d", &elemento) == 1) {
        conjuntoB[*tamanhoB] = elemento;
        (*tamanhoB)++;
    }

    fclose(arquivo);
}

//Questão D

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

//Questão E

void GerarConjuntosProprios(int conjunto[], int size, int index, int subset[], int subsetIndex, FILE* arquivo) {
    if (index == size) {
        if (subsetIndex > 0 && subsetIndex < size) {
            fprintf(arquivo, "{ ");
            for (int i = 0; i < subsetIndex; ++i) {
                fprintf(arquivo, "%d ", subset[i]);
            }
            fprintf(arquivo, "}\n");
        }
        return;
    }

    // Incluir o elemento atual no subconjunto e chamar recursivamente para o próximo elemento
    subset[subsetIndex] = conjunto[index];
    GerarConjuntosProprios(conjunto, size, index + 1, subset, subsetIndex + 1, arquivo);

    // Excluir o elemento atual do subconjunto e chamar recursivamente para o próximo elemento
    GerarConjuntosProprios(conjunto, size, index + 1, subset, subsetIndex, arquivo);
}

//Questão F

bool contains(int array[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (array[i] == element) {
            return true;
        }
    }
    return false;
}

void calcularUniao(int conjuntoA[], int tamanhoA, int conjuntoB[], int tamanhoB, int uniao[], int *tamanhoUniao) {
    int indexUniao = 0;

    for (int i = 0; i < tamanhoA; i++) {
        if (!contains(uniao, indexUniao, conjuntoA[i])) {
            uniao[indexUniao++] = conjuntoA[i];
        }
    }

    for (int i = 0; i < tamanhoB; i++) {
        if (!contains(uniao, indexUniao, conjuntoB[i])) {
            uniao[indexUniao++] = conjuntoB[i];
        }
    }

    *tamanhoUniao = indexUniao;
}

//Questão G

void calcularIntersecaoEArmazenar(int A[], int tamA, int B[], int tamB, const char *arquivo) {
    int intersecao[100];
    int tamIntersecao = 0;

    for (int i = 0; i < tamA; i++) {
        for (int j = 0; j < tamB; j++) {
            if (A[i] == B[j]) {
                intersecao[tamIntersecao] = A[i];
                tamIntersecao++;
                break;
            }
        }
    }

    FILE *arquivoSaida = fopen(arquivo, "w");
    if (arquivoSaida == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    fprintf(arquivoSaida, "Interseção:\n");
    for (int i = 0; i < tamIntersecao; i++) {
        fprintf(arquivoSaida, "%d ", intersecao[i]);
    }

    fclose(arquivoSaida);

    printf("Interseção calculada e armazenada no arquivo.\n");
}

//Questão H


void calcularDiferencaEArmazenar(int A[], int tamA, int B[], int tamB, const char *arquivo) {
    FILE *arquivoSaida = fopen(arquivo, "a");  // Abre o arquivo em modo de adição para não sobrescrever o conteúdo
    if (arquivoSaida == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    fprintf(arquivoSaida, "Diferenca A - B: ");

    for (int i = 0; i < tamA; i++) {
        int pertenceAeNaoB = 1;

        for (int j = 0; j < tamB; j++) {
            if (A[i] == B[j]) {
                pertenceAeNaoB = 0;
                break;
            }
        }

        if (pertenceAeNaoB) {
            fprintf(arquivoSaida, "%d ", A[i]);
        }
    }

    fprintf(arquivoSaida, "\n");

    fclose(arquivoSaida);

    printf("Diferenca calculada e armazenada no arquivo.\n");
}

//Questão I

void calcularDiferencaBmenosA(int A[], int tamA, int B[], int tamB, const char *arquivo) {
    FILE *arquivoSaida = fopen(arquivo, "a");
    if (arquivoSaida == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    fprintf(arquivoSaida, "Diferenca B - A: ");

    for (int i = 0; i < tamB; i++) {
        int pertenceBeNaoA = 1;

        for (int j = 0; j < tamA; j++) {
            if (B[i] == A[j]) {
                pertenceBeNaoA = 0;
                break;
            }
        }

        if (pertenceBeNaoA) {
            fprintf(arquivoSaida, "%d ", B[i]);
        }
    }

    fprintf(arquivoSaida, "\n");

    fclose(arquivoSaida);

    printf("Diferenca B - A calculada e armazenada no arquivo.\n");
}

//Questão J


void calcularProdutoCartesianoEArmazenar(int A[], int tamA, int B[], int tamB, const char *arquivo) {
    FILE *arquivoSaida = fopen(arquivo, "a");
    if (arquivoSaida == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    fprintf(arquivoSaida, "Produto Cartesiano A x B:\n");

    for (int i = 0; i < tamA; i++) {
        for (int j = 0; j < tamB; j++) {
            fprintf(arquivoSaida, "(%d, %d) ", A[i], B[j]);
        }
        fprintf(arquivoSaida, "\n");
    }

    fclose(arquivoSaida);

    printf("Produto cartesiano calculado e armazenado no arquivo.\n");
}

//Questão K

void calcularProdutoCartesianoBxA(int A[], int tamA, int B[], int tamB, const char *arquivo) {
    FILE *arquivoSaida = fopen(arquivo, "a");
    if (arquivoSaida == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    fprintf(arquivoSaida, "Produto Cartesiano B x A:\n");

    for (int i = 0; i < tamB; i++) {
        for (int j = 0; j < tamA; j++) {
            fprintf(arquivoSaida, "(%d, %d) ", B[i], A[j]);
        }
        fprintf(arquivoSaida, "\n");
    }

    fclose(arquivoSaida);

    printf("Produto cartesiano calculado e armazenado no arquivo.\n");
}

int main(void) {

  //Questão A

  int tamanho1, tamanho2;

  printf("Digite o tamanho da primeira sequência: ");
  scanf("%d", &tamanho1);

  printf("Digite o tamanho da segunda sequência: ");
  scanf("%d", &tamanho2);

  int sequencia1[tamanho1];
  int sequencia2[tamanho2];

  lerSequencia(sequencia1, tamanho1);
  lerSequencia(sequencia2, tamanho2);

  apresentarSequencia(sequencia1, tamanho1);
  apresentarSequencia(sequencia2, tamanho2);

  salvarSequenciaEmArquivo(sequencia1, tamanho1, "sequencia1.txt");
  salvarSequenciaEmArquivo(sequencia2, tamanho2, "sequencia2.txt");

  //Qeustão B

  int vetorA[100], tamanhoA5;
  int vetorB[100], tamanhoB5;

  lerSequenciasDoArquivo("sequencias.txt", vetorA, &tamanhoA5, vetorB, &tamanhoB5);

  printf("Primeira sequência lida do arquivo:\n");
  for (int i = 0; i < tamanhoA5; i++) {
      printf("%d ", vetorA[i]);
  }
  printf("\n");

  printf("Segunda sequência lida do arquivo:\n");
  for (int i = 0; i < tamanhoB5; i++) {
      printf("%d ", vetorB[i]);
  }
  printf("\n");

  //Questão C

  char nomeArquivo[] = "sequencias.txt";
    int conjuntoA1[100], tamanhoA9;
    int conjuntoB1[100], tamanhoB9;

    lerSequenciasDoArquivoC(nomeArquivo, conjuntoA1, &tamanhoA9, conjuntoB1, &tamanhoB9);

    printf("Conjunto A: ");
    for (int i = 0; i < tamanhoA9; i++) {
        printf("%d ", conjuntoA1[i]);
    }
    printf("\n");

    printf("Conjunto B: ");
    for (int i = 0; i < tamanhoB9; i++) {
        printf("%d ", conjuntoB1[i]);
    }
    printf("\n");



  //Questão D
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


  //Questão E

  int conjuntoA2[] = {1, 2};
  int conjuntoB2[] = {3, 4, 5};
  int tamanhoA2 = sizeof(conjuntoA) / sizeof(conjuntoA[0]);
  int tamanhoB2 = sizeof(conjuntoB) / sizeof(conjuntoB[0]);

  FILE* arquivo2 = fopen("conjuntos_proprios.txt", "w");
  if (arquivo2 == NULL) {
      printf("Erro ao abrir o arquivo.\n");
      return 1;
  }

  int subset[tamanhoA2];
  fprintf(arquivo2, "Conjuntos próprios de A:\n");
  GerarConjuntosProprios(conjuntoA2, tamanhoA2, 0, subset, 0, arquivo2);

  int subsetB[tamanhoB]; // Limpar o vetor subset para uso com o próximo conjunto
  fprintf(arquivo, "Conjuntos próprios de B:\n");
  GerarConjuntosProprios(conjuntoB2, tamanhoB2, 0, subsetB, 0, arquivo2);

  fclose(arquivo2);
  printf("Conjuntos próprios foram armazenados no arquivo 'conjuntos_proprios.txt'.\n");

  //Questão F

  int conjuntoA3[] = {1, 2, 3, 4, 5};
  int tamanhoA3 = sizeof(conjuntoA3) / sizeof(conjuntoA3[0]);

  int conjuntoB3[] = {3, 4, 5, 6, 7};
  int tamanhoB3 = sizeof(conjuntoB3) / sizeof(conjuntoB3[0]);

  int uniao[tamanhoA3 + tamanhoB3];
  int tamanhoUniao = 0;

  calcularUniao(conjuntoA3, tamanhoA3, conjuntoB3, tamanhoB3, uniao, &tamanhoUniao);

  FILE *arquivo4 = fopen("conjuntosUniao.txt", "w");
  if (arquivo == NULL) {
      printf("Erro ao abrir o arquivo.\n");
      return 1;
  }

  fprintf(arquivo, "União dos conjuntos A e B: ");
  for (int i = 0; i < tamanhoUniao; i++) {
      fprintf(arquivo, "%d ", uniao[i]);
  }
  fprintf(arquivo, "\n");

  fclose(arquivo);
  printf("União dos conjuntos foi salva no arquivo 'conjuntosUniao.txt'.\n");

  
  printf("União dos conjuntos A e B: ");
  for (int i = 0; i < tamanhoUniao; i++) {
      printf("%d ", uniao[i]);
  }
  printf("\n");

  //Questão G

  int A[] = {1, 2, 3, 4, 5};
  int tamA = 5;
  int B[] = {3, 4, 5, 6, 7};
  int tamB = 5;

  calcularIntersecaoEArmazenar(A, tamA, B, tamB, "conjuntos.txt");

  //Questão H
  
  int A1[] = {1, 2, 3, 4, 5};
  int tamA1 = 5;
  int B1[] = {3, 4, 5, 6, 7};
  int tamB1 = 5;

  calcularDiferencaEArmazenar(A1, tamA1, B1, tamB1, "conjuntosDiferenca.txt");

  //Questão I

  int A2[] = {1, 2, 3, 4, 5};
  int tamA2 = 5;
  int B2[] = {3, 4, 5, 6, 7};
  int tamB2 = 5;

  calcularDiferencaBmenosA(A2, tamA2, B2, tamB2, "conjuntosBmenosA.txt");

  //Questão J

  int A3[] = {1, 2, 3};
  int tamA3 = 3;
  int B3[] = {10, 20};
  int tamB3 = 2;

  calcularProdutoCartesianoEArmazenar(A3, tamA3, B3, tamB3, "conjuntosProdutoCartesiano.txt");

  //Questão K

  int A4[] = {1, 2, 3};
  int tamA4 = 3;
  int B4[] = {10, 20};
  int tamB4 = 2;

  calcularProdutoCartesianoBxA(A4, tamA4, B4, tamB4, "conjuntosProdutoCartesiaBxA.txt");

  return 0;
}