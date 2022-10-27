// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica #03: Calculadora de lenguajes formales
// Autor: José Javier Díaz González
// Correo: alu0101128894@ull.es
// Fecha: 20/10/2022
// Archivo Alphabet.cc
// Definición de la clase
// Historial de revisiones
// 20/10/2022 - Actualización (primera versión) del Alphabet.cc
// 20/10/2022 - Finalización práctica 3

#include "../include/Alphabet.h"

// Inserta un símbolo en el alfabeto.
void Alphabet::InsertSymbol(const Symbol& symbol) { alphabet_.insert(symbol); }

// Comprobar si un símbolo está en el alfabeto.
bool Alphabet::CheckSymbol(Symbol sim_1) {
  // Comprobando si el símbolo es el símbolo vacío.
  if (sim_1.getDataSymbol() == "&") return true;
  // Iterando a través del conjunto de alfabeto_
  // y verificando si el símbolo es igual al símbolo pasado por parámetro.
  for (const auto& symbol : alphabet_) {
    if (sim_1 == symbol) return true;
  }
  return false;
}

// Una función que imprime el alfabeto en la consola.
std::ostream& operator<<(std::ostream& os, const Alphabet& alphabet) {
  os << "{ ";
  for (const auto& symbol : alphabet.alphabet_) {
    os << symbol << " ";
  }
  os << "}";
  return os;
}

// Una función que imprime un alfabeto en un archivo de salida.
std::ofstream& operator<<(std::ofstream& os, const Alphabet& alphabet) {
  os << "{ ";
  for (const auto& symbol : alphabet.alphabet_) {
    os << symbol << " ";
  }
  os << "}";
  return os;
}

// Compara dos alfabetos y devuelve verdadero si son diferentes y falso si son iguales.
bool Alphabet::operator!=(const Alphabet& alphabet2) {
  return alphabet_ != alphabet2.alphabet_;  // verdadero si los alfabetos no son iguales, falso si son iguales
}

// Comparar dos alfabetos y devolver verdadero si son iguales y falso si no son iguales.
bool Alphabet::operator==(const Alphabet& alphabet) {
  return alphabet_ == alphabet.alphabet_;
}