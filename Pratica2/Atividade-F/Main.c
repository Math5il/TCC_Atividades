#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> CalcularUniao(int conjuntoA[], int tamanhoA, int conjuntoB[], int tamanhoB) {
    std::vector<int> aux;

    for (int i = 0; i < tamanhoA; i++) {
        if (std::find(aux.begin(), aux.end(), conjuntoA[i]) == aux.end()) {
            aux.push_back(conjuntoA[i]);
        }
    }

    for (int i = 0; i < tamanhoB; i++) {
        if (std::find(aux.begin(), aux.end(), conjuntoB[i]) == aux.end()) {
            aux.push_back(conjuntoB[i]);
        }
    }

    return aux;
}

int main() {
    int conjuntoA[] = {1, 2, 3, 4, 5};
    int tamanhoA = sizeof(conjuntoA) / sizeof(conjuntoA[0]);

    int conjuntoB[] = {3, 4, 5, 6, 7};
    int tamanhoB = sizeof(conjuntoB) / sizeof(conjuntoB[0]);

    std::vector<int> uniao = CalcularUniao(conjuntoA, tamanhoA, conjuntoB, tamanhoB);

    std::cout << "União dos conjuntos A e B: ";
    for (int i = 0; i < uniao.size(); i++) {
        std::cout << uniao[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}


/*

UTILIZANDO ALOCAÇÂO DE MEMORIA TEMPORARIA

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> CalcularUniao(int* conjuntoA, int tamanhoA, int* conjuntoB, int tamanhoB) {
    std::vector<int> aux;

    for (int i = 0; i < tamanhoA; i++) {
        if (std::find(aux.begin(), aux.end(), conjuntoA[i]) == aux.end()) {
            aux.push_back(conjuntoA[i]);
        }
    }

    for (int i = 0; i < tamanhoB; i++) {
        if (std::find(aux.begin(), aux.end(), conjuntoB[i]) == aux.end()) {
            aux.push_back(conjuntoB[i]);
        }
    }

    return aux;
}

int main() {
    int tamanhoA = 5;
    int* conjuntoA = new int[tamanhoA]{1, 2, 3, 4, 5};

    int tamanhoB = 5;
    int* conjuntoB = new int[tamanhoB]{3, 4, 5, 6, 7};

    std::vector<int> uniao = CalcularUniao(conjuntoA, tamanhoA, conjuntoB, tamanhoB);

    std::cout << "União dos conjuntos A e B: ";
    for (int i = 0; i < uniao.size(); i++) {
        std::cout << uniao[i] << " ";
    }
    std::cout << std::endl;

    // Libere a memória alocada dinamicamente
    delete[] conjuntoA;
    delete[] conjuntoB;

    return 0;
}

*/