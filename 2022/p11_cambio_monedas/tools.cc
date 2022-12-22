/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingenierıa Informatica
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 11: cambio de monedas
 *
 * @author José Javier Díaz González
 * Correo: alu0101128894@ull.edu.es
 *
 * @date 22/12/2022
 * @file tools.cc
 * @brief Contiene definiciones de las funciones de uso que corresponden al programa
 *
 * 22/12/2022 - Actualización (finalizacion) del tools.cc
 **/

#include "tools.h"

/** Muestra el modo de uso correcto del programa
 *  @param[in] argc Number of command line parameters
 *  @param[in] argv Vector containing (char*) the parameters
 */
void Usage(int argc, char* argv[]) {
  if (argc == 1) {
    std::cout << argv[0] << " -- Algoritmos Voraces (Greedy). Cambio de Monedas\n\
    Modo de uso: "
              << argv[0] << " [-o] [-b] cantidad_n \n\
    Pruebe " << argv[0]
              << " --help para más información" << std::endl;
    exit(EXIT_SUCCESS);
  }
  if (argc == 2) {
    std::string parameter = argv[1];
    if (parameter == "--help") {
      std::cout << kHelpText;
      exit(EXIT_SUCCESS);
    }
  }
}