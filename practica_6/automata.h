#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <vector>
#include <string>
#include <set>
#include <map>
#include "estado.h"
#include "alfabeto.h"

class Automata
{
public:
  Automata() {}
  Automata(std::string nombre_archivo, std::string nombre_archivo2 = "input.txt")
  {
    std::ifstream file(nombre_archivo);
    if (!file.is_open()) {
      std::cout << "Error al abrir el archivo: " << nombre_archivo << std::endl;
      return;
    }
    std::cout << "¡Archivo abierto con exito!\n";
    std::string line;
    while (std::getline(file, line))
    {
      content.push_back(line);
    }
    alfabeto_.set_alfabeto(content[0]);
    std::cout << "\nAlfabeto: " << alfabeto_ << std::endl;
    int n_estados = std::stoi(content[1]);

    for (int i = 0; i < n_estados; i++) {
      std::stringstream ss(content[3 + i]);
      int id;
      int aceptacion;
      ss >> id >> aceptacion;
      Estado nuevo(aceptacion == 0 ? false : true);
      estados_[id] = nuevo;

      char simbolo;
      int destino;
      
      while (ss >> simbolo >> destino) {
        transiciones_[id][simbolo] = destino;
      }
    }
    std::ifstream file2(nombre_archivo2);
    if (!file2.is_open()) {
      std::cout << "Error al abrir el archivo: " << nombre_archivo2 << std::endl;
      return;
    }
    std::getline(file2, cadena_);
    std::cout << cadena_ << std::endl; 
  }

  void MostrarEstados() {
    for (const auto& estado : estados_) {
      std::cout << "Estado: " << estado.first << " ";
      std::cout << "Aceptado: " << estado.second << std::endl;
    }
  }

  void MostrarPosiblesCaminos() {
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

  bool SimuladorCadena (string cadena) {
    return 0; 
  }

private:
  std::map<int, Estado> estados_;
  std::map<int, std::map<char, int>> transiciones_;
  std::vector<std::string> content;
  std::string cadena_;
  Alfabeto alfabeto_;
};

#endif