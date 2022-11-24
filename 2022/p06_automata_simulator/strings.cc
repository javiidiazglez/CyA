// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Simulacion de Autómatas Finitos
// Autor: José Javier Díaz González
// Correo: alu0101128894@ull.es
// Fecha: 10/11/2022
// Archivo strings.cc
// Definición de la clase
// Historial de revisiones
// 10/11/2022 - Actualización (primera versión) del strings.cc
// 10/11/2022 - Finalización practica 6

#include "language.h"

// El constructor de la clase Strings.pos_i
Strings::Strings() {
  Symbol empty{kEmptyString};
  str_.push_back(empty);
}
// Leer un archivo y crear una cadena a partir de él.
Strings::Strings(std::ifstream& os) {
  std::string line, symb;
  symb.resize(0);
  std::vector<Symbol> vector_symbol_str;
  if (getline(os, line)) {
    if (!line.empty()) {
      for (int pos_i = 0; pos_i < line.size(); pos_i++) {
        symb += line[pos_i];
        if (line[pos_i] == kCharSpace) {     // Comprobando si el carácter es un espacio.
          symb.pop_back();                   // Eliminando el último carácter de la cadena.
          Symbol smb(symb);                  // Creación de un símbolo a partir de una cadena.
          vector_symbol_str.push_back(smb);  // Empujar un símbolo hacia atrás en un vector de símbolos.
          symb.resize(0);
        }
      }
      // Comprobando si la cadena tiene un alfabeto. > 0
      if (vector_symbol_str.size() > 0) {
        alphabet_str = vector_symbol_str;
        Symbol symbol_str, symbol(symb);
        symbol_str.Empty();

        for (int pos_i = 0; pos_i < symbol.GetSize(); pos_i++) {
          for (int pos_j = alphabet_str.GetSize() - 1; pos_j >= 0; pos_j--) {
            if (symbol.GetSymbol()[pos_i] == alphabet_str.GetSymbol(pos_j).GetSubSymbol(0)) {  // Comprobando si el símbolo está en el alfabeto.
              if (symbol.Contains(alphabet_str.GetSymbol(pos_j))) {                            // Comprobando si el símbolo está contenido en el alfabeto.
                str_.push_back(alphabet_str.GetSymbol(pos_j));                                 // Empujar un símbolo hacia atrás en el vector de símbolos.
                pos_i += alphabet_str.GetSymbol(pos_j).GetSize() - 1;                          // Saltarse los símbolos que ya están en el alfabeto.
              }
            }
          }
        }
        // Comprobando si la cadena tiene un alfabeto. == 0
      } else if (vector_symbol_str.size() == 0) {
        for (int pos_i = 0; pos_i < symb.size(); pos_i++) {
          std::string sub_symb;
          sub_symb += symb[pos_i];
          Symbol symbol(sub_symb);
          str_.push_back(symbol);
        }
        alphabet_str = str_;
      }
    }
  }
}
// Crear una cadena a partir de una cadena.
Strings::Strings(const std::string& input_string) {
  for (int pos_i = 0; pos_i < input_string.size(); pos_i++) {
    std::string symb;
    symb += input_string[pos_i];
    Symbol symbol(symb);
    str_.push_back(symbol);
  }
  alphabet_str = str_;
}

// Devolviendo el símbolo a la posición pos.
Symbol Strings::GetSymbol(int pos) const {
  if (pos < str_.size()) {
    return str_[pos];
  }
  Symbol error(kError);  // Creando un símbolo con el valor de kError.
  return error;
}
// Devolver una cadena que es el reverso de la cadena que está llamando al método.
Strings Strings::GetReverse() const {
  Strings reverse;
  reverse.str_.resize(0);
  reverse.alphabet_str = alphabet_str;
  for (int pos_i = str_.size() - 1; pos_i >= 0; pos_i--) {
    ;
    reverse.str_.push_back(str_[pos_i]);
  }
  return reverse;
}

// Devolviendo un idioma con todos los prefijos de la cadena.
Language Strings::GetPrefix() const {
  Language language_;
  Strings string_;
  Symbol symbol_;
  string_.alphabet_str = alphabet_str;
  string_.str_.resize(0);
  symbol_.Empty();
  for (int pos_i = 0; pos_i < str_.size(); pos_i++) {
    symbol_ = str_[pos_i].GetSymbol();
    string_.str_.push_back(symbol_);
    language_.InsertStrings(string_);
  }
  string_.str_.resize(0);
  symbol_ = kEmptyString;
  string_.str_.push_back(symbol_);
  language_.InsertStrings(string_);
  return language_;
}

// Devolviendo un idioma con todos los sufijos de la cadena.
Language Strings::GetSufix() const {
  Language language_;
  Strings string_;
  Symbol symbol_;
  string_.alphabet_str = alphabet_str;
  string_.str_.pop_back();
  symbol_.Empty();
  for (int pos_i = str_.size() - 1; pos_i >= 0; pos_i--) {  // Iterando a través de la cadena hacia atrás.
    symbol_ = str_[pos_i].GetSymbol();                      // Obtener el símbolo en la posición pos_i de la cadena.
    string_.str_.emplace(string_.str_.begin(), symbol_);
    language_.InsertStrings(string_);
  }
  string_.str_.resize(0);
  symbol_ = kEmptyString;
  string_.str_.push_back(symbol_);
  language_.InsertStrings(string_);
  return language_;
}

// Devolver un idioma con todas las subcadenas de la cadena.
Language Strings::GetSubstr() const {
  Language language_;
  Strings string_;
  Symbol symbol_;
  string_.alphabet_str = alphabet_str;
  string_.str_.resize(0);
  symbol_.Empty();
  for (int pos_i = 1; pos_i < str_.size(); pos_i++) {
    for (int pos_j = 0, count = 0; pos_j < str_.size(); pos_j++) {  // Un bucle for que itera a través de la cadena y cuenta el número de símbolos que se han iterado.
      symbol_ = str_[pos_j].GetSymbol();
      string_.str_.push_back(symbol_);
      count++;
      if (count == pos_i) {
        language_.InsertStrings(string_);
        string_.str_.erase(string_.str_.begin()); // Borrando el primer elemento del vector.
        count = count - 1;
      }
    }
    string_.str_.erase(string_.str_.begin(), string_.str_.end());
  }
  for (int pos_i = 0; pos_i < str_.size(); pos_i++) {
    symbol_ = str_[pos_i].GetSymbol();
    string_.str_.push_back(symbol_); // Empujando hacia atrás un símbolo en la cadena.
  }
  language_.InsertStrings(string_);
  string_.str_.resize(0);
  symbol_ = kEmptyString;
  string_.str_.push_back(symbol_);
  language_.InsertStrings(string_);
  return language_;
}

// Comparar dos cadenas y devolver verdadero si son iguales y falso si no lo son.
bool operator==(const Strings& string_1, const Strings& string_2) {
  if (string_1.GetLength() == string_2.GetLength()) {
    for (int pos_i = 0; pos_i < string_1.GetLength(); pos_i++) {
      if (string_1.str_[pos_i].GetSymbol() != string_2.str_[pos_i].GetSymbol())
        return false;
    }
    return true;
  }
  return false;
}
// Comparando dos cadenas y devolviendo verdadero si la primera es más pequeña que la segunda.
bool operator<(const Strings& string_1, const Strings& string_2) {
  if (string_1.str_.size() < string_2.str_.size()) {
    return true;
  }
  if (string_1.str_.size() == string_2.str_.size()) {
    for (int pos_i = 0; pos_i < string_1.GetLength(); pos_i++) {
      if (string_1.str_[pos_i].GetSymbol() > string_2.str_[pos_i].GetSymbol()) {
        return false;
      }
      if (string_1.str_[pos_i].GetSymbol() < string_2.str_[pos_i].GetSymbol()) {
        return true;
      }
    }
  }
  return false;
}
// Comparando dos cadenas y devolviendo verdadero si la primera es más grande que la segunda.
bool operator>(const Strings& string_1, const Strings& string_2) {
  return !(string_1 < string_2);
}

// Imprimiendo la cadena en el archivo.
std::ofstream& operator<<(std::ofstream& file, const Strings& string) {
  for (int pos_i = 0; pos_i < string.str_.size(); pos_i++) {
    file << string.str_[pos_i].GetSymbol();
  }
  return file;
}

// Imprimiendo la cadena en el archivo.
std::ostream& operator<<(std::ostream& file, const Strings& string) {
  for (int pos_i = 0; pos_i < string.str_.size(); pos_i++) {
    file << string.str_[pos_i].GetSymbol();
  }
  return file;
}

// Leer una cadena del flujo de entrada y crear un objeto Strings a partir de ella.
std::istream& operator>>(std::istream& in, Strings& string) {
  Symbol symbol_;
  std::string dummy_str;

  in >> symbol_;
  string.str_.resize(0);

  for (int pos_i = 0; pos_i < symbol_.GetSize(); pos_i++) {
    dummy_str.resize(0);
    dummy_str += symbol_.GetSubSymbol(pos_i);
    Symbol dummy2(dummy_str);
    string.str_.push_back(dummy2);
  }
  string.alphabet_str = string.str_;
  return in;
}

// Concatenación de dos cadenas.
const Strings operator+(const Strings& string_1, const Strings& string_2) {
  Strings string_;
  string_.alphabet_str = Union(string_1.alphabet_str, string_2.alphabet_str);
  string_.str_.resize(0);
  Symbol dummy_symbol;
  for (int pos_i = 0; pos_i < string_1.str_.size(); pos_i++) {
    dummy_symbol = string_1.str_[pos_i].GetSymbol();
    string_.str_.push_back(dummy_symbol);
  }
  for (int pos_i = 0; pos_i < string_2.str_.size(); pos_i++) {
    dummy_symbol = string_2.str_[pos_i].GetSymbol();
    string_.str_.push_back(dummy_symbol);
  }
  return string_;
}
// Una función recursiva que concatena una cadena consigo misma n veces.
const Strings operator^(const Strings& string, const int potencia) {
  Strings string_;
  string_.alphabet_str = string.alphabet_str;
  if (potencia == 0) {
    return string_;
  }
  if (potencia == 1) {
    return string;
  } else {
    int n = potencia - 1;
    return string + operator^(string, n);
  }
}

// Un método privado que devuelve todas las subcadenas de una cadena.
void Strings::GetSubStr(std::vector<Strings>& substr) const {
  substr.resize(0);
  Strings dummy;
  Symbol dummy_s;
  dummy.alphabet_str = alphabet_str;
  substr.push_back(dummy);
  dummy.str_.resize(0);
  dummy_s.Empty();
  for (int pos_i = 1; pos_i < str_.size(); pos_i++) {
    for (int pos_j = 0, count = 0; pos_j < str_.size(); pos_j++) {
      dummy_s = str_[pos_j].GetSymbol();
      dummy.str_.push_back(dummy_s);
      count++;
      if (count == pos_i) {
        substr.push_back(dummy);
        dummy.str_.erase(dummy.str_.begin());
        count = count - 1;
      }
    }
    dummy.str_.erase(dummy.str_.begin(), dummy.str_.end());
  }

  for (int pos_i = 0; pos_i < str_.size(); pos_i++) {
    dummy_s = str_[pos_i].GetSymbol();
    dummy.str_.push_back(dummy_s);
  }
  substr.push_back(dummy);
}