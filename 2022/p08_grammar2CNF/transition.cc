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
 * @file transition.cc
 * @brief Contiene implementacion de la clase transition
 *
 * 24/11/2022 - Actualización (finalizacion) del transition.cc
 **/

#include "transition.h"

// Constructores
Transition::Transition() : symbol_(), nextStateID_() {}
Transition::Transition(int nextState, Symbol& symbol) : symbol_(symbol), nextStateID_(nextState) {}

Transition::Transition(const Transition& newTransition) {
  symbol_ = newTransition.symbol_;
  nextStateID_ = newTransition.nextStateID_;
}

// Sobrecarga operador ==
Transition& Transition::operator=(const Transition& rhs) {
  this->symbol_ = rhs.symbol_;
  this->nextStateID_ = rhs.nextStateID_;
}

// Sobrecarga operador == (bool)
bool Transition::operator==(const Transition& rhs) {
  if ((this->symbol_ == rhs.symbol_) && (this->nextStateID_ == rhs.nextStateID_))
    return true;
  else
    return false;
}

// Sobrecarga del operador menor (Set)
bool Transition::operator<(const Transition& rhs) const {
  if (this->symbol_ <= rhs.getSymbol())
    return true;
  else
    return false;
}

// Destructor
Transition::~Transition() {
  symbol_ = Symbol('0');
  nextStateID_ = -1;
}
