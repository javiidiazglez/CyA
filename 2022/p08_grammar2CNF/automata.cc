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
 * @file automata.cc: clase NFA (automata finito no determinista)
 * @brief Contiene definiciones de la clase NFA
 *
 * 24/11/2022 - Actualización (finalizacion) del automata.cc
 **/

#include "automata.h"

/**
 * El constructor de la clase Automata. Está inicializando los atributos de la clase.
 * @param fileName Nombre del fichero de texto
 */
Automata::Automata(std::string& fileName) : sigma_(), setOfStates_(), initialState_(), acceptedStates_() {
  std::ifstream input_file{"./" + fileName};
  if (!input_file) {
    std::cerr << "Error de Archivo: '" << fileName << "' no se pudo abrir." << std::endl;
    exit(EXIT_FAILURE);
  }
  // alphabeto
  std::string line_file;
  std::string delimiter{" "};
  size_t pos = 0;
  std::string alphabet_symbol;
  getline(input_file, line_file);
  line_file += delimiter;
  while ((pos = line_file.find(delimiter)) != std::string::npos) {
    alphabet_symbol = line_file.substr(0, pos);
    sigma_.insert(Symbol(alphabet_symbol));
    line_file.erase(0, pos + delimiter.length());  // Borrar el símbolo que se ha leído del archivo.
  }
  int number_states;            // Numero de estados
  input_file >> number_states;  // Estado inicial
  int initial_state_id;
  input_file >> initial_state_id;  // Cada estado + transicion

  int current_state_id;
  int number_of_transitions;
  bool is_accepted_state;
  int next_state_id;
  State tmp_state;
  for (int pos_i{0}; pos_i < number_states; ++pos_i) {
    input_file >> current_state_id;
    input_file >> is_accepted_state;
    input_file >> number_of_transitions;
    if (current_state_id == initial_state_id)
      initialState_.setIdentifier(current_state_id);  // si el estado a analizar es el inicial colocar si ID
    else
      tmp_state.setIdentifier(current_state_id);  // si no se lo coloca a un estado temporal
    std::string symbol_string;
    for (int pos_j{0}; pos_j < number_of_transitions; ++pos_j) {
      input_file >> symbol_string;
      if (!sigma_.check(symbol_string)) {  // comprueba si el simbolo pertenece al alfabeto
        std::cerr << "Error: Hay un símbolo que no pertenece al alfabeto en el fichero del automata." << std::endl;
        std::cout << symbol_string << std::endl;
        exit(EXIT_FAILURE);
      }
      input_file >> next_state_id;
      Symbol aux_symbol(symbol_string);
      if (current_state_id == initial_state_id) {
        initialState_.setNextState(next_state_id, aux_symbol);
      } else {
        tmp_state.setNextState(next_state_id, aux_symbol);
      }
    }
    if (current_state_id == initial_state_id)
      setOfStates_.insert(initialState_);
    else
      setOfStates_.insert(tmp_state);
    // Verificando si el estado actual es un estado aceptado y si es el estado inicial, luego lo agrega al conjunto de estados aceptados.
    if (is_accepted_state && (current_state_id == initial_state_id)) acceptedStates_.insert(initialState_);
    // Comprobando si el estado actual es un estado aceptado y si no es el estado inicial. Si ambas condiciones son verdaderas, agrega el estado actual al conjunto de estados aceptados.
    if (is_accepted_state && !(current_state_id == initial_state_id)) acceptedStates_.insert(tmp_state);
    tmp_state.clear();
  }
  input_file.close();
}

/**
 * Función para evaluar la cadena y saber si está aceptada o no
 * @param[in] chain cadena a analizar
 * @return true si es aceptada. False en caso contrario
 */
bool Automata::evaluateChain(Chain& chain) {
  std::vector<std::string> paths;
  std::vector<int> path_stack;
  paths.resize(1);
  path_stack.push_back(0);
  int current_path = 0;
  deepSearch(chain, initialState_.getIdentifier(), paths, current_path, path_stack);
  return AnalizePaths(paths);
}

/**
 * Getter para obtener un estado del set de setOfStates_
 * @param id Id del estado
 */
State Automata::getState(int id) const {
  State result;
  bool found{false};
  std::set<State>::iterator iter{setOfStates_.begin()};
  while ((iter != setOfStates_.end()) && !found) {
    if ((*iter).getIdentifier() == id) {
      found = true;
      result = *iter;
    } else {
      ++iter;
    }
  }
  return result;
}

/**
 * Función que analiza una cadena con o sin epsilon transiciones, escribiendo los diferente posibles recorridos en caso de que halla epsilon transiciones
 * @param input_chain Cadena
 * @param current_id Estado as analizar
 * @param paths posibles caminos
 * @param current_path camino actual
 * @param path_stack pila de rutas por analizar
 */
void Automata::deepSearch(Chain& input_chain, int current_id, std::vector<std::string>& paths, int& current_path, std::vector<int>& path_stack) {
  Chain chain = input_chain;
  // Si la cadena tiene tamaño mayor o igual a 1
  if (chain.size() >= 1) {
    // Si tiene epsilon transciones y el numero de transiciones es != 0 (Solo en caso de que tenga epsilon transiciones)
    if ((getState(current_id).hasEpsTransitions()) && getState(current_id).numberOfTransitions()) {
      std::vector<int> next_eps_id = getState(current_id).getEpsTransitions();
      int tmp_id;
      std::string new_path;
      for (int pos_i{0}; pos_i < next_eps_id.size(); ++pos_i) {
        new_path = "";
        paths.push_back(new_path);
        paths.back() = paths[current_path];
        new_path.clear();
        tmp_id = paths.size() - 1;
        path_stack.push_back(tmp_id);
      }
      if (!next_eps_id.empty()) {
        for (int pos_i{0}; pos_i < next_eps_id.size(); ++pos_i) {
          paths[current_path] += "q" + std::to_string(current_id) + " " + "&" + " " + "q" + std::to_string(next_eps_id[pos_i]) + "|";
          deepSearch(chain, next_eps_id[pos_i], paths, current_path, path_stack);
        }
        next_eps_id.clear();
      }
    }
    // Cogemos el primer símbolo de la cadena y los quitamos de la cadena
    Symbol symbol = chain.at(0);
    chain.substr(0, 1);
    if (symbol.getData() == "&") {
      paths[current_path] += "q" + std::to_string(current_id) + " " + "&" + " " + "q" + std::to_string(current_id) + "|";
      paths[current_path] += std::to_string(current_id);
    } else {
      std::set<int> nextID = getState(current_id).getNextStateID(symbol);
      if (nextID.size() > 1) {
        int tmp_id;
        std::string new_path;
        for (int pos_i{1}; pos_i < nextID.size(); ++pos_i) {
          new_path = "";
          paths.push_back(new_path);
          new_path.clear();
          tmp_id = paths.size() - 1;
          path_stack.push_back(tmp_id);
        }
      }
      if (nextID.empty()) {
        paths[current_path] += "q" + std::to_string(current_id) + " " + symbol.getData() + " o" + "|";
        eraseAPathID(path_stack, current_path);
        current_path = path_stack.back();
      } else {
        for (std::set<int>::iterator iter{nextID.begin()}; iter != nextID.end(); ++iter) {
          paths[current_path] += "q" + std::to_string(current_id) + " " + symbol.getData() + " " + "q" + std::to_string(*iter) + "|";
          deepSearch(chain, (*iter), paths, current_path, path_stack);
        }
      }
    }
  } else {
    paths[current_path] += std::to_string(current_id);
    eraseAPathID(path_stack, current_path);
    if (!path_stack.empty()) current_path = path_stack.back();
  }
}

/**
 * Función para borrar un camino de la path_stack
 */
void Automata::eraseAPathID(std::vector<int>& path_stack, int id) {
  std::vector<int>::iterator iter = path_stack.begin();
  bool found{false};
  while ((iter != path_stack.end()) && !found) {
    if ((*iter) == id)
      found = true;
    else
      ++iter;
  }
  path_stack.erase(iter);
}

/**
 * Comprobando si el estado es un estado aceptado.
 */
bool Automata::isAnAcceptedState(const State& userState) {
  bool found{false};
  std::set<State>::iterator iter = acceptedStates_.begin();
  while ((iter != acceptedStates_.end()) && !found) {
    if ((*iter).getIdentifier() == userState.getIdentifier())
      found = true;
    else
      ++iter;
  }
  return found;
}

/**
 * Comprobando si el estado es un estado aceptado.
 */
bool Automata::isAnAcceptedState(const State& userState) const {
  std::set<State>::iterator iter = acceptedStates_.find(userState);
  if (iter == acceptedStates_.end()) {
    if ((*iter) == userState)
      return true;
    else
      return false;
  } else
    return false;
}

/**
 * Comprobando si las rutas son válidas.
 * @param[in] paths todos los posibles caminos
 */
bool Automata::AnalizePaths(std::vector<std::string>& paths) {
  bool accepted = false;
  for (int pos_i{0}; pos_i < paths.size(); ++pos_i) {
    
    int pos_j = (paths[pos_i].size() - 1);
    // std::cout << "La cadena no está ACEPTADA" << std::endl;
    if (paths[pos_i][pos_j] != 'o') {
      int lastStateID = paths[pos_i][pos_j] - '0';
      if (isAnAcceptedState(getState(lastStateID))) {
        // std::cout << "La cadena está ACEPTADA" << std::endl;
        accepted = true;
      }
    }
  }
  return accepted;
}

bool Automata::isDFA() {
  bool is_dfa{true};
  std::set<State>::iterator iter = setOfStates_.begin();
  while ((iter != setOfStates_.end()) && is_dfa) {
    std::vector<std::pair<Symbol, int>> transitions_count;
    for (auto symbol : sigma_.getAlphabet()) {
      std::pair<Symbol, int> aux = std::make_pair(symbol, 0);
      transitions_count.push_back(aux);
    }
    for (auto transition : (*iter).getTransitions()) {
      for (int pos_i{0}; pos_i < transitions_count.size(); ++pos_i) {
        if (transition.getSymbol().getData() == transitions_count[pos_i].first.getData()) ++transitions_count[pos_i].second;
      }
    }
    for (int pos_i{0}; pos_i < transitions_count.size(); ++pos_i) {
      if (transitions_count[pos_i].second > 1) is_dfa = false;
    }
    ++iter;
  }
  return is_dfa;
}