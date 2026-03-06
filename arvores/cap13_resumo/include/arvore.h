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
void inserir(No *raiz, Item valor);
void emordem(No raiz);

#endif 