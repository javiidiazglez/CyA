// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica #02: Operaciones con lenguajes
// Autor: José Javier Díaz González
// Correo: alu0101128894@ull.es
// Fecha: 12/10/2022
// Archivo Alphabet.h
// Definición de la clase
// Historial de revisiones
// 12/10/2022 - Actualización (primera versión) del Alphabet.h
// 12/10/2022 - Finalización práctica 2

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
  bool operator!=(const Alphabet&);  // Una sobrecarga de operador para el operador !=.

  int getSize() const { return alphabet_.size(); }       // Un getter para el tamaño del alfabeto.
  std::set<Symbol> getAlphabet() { return alphabet_; };  // Un getter para el alfabeto.

  friend std::ostream& operator<<(std::ostream&, const Alphabet&);    // Imprime un alfabeto en la consola.
  friend std::ofstream& operator<<(std::ofstream&, const Alphabet&);  // Imprime un alfabeto en un archivo de salida.

 private:
  std::set<Symbol> alphabet_;  // Un conjunto de símbolos.
};

#endif