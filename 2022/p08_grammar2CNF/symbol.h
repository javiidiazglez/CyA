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
 * @file symbol.h: clase Symbol
 * @brief Contiene declaraciones de la clase Symbol.
 *
 * 24/11/2022 - Actualización (finalizacion) del symbol.h
 **/

#ifndef SYMBOL_H_
#define SYMBOL_H_

#include <fstream>
#include <iostream>
#include <string>

/** Clase Symbol:
 * Definición de la clase símbolo.
 */
class Symbol {
 public:
  // Constructor & Destructor
  Symbol() = default;
  Symbol(std::string data) : data_(data){};
  Symbol(char data) : data_(std::string(1, data)){};
  ~Symbol(){};

  // Getter & Setters
  std::string getData() const { return data_; };     // Getter for data
  void setData(std::string data) { data_ = data; };  // Setter for data

  // Functions
  friend std::ostream& operator<<(std::ostream&, const Symbol&);
  friend std::ofstream& operator<<(std::ofstream&, const Symbol&);
  friend bool operator<(const Symbol&, const Symbol&);
  friend bool operator==(const Symbol&, const Symbol&);
  friend bool operator!=(const Symbol&, const Symbol&);
  friend bool operator<=(const Symbol&, const Symbol&);

 private:
  std::string data_;  // Una variable privada de la clase Símbolo.
};

#endif