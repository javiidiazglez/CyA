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
 * @file alphabet.h: clase alphabet (alphabet, alfabeto).
 * @brief Contiene definiciones de las funciones de la clase alphabet.
 *
 * 17/11/2022 - Actualización (finalizacion) del alphabet.h
 **/

#ifndef ALPHABET_H_
#define ALPHABET_H_

#include <set>

#include "symbol.h"

/** Class Alphabet:
 * Definición de una clase llamada Alfabeto.
 */
class Alphabet {
 public:
  Alphabet() = default;  // Un constructor predeterminado.
  ~Alphabet(){};         // Un destructor.

  std::set<Symbol> getAlphabet() { return alphabet_; };  // Una función captadora.
  int getAlphabetSize() { return alphabet_.size(); }     // Una función que devuelve el tamaño del alfabeto.

  void insert(const Symbol&);  // Insertar un símbolo en el alfabeto.
  bool check(Symbol);          // Comprobar si un símbolo está en el alfabeto.

  friend std::ostream& operator<<(std::ostream&, const Alphabet&);    // Una función amiga que nos permite imprimir el alfabeto.
  friend std::ofstream& operator<<(std::ofstream&, const Alphabet&);  // Una función amiga que nos permite imprimir el alfabeto en un archivo.

  bool operator!=(const Alphabet&);  // Sobrecarga !=
  bool operator==(const Alphabet&);  // Sobrecarga ==

 private:
  std::set<Symbol> alphabet_;  // Un conjunto de símbolos.
};

#endif