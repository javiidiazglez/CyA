// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Simulacion de Autómatas Finitos
// Autor: José Javier Díaz González
// Correo: alu0101128894@ull.es
// Fecha: 10/11/2022
// Archivo alphabet.h
// Definición de la clase
// Historial de revisiones
// 10/11/2022 - Actualización (primera versión) del alphabet.h
// 10/11/2022 - Finalización practica 6

#ifndef ALPHABET_H_
#define ALPHABET_H_

#include <set>
#include <vector>

#include "symbol.h"

const std::string NOT_EMPTY = "notempty";

class Alphabet {
 public:
  Alphabet();  // El constructor predeterminado de la clase Alfabeto.

  Alphabet(const std::vector<Symbol>&);  // Un constructor que toma un vector de símbolos y crea un alfabeto con ellos.
  Alphabet(const std::set<Symbol>&);     // Un constructor que toma un conjunto de símbolos y crea un alfabeto con ellos.
  ~Alphabet() { symbols_.clear(); }      // El destructor de la clase Alfabeto. Se utiliza para liberar la memoria asignada para el objeto.

  Symbol GetSymbol(int) const;                     // Un método que devuelve el símbolo en la posición indicada por el parámetro.
  int GetSize() const { return symbols_.size(); }  // Un método que devuelve el tamaño del alfabeto.

  void operator=(const std::vector<Symbol>&);  // Una sobrecarga de operadores que nos permite asignar un vector de símbolos a un alfabeto.
  void operator=(const Alphabet&);             // Un método que nos permite asignar un alfabeto a otro alfabeto.

  friend bool operator==(const std::vector<Symbol>&, const Alphabet&);  // Una función amiga que compara dos alfabetos.
  friend bool Contains(const Symbol&, const Alphabet&);                 // Una función que verifica si un símbolo está en un alfabeto.
  friend Alphabet Union(const Alphabet&, const Alphabet&);              // Una función que devuelve un alfabeto que es la unión de dos alfabetos.

 private:
  std::set<Symbol> symbols_;  // Un conjunto de símbolos.
};

bool operator==(const std::vector<Symbol>&, const Alphabet&);  // Una función amiga que compara dos alfabetos.
bool Contains(const Symbol&, const Alphabet&);                 // Una función que verifica si un símbolo está en un alfabeto.
Alphabet Union(const Alphabet&, const Alphabet&);              // Una función que devuelve un alfabeto que es la unión de dos alfabetos.

#endif