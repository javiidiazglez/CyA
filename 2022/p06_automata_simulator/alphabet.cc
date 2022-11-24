// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Simulacion de Autómatas Finitos
// Autor: José Javier Díaz González
// Correo: alu0101128894@ull.es
// Fecha: 10/11/2022
// Archivo alphabet.cc
// Definición de la clase
// Historial de revisiones
// 10/11/2022 - Actualización (primera versión) del alphabet.cc
// 10/11/2022 - Finalización practica 6

#include "alphabet.h"

// El constructor de la clase Alfabeto.
Alphabet::Alphabet() {
  Symbol not_empty(NOT_EMPTY);
  symbols_.insert(not_empty);
}

// Un constructor que toma un vector de símbolos
// y los inserta en el conjunto de símbolos del alfabeto.
Alphabet::Alphabet(const std::vector<Symbol>& symbol) {
  int size = symbol.size();
  for (int pos = 0; pos < size; pos++) {
    symbols_.insert(symbol[pos]);
  }
}

// Devolviendo el símbolo en la posición pos.
Symbol Alphabet::GetSymbol(int pos) const {
  Symbol error(kError);
  if (pos < symbols_.size()) {
    std::set<Symbol>::iterator iter = symbols_.begin();  // Un iterador que apunta al primer elemento del conjunto.
    for (int pos = 0; pos != pos; pos++) {
      iter++;
    }
    return *iter;  // Devolviendo el valor del iterador.
  }
  return error;
}

// Una sobrecarga de operadores que nos permite asignar un vector de símbolos a un alfabeto.
void Alphabet::operator=(const std::vector<Symbol>& symbol) {
  int size = symbol.size();
  symbols_.erase(symbols_.begin(), symbols_.end());  // Borrado de todos los elementos del conjunto.
  for (int pos = 0; pos < size; pos++) {
    symbols_.insert(symbol[pos]);  // Insertar un símbolo en el conjunto de símbolos.
  }
}

// Una función que nos permite asignar un alfabeto a otro alfabeto.
void Alphabet::operator=(const Alphabet& alphabet_new) {
  symbols_.erase(symbols_.begin(), symbols_.end());
  for (std::set<Symbol>::iterator iter = alphabet_new.symbols_.begin();
       iter != alphabet_new.symbols_.end(); iter++) {  // Una condición que se utiliza para iterar sobre los elementos del conjunto.
    symbols_.insert(*iter);                          // Insertar un símbolo en el conjunto de símbolos.
  }
}

// Comparando dos alfabetos.
bool operator==(const std::vector<Symbol>& vector, const Alphabet& alphabet) {
  int size = vector.size(), size_2 = alphabet.symbols_.size();
  if (size != size_2) {
    return false;
  }
  for (int pos = 0; pos < size; pos++) {
    if (!Contains(vector[pos], alphabet)) {  // Comprobando si el símbolo en el vector está en el alfabeto.
      return false;
    }
  }
  return true;
}

// Una función que verifica si un símbolo está en el alfabeto.
bool Contains(const Symbol& symbol, const Alphabet& symbol_alphabet) {
  if (symbol_alphabet.symbols_.count(symbol) == 1) {  // Comprobando si el símbolo está en el alfabeto.
    return true;
  }
  return false;
}

// Una función que devuelve la unión de dos alfabetos.
Alphabet Union(const Alphabet& alphabet_1, const Alphabet& alphabet_2) {
  Alphabet result;
  // Comparando el tamaño de los dos alfabetos.
  if (alphabet_1.GetSize() > alphabet_2.GetSize()) {
    result = alphabet_1;
    // Iterando sobre los elementos del conjunto para alphabet_2
    for (std::set<Symbol>::iterator iter = alphabet_2.symbols_.begin();
         iter != alphabet_2.symbols_.end(); iter++) {
      result.symbols_.insert(*iter);
    }
    return result;
  } else {
    result = alphabet_2;
    for (std::set<Symbol>::iterator iter = alphabet_1.symbols_.begin();
         iter != alphabet_1.symbols_.end(); iter++) {
      result.symbols_.insert(*iter);
    }
    return result;
  }
}