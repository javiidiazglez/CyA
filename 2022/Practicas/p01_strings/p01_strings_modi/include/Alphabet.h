// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Símbolos, alfabetos y cadenas
// Autor: José Javier Díaz González
// Correo: alu0101128894@ull.es
// Fecha: 06/10/2022
// Archivo Alphabet.h
// Definición de la clase
// Historial de revisiones
// 06/10/2022 - Actualización (segunda versión) del String.h

#ifndef ALPHABET_H
#define ALPHABET_H

#include <vector>

#include "Symbol.h"

const std::string NOT_EMPTY = "Not";
const std::string MAX = "Max";

class Alphabet
{
 public:
  Alphabet();                            // Un constructor que crea un alfabeto con un solo símbolo "Not" (Alfabeto vacio = asigna)
  Alphabet(const std::vector<Symbol>&);  // Un constructor que toma un vector de símbolos y los copia en el alfabeto.

  // Destructor
  ~Alphabet() { alphabet_symbols_.clear(); }  // El destructor de la clase Alfabeto. Se utiliza para liberar la memoria asignada para el vector alphabet_symbols_.

  Symbol GetSymbol(int) const;  // Una función que devuelve el símbolo en la posición del alfabeto que se pasa como parámetro.

  int GetSize() const { return alphabet_symbols_.size(); }  // Una función que devuelve el tamaño del alfabeto.

  void operator=(const std::vector<Symbol>&);
  void operator=(const Alphabet&);

  void Write(std::fstream&) const;

  friend bool Exists(const Symbol&, const Alphabet&);  // Una función amiga de la clase Alfabeto. Se utiliza para comprobar si existe un símbolo en el alfabeto.
  friend void Sort(Alphabet&);                         // Ordenar los símbolos en el alfabeto en orden de longitud.

 private:
  std::vector<Symbol> alphabet_symbols_;
};

bool Exists(const Symbol&, const Alphabet&);  // Una función que comprueba si existe un símbolo en un alfabeto.
void Sort(Alphabet&);

#endif