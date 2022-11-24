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
 * @file grammar.cc: clase Grammar
 * @brief Contiene definicion de la clase Grammar
 *
 * 17/11/2022 - Actualización (finalizacion) del Grammar
 **/

#include "grammar.h"

// Constructor
Grammar::Grammar() : terminals_(), no_terminals_(), initial_symbol_(), productions_() {}

/** Función para pasar de un Dfa a una gramatica
 * @param dfa automata
 */
void Grammar::ConvertToGrammar(Automata& dfa) {
  terminals_ = dfa.getAlphabet();
  Production production_tmp;
  std::set<Production> set_of_productions;
  char no_terminal_symb('A');
  std::vector<std::pair<int, char>> equivalences;
  std::pair<int, char> pair_equivalence;
  for (int pos_i = 0; pos_i < dfa.getTotalStates(); pos_i++) {
    if (pos_i == dfa.getInitialState().getIdentifier()) {
      pair_equivalence = std::make_pair(pos_i, 'S');
      initial_symbol_.setSymbolNoTerminal(Symbol(pair_equivalence.second));
      equivalences.push_back(pair_equivalence);
      no_terminals_.insert(Symbol(pair_equivalence.second));
    } else {
      pair_equivalence = std::make_pair(pos_i, no_terminal_symb);
      equivalences.push_back(pair_equivalence);
      no_terminals_.insert(Symbol(pair_equivalence.second));
      ++no_terminal_symb;
    }
  }
  // Iterando sobre los estados del DFA.
  for (const auto& state : dfa.getStates()) {
    production_tmp.StateToProduction(equivalences, state);
    set_of_productions.insert(production_tmp);
  }

  for (const auto& state : dfa.getOnlyAccepted()) {
    Symbol epsilon("ε");
    Chain epsilonChain(epsilon);
    std::set<Chain> chain_acceptance;
    chain_acceptance.insert(epsilonChain);
    for (int pos_j = 0; pos_j < equivalences.size(); pos_j++) {
      if (state.getIdentifier() == equivalences[pos_j].first) {
        std::string symbol_NT;
        symbol_NT += equivalences[pos_j].second;
        Symbol NT_acceptance(symbol_NT);
        Production acceptance(NT_acceptance, chain_acceptance);
        set_of_productions.insert(acceptance);
      }
    }
  }
  productions_ = set_of_productions;
}

// sobrecarga de operador << para fichero
std::ostream& operator<<(std::ostream& os, const Grammar& grammar) {
  os << grammar.getAlphabetTerminal().getAlphabetSize() << '\n';
  for (const auto& symbol : grammar.getAlphabetTerminal().getAlphabet()) {
    os << symbol << '\n';
  }
  os << grammar.getAlphabetNoTerminal().getAlphabetSize() << '\n';
  for (const auto& symbol : grammar.getAlphabetNoTerminal().getAlphabet()) {
    os << symbol << '\n';
  }
  os << grammar.initial_symbol_.getSymbolNoTerminal() << '\n';
  for (const auto& production : grammar.getProductions()) {
    os << production;
  }
  return os;
}