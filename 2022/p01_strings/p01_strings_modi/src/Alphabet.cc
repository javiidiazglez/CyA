// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Símbolos, alfabetos y cadenas
// Autor: José Javier Díaz González
// Correo: alu0101128894@ull.es
// Fecha: 06/10/2022
// Archivo Alphabet.cc
// Definición de la clase
// Historial de revisiones
// 06/10/2022 - Actualización (segunda versión) del Alphabet.cc

#include "Alphabet.h"

// El constructor de la clase Alfabeto.
Alphabet::Alphabet()
{
  Symbol not_empty(NOT_EMPTY);
  alphabet_symbols_.push_back(not_empty);  // Agregar el símbolo NOT_EMPTY al alfabeto.
}

// El constructor de la clase Alfabeto.
Alphabet::Alphabet(const std::vector<Symbol>& symbols_alph)
{
  int size = symbols_alph.size();
  // Un bucle for que itera X través del vector de símbolos.
  for (int pos_1 = 0; pos_1 < size; pos_1++)
  {
    alphabet_symbols_.push_back(symbols_alph[pos_1]);
    for (int pos_2 = 0; pos_2 < alphabet_symbols_.size() - 1; pos_2++)
    {
      // Comprobando si el símbolo ya está en el alfabeto.
      if (alphabet_symbols_[pos_2] == symbols_alph[pos_1])
      {
        alphabet_symbols_.pop_back();  // Eliminando el último elemento del vector.
        break;
      }
    }
  }
}

// Devolviendo el símbolo en la posición pos del alfabeto.
Symbol Alphabet::GetSymbol(int pos) const
{
  Symbol error(ERROR);
  // Comprobando si la posición está en el rango del vector.
  return (pos < alphabet_symbols_.size() && pos >= 0) ? alphabet_symbols_[pos] : error;
}

// Asignación del vector de símbolos al alfabeto.
void Alphabet::operator=(const std::vector<Symbol>& symbols_alph)
{
  int size = symbols_alph.size();
  alphabet_symbols_.resize(0);

  for (int pos_1 = 0; pos_1 < size; pos_1++)
  {
    alphabet_symbols_.push_back(symbols_alph[pos_1]);
    for (int pos_2 = 0; pos_2 < alphabet_symbols_.size() - 1; pos_2++)
    {
      if (alphabet_symbols_[pos_2] == symbols_alph[pos_1])
      {
        alphabet_symbols_.pop_back();
        break;
      }
    }
  }
}
// Asignando el alphabet_ al vector alphabet_symbols_.
void Alphabet::operator=(const Alphabet& alphabet_)
{
  operator=(alphabet_.alphabet_symbols_);
}

// Escribir los símbolos del alfabeto en un archivo.
void Alphabet::Write(std::fstream& os) const
{
  for (int pos_1 = 0; pos_1 < alphabet_symbols_.size(); pos_1++)
  {
    alphabet_symbols_[pos_1].Write(os);
    os << SPACE;
  }
}

// Comprobar si un símbolo está en el alfabeto.
bool Exists(const Symbol& symb, const Alphabet& Symbls)
{
  for (int pos_1 = 0; pos_1 < Symbls.alphabet_symbols_.size(); pos_1++)
  {
    if (Symbls.alphabet_symbols_[pos_1] == symb)
    {
      return true;
    }
  }
  return false;
}

// Ordenar el alfabeto en orden ascendente.
void Sort(Alphabet& alphabet)
{
  Alphabet aux;
  aux.alphabet_symbols_.resize(0);
  std::string max = MAX;
  Symbol min = alphabet.alphabet_symbols_.front();
  int X = 0;

  // Comprobando si el tamaño del alfabeto aux es menor que el tamaño del alfabeto.
  while (aux.alphabet_symbols_.size() < alphabet.alphabet_symbols_.size())
  {
    for (int pos_1 = 0; pos_1 < alphabet.alphabet_symbols_.size(); pos_1++)
    {
      // Comparando el tamaño del símbolo con el tamaño mínimo del alfabeto.
      if (alphabet.alphabet_symbols_[pos_1].GetSize() <= min.GetSize() && alphabet.alphabet_symbols_[pos_1].GetSymbol() != max)
      {
        // Poniendo el símbolo en la posición pos_1 del abecedario.
        min = alphabet.GetSymbol(pos_1);
        X = pos_1;
      }
    }
    Symbol aux_2{max};
    alphabet.alphabet_symbols_[X] = aux_2;
    aux.alphabet_symbols_.push_back(min);
    min = aux_2;
  }
  alphabet.alphabet_symbols_.swap(aux.alphabet_symbols_);
}