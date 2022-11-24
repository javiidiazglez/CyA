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
 * @file production.cc: clase Production
 * @brief Contiene implementacion de la clase Production.
 *
 * 24/11/2022 - Actualización (finalizacion) del production.cc
 **/

#include "production.h"

// El constructor de la clase Producción.
Production::Production(Symbol& no_terminal, Chain& vector_chain) {
  no_terminal_symbol_ = no_terminal;
  production_ = vector_chain;
}

// Destructor
void Production::clear() {
  std::vector<Symbol> vector_symb;
  vector_symb.clear();
  no_terminal_symbol_.setData("");
  production_.setChain(vector_symb);
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
  os << production.getSymbolNoTerminal() << " -> " << production.getProductionsChain() << std::endl;
  return os;
}

void Production::ReplaceChainProduction( const Chain& replace_chain) {
  no_terminal_symbol_ = no_terminal_symbol_;
  production_ = replace_chain;
}

