#include "automata.h"

void Automata::MostrarEstados() {
  for (const auto& estado : estados_) {
    std::cout << "Estado: " << estado.first << " ";
    std::cout << "Aceptado: " << estado.second << std::endl;
  }
}

void Automata::MostrarPosiblesCaminos() {
    for (const auto& estado : transiciones_) {
      std::cout << "Estado: " << estado.first << std::endl;
      for (const auto& transicion : estado.second) {
        std::cout << transicion.first
                  << " -> "
                  << transicion.second
                  << std::endl;
      }
    }
  }

void Automata::SimuladorCadena () {
    int nuevo_estado;
    int estado_actual_ = estado_inicial_;
    std::cout << "\n Simulando el paso por DFA: \n" << std::endl;
    std::cout << "- Estado actual   - Entrada   - Nuevo Estado\n";
    for (int i = 0; i < cadena_.size(); i++) {
      nuevo_estado = transiciones_[estado_actual_][cadena_[i]]; 
      std::cout << estado_actual_ << "                 " 
                << cadena_[i] << "            " 
                << nuevo_estado << std::endl;
      estado_actual_ = nuevo_estado;
    }
    std::cout << std::endl;
    if (estados_[estado_actual_].get_estado() == true) {
      std::cout << "CADENA ACEPTADA" << std::endl;
    } else {
      std::cout << "CADENA RECHAZADA" << std::endl;
    }
  }

void Automata::SimuladorCadena (std::string salida) {
    std::string fileout_path = salida;

    std::ofstream output_file(fileout_path);
    if (!output_file.is_open()) {
      std::cerr << "Error: no se pudo abrir el archivo de salida: " << fileout_path << "\n";
    }

    int nuevo_estado;
    int estado_actual_ = estado_inicial_;
    
    output_file << "\n Simulando el paso por DFA: \n" << std::endl;
    output_file << "- Estado actual   - Entrada   - Nuevo Estado\n";
    for (int i = 0; i < cadena_.size(); i++) {
      nuevo_estado = transiciones_[estado_actual_][cadena_[i]]; 
      output_file << estado_actual_ << "                 " 
                << cadena_[i] << "            " 
                << nuevo_estado << std::endl;
      estado_actual_ = nuevo_estado;
    }
    output_file << std::endl;
    if (estados_[estado_actual_].get_estado() == true) {
      output_file << "CADENA ACEPTADA" << std::endl;
    } else {
      output_file << "CADENA RECHAZADA" << std::endl;
    }

  }
