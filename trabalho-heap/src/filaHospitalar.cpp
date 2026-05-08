#include "filaHospitalar.h"
#include <iostream>
#include <string>
#include <limits> 

void FilaHospitalar::cadastrarPaciente() {
    std::string nome;
    int nivel;

    std::cout << "\n--- NOVO CADASTRO ---" << std::endl;
    std::cout << "Nome do Paciente: ";

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, nome);
    
    std::cout << "Nivel (10-Emergencia, 5-Urgencia, 1-Eletivo): ";
    std::cin >> nivel;

    contadorChegada++;

    Elemento novo;
    novo.dado = nome; 
    novo.prioridade = nivel;
    novo.ordemChegada = contadorChegada;

    heap.inserir(novo); 
    std::cout << ">>> Paciente " << nome << " inserido na fila!" << std::endl;
}

void FilaHospitalar::atenderProximo() {
    if (heap.estaVazia()) {
        std::cout << "\n[!] Nao ha pacientes na fila de espera." << std::endl;
        return;
    }

    Elemento p = heap.remover();
    std::cout << "\n-----------------------------------";
    std::cout << "\n PROXIMO PACIENTE: " << p.dado; 
    std::cout << "\n NIVEL DE PRIORIDADE: " << p.prioridade;
    std::cout << "\n-----------------------------------" << std::endl;
}

bool FilaHospitalar::filaVazia() {
    return heap.estaVazia();
}