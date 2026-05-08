#include "heap.h"
#include <algorithm>
#include <stdexcept>

void MaxHeap::heapifyUp(int i) {
    while (i > 0 && v[i].temMaiorPrioridade(v[indicePai(i)])) {
        std::swap(v[i], v[(i - 1) / 2]);
        i = indicePai(i);
    }
}


bool Elemento::temMaiorPrioridade(const Elemento& outro) const {
    if (this->prioridade != outro.prioridade) return this->prioridade > outro.prioridade;
    return this->ordemChegada < outro.ordemChegada;
}


int MaxHeap::indiceEsquerda(int i) {return 2 * i + 1;}
int MaxHeap::indiceDireita(int i) {return 2 * i + 2;}
int MaxHeap::indicePai(int i) {return (i - 1) / 2;}

void MaxHeap::heapifyDown(int i) {
    int maior = i;
    int esq = indiceEsquerda(i);
    int dir = indiceDireita(i); 

    if (esq < v.size() && v[esq].temMaiorPrioridade(v[maior])) maior = esq;
    if (dir < v.size() && v[dir].temMaiorPrioridade(v[maior])) maior = dir;

    if (maior != i) {
        std::swap(v[i], v[maior]);
        heapifyDown(maior); 
    } 
}

Elemento MaxHeap::remover() {
    if (v.empty()) {
        throw std::runtime_error("Heap vazio");
    }

    Elemento topo = v[0];
    
    v[0] = v.back();
    v.pop_back();

    if (!v.empty()) {
        heapifyDown(0);
    }
        
    return topo;
}


void MaxHeap::inserir(Elemento e) {
    v.push_back(e);
    heapifyUp(v.size() - 1); 
}

void MaxHeap::buildHeap(std::vector<Elemento> novoVetor) {
    v = novoVetor;
    int primeiroPai = v.size() / 2 - 1;
    
    for (int i = primeiroPai; i >= 0; i--) {
        heapifyDown(i);
    }
} 

bool MaxHeap::estaVazia() {return v.empty(); }


