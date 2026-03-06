#include "arvore.h"
#include <stdio.h>

void inserir_elementos(int *numeros, int tam, No *raiz) {
    for (int i = 0; i < tam; i++) {
        inserir(numeros[i], raiz);
    }
}

// buscar um elemento em uma árvore binária comum (sem regras de ordenação)
int tem(Item valor, No raiz) {
    if (raiz == NULL) return 0;
    if (raiz->valor == valor) return 1;

    int n = tem(valor, raiz->esq);
    if (n == 1) return 1;

    n = tem(valor, raiz->dir);
    if (n == 1) return 1;
    
    return 0;
}



int main() {
    int numeros[10] = {5, 3, 7, 1, 4, 6, 9, 0, 2, 8};
    No raiz = NULL;
    int valor;

    inserir_elementos(numeros, 10, &raiz);

    printf("Insira o valor que deseja procurar na arvore: ");
    scanf("%d", &valor);

    if (tem(valor, raiz) == 1) {
        printf("O valor %d esta presente na arvore", valor);
    }
    else {
        printf("O valor %d nao esta presente na arvore", valor);
    }

    destroi(&raiz);
}

// Caso a árvore seja uma árvore de busca binária podemos usar outra função para verificar se tem um elemento x na árvore, função essa que reduz a complexidade para árvores balanceadas (função definida em arvore.h)