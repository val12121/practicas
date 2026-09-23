// Universidad de La Laguna
// Escuela Superior de Ingenier´ıa y Tecnolog´ıa
// Grado en Ingenier´ıa Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Pr´actica 2: Cadenas y lenguajes
// Autor: Camila Valentina Alonso Yepez
// Correo: alu0101548999@ull.edu.es
// Fecha: 16/09/2025
// Archivo cya-P02-strings.cc: chain.cc.
// Contiene la función chain.cc, donde se inicializan las funciones de la clase Chain
// Referencias:
// Enlaces de inter´es
// Historial de revisiones
// 22/09/2026 - Creaci´on (primera versi´on) del c´odigo

#include "chain.h"

void Chain::Inversa() const
{
  for (const auto &element : chain_)
  {
    std::cout << element;
  }
  std::cout << " -> ";
  std::vector<char> inverso(chain_.begin(), chain_.end());
  for (int i = inverso.size() - 1; i >= 0; i--)
  {
    std::cout << inverso[i];
  }
  std::cout << std::endl;
}

std::vector<std::string> Chain::Prefixes() const
{
  std::vector<std::string> prefixes;
  prefixes.push_back("&");
  for (size_t i = 0; i < chain_.size(); ++i)
  {
    prefixes.push_back(chain_.substr(0, i + 1));
  }
  for (int i = 0; i < prefixes.size(); i++)
  {
    std::cout << prefixes[i] << " ";
  }
  std::cout << std::endl;
  return prefixes;
}

std::vector<std::string> Chain::Suffixes() const
{
  std::vector<std::string> suffixes;
  suffixes.push_back("&");
  for (int i = static_cast<int>(chain_.size()) - 1; i >= 0; --i)
  {
    suffixes.push_back(chain_.substr(i));
  }
  for (int i = 0; i < suffixes.size(); i++)
  {
    std::cout << suffixes[i] << " ";
  }
  std::cout << std::endl;
  return suffixes;
}

bool Chain::Verification() const
{
  for (char symbol : chain_)
  {
    if (!alphabet_.found(symbol))
    {
      return false;
    }
  }
  return true;
}