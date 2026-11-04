#include "automata.h"

using namespace std;

int main(int argc, char* argv[]) {
  if (argc < 3) {
    std::cerr << "El número de argumentos no es correcto." << std::endl;
    return 1;
  }
  std::string archivo = argv[1];
  Automata autos(archivo);
  autos.MostrarEstados();
  std::cout << "\nPosibles transiciones: \n";
  autos.MostrarPosiblesCaminos();
}