// Universidad de La Laguna
// Escuela Superior de Ingenier´ıa y Tecnolog´ıa
// Grado en Ingenier´ıa Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Pr´actica 2: Cadenas y lenguajes
// Autor: Nombre y Apellidos
// Correo: alu0101548999@ull.edu.es
// Fecha: 16/09/2025
// Archivo cya-P02-strings.cc: programa cliente.
// Contiene la funci´on main del proyecto que usa las clases X e Y
// para ... (indicar brevemente el objetivo)
// Referencias:
// Enlaces de inter´es
// Historial de revisiones
// 16/09/2025 - Creaci´on (primera versi´on) del c´odigo

#include <iostream>
#include <set>
#include "chain.h"

int main(int argc, char* argv[]) {
  std::vector<char> vector_prueba = {'a', 'b', 'c', 'e'};
  std::string chain = "cabe"; 
  Chain chainy(chain, vector_prueba);
  std::string option; 
  
  if (argc > 0) {
    option = argv[1];
  }

  switch (option[0])
  {
  case '1':
    std::cout << "Has elegido la opción 1: Alfabeto\n";
    std::cout << chainy << std::endl;
    break;
  case '2': 
    std::cout << "Has elegido la opcion 2: Longitud\n";
    std::cout << chainy.Longitud() << std::endl;
    break;
  case '3':
    std::cout << "Has elegido la opcion 3: Inversa\n";
    chainy.Inversa();
    break;
  case '4':
    std::cout << "Has elegido la opcion 4: Prefijos\n";
    chainy.Prefixes();
    break;
  case '5':
    std::cout << "Has elegido la opcion 5: Sufijos\n";
    chainy.Suffixes();
    break;
  case '6':
    std::cout << "Has elegido la opcion 6: Verificacion\n";
    if (chainy.Verification()) {
      std::cout << "OK\n";
    } else {
      std::cout << "ERROR\n";
    }
    break;
  default:
    break;
  }
}