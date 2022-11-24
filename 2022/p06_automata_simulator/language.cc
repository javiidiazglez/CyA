// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Simulacion de Autómatas Finitos
// Autor: José Javier Díaz González
// Correo: alu0101128894@ull.es
// Fecha: 10/11/2022
// Archivo language.cc
// Definición de la clase
// Historial de revisiones
// 10/11/2022 - Actualización (primera versión) del language.cc
// 10/11/2022 - Finalización practica 6

#include "language.h"

// El constructor de la clase Language.
Language::Language() {
  if (!language_.empty()) {
    language_.clear();
  }
}

// Inserta una cadena en el lenguaje.
void Language::InsertStrings(const Strings& string) {
  bool empty = true;
  Symbol symbol_string;
  for (int i = 0; i < string.GetLength(); i++) {
    if (!(string.GetSymbol(i).GetSymbol() == symbol_string)) {  // Comprobando si la cadena está vacía.
      empty = false;
    }
  }
  if (!empty) {
    language_.insert(string);  // Inserta una cadena en el lenguaje.
  }
}

// Devolviendo la cadena en la posición pos.
Strings Language::GetString(int pos) const {
  Strings no_string;
  if (pos < language_.size()) {
    std::set<Strings>::iterator iter = language_.begin();  // Un iterador que apunta al primer elemento del conjunto.
    for (int i = 0; i != pos; i++) {                     // Iterando a través del conjunto hasta que alcanza la posición pos.
      iter++;
    }
    return *iter;
  }
  return no_string;
}

// Una sobrecarga del operador. Se utiliza para imprimir el lenguaje.
std::ostream& operator<<(std::ostream& os, const Language& language) {
  os << kOpen;  // {
  for (std::set<Strings>::iterator iter = language.language_.begin();
       iter != language.language_.end(); iter++) {
    os << *iter << kSpaces;  // " "
  }
  os << kClose;  // }
  return os;
}

// Una función que escribe el lenguaje en un archivo.
std::ofstream& operator<<(std::ofstream& os, const Language& language) {
  os << kOpen;  // {
  for (std::set<Strings>::iterator iter = language.language_.begin();
       iter != language.language_.end(); iter++) {
    os << *iter << kSpaces;  // " "
  }
  os << kClose;  // }
  return os;
}