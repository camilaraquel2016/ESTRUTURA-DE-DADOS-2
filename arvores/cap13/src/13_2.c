#include "arvore.h"
#include <stdio.h>

int nos(No raiz) {
    if (raiz == NULL) return 0;

    return nos(raiz->esq) + nos(raiz->dir) + 1;
}

void inserir_elementos(int *numeros, int tam, No *raiz) {
    for (int i = 0; i < tam; i++) {
        inserir(numeros[i], raiz);
    }
}

int main() {
    int numeros[10] = {5, 3, 7, 1, 4, 6, 9, 0, 2, 8};
    No raiz = NULL;

    inserir_elementos(numeros, 10, &raiz);

    printf("Quantidade de nos: %d", nos(raiz));

    destroi(&raiz); 
} 