// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Simulacion de Autómatas Finitos
// Autor: José Javier Díaz González
// Correo: alu0101128894@ull.es
// Fecha: 10/11/2022
// Archivo state.h
// Definición de la clase
// Historial de revisiones
// 10/11/2022 - Actualización (primera versión) del state.h
// 10/11/2022 - Finalización practica 6

#ifndef STATE_H_
#define STATE_H_

#include <map>

#include "alphabet.h"

class State {
 public:
  State() {}                                                                            // Inicializando el atributo state_name_ con el valor del atributo state_name_.
  State(const int name) : state_name_{state_name_} {}                                   // Inicializando el atributo state_name_ con el valor del atributo state_name_.
  State(const int name, bool accept) : state_name_{name}, state_acceptance_{accept} {}  // Inicializando el atributo state_name_ con el valor del atributo state_name_.

  void AddTrantition(const Symbol&, State&);                   // Añadir una transición al estado actual.
  void GetPossibleStates(const Symbol&, std::vector<State>&);  // Obtener los estados posibles para un símbolo dado.
  void AddEpsilonTransition(std::vector<State>&);              // Adición de transiciones épsilon al DFA.

  int Which() const { return state_name_; }  // Devuelve el nombre del estado.

  bool IsAccept() const { return state_acceptance_; }  // Devuelve si el estado es de aceptación o no.
  bool IsError() const { return (state_name_ < 0); }   // Devuelve si el estado es de error o no.

  State& operator=(const State&);                      // Un operador sobrecargado. Se utiliza para asignar el valor de un objeto a otro.
  friend bool operator==(const State&, const State&);  // Una función de amigo. Es una función que no es miembro de la clase, pero tiene acceso a los miembros privados y protegidos de la clase.

  friend class NFA;  // Permite que la clase NFA acceda a los miembros privados  de esta clase.

 private:
  int state_name_ = -1;                                      // Nombre del estado
  bool state_acceptance_ = false;                            // Una variable booleana que indica si el estado es un estado de aceptación o no.
  std::map<Symbol, std::vector<State*>> state_trantitions_;  // Un mapa que almacena las transiciones de un símbolo a qué estado o estados va.
};
bool operator==(const State&, const State&);  // Una función que no es miembro de la clase, pero tiene acceso a los miembros privados de la clase.

#endif