// Universidad de La Laguna
// Escuela Superior de Ingenier´ıa y Tecnolog´ıa
// Grado en Ingenier´ıa Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Pr´actica 2: Cadenas y lenguajes
// Autor: Camila Valentina Alonso Yepez
// Correo: alu0101548999@ull.edu.es
// Fecha: 16/09/2025
// Archivo cya-P02-strings.cc: main.cc.
// Contiene la funci´on main del proyecto que usa las clases Alphabet y Chain para
// cumplimentar los distintos requisitos reequeridos por la práctica
// Referencias:
// Enlaces de inter´es
// Historial de revisiones
// 22/09/2026 - Creaci´on (primera versi´on) del c´odigo

#include <iostream>
#include <set>
#include <fstream>
#include "chain.h"

void PrintUsage(const std::string& program_name) {
  std::cout << "Uso: " << program_name << " filein.txt fileout.txt opcode\n";
  std::cout << "Pruebe '" << program_name << " --help' para mas informacion.\n";
}

void PrintHelp() {
  std::cout << "Modo de empleo: ./cya-P02-strings filein.txt fileout.txt opcode\n\n";
  std::cout << "Opciones de opcode:\n";
  std::cout << "  1: Alfabeto asociado a la cadena\n";
  std::cout << "  2: Longitud de la cadena\n";
  std::cout << "  3: Inversa de la cadena\n";
  std::cout << "  4: Prefijos de la cadena\n";
  std::cout << "  5: Sufijos de la cadena\n";
  std::cout << "  6: Verificacion de simbolos\n";
}

int main(int argc, char* argv[]) {
  
  if (argc == 2 && std::string(argv[1]) == "--help") {
    PrintHelp();
    return 0;
  }

  if (argc != 4 && argv[3][0] != '7') {
    PrintUsage(argv[0]);
    return 1;
  }

  std::string filein_path = argv[1];
  std::string fileout_path = argv[2];
  char opcode = argv[3][0]; //porque el argv es un string

  std::ifstream input_file(filein_path);
  if (!input_file.is_open()) {
    std::cerr << "Error: no se pudo abrir el archivo de entrada: " << filein_path << "\n";
    return 1;
  }

  std::ofstream output_file(fileout_path);
  if (!output_file.is_open()) {
    std::cerr << "Error: no se pudo abrir el archivo de salida: " << fileout_path << "\n";
    return 1;
  }

  // Lectura del fichero en un vector de Chain
  std::vector<Chain> chains;
  std::string word, alphabet_str;
  while (input_file >> word >> alphabet_str) {
    chains.emplace_back(word, alphabet_str);
  }
  input_file.close();

  for (const auto& current_chain : chains) {
    switch (opcode)
    {
    case '1':
      std::cout << "Has elegido la opción 1: Alfabeto\n";
      std::cout << current_chain << std::endl;
      break;
    case '2': 
      std::cout << "Has elegido la opcion 2: Longitud\n";
      std::cout << current_chain.Longitud() << std::endl;
      break;
    case '3':
      std::cout << "Has elegido la opcion 3: Inversa\n";
      current_chain.Inversa();
      break;
    case '4':
      std::cout << "Has elegido la opcion 4: Prefijos\n";
      current_chain.Prefixes();
      break;
    case '5':
      std::cout << "Has elegido la opcion 5: Sufijos\n";
      current_chain.Suffixes();
      break;
    case '6':
      std::cout << "Has elegido la opcion 6: Verificacion\n";
      if (current_chain.Verification()) {
        std::cout << "OK\n";
      } else {
        std::cout << "ERROR\n";
      }
      break;
    case '7':
      std::cout << "Has elegido la opcion 7: Potencia\n";
      current_chain.Potencia((int)(argv[4][0] - '0'));
      break;
    default:
      break;
    }
  }
}