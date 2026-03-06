#include "arvore.h"
#include <stdio.h>

void inserir_elementos(int *numeros, int tam, No *raiz) {
    for (int i = 0; i < tam; i++) {
        inserir(numeros[i], raiz);
    }
}


int altura(No raiz) {
    if (raiz == NULL) return 0;

    int esq = altura(raiz->esq);
    int dir = altura(raiz->dir);

    if (esq > dir) return esq + 1;
    return dir + 1;
}

int main() {
    int numeros[10] = {5, 3, 7, 1, 4, 6, 9, 0, 2, 8};
    No raiz = NULL;

    inserir_elementos(numeros, 10, &raiz);

    printf("Altura: %d", altura(raiz));

    destroi(&raiz);
}