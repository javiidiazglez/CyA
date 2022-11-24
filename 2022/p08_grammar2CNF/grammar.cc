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
 * @file grammar.cc: clase Grammar
 * @brief Contiene implementacion de la clase Grammar.
 *
 * 24/11/2022 - Actualización (finalizacion) del grammar.cc
 **/

#include "grammar.h"

// Constructor
Grammar::Grammar() : terminals_(), no_terminals_(), initial_symbol_(), productions_() {}

// Constructor a partir de un fichero
Grammar::Grammar(std::ifstream& input) {
  size_t terminal_symbols_size;  // Símbolos terminales
  input >> terminal_symbols_size;
  std::string symbol_string;
  for (int pos_i{0}; pos_i < terminal_symbols_size; ++pos_i) {
    input >> symbol_string;
    terminals_.insert(Symbol(symbol_string));
  }
  size_t non_terminal_symbols_size;  // Símbolos no terminales
  input >> non_terminal_symbols_size;
  for (int pos_i{0}; pos_i < non_terminal_symbols_size; ++pos_i) {
    input >> symbol_string;
    no_terminals_.insert(Symbol(symbol_string));
  }
  // Símbolo de arranque
  input >> symbol_string;
  if (no_terminals_.check(Symbol(symbol_string))) {
    initial_symbol_ = Symbol(symbol_string);
  } else {
    std::cerr << "Error: El símbolo de arranque no se encuentra en el conjunto de símbolos no terminales." << std::endl;
    exit(EXIT_FAILURE);
  }
  // Producciones
  size_t productions_size;
  input >> productions_size;
  std::string no_terminal_string;
  std::string arrow;
  std::string production_string;
  Chain chain_string;
  for (int pos_i{0}; pos_i < productions_size; ++pos_i) {
    input >> no_terminal_string >> arrow >> production_string;
    Chain chain_tmp(production_string);
    Symbol symb_tmp(no_terminal_string);
    Production production_tmp(symb_tmp, chain_tmp);
    productions_.push_back(production_tmp);
    production_tmp.clear();
  }
}

// Sobrecarga de operador << para fichero
std::ostream& operator<<(std::ostream& os, const Grammar& grammar) {
  os << grammar.getAlphabetTerminal().getAlphabetSize() << '\n';
  for (const auto& symbol : grammar.getAlphabetTerminal().getAlphabet()) {
    os << symbol << '\n';
  }
  os << grammar.getAlphabetNoTerminal().getAlphabetSize() << std::endl;
  for (const auto& symbol : grammar.getAlphabetNoTerminal().getAlphabet()) {
    os << symbol << '\n';
  }
  os << grammar.initial_symbol_ << std::endl;
  os << grammar.getProductions().size() << std::endl;
  for (const auto& production : grammar.getProductions()) {
    os << production;
  }
  return os;
}

/** Función para comprobar si la gramatica tiene producciones vacias o unitarias
 * @return true si contiene; false no contiene
 */
bool Grammar::HaveEmptyAndUnitaryProduction() {
  bool verify{false};
  for (const auto& production : getProductions()) {
    for (const auto& no_terminal : getAlphabetNoTerminal().getAlphabet()) {
      if ((production.getProductionsChain().getChain() == no_terminal.getData()) && (!terminals_.check(production.getProductionsChain().getChain()))) {
        verify = true;
        std::cerr << "La gramatica introducida contiene " << production << " que es una producción unitaria" << std::endl;
        exit(EXIT_FAILURE);
      }
      if (production.getProductionsChain().getChain() == "ε") {
        if (production.getSymbolNoTerminal() != initial_symbol_) {
          verify = true;
          std::cerr << "La gramatica introducida contiene " << production << " que es una produccion vacía" << std::endl;
          exit(EXIT_FAILURE);
        }
      }
    }
  }

  return verify;
}

// Algoritmo de una gramatica libre de producciones unitarias y vacias a forma normal de chomsky

// PRIMERA ETAPA

// for all (A → X1X2 ... Xn (con n ≥ 2, Xi ∈ (Σ ∪ V )) do
//   for all (Xi) do
//     if (Xi = a ∈ Σ) then
//       Add the production Ca → a;
//       Replace Xi with Ca in A → X1X2 . . . Xn;
//     end if
//   end for
// end for

// SEGUNDA ETAPA

// for all (A → B1B2 . . . Bm (con m ≥ 3, Bi ∈ V ) do
//     Add m − 2 non-terminal symbols D1D2 . . . Dm−2;
//     Replace the production A → B1B2 . . . Bm with productions:
//       A → B1D1
//       D1 → B2D2
//       ...
//       Dm−2 → Bm−1Bm
//     end for

void Grammar::FNChomsky() {
  std::string chain_string;
  bool first_stage = false;
  char last_non_terminal_char('A');
  while (!first_stage) {
    for (int pos_i{0}; pos_i < productions_.size(); ++pos_i) {
      if (productions_[pos_i].getProductionsChain().size() >= 2) {
        for (int pos_j{0}; pos_j < productions_[pos_i].getProductionsChain().size(); ++pos_j) {
          if (terminals_.check(productions_[pos_i].getProductionsChain().getChain()[pos_j])) {
            // Buscar el símbolo no terminal que no se repita
            while (no_terminals_.check(last_non_terminal_char)) {
              ++last_non_terminal_char;
            }
            no_terminals_.insert(Symbol(last_non_terminal_char));
            std::string last_non_terminal_string = "";
            last_non_terminal_string += last_non_terminal_char;
            std::string last_symb_string = "";
            last_symb_string += productions_[pos_i].getProductionsChain().getChain()[pos_j];
            // Cambiar en todas las producciones
            ChangeProductions(last_symb_string, last_non_terminal_string);
            Symbol symb_tmp(last_non_terminal_string);
            Chain chain_tmp(last_symb_string);
            Production production_tmp(symb_tmp, chain_tmp);
            productions_.push_back(production_tmp);
            production_tmp.clear();
          }
        }
      }
    }
    first_stage = HasTerminalSymbolInProductions();
  }
  // SEGUNDA ETAPA
  std::string new_string_production;
  std::string old_string_production;
  for (int pos_i{0}; pos_i < productions_.size(); ++pos_i) {
    if (productions_[pos_i].getProductionsChain().size() >= 3) {
      // Buscar el símbolo no terminal que no se repita
      while (no_terminals_.check(last_non_terminal_char)) {
        ++last_non_terminal_char;
      }
      no_terminals_.insert(Symbol(last_non_terminal_char));
      for (int pos_j{0}; pos_j < productions_[pos_i].getProductionsChain().size(); ++pos_j) {
        if (pos_j == 0) {
          new_string_production += productions_[pos_i].getProductionsChain().getChain()[pos_j];
        } else {
          old_string_production += productions_[pos_i].getProductionsChain().getChain()[pos_j];
        }
      }
      new_string_production += last_non_terminal_char;
      Symbol symb_tmp(last_non_terminal_char);
      Chain chain_old_tmp(old_string_production);
      productions_.push_back(Production(symb_tmp, chain_old_tmp));
      Chain chain_new_tmp(new_string_production);
      productions_[pos_i].setProductionsChains(chain_new_tmp);
      new_string_production = "";
      old_string_production = "";
    }
  }
}

/** Funcion para cambiar producciones talescomo "Ba" (NoTerminal-Terminal) a "BC" con C -> a.
 * @param last_symbol terminal anterior en este caso a
 * @param last_symbol new_symbol	No terminal nuevo en este caso C
 */
void Grammar::ChangeProductions(const std::string& last_symbol, const std::string& new_symbol) {
  std::string chain_string;
  for (auto& production : productions_) {
    chain_string = production.getProductionsChain().getChain();
    if (chain_string.size() >= 2) {
      for (int pos_j{0}; pos_j < chain_string.size(); ++pos_j) {
        std::string sym_tmp_string = "";
        sym_tmp_string += chain_string[pos_j];
        if (sym_tmp_string == last_symbol) {
          chain_string.replace(chain_string.find(sym_tmp_string), new_symbol.length(), new_symbol);
          Chain tmp_chain(chain_string);
          Symbol tmp_symb(production.getSymbolNoTerminal());
          Production produc_tmp(tmp_symb, tmp_chain);
          production = produc_tmp;
        }
      }
    }
  }
}

/** Funcion para saber si hay producciones del tipo C -> a
 * @return  true si hay; false si no hay
 */
bool Grammar::HasTerminalSymbolInProductions() {
  for (const auto& production : getProductions()) {
    for (auto symbol : terminals_.getAlphabet()) {
      if (production.getProductionsChain().getChain() == symbol.getData()) return true;
    }
  }
  return false;
}