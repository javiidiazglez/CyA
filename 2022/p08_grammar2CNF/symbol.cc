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
 * @file symbol.cc: clase Symbol
 * @brief Contiene definiciones de la clase Symbol.
 *
 * 24/11/2022 - Actualización (finalizacion) del symbol.cc
 **/

#include "symbol.h"

/** Una sobrecarga del operador para imprimir un símbolo
 * @param os
 * @param symbol symbol
 */
std::ostream& operator<<(std::ostream& os, const Symbol& symbol) {
  os << symbol.getData();
  return os;
}

/** Una sobrecarga del operador para imprimir un símbolo
 * @param os
 * @param symbol symbol
 */
std::ofstream& operator<<(std::ofstream& os, const Symbol& symbol) {
  os << symbol.getData();
  return os;
}

/** Sobrecarga <
 * @param symbol_1 primer simbolo
 * @param symbol_2 segundo simbolo
 */
bool operator<(const Symbol& symbol_1, const Symbol& symbol_2) {
  return symbol_1.getData() < symbol_2.getData();
}
/** Sobrecarga ==
 * @param symbol_1 primer simbolo
 * @param symbol_2 segundo simbolo
 */
bool operator==(const Symbol& symbol_1, const Symbol& symbol_2) {
  return symbol_1.getData() == symbol_2.getData();
}
/** Sobrecarga !=
 * @param symbol_1 primer simbolo
 * @param symbol_2 segundo simbolo
 */
bool operator!=(const Symbol& symbol_1, const Symbol& symbol_2) {
  return !(symbol_1 == symbol_2);
}

/** Sobrecarga <=
 * @param symbol_1 primer simbolo
 * @param symbol_2 segundo simbolo
 */
bool operator<=(const Symbol& symbol_1, const Symbol& symbol_2) {
  return symbol_1.getData() <= symbol_2.getData();
}