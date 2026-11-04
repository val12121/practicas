#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

class Estado{
  public:
    Estado() {}
    Estado(bool acept) : aceptado_(acept) {}
    void set_estado(bool nuevo) { aceptado_ = nuevo; }
    void set_inicial(bool nuevo) { inicial_ = nuevo; }
    bool get_estado() const { return aceptado_; }
  private:
    bool aceptado_ = false;
    bool inicial_ = false;
};