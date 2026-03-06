#include "arvore.h"
#include <stdio.h>

void inserir_elementos(int *numeros, int tam, No *raiz) {
    for (int i = 0; i < tam; i++) {
        inserir(numeros[i], raiz);
    }
}


int folhas(No raiz) {
    if (raiz == NULL) return 0;
    
    if (raiz->esq == NULL && raiz->dir == NULL) return 1;

    return folhas(raiz->esq) + folhas(raiz->dir);
}


int main() {
    int numeros[10] = {5, 3, 7, 1, 4, 6, 9, 0, 2, 8};
    No raiz = NULL;

    inserir_elementos(numeros, 10, &raiz);

    printf("Quantidade de folhas: %d", folhas(raiz));

    destroi(&raiz);
}