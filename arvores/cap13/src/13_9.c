#include "arvore.h"
#include <stdio.h>
#include <ctype.h>

void exibe_dec(No raiz) {
    if (raiz == NULL) return;
    exibe_dec(raiz->dir);
    printf("(%d) ", raiz->valor);
    exibe_dec(raiz->esq);
}

void inserir_elementos(No *raiz) {
    int entrada;

    while (1) {
        printf("Insira um numero (-1 para sair): ");
        scanf("%d", &entrada);

        if (entrada == -1) break;

        inserir(entrada, raiz);
    }
}
 
int main() {
    No raiz = NULL;

    inserir_elementos(&raiz);

    printf("Arvore em ordem decrescente: ");
    exibe_dec(raiz);

    destroi(&raiz);
}