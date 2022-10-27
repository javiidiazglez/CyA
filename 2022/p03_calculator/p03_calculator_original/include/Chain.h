// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica #03: Calculadora de lenguajes formales
// Autor: José Javier Díaz González
// Correo: alu0101128894@ull.es
// Fecha: 20/10/2022
// Archivo Chain.h
// Definición de la clase
// Historial de revisiones
// 20/10/2022 - Actualización (primera versión) del Chain.h
// 20/10/2022 - Finalización práctica 3


#ifndef CHAIN_H_
#define CHAIN_H_

#include <algorithm>
#include <vector>

#include "Alphabet.h"

// Definición de la cadena de clases.
class Chain {
 public:
  Chain() = default;                       // Constructor por defecto
  Chain(std::string&);                     // Un constructor que crea una cadena sin un alfabeto.
  Chain(std::string&, Alphabet&);          // Un constructor que crea una cadena con un alfabeto.
  Chain(Symbol&);                          // Un constructor que crea una cadena con un símbolo.
  Chain(std::vector<Symbol>&, Alphabet&);  // Un constructor que crea una cadena con un vector de símbolos y un alfabeto.

  ~Chain(){};  // El destructor de la clase.

  Alphabet getAlphabet() const { return alphabet_; }             // Un getter para el atributo alphabet_.
  void SetAlphabet(Alphabet alphabet) { alphabet_ = alphabet; }  // Un setter para el atributo alphabet_.
  size_t SizeChain() const;                                      // Una función que devuelve el tamaño de la cadena.

  Chain InverseChain();              // Una función que devuelve una nueva cadena que es la inversa de la cadena actual.
  Chain ConcatenationChain(Chain&);  // Una función que concatena dos cadenas.

  std::set<Chain> SetPrefix();    // Devuelve un conjunto de cadenas que son prefijos de la cadena.
  std::set<Chain> SetSuffix();    // Devuelve un conjunto de cadenas que son sufijos de la cadena.
  std::set<Chain> SetSubchain();  // Devuelve un conjunto de cadenas que son subcadenas de la cadena.

  friend std::ostream& operator<<(std::ostream&, const Chain&);
  friend std::ofstream& operator<<(std::ofstream&, const Chain&);

  bool operator<(const Chain&) const;
  bool operator==(const Chain&) const;
  bool operator!=(const Chain&) const;

 private:
  std::vector<Symbol> chain_;  // Un vector de símbolos.
  Alphabet alphabet_;          // Declarar una variable de tipo Alfabeto.
};

#endif