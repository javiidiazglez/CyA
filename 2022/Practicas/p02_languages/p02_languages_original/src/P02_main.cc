// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica #02: Operaciones con lenguajes
// Autor: José Javier Díaz González
// Correo: alu0101128894@ull.es
// Fecha: 12/10/2022
// Archivo P02_main.cc
// Programa principal
// Historial de revisiones
// 12/10/2022 - Actualización (primera versión) del P02_main.cc
// 12/10/2022 - Finalización práctica 2

#include <fstream>
#include <iostream>

#include "Usage.h"

int main(int argc, char* argv[]) {
  const char SPACE = ' ';
  const char KEY_OPEN = '{';
  const char CLOSE_KEY = '}';

  Usage(argc, argv);  // Comprobando que el número de argumentos es correcto.

  std::string input_1{argv[1]};
  std::string input_2{argv[2]};
  std::string output{argv[3]};
  std::string opcode{argv[4]};

  const int kOpcode = stoi(opcode);
  int power;

  // Abriendo el archivo en la ruta ./input_1
  std::ifstream filein1{"./" + input_1};
  if (!filein1) {
    std::cerr << "Error: El fichero '" << input_1 << "' no se puede abrir. Pruebe de nuevo.\n" << std::endl;
    exit(EXIT_FAILURE);
  }
  // Abriendo el archivo en la ruta ./input_2
  std::ifstream filein2{"./" + input_2};
  if (!filein2) {
    std::cerr << "Error: El fichero'" << input_2 << "' no se puede abrir. Pruebe de nuevo.\n" << std::endl;
    exit(EXIT_FAILURE);
  }
  // Abriendo el archivo en la ruta ./output
  std::ofstream fileout{"./" + output};
  if (!fileout) {
    std::cerr << "Error: El fichero'" << output << "' no se puede abrir. Pruebe de nuevo.\n" << std::endl;
    exit(EXIT_FAILURE);
  }
  // Al verificar si el código de operación es 6, si lo es, le preguntará al usuario la potencia a la que se elevará
  if (kOpcode == 6) {
    std::cout << "¿Potencia a elevar el lenguaje?: ";
    std::cin >> power;
  }
  // Leer el archivo hasta que llegue al final del archivo.
  while (!filein1.eof() && !filein2.eof()) {
    Language language_1, language_2;
    filein1 >> language_1;
    filein2 >> language_2;

    switch (kOpcode) {
      case 1:
        fileout << language_1.Concatenation(language_2) << std::endl;  // Concatenación
        break;
      case 2:
        fileout << language_1.Union(language_2) << std::endl;  // Union
        break;
      case 3:
        fileout << language_1.Intersection(language_2) << std::endl;  // Intersección
        break;
      case 4:
        fileout << language_1.Difference(language_2) << std::endl;  // Diferencia
        break;
      case 5:
        fileout << language_1.Inverse() << std::endl;  // Inversa
        break;
      case 6:
        fileout << language_1.Power(power) << std::endl;  // Potencia
        break;
      default:
        std::cerr << kOpcode;
        exit(EXIT_FAILURE);
        break;
    }
  }
  std::cout << "Funciona correctamente\n -> Fichero de salida: 'fileout.txt'" << std::endl;

  filein1.close();
  filein2.close();
  fileout.close();

  exit(EXIT_SUCCESS);  // Una función que termina el programa.
}