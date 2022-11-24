// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Simulacion de Autómatas Finitos
// Autor: José Javier Díaz González
// Correo: alu0101128894@ull.es
// Fecha: 10/11/2022
// Archivo state.ccs
// Definición de la clase
// Historial de revisiones
// 10/11/2022 - Actualización (primera versión) del state.cc
// 10/11/2022 - Finalización practica 6

#include "state.h"

// Funcion para saber si un vector de estados contiene un estado en concreto
bool Contains(const std::vector<State>& vector, const State& contained_state) {
  int size = vector.size();
  for (int pos = 0; pos < size; pos++) {
    if (vector[pos] == contained_state) {
      return true;
    }
  }
  return false;
}

// El operador = sobrecarga. Se utiliza para asignar el valor de un estado a otro.
State& State::operator=(const State& state) {
  state_name_ = state.state_name_;
  state_acceptance_ = state.state_acceptance_;
  state_trantitions_ = state.state_trantitions_;
  return *this;
}

// Funcion para añadir relacion simbolo, estado
void State::AddTrantition(const Symbol& symbs, State& next) {
  State* n = &next;
  std::map<Symbol, std::vector<State*>>::iterator iter;
  iter = state_trantitions_.find(symbs);
  if (iter != state_trantitions_.end()) {  // Comprobando si el mapa state_trantitions_ contiene el estado actual.
    state_trantitions_.at(symbs).push_back(n);
  } else {
    std::vector<State*> vector_dum = {n};
    state_trantitions_.insert(std::pair<Symbol, std::vector<State*>>(symbs, vector_dum));  // Creación de un mapa de símbolos a un vector de estados.
  }
}

// Funcion para encontrar posibles estados
void State::GetPossibleStates(const Symbol& symb, std::vector<State>& acc) {
  std::map<Symbol, std::vector<State*>>::iterator iter;
  iter = state_trantitions_.find(symb);
  if (iter != state_trantitions_.end()) {
    int size = state_trantitions_.at(symb).size();  // Obtener el tamaño del vector de estados para ese símbolo.
    for (int pos = 0; pos < size; pos++) {
      acc.push_back(*state_trantitions_.at(symb).at(pos));             // Agregar el estado señalado por el puntero al vector de estados.
      state_trantitions_.at(symb).at(pos)->AddEpsilonTransition(acc);  // Agregando la transición épsilon al estado.
    }
  }
}

// Funcion para añadir epsilon transición
void State::AddEpsilonTransition(std::vector<State>& acc) {
  Symbol epsilon(kEmptyString);
  int size = state_trantitions_[epsilon].size() - 1;  // Obtener el tamaño del vector de estados para el símbolo épsilon.
  for (int pos = 0; pos < size; pos++) {
    if (!Contains(acc, *state_trantitions_[epsilon][pos])) {  // Comprobando si el vector de estados contiene el estado señalado por el puntero.
      acc.push_back(*state_trantitions_[epsilon][pos]);       // Agregar el estado señalado por el puntero al vector de estados.
    }
  }
}

// Sobrecarga operador ==  que compara dos estados.
bool operator==(const State& state_1, const State& state_2) {
  return (state_1.state_name_ == state_2.state_name_);
}