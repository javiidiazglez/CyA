// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica #02: Operaciones con lenguajes
// Autor: José Javier Díaz González
// Correo: alu0101128894@ull.es
// Fecha: 12/10/2022
// Archivo Language.h
// Definición de la clase
// Historial de revisiones
// 12/10/2022 - Actualización (primera versión) del Language.h
// 12/10/2022 - Finalización práctica 2

#ifndef LANGUAGE_H_
#define LANGUAGE_H_

#include <set>

#include "Chain.h"

// Definición de la clase Lenguaje.
class Language {
 public:
  Language() = default;  // El constructor predeterminado.
  // Un constructor que toma un conjunto de cadenas y un alfabeto como parámetros.
  Language(std::set<Chain>& language, Alphabet& alphabet_lang) : language_(language), alphabet_language_(alphabet_lang){};
  ~Language(){};  // Destructor

  void InsertChain(const Chain&);  // Inserta una cadena

  Language Concatenation(Language);  // Una función que concatena dos lenguajes
  Language Union(Language&);         // Haciendo la unión de dos lenguajes.
  Language Intersection(Language&);  // Intertección, objeto lenguaje como parámetro y devuelve un objeto lenguaje.
  Language Difference(Language&);    // Diferencia, objeto lenguaje como parámetro y devuelve un objeto lenguaje.
  Language Inverse();                // Inversa, Una función que devuelve el reverso de un lenguaje.
  Language Power(int);               // Toma un número entero como argumento y devuelve la potencia de un lenguaje.

  friend std::ostream& operator<<(std::ostream&, const Language&);    // `ostream` clase que representa un flujo de salida. Pantalla
  friend std::ofstream& operator<<(std::ofstream&, const Language&);  // `ofstream` clase que representa un flujo de archivo de salida. Pantalla
  friend std::istream& operator>>(std::istream&, Language&);          // `istream` clase que representa un flujo de entrada. Teclado
  friend std::ifstream& operator>>(std::ifstream&, Language&);        // `ifstream` clase que representa un flujo flujo de archivos de entrada.. Teclado

 private:
  std::set<Chain> language_;
  Alphabet alphabet_language_;  // Un miembro privado de la clase Language. Es un objeto de la clase Alfabeto.
};

#endif