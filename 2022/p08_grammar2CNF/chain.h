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
 * @file chain.h: clase cadena
 * @brief Contiene definicion de la clase chain.h
 *
 * 24/11/2022 - Actualización (finalizacion) del chain.h
 **/

#ifndef CHAIN_H_
#define CHAIN_H_

#include <algorithm>
#include <vector>

#include "alphabet.h"

/** Clase Chain:
 */
class Chain {
 public:
  // Constructor & Destructor
  Chain() = default;
  Chain(std::string&);
  Chain(std::string&, Alphabet&);
  Chain(std::vector<Symbol>&, Alphabet&);
  Chain(Symbol&);
  ~Chain(){};
  
  // Getter & Setters
  Alphabet getAlphabet() { return alphabet_; };
  void setAlphabet(Alphabet& alphabet) { alphabet_ = alphabet; };
  void setChain(std::vector<Symbol> chain) {chain_ = chain;};
  std::string getChain() const;
  
  // Funciones
  Symbol at(int);
  void substr(int);
  void substr(int, int);
  size_t size() const;
  Chain inverse();
  std::set<Chain> SetPrefixs();
  std::set<Chain> SetSuffixs();
  std::set<Chain> SetSubchains();
  friend std::ostream& operator<<(std::ostream&, const Chain&);
  friend std::ofstream& operator<<(std::ofstream&, const Chain&);
  bool operator<(const Chain&) const;
  bool operator==(const Chain&) const;
  bool operator!=(const Chain&) const;
  Chain operator+(const Chain&);
  Chain concatenate(Chain&);
  Chain pow(int);

 private:
  std::vector<Symbol> chain_;
  Alphabet alphabet_;
};

#endif