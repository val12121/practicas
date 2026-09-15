//Números de PELL

#include <iostream>
#include <cmath>

double Pell(int num) {
  double a = pow(1 + std::sqrt(2), num);
  double b = pow(1 - std::sqrt(2), num);
  double c = 2 * std::sqrt(2);
  double resultado = (a - b) / c;
  return resultado;
}

void Show(int number) {
  for (int i = 0; i < number; i++) {
    if (i == 0 || i == 1) {
      std::cout << i << " ";
    }
    else {
      std::cout << Pell(i) << " ";
    }
  }
  std::cout << std::endl;
}

void Usage(int argc, char* argv[]) {
  if (argc != 2) {
    printf("Usage: %s <nombre>\n", argv[0]);
    return 1;
  }
}

int main(int argc, char* argv[]) {
  Usage(argc, argv);
  Show(std::stoi(argv[1]));
}