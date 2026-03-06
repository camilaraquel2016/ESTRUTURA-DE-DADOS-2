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
 

No obter_maior(No raiz) {
    if (raiz == NULL) abort();

    if (raiz->dir == NULL) return raiz;
    return obter_maior(raiz->dir);
}

// removendo em uma árvore binária de busca
void remocao_por_fusao(No *raiz, Item valor) {
    if (*raiz == NULL) return;

    if ((*raiz)->valor == valor) {
        No removido = *raiz;

        if (removido->esq == NULL) *raiz = removido->dir;
        else if (removido->dir == NULL) *raiz = removido->esq;
        else {
            No maior = obter_maior(removido->esq);

            maior->dir = removido->dir;
            *raiz = removido->esq;
        }

        free(removido);
    } 

    else if (valor < (*raiz)->valor) remocao_por_fusao(&(*raiz)->esq, valor);
    else remocao_por_fusao(&(*raiz)->dir, valor);

}

int main() {
    int numeros[14] = {8, 3, 11, 1, 4, 10, 13, 0, 2, 6, 12, 14, 5, 7};
    No raiz = NULL;

    inserir_elementos(&raiz, 14, numeros);

    printf("Antes da remocao: ");
    emordem(raiz);
    printf("\n\n");

    remocao_por_fusao(&raiz, 8);

    printf("Apos remocao: ");
    emordem(raiz);
}