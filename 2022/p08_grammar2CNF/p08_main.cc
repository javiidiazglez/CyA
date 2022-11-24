/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingenierıa Informatica
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 8: Gramáticas en Forma Normal de Chomsky
 *
 * @author José Javier Díaz González
 * Correo: alu0101128894@ull.edu.es
 *
 * @date 24/11/2022
 * @file p08_main.cc: programa
 * @brief Contiene definición de la clase
 *
 * 24/11/2022 - Actualización (finalizacion) del p08_main.cc
 **/

#include <fstream>
#include <iostream>

#include "automata.h"
#include "grammar.h"
#include "usage.h"

int main(int argc, char* argv[]) {
  Usage(argc, argv);
  std::string input_grammar{argv[1]};
  std::string output_grammarFNC{argv[2]};
  std::ifstream input_file_texts{"./" + input_grammar};
  if (!input_file_texts) {
    std::cerr << "Error de Archivo: " << input_grammar << " no se pudo abrir." << std::endl;
    exit(EXIT_FAILURE);
  }
  std::ofstream output_file{"./" + output_grammarFNC};
  if (!output_file) {
    std::cerr << "Error de Archivo: " << output_grammarFNC << " no se pudo abrir." << std::endl;
    exit(EXIT_FAILURE);
  }
  Grammar grammar(input_file_texts);
  if (grammar.HaveEmptyAndUnitaryProduction() == false) {
    grammar.FNChomsky();
    output_file << grammar;
    std::cout << "Práctica 8: Gramáticas en Forma Normal de Chomsky. José Javier Díaz González\n" << std::endl;
    std::cout << "El fichero generado está en: '" << output_grammarFNC << "'" << std::endl;
  }
  return 0;
}