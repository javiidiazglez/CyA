/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingenierıa Informatica
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 7: Gramática Regular a partir de un DFA
 *
 * @author José Javier Díaz González
 * Correo: alu0101128894@ull.edu.es
 *
 * @date 17/11/2022
 * @file p07_main.cc: programa
 * @brief Contiene definición de la clase
 *
 * 17/11/2022 - Actualización (finalizacion) del p07_main.cc
 **/

#include <fstream>
#include <iostream>

#include "usage.h"
#include "automata.h"
#include "grammar.h"


int main(int argc, char* argv[]) {
  Usage(argc, argv);
  std::string input_automata{argv[1]};
  std::string output_grammar{argv[2]};
  std::ifstream input_file_texts{"./" + input_automata};
  if (!input_file_texts) {
    std::cerr << "Error de Archivo: '" << input_automata << "' no se pudo abrir." << std::endl;
    exit(EXIT_FAILURE);
  }
  std::ofstream output_file{"./" + output_grammar};
  if (!output_file) {
    std::cerr << "Error de Archivo: '" <<  output_grammar << "' no se pudo abrir." << std::endl;
    exit(EXIT_FAILURE);
  }
  Automata automata(input_automata);
  Grammar grammar;
  if(automata.isDFA() == true) {
    grammar.ConvertToGrammar(automata);
    output_file << grammar;
    std::cout << "Práctica 7: Gramática Regular a partir de un DFA. José Javier Díaz González\n" << std::endl;
    std::cout << "El fichero generado está en: '" << output_grammar << "'" << std::endl;
  } else {
    std::cout << "Error: El automata especificado en el fichero '" << input_automata << "' no es un DFA." << std::endl;
  }
  
  return 0;
}