// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica #03: Calculadora de lenguajes formales
// Autor: José Javier Díaz González
// Correo: alu0101128894@ull.es
// Fecha: 20/10/2022
// Archivo Symbol.h
// Definición de la clase
// Historial de revisiones
// 20/10/2022 - Actualización (primera versión) del Symbol.h
// 20/10/2022 - Finalización práctica 3

#ifndef SYMBOL_H_
#define SYMBOL_H_

#include <fstream>
#include <iostream>
#include <string>

// Definición de la clase Symbol.
class Symbol {
 public:
  Symbol() = default;                                 // El constructor predeterminado.
  Symbol(std::string data) : data_(data){};           // Un constructor que toma una cadena como parámetro y la asigna al atributo data_.
  Symbol(char data) : data_(std::string(1, data)){};  // Un constructor que toma un carácter como parámetro y lo convierte en una cadena.
  ~Symbol(){};                                        // El destructor de la clase.

  std::string getDataSymbol() const { return data_; };     // Un getter para el atributo data_.
  void setDataSymbol(std::string data) { data_ = data; };  // Un setter para el atributo data_.

  friend std::ostream& operator<<(std::ostream&, const Symbol&);    // Imprime el simbolo en la consola.
  friend std::ofstream& operator<<(std::ofstream&, const Symbol&);  // Imprime un simbolo en un archivo de salida.

  friend bool operator==(const Symbol&, const Symbol&);
  friend bool operator!=(const Symbol&, const Symbol&);
  friend bool operator<(const Symbol&, const Symbol&);

 private:
  std::string data_;  // Un atributo privado de la clase Símbolo.
};

#endif