// UNIVERSIDAD DE LA LAGUNA
// GRADO EN INGENIERIA INFORMATICA
// AUTOR: José Javier Díaz González
// FECHA: 18-11-2020
// E-MAIL: alu0101128894@ull.edu.es
// ASIGNATURA: Computabilidad y Algoritmia
// PRACTICA: P07 - DFA
// Referencias: https://es.wikipedia.org/wiki/Aut%C3%B3mata_finito_determinista
// Nombre del archivo: dfa_t.h

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <sstream>

#include "estado_t.h"
#include "transicion_t.h"

class dfa_t {
 private:
  std::vector<estado_t> estados_;
  std::vector<transicion_t> transiciones_;
  std::set<char> alfabeto_;
  int numeros_estados;
  int numeros_transiciones;

 public:
  /**
   * @brief Se rea el dfa
   * @param archivo_entrada_dfa Archivo de entrada del dfa
   */
  dfa_t(char* archivo_entrada_dfa); // Si es uno puedo poner un explicit

  /**
   * @brief Calcula si encuentra las cadenas
   * @param input Archivo de entrada con las cadenas
   * @param output Archivo de salida
   */
  void encontrar_cadenas(char* input, char* output);    // Funcion que encuentra las cadenas 

  /**
   * @brief Calcula si imprime las cadenas
   * @param input Archivo de entrada con las cadenas
   * @param output Archivo de salida
   * @param cadena La cadena 
   * @param estado_actual El propio estado en el que está
   * @param si_pertenece_alfabet Si pertenece al alfabeto
   */
  void imprimir_cadenas(char* input, char* output, std::string cadena, std::string estado_actual, bool si_pertenece_alfabeto); 
};
