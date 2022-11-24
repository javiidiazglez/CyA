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
 * @file grammar.h:
 * @brief Contiene declaracion de la clase grammar
 *
 * 24/11/2022 - Actualización (finalizacion) del grammar.h
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
  Grammar(std::ifstream&); // Un constructor que toma un archivo como parámetro.

  // Getters y Setters
  void setAlphabetTerminal(Alphabet terminals) { terminals_ = terminals; }                  // Un setter para el atributo terminales_ de la clase Grammar.
  Alphabet getAlphabetTerminal() const { return terminals_; }                               // Un getter para el atributo terminales_ de la clase Grammar.
  void setAlphabetNoTerminal(Alphabet no_terminals) { no_terminals_ = no_terminals; }       // Un setter para el atributo no_terminals_ de la clase Grammar.
  Alphabet getAlphabetNoTerminal() const { return no_terminals_; }                          // Un getter para el atributo no_terminals_ de la clase Grammar.
  void setProductions(std::vector<Production> productions) { productions_ = productions; }  // Un setter para el atributo productions_ de la clase Gramática.
  std::vector<Production> getProductions() const { return productions_; }                   // Un getter para el atributo productions_ de la clase Grammar.

  // Funciones
  void ConvertToGrammar(Automata&);  // Convertir un autómata en una gramática.
  bool HaveEmptyAndUnitaryProduction();
  void FNChomsky();                                                // Declarando una función FNChomsky.
  void ChangeProductions(const std::string&, const std::string&);  // Cambiando las producciones de la gramática.
  bool HasTerminalSymbolInProductions();                           // Comprobando si la gramática tiene algún símbolo terminal en sus producciones.

  // Sobrecarga
  friend std::ostream& operator<<(std::ostream&, const Grammar&);

 private:
  Alphabet terminals_;
  Alphabet no_terminals_;
  Symbol initial_symbol_;
  std::vector<Production> productions_;
};

#endif