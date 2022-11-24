/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingenierıa Informatica
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 7: Gramática Regular a partir de un DFA
 * 
 * @author José Javier Díaz González
 * Correo: alu0101128894@ull.edu.es
 *
 * @date 17/11/2022
 * @file alphabet.cc: clase alphabet (alphabet, alfabeto).
 * @brief Contiene definiciones de las funciones de la clase alphabet.
 *
 * 17/11/2022 - Actualización (finalizacion) del alphabet.cc
 **/ 

#include "alphabet.h"

/** Insertar un símbolo en el alfabeto.
 * @param symbol Symbol
 */
void Alphabet::insert(const Symbol& symbol) { alphabet_.insert(symbol); }

/** Comprobar si un símbolo está en el alfabeto.
 * @param symbol SYmbol to check
 * @return Verdadero si está, falso en otro caso
 */
bool Alphabet::check(Symbol symbol) {
  if (symbol.getData() == "&") return true;
  for (const auto& symbol : alphabet_) {
    if (symbol == symbol) return true;
  }
  return false;
}
/** Function to print an ALphabet
 * @param[in] os
 * @param[in] alphabet The Alphabet to be printed
 */
std::ostream& operator<<(std::ostream& os, const Alphabet& alphabet) {
  os << "{ ";
  for (const auto& symbol : alphabet.alphabet_) {
    os << symbol << " ";
  }
  os << "}";
  return os;
}

/** Una función para imprimir un Alfabeto en un archivo.
 * @param os
 * @param alphabet Alfabeto a imprimir
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