#ifndef CHAIN_H_
#define CHAIN_H_

#include <iostream>
#include <string>
#include <vector>
#include "alphabet.h"

class Chain {
 public:
  Chain() = default;
  Chain(const std::string& chain, const std::string& alphabet) 
      : chain_(chain), alphabet_(alphabet) {}

  int Longitud() const {
    return static_cast<int>(chain_.size());
  }
  void Potencia(int iter) const {
    for (int i = 0; i < iter; i++) {
      std::cout << chain_;
    }
    std::cout << std::endl;
  }

  void Inversa() const {
    for (const auto& element: chain_) {
      std::cout << element;
    }
    std::cout << " -> ";
    std::vector<char> inverso (chain_.begin(), chain_.end());
    for (int i = inverso.size() - 1; i >= 0 ; i--) {
      std::cout << inverso[i];
    }
    std::cout << std::endl;
  }

  std::vector<std::string> Prefixes() const {
    std::vector<std::string> prefixes;
    prefixes.push_back("&");
    for (size_t i = 0; i < chain_.size(); ++i) {
      prefixes.push_back(chain_.substr(0, i + 1));
    }
    for (int i = 0; i < prefixes.size(); i++) {
      std::cout << prefixes[i] << " ";
    }
    std::cout << std::endl;
    return prefixes;
    
  }

  std::vector<std::string> Suffixes() const {
    std::vector<std::string> suffixes;
    suffixes.push_back("&");
    for (int i = static_cast<int>(chain_.size()) - 1; i >= 0; --i) {
      suffixes.push_back(chain_.substr(i));
    }
    for (int i = 0; i < suffixes.size(); i++) {
      std::cout << suffixes[i] << " ";
    }
    std::cout << std::endl;
    return suffixes;
  }

  bool Verification() const {
    for (char symbol : chain_) {
      if (!alphabet_.found(symbol)) {
        return false;
      }
    }
    return true;
  }

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