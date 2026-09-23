#include <unordered_set>
#include "alphabet.h"


class Chain {
  public:
    Chain() {}
    Chain(std::string chain, std::vector<char> alphabet) : chain_(chain), 
    alphabet_(alphabet) {}
    int Longitud() {
      int i = 0;
      for (const auto& element : chain_) {
        i++;
      }
      return i; 
    }
    
    void Inversa() {
      this->Show();
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
        std::string entrada = "";
        // Construye el prefijo desde el inicio hasta la posición i
          for (size_t j = 0; j <= i; ++j) {
            entrada += chain_[j];
          }
        prefixes.push_back(entrada);
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
      for (int i = chain_.size() - 1; i >= 0; --i) {
        suffixes.push_back(chain_.substr(i));
      }

      for (int i = 0; i < suffixes.size(); i++) {
        std::cout << suffixes[i] << " ";
      }
      std::cout << std::endl;
      return suffixes;
    }

    bool Verification () {
      if (alphabet_.get_size() != chain_.size()) {
        return false;
      }
      for (int i = 0; i < chain_.size(); i++) {
        if (alphabet_.found(chain_[i]) != true) {
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
    void Show() {
      for (const auto& element: chain_) {
        std::cout << element;
      }
    }
  private:
    Alphabet alphabet_;
    std::string chain_;
};