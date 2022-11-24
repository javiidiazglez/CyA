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
 * @file usage.cc
 * @brief Contiene definiciones de las funciones de uso que corresponden al programa
 *
 * 24/11/2022 - Actualización (finalizacion) del usage.cc
 **/


#include "usage.h"

/** Muestra el modo de uso correcto del programa
 *  En caso de que el uso no sea el correcto, muestra el mensaje y finaliza
 *  la ejecución del programa.
 *  El programa precisa un único número natural para su ejecución.
 *
 *  @param[in] argc Number of command line parameters
 *  @param[in] argv Vector containing (char*) the parameters
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