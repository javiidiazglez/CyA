// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Símbolos, alfabetos y cadenas
// Autor: José Javier Díaz González
// Correo: alu0101128894@ull.es
// Fecha: 06/10/2022
// Archivo Usage.cc
// Definición de funciones del programa
// Historial de revisiones
// 06/10/2022 - Actualización (segunda versión) del Usage.cc

#include "Usage.h"

#include <stdlib.h>

#include <iostream>
#include <string>

// Una función que comprueba si el usuario ha introducido el número correcto de parámetros.
void Usage(int argc, char** argv)
{
  if (argc != 4)
  {
    if (argc == 2)
    {
      std::string argv_1{argv[1]};
      if (argv_1 == kHelp)
      {
        std::cout << kInstruction;
        exit(EXIT_SUCCESS);
      }
    }
    std::cout << "Error: Escriba correctamente. Porfavor \n ->" << argv[0] << " filein.txt fileout.txt opcode"
              << "\nPara más información use: '" << argv[0] << " --help'\n";
    exit(EXIT_SUCCESS);
  }
}
// Comprobando si los archivos están abiertos.
void CheckItsOk(const std::fstream& file_input, const std::fstream& file_output)
{
  if (!file_input.is_open() || !file_output.is_open())
  {
    std::cout << "Uno de los ficheros no funciona. Pruebe de nuevo\n";
    exit(EXIT_SUCCESS);  // Una función que termina el programa.
  }
}