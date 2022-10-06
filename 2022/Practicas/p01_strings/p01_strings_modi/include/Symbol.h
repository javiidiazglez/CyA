// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Símbolos, alfabetos y cadenas
// Autor: José Javier Díaz González
// Correo: alu0101128894@ull.es
// Fecha: 06/10/2022
// Archivo Symbol.h
// Definición de la clase
// Historial de revisiones
// 06/10/2022 - Actualización (segunda versión) del Symbol.h

#ifndef SYMBOL_H
#define SYMBOL_H

#include <fstream>
#include <string>

const std::string ERROR = "Error";
const std::string SPACE = " ";
const std::string ENDL = "\n";
const char CHAR_SPACE = ' ';
const char CHAR_ENDL = '\n';

class Symbol
{
 public:
  /// El constructor de la clase Símbolo, que inicializa el atributo símbolo_ con el valor de la constante ESPACIO.
  Symbol() : symbol_(SPACE) {}
  // Un constructor que inicializa el atributo symbol_ con el valor del parámetro symbol.
  Symbol(const std::string& symbol) : symbol_(symbol) {}
  // Un constructor que inicializa el atributo symbol_ con el valor del símbolo del parámetro.
  Symbol(const char);
  // El destructor de la clase Symbol. Se utiliza para liberar la memoria asignada para el objeto.
  ~Symbol() { symbol_.clear(); }

  // Getters
  std::string GetSymbol() const { return symbol_; }                     // Un getter que devuelve el valor del atributo symbol_.
  char GetMainSymbol(int posicion) const { return symbol_[posicion]; }  // Devolviendo el carácter en la posición de la cadena symbol_.
  int GetSize() const { return symbol_.size(); }                        // Devuelve el tamaño de la cadena symbol_.
  int GetLength() const { return symbol_.length(); }                    // Devuelve el tamaño de la cadena symbol_.

  // Setter que establece el valor del atributo symbol_ al valor del parámetro del símbolo.
  void SetSymbol(const std::string& symbol) { symbol_ = symbol; }

  // Sobrecarga de operadores
  // Un método que permite asignar un símbolo a otro símbolo.
  void operator=(const Symbol& SymbolMethod) { symbol_ = SymbolMethod.symbol_; }
  void operator=(const char);

  friend bool operator==(const Symbol&, const Symbol&);  // Una función amiga que compara dos símbolos.
  friend void operator+=(Symbol&, const char);           // Una función amiga que permite agregar un carácter a un símbolo.
  friend void operator+=(Symbol&, const std::string&);   // Una función amiga que permite agregar una cadena a un símbolo.

  void Write(std::fstream&) const;  // Un método que escribe el símbolo en un archivo.

  bool Exists(const Symbol&);
  void Empty() { symbol_.resize(0); }  // Pone longitud 0 al simbolo

 private:
  std::string symbol_;
};

// Sobrecarga de operadores
bool operator==(const Symbol&, const Symbol&);
void operator+=(Symbol&, const char);
void operator+=(Symbol&, const std::string&);

#endif