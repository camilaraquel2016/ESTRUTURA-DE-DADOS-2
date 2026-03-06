#include "arvore.h"
#include "stdio.h"

// altura definida em números de nós

int calcular_altura(No raiz) {
    if (raiz == NULL) return 0;

    int altura_esquerda = calcular_altura(raiz->esq);
    int altura_direita = calcular_altura(raiz->dir);

    return (altura_esquerda > altura_direita) ? altura_esquerda + 1 : altura_direita + 1;
}


int main() {
    No no4 = criar_no(NULL, NULL, 4); 
    No no5 = criar_no(NULL, NULL, 5);
    No no6 = criar_no(NULL, NULL, 6);

    No no2 = criar_no(no4, no5, 2);
    No no3 = criar_no(NULL, no6, 3);

    No no1 = criar_no(no2, no3, 1);

    printf("A arvore possui altura %d", calcular_altura(no1));
}