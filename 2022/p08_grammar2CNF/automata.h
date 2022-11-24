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
 * @file automata.h: clase NFA (automata finito no determinista)
 * @brief Contiene declaracion de la clase NFA
 *
 * 24/11/2022 - Actualización (finalizacion) del automata.h
 **/

#ifndef AUTOMATA_H_
#define AUTOMATA_H_

#include <cstdio>
#include <fstream>
#include <iomanip>
#include <iostream>

#include "alphabet.h"
#include "chain.h"
#include "state.h"

class Automata {
 public:
  // Constructores y Destructores
  Automata();
  ~Automata(){};
  Automata(std::string&);
  Automata(const Automata&);

  // Getter y Setter
  Alphabet getAlphabet() const { return sigma_; };
  int getTotalStates() const { return setOfStates_.size(); }
  int getAcceptedStates() const { return acceptedStates_.size(); }
  State getInitialState() const { return initialState_; }
  std::set<State> getStates() const { return setOfStates_; }
  std::set<State> getOnlyAccepted() const { return acceptedStates_; }

  // Funciones
  bool evaluateChain(Chain&);
  bool isDFA();

 private:
  Alphabet sigma_;                  // El alfabeto de los autómatas.
  std::set<State> setOfStates_;     // Un conjunto de estados.
  State initialState_;              // El estado inicial de los autómatas.
  std::set<State> acceptedStates_;  // Un conjunto de estados que son aceptados.

  // Funciones
  bool isAnAcceptedState(const State&);
  bool isAnAcceptedState(const State&) const;
  State getState(int) const;
  void deepSearch(Chain&, int, std::vector<std::string>&, int&, std::vector<int>&);
  void eraseAPathID(std::vector<int>&, int);
  bool AnalizePaths(std::vector<std::string>& paths);
};

#endif