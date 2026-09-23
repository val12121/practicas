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
#include <map>

class MultipleGrades {
  public:
    MultipleGrades() {}
    MultipleGrades(std::string alu, double grade) : students_{{alu, grade}} {}
    
    bool Search (std::string alu) {
      auto aux = this->students_.find(alu);
      if (aux != this->students_.end()) {
        return true;
      }
      return false;
    }
    void Add(std::string alu, double grade) {
      this->students_.insert(std::make_pair(alu, grade));
    }

    void Show() {
      std::string previous_alu;
      double media = 0;
      int i = 0;
     
      for (const auto& pair : this->students_) {
        if (pair.first != previous_alu) {
          if (previous_alu.empty()) { std::cout << std::endl; }
          else {
            i++;
            media = media / i;
            previous_alu = pair.first;
            std::cout << pair.first << " " << media << std::endl;
            media = 0;
            i = 0;
          }
        }
        i++;
        media += pair.second;
      }
    }
    friend std::ostream& operator<<(std::ostream& os, const MultipleGrades& multiple) {
      std::string previous_alu;
      for (const auto& pair : multiple.students_) {
        if (pair.first != previous_alu) {
          if (!previous_alu.empty()) { os << std::endl; }
          os << pair.first << ": ";
          previous_alu = pair.first;
        }
        os << pair.second << " ";                       
      }
      os << std::endl;
      return os;
    }

  private:
    std::multimap<std::string, double> students_;
};