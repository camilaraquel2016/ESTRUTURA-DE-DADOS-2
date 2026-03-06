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

// inserção em árvore de busca binária 
void inserir(Item valor, No *raiz) {
    if (*raiz == NULL) *raiz = criar_no(NULL, NULL, valor);
    else if (valor < (*raiz)->valor) inserir(valor, &(*raiz)->esq);
    else inserir(valor, &(*raiz)->dir);
}


void emordem(No raiz) {
    if (raiz == NULL) return;
    emordem(raiz->esq);
    printf("(" ITEM_FMT ") ", raiz->valor);
    emordem(raiz->dir);
}


void preordem(No raiz) {
    if (raiz == NULL) return;
    printf("(" ITEM_FMT ") ", raiz->valor);
    preordem(raiz->esq);
    preordem(raiz->dir);
}


void posordem(No raiz) {
    if (raiz == NULL) return;
    posordem(raiz->esq);
    posordem(raiz->dir);
    printf("(" ITEM_FMT ") ", raiz->valor);
}



void destroi(No *raiz) {
    if (*raiz == NULL) return;

    destroi(&(*raiz)->esq);
    destroi(&(*raiz)->dir);

    free(*raiz);
    *raiz = NULL;
}

// buscar em árvore de busca binária
int buscar(Item valor, No raiz) {
    if (raiz == NULL) return 0;
    if (valor == raiz->valor) return 1;
    if (valor < raiz->valor) return buscar(valor, raiz->esq);
    return buscar(valor, raiz->dir);
}


// remoção do item máximo em árvore de busca binária de forma recursiva
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
 

// remoção do item máximo em árvore de busca binária de forma iterativa 
Item remmax_iterativo(No *raiz) {
    if (*raiz == NULL) abort();

    while ((*raiz)->dir != NULL) {
        raiz = &(*raiz)->dir;
    }

    No removido = *raiz;
    Item valor = removido->valor;

    *raiz = removido->esq;
    free(removido);

    return valor;
}

// remoção em árvore de busca binária
void rem(Item x, No *raiz) {
    if (*raiz == NULL) return;

    if (x == (*raiz)->valor) {
        No no_encontrado = *raiz;

        if (no_encontrado->esq == NULL) *raiz = no_encontrado->dir;
        else if (no_encontrado->dir == NULL) *raiz = no_encontrado->esq;
        else no_encontrado->valor = remmax_recursivo(&no_encontrado->esq);

        if (no_encontrado != *raiz) free(no_encontrado);
    }

    else if (x < (*raiz)->valor) rem(x, &(*raiz)->esq);
    else rem(x, &(*raiz)->dir);
}












