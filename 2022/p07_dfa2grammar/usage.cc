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
 * @file usage.cc
 * @brief Contiene definiciones de las funciones de uso que corresponden al programa
 *
 * 17/11/2022 - Actualización (finalizacion) del usage.cc
 **/

#include "usage.h"

/** Una función que muestra el uso correcto del programa.
 *  @param argc Numero de lineas parametros
 *  @param argv Vector (char*)
 */
void Usage(int argc, char* argv[]) {
  if (argc == 1) {
    std::cout << argv[0] << " -- Gramatica Forma Normal de Chomsky\n\
    Modo de uso: "
              << argv[0] << " input.gra outputCFN.gra \n\
    Pruebe " << argv[0]
              << " --help para más información" << std::endl;
    exit(EXIT_SUCCESS);
  }
  if (argc != 3 && argc > 1) {
    std::string parameter{argv[1]};
    if (parameter == "--help") {
      std::cout << kHelpText << std::endl;
      exit(EXIT_SUCCESS);
    }
    std::cout << argv[0] << " -- Gramatica Forma Normal de Chomsky\n\
    Modo de uso: "
              << argv[0] << " input.gra outputCFN.gra \n\
    Pruebe " << argv[0]
              << " --help para más información" << std::endl;
    exit(EXIT_SUCCESS);
  } 
}