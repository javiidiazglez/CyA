// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Simulacion de Autómatas Finitos
// Autor: José Javier Díaz González
// Correo: alu0101128894@ull.es
// Fecha: 10/11/2022
// Archivo symbol.cc
// Definición de la clase
// Historial de revisiones
// 10/11/2022 - Actualización (primera versión) del symbol.cc
// 10/11/2022 - Finalización practica 6

#include "symbol.h"

// Una sobrecarga de operador para el operador <<. Se utiliza para escribir el símbolo en un archivo.
std::ofstream& operator<<(std::ofstream& of, const Symbol& symbol) {
  of << symbol.GetSymbol();
  return of;
}
// Una sobrecarga del operador >>. Se utiliza para leer un símbolo de un archivo.
std::istream& operator>>(std::istream& is, Symbol& symb) {
  is >> symb.symb_;
  return is;
}
// Una sobrecarga del operador <. Se utiliza para comparar dos símbolos.
bool operator<(const Symbol& symbol_1, const Symbol& symbol_2) {
  return (symbol_1.symb_ < symbol_2.symb_);
}
// Comparando dos símbolos.
bool operator==(const Symbol& symbol_1, const Symbol& symbol_2) {
  return (symbol_1.symb_ == symbol_2.symb_);
}

// Una función que comprueba si un símbolo contiene otro símbolo.
bool Symbol::Contains(const Symbol& symbol) {
  if (symb_.size() >= symbol.symb_.size()) {  // Comprobando si el símbolo es más grande que el símbolo que estamos buscando.
    for (int pos_i = 0; pos_i < symb_.size(); pos_i++) {
      if (symb_[pos_i] == symbol.symb_[0]) {  // Coincidencia primer carácter
        bool sol = true;
        int result_pos = pos_i + 1, j;
        for (j = 1; j < symbol.symb_.size() && result_pos < symb_.size(); j++, result_pos++) {  // Comprobando si el resto de los caracteres coinciden.
          if (symb_[result_pos] != symbol.symb_[j]) {                                           // Comparar los caracteres del símbolo con los caracteres del símbolo que buscamos.
            sol = false;
            break;
          }
        }
        if (sol && (j == symbol.symb_.size())) {  // Comprobando si el símbolo está contenido en el otro símbolo.
          return true;
        }
      }
    }
    return false;
  }
  return false;
}