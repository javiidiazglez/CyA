// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Simulacion de Autómatas Finitos
// Autor: José Javier Díaz González
// Correo: alu0101128894@ull.es
// Fecha: 10/11/2022
// Archivo nfa.cc
// Definición de la clase
// Historial de revisiones
// 10/11/2022 - Actualización (primera versión) del nfa.cc
// 10/11/2022 - Finalización practica 6

#include "nfa.h"

#include <ctype.h>
#include <stdlib.h>

// Constructor parametrizado

// El constructor de la clase NFA. Se utiliza para crear un objeto de la clase NFA.
NFA::NFA(const Alphabet& alphabet, const State& state, const std::vector<State>& function) {
  inputs_ = alphabet;
  current_ = state;
  start_ = state;
  int size = function.size();
}

// El constructor de la clase NFA. Se utiliza para crear un objeto de la clase NFA.
NFA::NFA(std::ifstream& input) {
  states_.resize(0);  // Cambiar el tamaño del vector a 0.
  std::string line, symbol_space = "";
  int line_n = 0, states_pos = 0;
  int start = 0, size;
  Symbol epsilon(kEmptyString);
  std::vector<Symbol> symbol_epsilon = {epsilon};
  while (getline(input, line)) {
    switch (line_n) {
      case 0:  // Simbolos alfabeto
        for (int pos_i = 0; pos_i < line[pos_i]; pos_i++) {
          if (line[pos_i] != kCharSpace) {
            symbol_space += line[pos_i];
            Symbol symbol_string = symbol_space;      // Creación de un símbolo a partir de una cadena.
            symbol_epsilon.push_back(symbol_string);  // Adición de un símbolo al alfabeto.
          }
          symbol_space = "";
        }
        inputs_ = symbol_epsilon;  // Asignación del alfabeto a la NFA.
        break;
      case 1:  // Estados en total
        size = std::stoi(line);
        for (int pos_i = 0; pos_i < size; pos_i++) {
          State state_string;
          states_.push_back(state_string);
        }
        break;
      case 2:  // Estado inicial
        start = std::stoi(line);
        break;

      default:                      // resto (transisciones)
        std::string no_space = "";  // String sin espacios
        for (int pos_i = 0; pos_i < line[pos_i]; pos_i++) {
          if (line[pos_i] != kCharSpace) {
            no_space += line[pos_i];
          }
        }
        int no_size = no_space.size();
        int trantitions_n;
        int current_state_n = (int)no_space[0] - '0';
        /*
          1. nombre a cada estado 0,1,2,3
          2. no_size es >= que tres => mas de 0 transiciones, si no no tiene ninguna transicion
          3. posicion del estado (empieza en 0) < numero de estados totales
          4. Tiene más de 3 caracteres y si la posición del estado es menor que el número total de estados.
        */
        // Comprobando si la línea tiene más de 3 caracteres y si la posición del estado es menor que el número total de estados.
        if (no_size >= 3 && states_pos < size) {
          // Asignación del nombre del estado al estado actual.
          states_[current_state_n].state_name_ = (int)no_space[0] - '0';
          // Comprobar si el estado es un estado de aceptación o no. (1 aceptacion, 0 no aceptacion)
          states_[current_state_n].state_acceptance_ = (no_space[1] == '1') ? true : false;
          // Obtener el número de transiciones totales que tiene el estado actual.
          trantitions_n = (int)no_space[2] - '0';
        }
        std::string string_no_space = "";
        Symbol symbol_string = string_no_space;
        std::vector<Symbol> symbol_epsilon = {epsilon};                                  // Creando un vector de símbolos con el símbolo vacío.
        for (int pos_i = 0, pos = 3; pos_i < trantitions_n && pos < no_size; pos_i++) {  // Un bucle for que itera a través de las transiciones del estado actual.
          string_no_space += no_space[pos];
          symbol_string = string_no_space;
          string_no_space.resize(0);
          // Agregar una transición al estado actual.
          states_[current_state_n].AddTrantition(symbol_string, states_[(int)no_space[pos + 1] - '0']);
          pos = 2 + pos;  // Sumar 2 a la posición del carácter en la cadena.
        }
        states_pos++;
        break;
    }
    line_n++;  // Incrementando el valor de line_n en 1.
  }
  for (int pos_i = 0; pos_i < size; pos_i++) {
    states_[pos_i].AddTrantition(epsilon, states_[pos_i]);  // Agregar una transición al propio estado.
    if (start == states_[pos_i].state_name_) {              // Comprobando si el estado de inicio es el mismo que el estado actual.
      start_ = states_[pos_i];                              // Asignación del estado inicial al estado actual.
    }
  }
}

// Concatenación de dos vectores.
void ConcatenateVector(const std::vector<State>& add_1, std::vector<State>& add_to) {
  int size = add_1.size();
  for (int pos_i = 0; pos_i < size; pos_i++) {
    add_to.push_back(add_1[pos_i]);
  }
}

// Evaluación de la cadena, linea por linea
bool NFA::Evaluate(const Strings& string) {
  int size = string.GetLength();
  current_ = start_;
  if (size > 0) {
    return Traverse(string);  // Llamando a la función recursiva Traverse.
  }
  return start_.state_acceptance_;
}

// void NFA::EstadodeMuerte(std::vector<State>&i) {

// }

// Una función recursiva que comprueba si la NFA acepta la cadena.
bool NFA::Traverse(const Strings& string, const int pos_i) {
  int size = string.GetLength();
  if (pos_i < size) {                                  // Comprobando si la posición del carácter en la cadena es menor que el tamaño de la cadena.
    if (Contains(string.GetSymbol(pos_i), inputs_)) {  // Comprobando si el símbolo pertenece al alfabeto.
      std::vector<State> next_possible;
      current_.GetPossibleStates(string.GetSymbol(pos_i), next_possible);  // Obtener los posibles estados a los que puede ir el estado actual.
      int posibilities = next_possible.size(), pos_i_next = pos_i + 1;
      for (int j = 0; j < posibilities; j++) {
        current_ = next_possible[j];
        if (Traverse(string, pos_i_next)) {
          return true;
        }
      }
      return false;
    } else {
      return false;
    }
  } else {
    return current_.state_acceptance_;  // Devolviendo el valor de la variable state_acceptance_ del estado actual.
  }
}