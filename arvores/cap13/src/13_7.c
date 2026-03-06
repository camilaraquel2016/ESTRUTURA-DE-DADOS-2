#include "arvore.h"
#include <stdio.h>

int igual(No raiz_a, No raiz_b) {
    if (raiz_a == NULL && raiz_b == NULL) return 1;
    if (raiz_a == NULL || raiz_b == NULL) return 0;
    
    if (raiz_a->valor != raiz_b->valor) return 0;

    if (igual(raiz_a->esq, raiz_b->esq) == 0) return 0;
       
    if (igual(raiz_a->dir, raiz_b->dir) == 0) return 0;

    return 1;
}

int inserir_elementos(No *raiz) {
    int entrada;
    int valor;

    while (1) {
        printf("Insira um numero: (-1 para sair): ");
        scanf("%d", &valor);

        if (valor == -1) break;

        inserir(valor, raiz);
    }
}

int main() {
    No raiz_a = NULL;
    No raiz_b = NULL;

    printf("-=-=-=-=- Primeira arvore -=-=-=-=-\n");
    inserir_elementos(&raiz_a);

    printf("-=-=-=-=- Segunda arvore -=-=-=-=-\n");
    inserir_elementos(&raiz_b);

    if (igual(raiz_a, raiz_b) == 1) {
        printf("Arvores sao iguais");
    }
    else {
        printf("Arvores sao diferentes");
    }
}