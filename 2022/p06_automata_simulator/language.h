// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Simulacion de Autómatas Finitos
// Autor: José Javier Díaz González
// Correo: alu0101128894@ull.es
// Fecha: 10/11/2022
// Archivo language.h
// Definición de la clase
// Historial de revisiones
// 10/11/2022 - Actualización (primera versión) del language.h
// 10/11/2022 - Finalización practica 6

#ifndef LANGUAGE_H_
#define LANGUAGE_H_

#include "strings.h"

const std::string kOpen = "{ ";   // Una cadena constante que se utiliza para imprimir "{"
const std::string kSpaces = " ";  // Una cadena constante que se utiliza para imprimir " "
const std::string kClose = "}";   // Una cadena constante que se utiliza para imprimir "}"

class Language {
 public:
  Language();     // El constructor de la clase Language.
  ~Language() {}  // El destructor de la clase Language.

  void InsertStrings(const Strings&);               // Inserta una cadena en el lenguaje.
  int GetSize() const { return language_.size(); }  // Devuelve el tamaño del lenguaje.

  Strings GetString(int) const;  // Una función que devuelve una cadena del lenguaje.

  friend std::ofstream& operator<<(std::ofstream&, const Language&);  // Una función amiga que sobrecarga el operador << para para imprimir el lenguaje.
  friend std::ostream& operator<<(std::ostream&, const Language&);    // Una función amiga que sobrecarga el operador << que escribe el lenguaje en un archivo.

 private:
  std::set<Strings> language_;  // Un conjunto de lenguajes
};
std::ofstream& operator<<(std::ofstream&, const Language&);  // Una función que sobrecarga el operador << para para imprimir el lenguaje.

#endif