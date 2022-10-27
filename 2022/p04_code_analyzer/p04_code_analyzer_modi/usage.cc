// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica #04: Expresiones Regulares
// Autor: José Javier Díaz González
// Correo: alu0101128894@ull.es
// Fecha: 27/10/2022
// Archivo usage.cc
// Definición de la clase
// Historial de revisiones
// 27/10/2022 - Actualización (primera versión) del usage.cc
// 27/10/2022 - Finalización práctica 4

#include "usage.h"

void Usage(int argc, char* argv[]) {
  if (argc != 3) {
    if (argc == 2) {
      std::string param{argv[1]};
      if (param == kHelp) {  // kHelp = "--help"
        std::cout << kInstruction;
        exit(EXIT_SUCCESS);
      }
    }
    std::cout << kParameter;
    exit(EXIT_SUCCESS);
  }
}