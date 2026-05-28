#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

static int get_height(Node *n) {
    if (n == NULL) return 0;
    return n->height;
}

static int max(int a, int b) {
    return (a > b) ? a : b;
}

static int get_balance(Node *n) {
    if (n == NULL) return 0;
    return get_height(n->left) - get_height(n->right);
}

static Node* create_node(int key) {
    Node* new_node = (Node*)malloc(sizeof(Node));
  
    new_node->key = key;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->height = 1;

    return new_node;
}

// Rotação Simples à Direita 
static Node* rotate_right(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(get_height(y->left), get_height(y->right));
    x->height = 1 + max(get_height(x->left), get_height(x->right));

    return x;
}

// Rotação Simples à Esquerda
static Node* rotate_left(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(get_height(x->left), get_height(x->right));
    y->height = 1 + max(get_height(y->left), get_height(y->right));

    return y;
}

// Função de Inserção 
Node* insert(Node* node, int key) {
    if (node == NULL) {
        return create_node(key);
    }

    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    } else {
        return node; 
    }

    node->height = 1 + max(get_height(node->left), get_height(node->right));
    int balance = get_balance(node);

    // Caso LL -> (Linear Esquerda) 
    if (balance > 1 && key < node->left->key) {
        return rotate_right(node);
    }

    // Caso RR -> (Linear Direita) 
    if (balance < -1 && key > node->right->key) {
        return rotate_left(node);
    }

    // Caso LR -> (Zigue-zague Esquerda-Direita) 
    if (balance > 1 && key > node->left->key) {
        node->left = rotate_left(node->left);
        return rotate_right(node);
    }

    // Caso RL -> (Zigue-zague Direita-Esquerda) 
    if (balance < -1 && key < node->right->key) {
        node->right = rotate_right(node->right);
        return rotate_left(node);
    }

    return node;
}

void free_tree(Node* root) {
    if (root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}