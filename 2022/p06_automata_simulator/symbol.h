// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Simulacion de Autómatas Finitos
// Autor: José Javier Díaz González
// Correo: alu0101128894@ull.es
// Fecha: 10/11/2022
// Archivo symbol.h
// Definición de la clase
// Historial de revisiones
// 10/11/2022 - Actualización (primera versión) del symbol.h
// 10/11/2022 - Finalización practica 6

#ifndef SYMBOL
#define SYMBOL

#include <fstream>
#include <iostream>
#include <string>

const std::string kError = "errorX";
const std::string kEmptyString = "&";
const std::string kSpace = " ";
const std::string kEndL = "\n";
const char kCharSpace = ' ';
const char kCharEndL = '\n';

class Symbol {
 public:
  Symbol() : symb_(kSpace) {}                       // El constructor de la clase Symbol. Está inicializando la variable symb_ con el valor de kSpace.
  Symbol(const std::string& symb) : symb_(symb) {}  // El constructor de la clase Symbol. Está inicializando la variable symb_ con el valor de kSpace.
  ~Symbol() { symb_.clear(); }                      // El destructor de la clase Symbol. Está borrando la variable symb_.

  std::string GetSymbol() const { return symb_; }          // Devuelve el símbolo.
  char GetSubSymbol(int pos) const { return symb_[pos]; }  // Devolviendo el carácter en la posición pos de la cadena symb_.

  int GetSize() const { return symb_.size(); }  // Devolviendo el tamaño de la cadena.

  friend std::istream& operator>>(std::istream&, Symbol&);  // Una función amiga que se usa para leer un símbolo de una transmisión.
  friend bool operator<(const Symbol&, const Symbol&);      // Una función amiga que compara dos símbolos <
  friend bool operator==(const Symbol&, const Symbol&);     // Una función amiga que compara dos símbolos ==

  bool Contains(const Symbol&);      // Una función que comprueba si el símbolo contiene el símbolo pasado como parámetro.
  void Empty() { symb_.resize(0); }  // Una función que comprueba si el símbolo contiene el símbolo pasado como parámetro.

 private:
  std::string symb_;  // Una variable privada de la clase Símbolo. Es una cadena que contiene el símbolo.
};

std::ofstream& operator<<(std::ofstream&, const Symbol&); // Una función que escribe un símbolo en un archivo.
std::istream& operator>>(std::istream&, Symbol&); // Una función que lee un símbolo de un flujo.

bool operator<(const Symbol&, const Symbol&); // Una función que compara dos símbolos.

#endif