// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica #03: Calculadora de lenguajes formales
// Autor: José Javier Díaz González
// Correo: alu0101128894@ull.es
// Fecha: 20/10/2022
// Archivo Alphabet.h
// Definición de la clase
// Historial de revisiones
// 20/10/2022 - Actualización (primera versión) del Alphabet.h
// 20/10/2022 - Finalización práctica 3

#ifndef ALPHABET_H_
#define ALPHABET_H_

#include <set>

#include "Symbol.h"

// Definición de la clase Alfabeto.
class Alphabet {
 public:
  Alphabet() = default;  // El constructor predeterminado.
  ~Alphabet(){};         // Destructor

  void InsertSymbol(const Symbol&);  // Insertar un símbolo en el alfabeto.
  bool CheckSymbol(Symbol);

  int getSize() const { return alphabet_.size(); }       // Un getter para el tamaño del alfabeto.
  std::set<Symbol> getAlphabet() { return alphabet_; };  // Un getter para el alfabeto.

  friend std::ostream& operator<<(std::ostream&, const Alphabet&);    // Imprime un alfabeto en la consola.
  friend std::ofstream& operator<<(std::ofstream&, const Alphabet&);  // Imprime un alfabeto en un archivo de salida.

  bool
  operator!=(const Alphabet&);       // Sobrecarga de operador para el operador !=.
  bool operator==(const Alphabet&);  // Sobrecarga de operador para el operador ==.

 private:
  std::set<Symbol> alphabet_;  // Un conjunto de símbolos.
};

#endif