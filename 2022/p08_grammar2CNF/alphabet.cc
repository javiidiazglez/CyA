/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingenierıa Informatica
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 8: Gramáticas en Forma Normal de Chomsky
 * 
 * @author José Javier Díaz González
 * Correo: alu0101128894@ull.edu.es
 *
 * @date 24/11/2022
 * @file alphabet.cc: clase alphabet (alphabet, alfabeto).
 * @brief Contiene definiciones de las funciones de la clase alphabet.
 *
 * 24/11/2022 - Actualización (finalizacion) del alphabet.cc
 **/ 

#include "alphabet.h"

/** Insertar un símbolo en el alfabeto.
 * @param symbol Symbol
 */
void Alphabet::insert(const Symbol& symbol) { alphabet_.insert(symbol); }

/** Comprobar si un símbolo está en el alfabeto.
 * @param symbol comprobar symbol
 * @return Verdadero si está, falso en otro caso
 */
bool Alphabet::check(Symbol sym) {
  if (sym.getData() == "&") return true;
  for (const auto& symbol : alphabet_) {
    if (sym == symbol) return true;
  }
  return false;
}
/** Funcion para imprimir el alfabeto
 * @param os
 * @param alphabet Alfabeto a imprimir
 */
std::ostream& operator<<(std::ostream& os, const Alphabet& alphabet) {
  os << "{ ";
  for (const auto& symbol : alphabet.alphabet_) {
    os << symbol << " ";
  }
  os << "}";
  return os;
}

/** Una función para imprimir un Alfabeto en un archivo
 * @param[in] os
 * @param[in] alphabet Alfabeto a imprimir
 */
std::ofstream& operator<<(std::ofstream& os, const Alphabet& alphabet) {
  os << "{ ";
  for (const auto& symbol : alphabet.alphabet_) {
    os << symbol << " ";
  }
  os << "}";
  return os;
}

/** Una sobrecarga del operador. !=
 * @param alphabet Alfabeto a comparar
 * @return Verdadadero si no son iguales, falso en otro caso
 */
bool Alphabet::operator!=(const Alphabet& alphabet) {
  return alphabet_ != alphabet.alphabet_;
}

/** Una sobrecarga del operador. ==
 * @param[in] alphabet Alfabeto a comparar
 * @return Verdadadero si no son iguales, falso en otro caso
 */
bool Alphabet::operator==(const Alphabet& alphabet) {
  return alphabet_ == alphabet.alphabet_;
}