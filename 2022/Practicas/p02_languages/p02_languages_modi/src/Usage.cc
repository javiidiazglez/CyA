// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica #02: Operaciones con lenguajes
// Autor: José Javier Díaz González
// Correo: alu0101128894@ull.es
// Fecha: 12/10/2022
// Archivo Usage.cc
// Definición de la clase
// Historial de revisiones
// 12/10/2022 - Actualización (primera versión) del Usage.cc
// 12/10/2022 - Finalización práctica 2

#include "Usage.h"

// Una función que comprueba si el usuario ha introducido el número correcto de parámetros.
void Usage(int argc, char* argv[]) {
  if (argc == 1) {
    std::cout << "Error: Escriba correctamente. Porfavor \n ->" << argv[0] << " filein.txt filein2.txt fileout.txt opcode"
              << "\nPara más información use: '" << argv[0] << " --help'\n";
    exit(EXIT_SUCCESS);
  }
  if (argc != 5 && argc > 1) {
    std::string parameter{argv[1]};
    if (parameter == "--help" || "--h") {
      std::cout << kInstruction << std::endl;
      exit(EXIT_SUCCESS);
    }
    std::cout << "Error: Escriba correctamente. Porfavor \n ->" << argv[0] << " filein.txt filein2.txt fileout.txt opcode"
              << "\nPara más información use: '" << argv[0] << " --help'\n";
    exit(EXIT_SUCCESS);
  }
}

// Una función que imprime el conjunto de cadenas.
void PrintUsage(std::set<Chain>& vector_chain, std::ofstream& os) {
  os << "{ ";
  for (const auto elements : vector_chain) {
    os << elements << " ";
  }
  os << " }";
  os << std::endl;
}