// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica #02: Operaciones con lenguajes
// Autor: José Javier Díaz González
// Correo: alu0101128894@ull.es
// Fecha: 12/10/2022
// Archivo Alphabet.cc
// Definición de la clase
// Historial de revisiones
// 12/10/2022 - Actualización (primera versión) del Alphabet.h
// 12/10/2022 - Finalización práctica 2

#include "Alphabet.h"

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

// Una función que compara dos alfabetos y devuelve verdadero si son diferentes y falso si son iguales.
bool Alphabet::operator!=(const Alphabet& alphabet_2) {
  return alphabet_ != alphabet_2.alphabet_;
}