// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Símbolos, alfabetos y cadenas
// Autor: José Javier Díaz González
// Correo: alu0101128894@ull.es
// Fecha: 06/10/2022
// Archivo String.h
// Definición de la clase
// Historial de revisiones
// 06/10/2022 - Actualización (segunda versión) del String.h

#ifndef STRING_H
#define STRING_H

#include "Alphabet.h"

const std::string EMPTY_STRING = "&";

class Strings
{
 public:
  Strings();               // El constructor predeterminado de la clase Strings.
  Strings(std::fstream&);  // Un constructor que lee una cadena de un archivo.
  ~Strings() {}            // El destructor de la clase.

  int GetLength() const { return elements_.size(); };  // Una función que devuelve la longitud de la cadena.

  void GetReverse(Strings&);                 // Una función que devuelve el reverso de la cadena.
  void GetPrefix(std::vector<Strings>&);     // Obtener los prefijos de la cadena.
  void GetSufix(std::vector<Strings>&);      // Obtener los sufijos de la cadena.
  void GetSubString(std::vector<Strings>&);  // Obtener todas las subcadenas de la cadena.

  void Write(std::fstream&) const;  // Una función que escribe la cadena en un archivo.

 private:
  std::vector<Symbol> elements_;  // Un vector de símbolos.
  Alphabet alphabet_elements_;    //  Un objeto de la clase Alfabeto.
};

#endif