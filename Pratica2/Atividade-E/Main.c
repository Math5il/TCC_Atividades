#include <iostream>
#include <vector>
#include <cstdio>

void GerarConjuntosProprios(std::vector<int>& conjunto, int index, std::vector<int>& subset, FILE* arquivo) {
    if (index == conjunto.size()) {
        if (subset.size() > 0 && subset.size() < conjunto.size()) {
            fprintf(arquivo, "{ ");
            for (int i = 0; i < subset.size(); ++i) {
                fprintf(arquivo, "%d ", subset[i]);
            }
            fprintf(arquivo, "}\n");
        }
        return;
    }

    // Incluir o elemento atual no subconjunto e chamar recursivamente para o próximo elemento
    subset.push_back(conjunto[index]);
    GerarConjuntosProprios(conjunto, index + 1, subset, arquivo);

    // Excluir o elemento atual do subconjunto e chamar recursivamente para o próximo elemento
    subset.pop_back();
    GerarConjuntosProprios(conjunto, index + 1, subset, arquivo);
}

int main() {
    std::vector<int> conjuntoA = {1, 2};
    std::vector<int> conjuntoB = {3, 4, 5};

    FILE* arquivo = fopen("conjuntos_proprios.txt", "w");
    if (arquivo == nullptr) {
        std::cerr << "Erro ao abrir o arquivo." << std::endl;
        return 1;
    }

    std::vector<int> subset;
    fprintf(arquivo, "Conjuntos próprios de A:\n");
    GerarConjuntosProprios(conjuntoA, 0, subset, arquivo);

    subset.clear(); // Limpar o vetor subset para uso com o próximo conjunto
    fprintf(arquivo, "Conjuntos próprios de B:\n");
    GerarConjuntosProprios(conjuntoB, 0, subset, arquivo);

    fclose(arquivo);
    std::cout << "Conjuntos próprios foram armazenados no arquivo 'conjuntos_proprios.txt'." << std::endl;

    return 0;
}





