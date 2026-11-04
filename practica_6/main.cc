#include "automata.h"

using namespace std;

void Help() {
  std::cout << "\n[OBJETIVO]: El objetivo principal de este programa es simular las transiciones de\n" 
            << "un DFA y mostrar cuales cadenas son aceptadas por el mismo\n"
            << "\n[MODO DE EMPLEO]: ./main [archivo .dfa] [archivo entrada.txt] [archivo salida .txt]\n\n";
}

int main(int argc, char* argv[]) {
  if (argc < 4) {
    std::cerr << "ERROR: El número de argumentos no es correcto." << std::endl;
    Help();
    return 1;
  } 
  std::string archivo = argv[1];
  Automata autos(archivo);
  autos.MostrarEstados();
  std::cout << "\nPosibles transiciones: \n";
  autos.MostrarPosiblesCaminos();
  autos.SimuladorCadena(std::string(argv[3]));
}