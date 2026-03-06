#include "arvore.h"
#include <stdio.h>

int eb(No raiz) {
    if (raiz == NULL) return 1;

    if (raiz->esq == NULL && raiz->dir == NULL) return 1;

    if (raiz->esq == NULL || raiz->dir == NULL) return 0;

    int esq = eb(raiz->esq);
    int dir = eb(raiz->dir);

    if (esq == 0 || dir == 0) return 0;

    return 1;
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

    if (eb(raiz) == 1) {
        printf("Arvore e estritamente binaria");
    }
    else {
        printf("Arvore nao e estritamente binaria");
    }
}