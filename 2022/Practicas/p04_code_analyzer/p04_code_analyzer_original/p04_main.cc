// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica #04: Expresiones Regulares
// Autor: José Javier Díaz González
// Correo: alu0101128894@ull.es
// Fecha: 27/10/2022
// Archivo p04_main.cc
// Definición de la clase
// Historial de revisiones
// 27/10/2022 - Actualización (primera versión) del p04_main.cc
// 27/10/2022 - Finalización práctica 4

#include <fstream>
#include <iostream>
#include <string>

#include "expresions.h"
#include "usage.h"

int main(int argc, char** argv) {
  Usage(argc, argv);
  std::string file_in{argv[1]};
  std::string file_out{argv[2]};
  std::ifstream in_file(file_in);
  std::ofstream out_file(file_out, std::ios::app);

  if (!in_file) {
    std::cerr << "\nError: El fichero '" << file_in << "' no se puede abrir. Escriba correctamente y pruebe de nuevo.\n"
              << "\nPara más información use './p04_code_analyzer --help'\n"
              << std::endl;
    exit(EXIT_FAILURE);
  }
  // if (!out_file) {
  //   std::cerr << "Error: El fichero'" << file_out << "' no se puede abrir. Escriba correctamente y pruebe de nuevo.\n"
  //   << "\nPara más información use './p04_code_analyzer --help'\n" << std::endl;

  //   exit(EXIT_FAILURE);
  // }
  Expresions ResultProgram(file_in);
  out_file << ResultProgram;

  std::cout << "Funciona correctamente\n -> Fichero de salida: 'codescheme.txt'" << std::endl;

  return 0;
}
