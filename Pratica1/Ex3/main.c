#include <stdio.h>

int main() {
  float cotacao_dolar, valor_dolar, valor_reais;

  printf("Digite a cotação do dólar em reais: ");
  scanf("%f", &cotacao_dolar);

  printf("Digite o valor em dólares que você possui: ");
  scanf("%f", &valor_dolar);

  valor_reais = valor_dolar * cotacao_dolar;

  printf("O valor em reais é: %.2f\n", valor_reais);

  return 0;
}
