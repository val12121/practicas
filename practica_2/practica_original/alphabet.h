#include <iostream>
#include <fstream>
#include <vector>
#include <set>

class Alphabet {
  public:
    Alphabet() {}
    Alphabet(std::vector<char> alfabeto_inicial) {
      for (char letter : alfabeto_inicial) {
        alfabeto_inicial_.insert(letter);
      }
    }
    void Show() {
      for (const auto& element : alfabeto_inicial_) {
        std::cout << element << " ";
      }
      std::cout << std::endl;
    }
    const int get_size() {
      int i = 0;
      for (const auto& element : alfabeto_inicial_) {
        i++;
      }
      return i;
    }
    bool found(char symbol) {
      if (alfabeto_inicial_.find(symbol) != alfabeto_inicial_.end()) {
        return true;
      }
      return false;
    }
    const std::set<char> get_alphabet() const { return alfabeto_inicial_;}
  private: 
    std::set<char> alfabeto_inicial_;
};