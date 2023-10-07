#include <stdio.h>
#include <stdlib.h>

struct Pessoa{
    char Nome[100];
    char Cpf[12];
    double Salario;
};

struct Pessoa *Alocarmeroria(int n){
    struct Pessoa *pessoas = (struct Pessoa *)calloc(n, sizeof(struct Pessoa));
    if(pessoas == NULL){
        printf("Falha na alocação de memória.\n");
        exit(1);
    }
    return pessoas;
};

int PreencherVetor(struct Pessoa *pessoas, int n){
    for (int i = 0; i < n; i++) {
    printf("Digite o CPF da pessoa %d: ", i + 1);
        fgets(pessoas[i].Cpf, sizeof(pessoas[i].Cpf), stdin);
        // Remover o caractere de nova linha '\n' do final da string
        pessoas[i].Cpf[strcspn(pessoas[i].Cpf, "\n")] = '\0';

        printf("Digite o nome da pessoa %d: ", i + 1);
        fgets(pessoas[i].Nome, sizeof(pessoas[i].Nome), stdin);
        pessoas[i].Nome[strcspn(pessoas[i].Nome, "\n")] = '\0';

        printf("Digite o salário da pessoa %d: ", i + 1);
        scanf("%lf", &pessoas[i].Salario);
        // Consumir o caractere de nova linha pendente no buffer
        getchar();

        }
};

int ImpressaoVetor(struct Pessoa *pessoas, int n){
    printf("Pessoas: \n ");
    for (int i = 0; i < n; i++) {
        printf("CPF: %s\n", pessoas[i].Cpf);
        printf("Nome: %s\n", pessoas[i].Nome);
        printf("Salário: %.2lf\n", pessoas[i].Salario);
        printf("\n");
}
};

int main(){
    int n;

    printf("Digite o número de pessoas do array: ");
    scanf("%d", &n);

    struct Pessoa *pessoas = Alocarmeroria(n);

    PreencherVetor(pessoas, n);
    ImpressaoVetor(pessoas, n);

    free(pessoas);
    return 0;
}

