// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Símbolos, alfabetos y cadenas
// Autor: José Javier Díaz González
// Correo: alu0101128894@ull.es
// Fecha: 06/10/2022
// Archivo Symbol.cc
// Definición de la clase
// Historial de revisiones
// 06/10/2022 - Actualización (segunda versión) del Symbol.cc

#include "Symbol.h"

// Constructor de la clase Symbol
Symbol::Symbol(const char main_symbol)
{
  // Agrega un carácter al símbolo de cadena y luego asignarlo al símbolo de atributo_
  std::string symbol;
  symbol += main_symbol;
  symbol_ = symbol;
}

// Asigna un carácter al símbolo del objeto que no sea el carácter de espacio.
void Symbol::operator=(const char symbol)
{
  if (symbol != CHAR_SPACE)
  {
    symbol_ += symbol;
  }
}

// Comparar dos símbolos y devolver verdadero si son iguales.
bool operator==(const Symbol& symbol_first, const Symbol& symbol_second)
{
  return (symbol_first.symbol_ == symbol_second.symbol_);
}

// sobrecarga += obj Symbol y char

// Adición de un carácter al símbolo.
void operator+=(Symbol& symbol, const char main_symbol)
{
  if (main_symbol != CHAR_SPACE)
  {
    symbol.symbol_ += main_symbol;
  }
}

// sobrecarga += obj Symbol y string

// Adición de una cadena al símbolo.
void operator+=(Symbol& symbol, const std::string& symbol_add)
{
  symbol.symbol_ += symbol_add;
}

// Escribir el atributo symbol_ en el archivo. (Sobrecarga)
void Symbol::Write(std::fstream& os) const
{
  os << symbol_;
}

// Comprobando si el símbolo está en la cadena symbol_.
bool Symbol::Exists(const Symbol& symbol)
{
  // Comprobando si el símbolo está en la cadena symbol_.
  if (symbol_.size() >= symbol.symbol_.size())
  {
    // Búsqueda de una subcadena en una cadena.
    for (int pos_1 = 0; pos_1 < symbol_.size(); pos_1++)
    {
      if (symbol_[pos_1] == symbol.symbol_[0])
      {
        // Comprobando si el símbolo es una subcadena del símbolo_.
        bool equal = true;
        int total_pos = pos_1 + 1, pos_2;
        for (pos_2 = 1; pos_2 < symbol.symbol_.size() && total_pos < symbol_.size(); pos_2++, total_pos++)
        {  // Si el simbolo no tiene coincidencia con el resto de caracteres, para
          if (symbol_[total_pos] != symbol.symbol_[pos_2])
          {
            equal = false;
            break;
          }
        }
        if ((pos_2 == symbol.symbol_.size()) && equal)
        {
          return true;
        }
      }
    }
    return false;
  }
  return false;
}