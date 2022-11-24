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
 * @file production.cc: clase Production
 * @brief Contiene implementacion de la clase Production.
 *
 * 17/11/2022 - Actualización (finalizacion) del production.cc
 **/

#include "production.h"

// El constructor de la clase Producción.
Production::Production(Symbol& no_terminal, Chain& vector_chain) {
  no_terminal_symbol_ = no_terminal;
  production_ = vector_chain;
}

/** Una función que transforma un estado en una producción.
 * @param no_terminal_symbol_ simbolo no terminal al estado
 * @param state estado que se va a transformar en produccion
 */
void Production::StateToProduction(std::vector<std::pair<int, char>> equivalences, const State& state) {
  std::set<Chain> chain_tmp;
  for (int pos_j = 0; pos_j < equivalences.size(); pos_j++) {
    if (state.getIdentifier() == equivalences[pos_j].first) {
      std::string symb_NT;
      symb_NT += equivalences[pos_j].second;
      no_terminal_symbol_.setData(symb_NT);
    }
  }
  for (const auto& transition : state.getTransitions()) {
    std::string chain_production = transition.getSymbol().getData();
    for (int pos_i = 0; pos_i < equivalences.size(); pos_i++) {
      if (transition.getNextStateID() == equivalences[pos_i].first) {
        chain_production += equivalences[pos_i].second;
        chain_tmp.insert(chain_production);
        chain_production.clear();
      }
    }
  }
  production_ = chain_tmp;
}
// Destructor
void Production::clear() {
  no_terminal_symbol_.setData("");
  production_.clear();
}

// sobrecarga operador < (uso del set)
bool operator<(const Production& production_one, const Production& production_two) {
  if (production_one.getSymbolNoTerminal().getData() == "S")
    return true;
  else if (production_two.getSymbolNoTerminal().getData() == "S")
    return false;
  else
    return production_one.getSymbolNoTerminal() <= production_two.getSymbolNoTerminal();
}

std::ostream& operator<<(std::ostream& os, const Production& production) {
  for (const auto& chain : production.getProductionsChains()) {
    os << production.getSymbolNoTerminal() << " -> " << chain << std::endl;
  }

  return os;
}
