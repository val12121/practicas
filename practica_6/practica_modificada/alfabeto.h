#include <iostream>
#include <fstream>

class Alfabeto {
  public:
    Alfabeto () {}
    Alfabeto (std::string alfabeto) : alfabeto_(alfabeto) {}
    void set_alfabeto(std::string alfa) { alfabeto_ = alfa; }
    friend std::ostream& operator <<(std::ostream& os, Alfabeto alph) { os << alph.alfabeto_; return os; }    
  private:
    std::string alfabeto_ = "";
};