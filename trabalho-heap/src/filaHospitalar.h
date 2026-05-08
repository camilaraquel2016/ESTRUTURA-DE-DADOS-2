#ifndef FILAHOSPITALAR_H
#define FILAHOSPITALAR_H

#include "heap.h" 

class FilaHospitalar {
private:
    MaxHeap heap;            
    int contadorChegada = 0; 

public:
    void cadastrarPaciente(); 
    void atenderProximo();    
    bool filaVazia();         
};

#endif