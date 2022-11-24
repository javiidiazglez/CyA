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
 * @file state.h: clase State (estado)
 * @brief Contiene la declaración de la clase State.
 *
 * 17/11/2022 - Actualización (finalizacion) del state.h
 **/

#ifndef STATE_H_
#define STATE_H_

#include <cstdio>
#include <iostream>
#include <set>
#include <vector>

#include "transition.h"

class State {
 public:
  // Constructores y Destructores
  State() : identifier_(-1), transitions_(){};
  ~State() { clear(); };
  State(int stateID) : identifier_(stateID), transitions_(){};
  State(const State&);
  State(std::set<Transition>&, int&);
  
  // setter
  void setIdentifier(int identifier) { identifier_ = identifier; };
  int getIdentifier() const { return identifier_; };
  std::set<Transition> getTransitions() const { return transitions_; };
  int getTansitionSize() const { return transitions_.size(); }

  // Funciones
  void clear();
  void setNextState(int, Symbol&);
  std::set<int> getNextStateID(Symbol&) const;
  bool hasEpsTransitions();
  int numberOfTransitions() const;
  std::vector<int> getEpsTransitions() const;
  bool symbolIsUsed(Symbol&) const;
  
  // Sobrecargas
  State& operator=(const State&);
  bool operator==(const State&) const;
  bool operator<(const State&) const;

 private:
  std::set<Transition> transitions_; // Un conjunto de transiciones.
  int identifier_; // El identificador del estado.
};

#endif