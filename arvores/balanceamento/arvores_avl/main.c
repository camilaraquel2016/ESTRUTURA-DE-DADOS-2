#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

void caso_LL() {

    Node* raiz = NULL;

    printf("\n========================================\n");
    printf("ROTACAO SIMPLES A DIREITA (LL)\n");
    printf("========================================\n");

    raiz = insert(raiz, 30);

    printf("\nInserindo 30:\n\n");
    printf("        [%d]\n\n", 30);

    raiz = insert(raiz, 20);

    printf("Inserindo 20:\n\n");
    printf("        [%d]\n", 30);
    printf("        /\n");
    printf("    [%d]\n\n", 20);

    printf("20 entrou a ESQUERDA de 30\n");

    raiz = insert(raiz, 10);

    printf("\nInserindo 10:\n\n");

    printf("        [%d]\n", 30);
    printf("        /\n");
    printf("    [%d]\n", 20);
    printf("     /\n");
    printf(" [%d]\n\n", 10);

    printf("AVL detectou desbalanceamento LL!\n");
    printf("Aplicando Rotacao Simples a Direita...\n");

    printf("\nResultado Final:\n");

    printf("        [%d]\n", 20);
    printf("        /   \\\n");
    printf("    [%d]   [%d]\n\n", 10, 30);

    free_tree(raiz);
}

void caso_RR() {

    Node* raiz = NULL;

    printf("\n========================================\n");
    printf("ROTACAO SIMPLES A ESQUERDA (RR)\n");
    printf("========================================\n");

    raiz = insert(raiz, 10);

    printf("\nInserindo 10:\n\n");
    printf("    [%d]\n\n", 10);

    raiz = insert(raiz, 20);

    printf("Inserindo 20:\n\n");
    printf("    [%d]\n", 10);
    printf("        \\\n");
    printf("        [%d]\n\n", 20);

    printf("20 entrou a DIREITA de 10\n");

    raiz = insert(raiz, 30);

    printf("\nInserindo 30:\n\n");

    printf("    [%d]\n", 10);
    printf("        \\\n");
    printf("        [%d]\n", 20);
    printf("            \\\n");
    printf("            [%d]\n\n", 30);

    printf("AVL detectou desbalanceamento RR!\n");
    printf("Aplicando Rotacao Simples a Esquerda...\n");

    printf("\nResultado Final:\n");

    printf("        [%d]\n", 20);
    printf("        /   \\\n");
    printf("    [%d]   [%d]\n\n", 10, 30);

    free_tree(raiz);
}


void caso_LR() {

    Node* raiz = NULL;

    printf("\n========================================\n");
    printf("ROTACAO DUPLA ESQUERDA-DIREITA (LR)\n");
    printf("========================================\n");

    raiz = insert(raiz, 30);

    printf("\nInserindo 30:\n\n");
    printf("        [%d]\n\n", 30);

    raiz = insert(raiz, 10);

    printf("Inserindo 10:\n\n");
    printf("        [%d]\n", 30);
    printf("        /\n");
    printf("    [%d]\n\n", 10);

    printf("10 entrou a ESQUERDA de 30\n");

    raiz = insert(raiz, 20);

    printf("\nInserindo 20:\n\n");

    printf("        [%d]\n", 30);
    printf("        /\n");
    printf("    [%d]\n", 10);
    printf("        \\\n");
    printf("        [%d]\n\n", 20);

    printf("20 entrou a DIREITA de 10\n");

    printf("AVL detectou ZIGUE-ZAGUE LR!\n");

    printf("\n1) Rotacao a Esquerda em 10\n");
    printf("2) Rotacao a Direita em 30\n");

    printf("\nResultado Final:\n");

    printf("        [%d]\n", 20);
    printf("        /   \\\n");
    printf("    [%d]   [%d]\n\n", 10, 30);

    free_tree(raiz);
}


void caso_RL() {

    Node* raiz = NULL;

    printf("\n========================================\n");
    printf("ROTACAO DUPLA DIREITA-ESQUERDA (RL)\n");
    printf("========================================\n");

    raiz = insert(raiz, 10);

    printf("\nInserindo 10:\n\n");
    printf("    [%d]\n\n", 10);

    raiz = insert(raiz, 30);

    printf("Inserindo 30:\n\n");
    printf("    [%d]\n", 10);
    printf("        \\\n");
    printf("        [%d]\n\n", 30);

    printf("30 entrou a DIREITA de 10\n");

    raiz = insert(raiz, 20);

    printf("\nInserindo 20:\n\n");

    printf("    [%d]\n", 10);
    printf("        \\\n");
    printf("        [%d]\n", 30);
    printf("        /\n");
    printf("    [%d]\n\n", 20);

    printf("20 entrou a ESQUERDA de 30\n");

    printf("AVL detectou ZIGUE-ZAGUE RL!\n");

    printf("\n1) Rotacao a Direita em 30\n");
    printf("2) Rotacao a Esquerda em 10\n");

    printf("\nResultado Final:\n");

    printf("        [%d]\n", 20);
    printf("        /   \\\n");
    printf("    [%d]   [%d]\n\n", 10, 30);

    free_tree(raiz);
}


void limpar() {
    system("cls || clear");
}


int main() {

    int opcao;

    do {

        printf("\n========================================\n");
        printf("     SIMULADOR DE ROTACOES AVL\n");
        printf("========================================\n");

        printf("1 - Rotacao LL\n");
        printf("2 - Rotacao RR\n");
        printf("3 - Rotacao LR (Zigue-Zague)\n");
        printf("4 - Rotacao RL (Zigue-Zague)\n");
        printf("0 - Sair\n");

        printf("\nEscolha um caso: ");
        scanf("%d", &opcao);

        limpar();

        switch(opcao) {

            case 1:
                caso_LL();
                break;

            case 2:
                caso_RR();
                break;

            case 3:
                caso_LR();
                break;

            case 4:
                caso_RL();
                break;

            case 0:
                printf("Encerrando simulador...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while(opcao != 0);

    return 0;
}