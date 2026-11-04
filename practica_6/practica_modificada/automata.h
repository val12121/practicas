#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <vector>
#include <string>
#include <set>
#include <map>
#include <cmath>
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
    estado_inicial_ = std::stoi(content[2]);

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
    //std::cout << cadena_ << std::endl; 
  }

  void MostrarEstados();
  void MostrarPosiblesCaminos();

  void SimuladorCadena ();
  void SimuladorCadena (std::string salida);
  //Modificación
  void GeneradorDeCadenas(int n = 3) {
    for (int j = 0; j <= n; j++) {
      int total_combinaciones = pow(2, j);
      for (int i = 0; i < total_combinaciones; i++) {
          std::string combinacion_actual = "";
          for (int z = j - 1; z >= 0; z--) {
              int bit = (i >> z) & 1;
              if (bit == 0) {
                  combinacion_actual += 'a';
              } else {
                  combinacion_actual += 'b';
              }
          }
          cadenas_.push_back(combinacion_actual);
      }
    }
    for (int i = 0; i < cadenas_.size(); i++) {
      std::cout << cadenas_[i] << std::endl;
    }
  }
  void SimuladorMultiple() {
    for (int i = 0; i < cadenas_.size(); i++) {
      cadena_ = cadenas_[i];
      std::cout << "La cadena a simular es: " << cadena_ << std::endl; 
      SimuladorCadena();
    }
  }
private:
  std::map<int, Estado> estados_;
  std::map<int, std::map<char, int>> transiciones_;
  std::vector<std::string> content;
  std::vector<std::string> cadenas_;  
  int estado_inicial_; 
  std::string cadena_;
  Alfabeto alfabeto_;
};

#endif