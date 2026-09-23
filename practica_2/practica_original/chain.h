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
// Se declara la Clase Chain y sus funciones 
// Referencias:
// Enlaces de inter´es
// Historial de revisiones
// 22/09/2026 - Creaci´on (primera versi´on) del c´odigo

#ifndef CHAIN_H_
#define CHAIN_H_

#include <vector>
#include <string>
#include <iostream>
#include "alphabet.h"

class Chain {
 public:
  Chain() = default;
  Chain(const std::string& chain, const std::string& alphabet) 
      : chain_(chain), alphabet_(alphabet) {}

  int Longitud() const {
    return chain_.size();
  }

  Chain Potencia(int n) const {
    Chain new_chain; 
    for (int i = 0; i < n; i++) {
      new_chain.Insert(chain_);
    }
    new_chain.alphabet_.set_alfabeto(this->alphabet_.get_alphabet());
    return new_chain;
  }

  void Insert (std::string chain) {
    chain_ += chain; 
  }

  void Inversa() const;

  std::vector<std::string> Prefixes() const ;

  std::vector<std::string> Suffixes() const ;

  bool Verification() const ;

  friend std::ostream& operator<<(std::ostream& os, const Chain& chain) {
    for (const auto& element : chain.chain_) {
      os << element;
    }
    os << " : {";
    for (const auto& element : chain.alphabet_.get_alphabet()) {
      os << element << ", ";
    }
    os << "}"; 
    return os;
  }

 private:
  Alphabet alphabet_;
  std::string chain_;
};

#endif  // CHAIN_H_