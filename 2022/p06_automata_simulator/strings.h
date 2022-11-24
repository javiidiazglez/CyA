// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Simulacion de Autómatas Finitos
// Autor: José Javier Díaz González
// Correo: alu0101128894@ull.es
// Fecha: 10/11/2022
// Archivo strings.h
// Definición de la clase
// Historial de revisiones
// 10/11/2022 - Actualización (primera versión) del strings.h
// 10/11/2022 - Finalización practica 6

#ifndef STRINGS_H_
#define STRINGS_H_

#include "alphabet.h"

class Language;

class Strings {
 public:
  Strings();                    // El constructor predeterminado de la clase Strings.
  Strings(std::ifstream&);      // Un constructor que recibe un archivo y lee las cadenas de este.
  Strings(const std::string&);  // Un constructor que recibe una cadena y crea un objeto Strings con esa cadena.
  ~Strings() {}                 // El destructor de la clase Strings.

  int GetLength() const { return str_.size(); };  // Una función que devuelve la longitud de la cadena.
  Symbol GetSymbol(int) const;                    // Una función que devuelve el símbolo de la cadena en la posición indicada por el parámetro.

  // Comprobando si el alfabeto de la cadena es correcto.
  bool IsCorrect(const std::vector<Symbol>& vec) const { return (vec == alphabet_str); }

  Strings GetReverse() const;  //   Devolviendo el reverso de la cadena.

  Language GetPrefix() const;  // Devolviendo el prefijo del idioma.
  Language GetSufix() const;   // Llamar al método GetSufix() de la clase Language.
  Language GetSubstr() const;  // Un método que devuelve las subcadenas de la cadena.

  friend bool operator==(const Strings&, const Strings&);  // Una función amiga que compara dos cadenas ==
  friend bool operator<(const Strings&, const Strings&);   // Una función amiga que compara dos cadenas <
  friend bool operator>(const Strings&, const Strings&);   // Una función amiga que compara dos cadenas >

  friend std::ofstream& operator<<(std::ofstream&, const Strings&);  // Una función amiga que nos permite imprimir las cadenas en un archivo.
  friend std::ostream& operator<<(std::ostream&, const Strings&);    // Una función amiga que nos permite imprimir las cadenas en pantalla.
  friend std::istream& operator>>(std::istream&, Strings&);          // Una función friend que nos permite leer cadenas desde la consola.

  friend const Strings operator+(const Strings&, const Strings&);  // Una función amiga que nos permite concatenar dos cadenas.
  friend const Strings operator^(const Strings&, const int);       // Una función que nos permite elevar una cadena a una potencia.

 private:
  std::vector<Symbol> str_;  // Un vector de símbolos.

  Alphabet alphabet_str;                        // Un objeto de la clase Alfabeto.
  void GetSubStr(std::vector<Strings>&) const;  // Un método privado que se utiliza para obtener las subcadenas de una cadena.
};
// Una función friend que nos permite leer cadenas desde la consola.
std::ofstream& operator<<(std::ofstream&, const Strings&);  // Una función que nos permite imprimir las cadenas en un archivo.
std::istream& operator>>(std::istream&, Strings&);          // Una función que nos permite imprimir las cadenas en pantalla.
bool operator==(const Strings&, const Strings&);            // Un booleano que compara dos cadenas ==
bool operator<(const Strings&, const int);                  // Un booleanoamiga que compara dos cadenas <
bool operator>(const Strings&, const Strings&);             // Un booleano  que compara dos cadenas >

const Strings operator+(const Strings&, const Strings&);  // Una función que concatena dos cadenas.
const Strings operator^(const Strings&, const int);       // Una función que devuelve una cadena que es el resultado de multiplicar la cadena por el número.

#endif