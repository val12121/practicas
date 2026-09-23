// Universidad de La Laguna
// Escuela Superior de Ingenier´ıa y Tecnolog´ıa
// Grado en Ingenier´ıa Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Pr´actica 1: Contenedores asociativos
// Autor: Camila Valentina Alonso Yepez
// Correo: alu0101548999@ull.edu.es
// Fecha: 15/09/2026
// Archivo main.cc: programa principal desde el que se crearan los objetos.
// Contiene la funci'on main del proyecto 
// Referencias:
// Enlaces de inter´es
// Historial de revisiones

#include <iostream>
#include <fstream>
#include <sstream>
#include "p01_single_grades.h"
#include "p01_multiple_grades.h"

int main (int argc, char* argv[]) {
  //Calificacion unica por estudiante
  std::string way = argv[1];
  std::ifstream file(way);

  if(!file.is_open()) {
    std::cerr << "Error: No se pudo abrir el archivo '" << way << "'\n";
    return 1;
  }
  
  MultipleGrades students;
  std::string line;
  int lines;
  
  while (std::getline(file, line)) {
    std::stringstream ss(line);
    std::string alu;
    double grade;
    ss >> alu >> grade;
    students.Add(alu, grade);
  }

  if (!argv[2]) {
    std::cout << students;
  } else {
    students.Show();
  }

}