// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Símbolos, alfabetos y cadenas
// Autor: José Javier Díaz González
// Correo: alu0101128894@ull.es
// Fecha: 06/10/2022
// Archivo String.cc
// Definición de la clase
// Historial de revisiones
// 06/10/2022 - Actualización (segunda versión) del String.cc

#include "String.h"

#include <iostream>

Strings::Strings()
{
  Symbol empty{EMPTY_STRING};  //   Creando un símbolo con el valor de la constante EMPTY_STRING.
  elements_.push_back(empty);  //   Agregar un símbolo vacío al vector de símbolos.
}

// Leer un archivo y crear una cadena a partir de él.
Strings::Strings(std::fstream& os)
{
  std::string line;
  Symbol symbol;
  symbol.Empty();
  std::vector<Symbol> aux;

  // Leyendo el archivo línea por línea.
  if (getline(os, line))
  {
    // Iterando a través de la línea y agregando cada carácter al símbolo.
    for (int pos_1 = 0; pos_1 < line.size(); pos_1++)
    {
      symbol += line[pos_1];
      // Verificando si el carácter es un espacio, si lo es, agrega el símbolo al vector y vacía el símbolo.
      if (line[pos_1] == CHAR_SPACE)
      {
        aux.push_back(symbol);  // Agregar el símbolo al vector.
        symbol.Empty();         // Vaciar el símbolo.
      }
    }

    // Comprobando si el alfabeto está vacío o no. 1 cadena sin alfabeto
    if (aux.size() > 0)
    {
      alphabet_elements_ = aux;  // Asignación del alfabeto a la cadena.
      Sort(alphabet_elements_);  // Ordenar los elementos del alfabeto.

      Symbol aux_symbol;   // Creación de un objeto símbolo.
      aux_symbol.Empty();  // Vaciar el símbolo.

      // Iterando a través de la línea y agregando cada carácter al símbolo.
      for (int pos_1 = 0; pos_1 < symbol.GetSize(); pos_1++)
      {
        // Iterando a través del vector alphabet_elements_ desde el último elemento hasta el primero.
        for (int pos_2 = alphabet_elements_.GetSize() - 1; pos_2 >= 0; pos_2--)
        {
          // Comprobando si el símbolo está en el alfabeto.
          if (symbol.GetSymbol()[pos_1] == alphabet_elements_.GetSymbol(pos_2).GetMainSymbol(0))
          {
            // Comprobando si el símbolo existe  en el alfabeto.
            if (symbol.Exists(alphabet_elements_.GetSymbol(pos_2)))
            {
              elements_.push_back(alphabet_elements_.GetSymbol(pos_2));
              pos_1 += alphabet_elements_.GetSymbol(pos_2).GetSize() - 1;  // Saltarse los caracteres que ya están en el alfabeto.
            }
          }
        }
      }
    }
    // Comprobando si el alfabeto está vacío o no.
    else if (aux.size() == 0)
    {
      // Iterando a través de la línea y agregando cada carácter al símbolo.
      for (int pos_1 = 0; pos_1 < symbol.GetSize(); pos_1++)
      {
        // Creando un símbolo con el valor del carácter en la posición pos_1 de la cadena.
        Symbol aux_symbol{symbol.GetMainSymbol(pos_1)};
        elements_.push_back(aux_symbol);
      }
      alphabet_elements_ = elements_;
      Sort(alphabet_elements_);  // Ordenar los elementos del alfabeto.
    }
  }
}

// Obteniendo el reverso de la cuerda.
void Strings::GetReverse(Strings& reverse)
{
  reverse.elements_.resize(0);  // Vaciar los elementos del vector_ del objeto inverso.
  reverse.alphabet_elements_ = alphabet_elements_;
  // Iterando a través de los elementos de la cadena desde el último elemento hasta el primero.
  for (int pos_1 = elements_.size() - 1; pos_1 >= 0; pos_1--)
  {
    reverse.elements_.push_back(elements_[pos_1]);  // Sumar el elemento en la posición pos_1 del vector elementos_ al vector elementos_ del objeto inverso.
  }
}

// Obtener los prefijos de la cadena.
void Strings::GetPrefix(std::vector<Strings>& prefix)
{
  prefix.resize(0);  // Vaciar el vector.
  Strings aux;
  Symbol aux_fix;
  aux.alphabet_elements_ = alphabet_elements_;  // Asignación del alfabeto de la cuerda al alfabeto de la cuerda aux.
  prefix.push_back(aux);
  aux.elements_.resize(0);
  aux_fix.Empty();
  for (int pos_1 = 0; pos_1 < elements_.size(); pos_1++)
  {
    aux_fix = elements_[pos_1].GetSymbol();  // Obteniendo el símbolo en la posición pos_1 del vector elementos_ y asignándolo al símbolo aux_fix.
    aux.elements_.push_back(aux_fix);
    prefix.push_back(aux);
  }
}

// Obtener los sufijos de la cadena.
void Strings::GetSufix(std::vector<Strings>& sufix)
{
  sufix.resize(0);
  Strings aux;
  Symbol aux_fix;
  aux.alphabet_elements_ = alphabet_elements_;
  sufix.push_back(aux);
  aux.elements_.resize(0);
  aux_fix.Empty();
  for (int pos_1 = elements_.size() - 1; pos_1 >= 0; pos_1--)
  {
    aux_fix = elements_[pos_1].GetSymbol();
    aux.elements_.emplace(aux.elements_.begin(), aux_fix);  // Agregando el símbolo aux_fix al comienzo del vector aux.elements_.
    sufix.push_back(aux);
  }
}

// Obtener todas las subcadenas posibles de la cadena.
void Strings::GetSubString(std::vector<Strings>& substring)
{
  this->GetPrefix(substring);  // Llamar a la función GetPrefix() y pasar la subcadena del parámetro.
  std::vector<Strings> aux;
  this->GetSufix(aux);  // Llamando a la función GetSufix() y pasando el parámetro aux.
  for (int pos_1 = 1; pos_1 < aux.size() - 1; pos_1++)
  {
    substring.push_back(aux[pos_1]);  // Agregar el elemento en la posición pos_1 del vector aux a la subcadena del vector.
  }
}

// Escribir la cadena en un archivo.
void Strings::Write(std::fstream& os) const
{
  for (int pos_1 = 0; pos_1 < elements_.size(); pos_1++)
  {
    elements_[pos_1].Write(os);  // Escribiendo el símbolo en la posición pos_1 de los elementos del vector_ al archivo.
  }
}
