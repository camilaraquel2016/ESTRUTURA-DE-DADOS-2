#define ITEM_TYPE char
#define ITEM_FMT "%c"
#include "arvore.h"


#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

float valor(No raiz) {
    if (raiz == NULL) return 0;

    if (isdigit(raiz->valor)) return raiz->valor - '0';

    float valor_esq = valor(raiz->esq);
    float valor_dir = valor(raiz->dir);

    switch (raiz->valor) {
        case '+':
            return valor_esq + valor_dir;

        case '-':
            return valor_esq - valor_dir;

        case '*':
            return valor_esq * valor_dir;  
            
        case '/':
            if (valor_dir == 0) {
                printf("Erro de divisão por zero!!!");
                exit(1);
            }    
            return valor_esq / valor_dir;
    }

    printf("Erro operador inválido: %c", raiz->valor);
    exit(1);
}

void inserir_elementos(No *raiz) {
    No no5 = criar_no(NULL, NULL, '5');
    No no3 = criar_no(NULL, NULL, '3');

    No no_mais = criar_no(no5, no3, '+');

    No no4 = criar_no(NULL, NULL, '4');

    No no_divide = criar_no(no_mais, no4, '/');

    No no6 = criar_no(NULL, NULL, '6');
    No no1 = criar_no(NULL, NULL, '1');

    No no_menos = criar_no(no6, no1, '-');

    No no_multiplica = criar_no(no_divide, no_menos, '*');

    *raiz = no_multiplica;
}

int main() {
    No raiz = NULL;

    inserir_elementos(&raiz);

    printf("Valor da expressao = %.2f", valor(raiz));

    destroi(&raiz);
}