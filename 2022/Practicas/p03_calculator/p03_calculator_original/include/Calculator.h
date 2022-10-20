// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica #03: Calculadora de lenguajes formales
// Autor: José Javier Díaz González
// Correo: alu0101128894@ull.es
// Fecha: 20/10/2022
// Archivo Calculator.h
// Definición de la clase
// Historial de revisiones
// 20/10/2022 - Actualización (primera versión) del Calculator.h
// 20/10/2022 - Finalización práctica 3

#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include <stack>
#include <vector>

#include "Language.h"

// Class Calculator que define la calculadora de lenguajes formales
class Calculator {
 public:
  Calculator() = default;  // Constructor por defecto
  ~Calculator(){};         // Destructor

  void Push_back(const Language&);     // Empujar una lengua al vector de las lenguas.
  bool IsOperatorChar(const char&);    // Comprobando si la calculadora es un char_operator.
  bool IsOperatorString(std::string);  // Comprobando si la cadena es un char_operator.
  int IsOperatorInt(const char&);      // Comprobando si el carácter es un número.
  Language RPN(std::string&);          // Una función que devuelve el algoritmo RPN

 private:
  std::vector<Language> calculator_;  // Un vector de calculadora.
};
#endif