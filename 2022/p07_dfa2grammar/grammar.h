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
 * @file grammar.h: clase Grammar
 * @brief Contiene definicion de la clase Grammar
 *
 * 17/11/2022 - Actualización (finalizacion) del grammar.h
 **/

#ifndef GRAMMAR_H_
#define GRAMMAR_H_

#include <cstdio>
#include <fstream>
#include <iomanip>
#include <iostream>

#include "alphabet.h"
#include "automata.h"
#include "production.h"

class Grammar {
 public:
  // Constructores y Destructor
  Grammar();
  ~Grammar(){};
  
  // Getters y Setters
  void setAlphabetTerminal(Alphabet terminals) { terminals_ = terminals; }
  Alphabet getAlphabetTerminal() const { return terminals_; }
  void setAlphabetNoTerminal(Alphabet no_terminals) { no_terminals_ = no_terminals; }
  Alphabet getAlphabetNoTerminal() const { return no_terminals_; }
  void setProductions(std::set<Production> productions) { productions_ = productions; }
  std::set<Production> getProductions() const { return productions_; }
  
  // Funciones
  void ConvertToGrammar(Automata&);
  
  // Sobrecarga
  friend std::ostream& operator<<(std::ostream&, const Grammar&);

 private:
  Alphabet terminals_;                // Un atributo privado de la clase Gramática. Es un objeto de la clase Alfabeto.
  Alphabet no_terminals_;             // Un atributo privado de la clase Gramática. Es un objeto de la clase Alfabeto.
  Production initial_symbol_;         // El símbolo inicial de la gramática.
  std::set<Production> productions_;  // Un conjunto de producciones.
};

#endif