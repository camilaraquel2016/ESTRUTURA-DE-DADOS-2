#include <stdio.h>
#include "arvore.h"
#include <stdlib.h>

Item remmax_recursivo(No *raiz) {
    if (*raiz == NULL) abort();

    if ((*raiz)->dir == NULL) {
        No removido = *raiz;
        *raiz = removido->esq;

        Item valor = removido->valor;
        free(removido);

        return valor;
    }

    return remmax_recursivo(&(*raiz)->dir);
}
 

void remocao_por_copia(Item x, No *raiz) {
    if (*raiz == NULL) return;

    if (x == (*raiz)->valor) {
        No no_encontrado = *raiz;

        if (no_encontrado->esq == NULL) *raiz = no_encontrado->dir;
        else if (no_encontrado->dir == NULL) *raiz = no_encontrado->esq;
        else no_encontrado->valor = remmax_recursivo(&no_encontrado->esq);

        if (no_encontrado != *raiz) free(no_encontrado);
    }

    else if (x < (*raiz)->valor) remocao_por_copia(x, &(*raiz)->esq);
    else remocao_por_copia(x, &(*raiz)->dir);
}


void inserir_elementos(No *raiz, int tamanho, int *numeros) {
    for (int i = 0; i < tamanho; i++) {
        inserir(raiz, numeros[i]);
    }   
}

int main() {
    int numeros[14] = {8, 3, 11, 1, 4, 10, 13, 0, 2, 6, 12, 14, 5, 7};
    No raiz = NULL;

    inserir_elementos(&raiz, 14, numeros);

    printf("Antes da remocao: ");
    emordem(raiz);
    printf("\n\n");

    remocao_por_copia(8, &raiz);

    printf("Apos remocao: ");
    emordem(raiz);
}