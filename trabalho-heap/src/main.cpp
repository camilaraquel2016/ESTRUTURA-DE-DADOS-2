#include "../include/filaHospitalar.h"
#include <iostream>

int main() {
    FilaHospitalar hospital;
    int opcao = 0;

    while (opcao != 3) {
        std::cout << "\n===== FILA DE ATENDIMENTO HOSPITALAR =====";
        std::cout << "\n1. Cadastrar Paciente";
        std::cout << "\n2. Atender Proximo";
        std::cout << "\n3. Sair do Sistema";
        std::cout << "\nEscolha uma opcao: ";
        std::cin >> opcao;

        if (opcao == 1) {
            hospital.cadastrarPaciente();
        } else if (opcao == 2) {
            hospital.atenderProximo();
        } else if (opcao == 3) {
            std::cout << "Encerrando sistema..." << std::endl;
        } else {
            std::cout << "Opcao invalida. Tente novamente." << std::endl;
        }
    }

    return 0;
}