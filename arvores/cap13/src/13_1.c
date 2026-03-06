#include "arvore.h"
#include <stdio.h>

int main() {
    No no4 = criar_no(NULL, NULL, 4);
    No no5 = criar_no(NULL, NULL, 5);
    No no6 = criar_no(NULL, NULL, 6);

    No no2 = criar_no(no4, no5, 2);
    No no3 = criar_no(NULL, no6, 3);

    No no1 = criar_no(no2, no3, 1);

    emordem(no1);

    destroi(&no1);
}