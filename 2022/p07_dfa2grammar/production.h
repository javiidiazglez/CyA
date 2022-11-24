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
 * @file production.h: clase Production
 * @brief Contiene declaracion de la clase production
 *
 * 17/11/2022 - Actualización (finalizacion) del production.h
 **/

#ifndef PRODUCTION_H_
#define PRODUCTION_H_

#include <cstdio>
#include <fstream>
#include <iomanip>
#include <iostream>

#include "alphabet.h"
#include "automata.h"
#include "chain.h"
#include "state.h"
#include "symbol.h"

class Production {
 public:
  Production() : no_terminal_symbol_(), production_(){};
   Production(Symbol&,Chain&);
  ~Production() { clear(); };
  
  // Funciones
  void StateToProduction(std::vector<std::pair<int, char>>, const State&);
  void clear();
  
  // Getters y Setters
  void setSymbolNoTerminal(Symbol no_terminal) { no_terminal_symbol_ = no_terminal; }
  Symbol getSymbolNoTerminal() const { return no_terminal_symbol_; }
  void setProductionsChains(std::set<Chain> production) { production_ = production; }
  std::set<Chain> getProductionsChains() const { return production_; }
  
  // sobrecarga operador
  friend bool operator<(const Production&, const Production&);
  friend std::ostream& operator<<(std::ostream&, const Production&);

 private:
  Symbol no_terminal_symbol_;
  std::set<Chain> production_;
};

#endif