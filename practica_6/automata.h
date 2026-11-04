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
  Automata(std::string nombre_archivo)
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
  }


private:
  std::map<int, Estado> estados_;
  std::map<int, std::map<char, int>> transiciones_;
  std::set<Estado> conjunto;
  std::vector<std::string> content;
  Alfabeto alfabeto_;
};

#endif