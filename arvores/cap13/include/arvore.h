#ifndef ARVORE_H
#define ARVORE_H

#ifndef ITEM_TYPE
#define ITEM_TYPE int
#endif

#ifndef ITEM_FMT
#define ITEM_FMT "%d"
#endif

typedef ITEM_TYPE Item;

typedef struct no {
    Item valor;
    struct no *esq;
    struct no *dir;
} *No;


No criar_no(No esq, No dir, Item valor);
void inserir(Item valor, No *raiz);
void destroi(No *raiz);
int buscar(Item valor, No raiz); // busca binária


// percursos em profundidade

void emordem(No raiz);
void preordem(No raiz);
void posordem(No raiz);

// remoção em arvore binaria de busca
Item remmax_iterativo(No *raiz);
Item remmax_recursivo(No *raiz);
void rem(Item x, No *raiz);

#endif  
