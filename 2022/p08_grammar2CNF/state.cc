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
 * @file state.cc: clase State (estado)
 * @brief Contiene definiciones de la clase State.
 *
 * 24/11/2022 - Actualización (finalizacion) del state.cc
 **/

#include "state.h"

// Constructor
State::State(const State& newState) {
  transitions_ = newState.transitions_;
  identifier_ = newState.identifier_;
}

State::State(std::set<Transition>& vector_transition, int& id) {
  transitions_ = vector_transition;
  identifier_ = id;
}

// Destructor
void State::clear() {
  transitions_.clear();
  identifier_ = -1;
}

/** Una función para establecer el siguiente estado
 * @param nextStateID nombre estado
 * @param symbol simbolo estado siguiente
 */
void State::setNextState(int nextStateID, Symbol& symbol) {
  Transition newTransition(nextStateID, symbol);
  transitions_.insert(newTransition);
}

/** Una función para obtener el nombre del estado siguiente
 * @param symbol simbolo para saber cual es su estado siguiente
 * @return numero entero que identifica a ese estado
 */
std::set<int> State::getNextStateID(Symbol& symbol) const {
  std::set<int> result;
  for (std::set<Transition>::iterator iter{transitions_.begin()}; iter != transitions_.end(); ++iter) {
    if ((*iter).getSymbol().getData() == symbol.getData()) {
      result.insert((*iter).getNextStateID());
    }
  }
  return result;
}

/** Una función para saber si tiene epsilon transiciones
 * @return true si tiene; false en otro caso
 */
bool State::hasEpsTransitions() {
  bool result{false};
  std::set<Transition>::iterator iter{transitions_.begin()};
  while ((iter != transitions_.end()) && !result) {
    if ((*iter).getSymbol().getData() == "&")
      result = true;
    else
      ++iter;
  }
  return result;
}

/** Una función para saber numero de transiciones del estado
 * @return numero de transiciones
 */
int State::numberOfTransitions() const {
  return transitions_.size();
}

/** Una función para obtener epsilon transiciones
 * @return estados que contienen epsilon transiciones
 */
std::vector<int> State::getEpsTransitions() const {
  std::vector<int> result;
  for (std::set<Transition>::iterator iter{transitions_.begin()}; iter != transitions_.end(); ++iter) {
    if ((*iter).getSymbol().getData() == "&") {
      result.push_back((*iter).getNextStateID());
    }
  }
  return result;
}

/** Una función para encontrar un simbolo en especifico en una transicion
 * @param symbol simbolo
 * @return true si se encuentra; false en otro caso
 */
bool State::symbolIsUsed(Symbol& symbol) const {
  bool found{false};
  std::set<Transition>::iterator iter{transitions_.begin()};
  while ((iter != transitions_.end()) && !found) {
    if ((*iter).getSymbol() == symbol)
      found = true;
    else
      ++iter;
  }
  return found;
}

// Sobrecarga operador =
State& State::operator=(const State& rhs) {
  this->transitions_ = rhs.transitions_;
  this->identifier_ = rhs.identifier_;
  return *this;
}

// Sobrecarga operador ==
bool State::operator==(const State& rhs) const {
  if ((this->identifier_ == rhs.identifier_) && ((this->transitions_).size() == rhs.transitions_.size())) {
    return true;
  } else
    return false;
}

// Sobrecarga operador < (set)
bool State::operator<(const State& rhs) const {
  if (this->identifier_ < rhs.identifier_) return true;
  return false;
}