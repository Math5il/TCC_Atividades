#include <stdio.h>

int main() {
  float cotacao_dolar, valor_dolar, valor_reais;

  printf("Digite a cota��o do d�lar em reais: ");
  scanf("%f", &cotacao_dolar);

  printf("Digite o valor em d�lares que voc� possui: ");
  scanf("%f", &valor_dolar);

  valor_reais = valor_dolar * cotacao_dolar;

  printf("O valor em reais �: %.2f\n", valor_reais);

  return 0;
}
