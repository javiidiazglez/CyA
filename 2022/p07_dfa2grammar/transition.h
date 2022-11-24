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
 * @file transition.h
 * @brief Contiene declaracion de la clase transition
 *
 * 17/11/2022 - Actualización (finalizacion) del transition.h
 **/

#ifndef TRANSITION_H_
#define TRANSITION_H_

#include <cstdio>
#include <iostream>
#include <set>

#include "symbol.h"

class Transition {
 public:
  // Constructores y Destructores
  Transition();
  ~Transition();
  Transition(int, Symbol&);       // Un constructor que toma un int y un símbolo como parámetros.
  Transition(const Transition&);  // Un constructor de copias.

  // Getter y Setter
  Symbol getSymbol() const { return symbol_; };
  int getNextStateID() const { return nextStateID_; };

  // Sobrecargas
  Transition& operator=(const Transition&);
  bool operator==(const Transition&);
  bool operator<(const Transition&) const;

 private:
  Symbol symbol_; // Un miembro privado de la clase Transición.
  int nextStateID_;  //   La siguiente identificación del estado.
};

#endif