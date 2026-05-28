#ifndef AVL_H
#define AVL_H

typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    int height;
} Node;

Node* insert(Node* node, int key);
void free_tree(Node* root);

#endif