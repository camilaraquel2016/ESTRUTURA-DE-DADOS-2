#include "stdio.h"
#include "arvore.h"

int contar_nos(No raiz) {
    if (raiz == NULL) return 0;

    return contar_nos(raiz->esq) + contar_nos(raiz->dir) + 1;
}

int eh_completa_recursiva(No raiz, int indice, int total) {
    if (raiz == NULL) return 1;
    if (indice >= total) return 0;
    if (eh_completa_recursiva(raiz->esq, indice * 2 + 1, total) == 0) return 0;
    if (eh_completa_recursiva(raiz->dir, indice * 2 + 2, total) == 0) return 0;
    return 1;
}


int eh_completa(No raiz) {
    int total = contar_nos(raiz);
    return eh_completa_recursiva(raiz, 0, total);
}




int main() {
    No no4 = criar_no(NULL, NULL, 4); 
    No no5 = criar_no(NULL, NULL, 5);
    No no6 = criar_no(NULL, NULL, 6);

    No no2 = criar_no(no4, no5, 2);
    No no3 = criar_no(NULL, no6, 3);

    No no1 = criar_no(no2, no3, 1);

    if (eh_completa(no1) == 1) {
        printf("Arvore e completa");
    }
    else {
        printf("Arvore nao e completa");
    }
}