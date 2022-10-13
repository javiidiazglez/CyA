// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica #02: Operaciones con lenguajes
// Autor: José Javier Díaz González
// Correo: alu0101128894@ull.es
// Fecha: 12/10/2022
// Archivo Symbol.cc
// Definición de la clase
// Historial de revisiones
// 12/10/2022 - Actualización (primera versión) del Symbol.cc
// 12/10/2022 - Finalización práctica 2

#include "Symbol.h"

// Una función que imprime un símbolo.
std::ostream& operator<<(std::ostream& os, const Symbol& symbol) {
  os << symbol.getDataSymbol();
  return os;
}

//Una función que imprime un símbolo en un archivo.
std::ofstream& operator<<(std::ofstream& os, const Symbol& symbol) {
  os << symbol.getDataSymbol();
  return os;
}

// Comparar dos símbolos para ver si son iguales.
bool operator==(const Symbol& symbol_1, const Symbol& symbol_2) {
  return symbol_1.getDataSymbol() == symbol_2.getDataSymbol();
}

// Comparar dos símbolos para ver si son diferentes.
bool operator!=(const Symbol& symbol_1, const Symbol& symbol_2) {
  return !(symbol_1 == symbol_2);
}

// Comparar dos símbolos para ver es menor que otro.
bool operator<(const Symbol& symbol_1, const Symbol& symbol_2) {
  return symbol_1.getDataSymbol() < symbol_2.getDataSymbol();
}
