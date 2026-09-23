#ifndef ALPHABET_H_
#define ALPHABET_H_

#include <iostream>
#include <set>
#include <string>

class Alphabet {
 public:
  Alphabet() = default;
  Alphabet(const std::string& alfabeto_inicial) {
    for (char letter : alfabeto_inicial) {
      alfabeto_inicial_.insert(letter);
    }
  }

  void Show() const {
    for (char element : alfabeto_inicial_) {
      std::cout << element << " ";
    }
    std::cout << "\n";
  }

  size_t get_size() const {
    return alfabeto_inicial_.size();
  }

  void set_alfabeto(std::set<char> alfabeto_nuevo) {
    for (const auto& elemento : alfabeto_nuevo) {
      alfabeto_inicial_.insert(elemento);
    }
  } 

  bool found(char symbol) const {
    return alfabeto_inicial_.find(symbol) != alfabeto_inicial_.end();
  }

  const std::set<char>& get_alphabet() const { 
    return alfabeto_inicial_; 
  }

 private: 
  std::set<char> alfabeto_inicial_;
};

#endif  // ALPHABET_H_