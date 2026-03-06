#include "arvore.h"
#include <stdlib.h>
#include <stdio.h>

No criar_no(No esq, No dir, Item valor) {
    No novo = malloc(sizeof(struct no));

    novo->valor = valor;
    novo->esq = esq;
    novo->dir = dir;

    return novo;
}

void inserir(No *raiz, Item valor) {
    if (*raiz == NULL) {
        No novo = criar_no(NULL, NULL, valor);
        *raiz = novo;
    }
    else if (valor < (*raiz)->valor) inserir(&(*raiz)->esq, valor);

    else inserir(&(*raiz)->dir, valor);
}

void emordem(No raiz) {
    if (raiz == NULL) return;
    emordem(raiz->esq);
    printf("(" ITEM_FMT ")", raiz->valor);
    emordem(raiz->dir);
}