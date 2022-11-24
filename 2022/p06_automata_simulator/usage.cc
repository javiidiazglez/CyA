// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Simulacion de Autómatas Finitos
// Autor: José Javier Díaz González
// Correo: alu0101128894@ull.es
// Fecha: 10/11/2022
// Archivo usage.cc
// Definición de la clase
// Historial de revisiones
// 10/11/2022 - Actualización (primera versión) del usage.cc
// 10/11/2022 - Finalización practica 6

#include "usage.h"

void Usage(int argc, char** argv) {
  if (argc != 3) {
    if (argc == 2) {
      std::string parameter = argv[1];
      if (parameter == kHelp) {
        std::cout << kHelpText; 
        exit(EXIT_SUCCESS); 
      }
    }
    std::cout << kErrorHelp; 
    exit(EXIT_SUCCESS); 
  }
}
void Files_open(const std::ifstream& in_dfa, const std::ifstream& in_strings) {
  if(!in_dfa.is_open() || !in_strings.is_open()) { // Comprobando si los archivos están abiertos.
    std::cout << KFileError; 
    exit(EXIT_FAILURE); 
  }
}
