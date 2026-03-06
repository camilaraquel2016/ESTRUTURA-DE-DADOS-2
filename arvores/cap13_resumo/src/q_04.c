#include "arvore.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

int calcular_altura(No raiz) {
    if (raiz == NULL) return 0;

    int altura_esquerda = calcular_altura(raiz->esq);
    int altura_direita = calcular_altura(raiz->dir);

    return (altura_esquerda > altura_direita) ? altura_esquerda + 1 : altura_direita + 1;
}

int contar_nos(No raiz) {
    if (raiz == NULL) return 0;

    return contar_nos(raiz->esq) + contar_nos(raiz->dir) + 1;
}


int eh_cheia(No raiz) {
    int qdt_nos = contar_nos(raiz);
    int altura = calcular_altura(raiz);

    return qdt_nos == pow(2, altura) - 1;
}


int main() {
    No no4 = criar_no(NULL, NULL, 4); 
    No no5 = criar_no(NULL, NULL, 5);
    No no6 = criar_no(NULL, NULL, 6);

    No no2 = criar_no(no4, no5, 2);
    No no3 = criar_no(NULL, no6, 3);

    No no1 = criar_no(no2, no3, 1);

    if (eh_cheia(no1) == 1) {
        printf("Arvore e cheia");
    }
    else {
        printf("Arvore nao e cheia");
    }

}