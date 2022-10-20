// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica #03: Calculadora de lenguajes formales
// Autor: José Javier Díaz González
// Correo: alu0101128894@ull.es
// Fecha: 20/10/2022
// Archivo P03_main.cc
// Definición de la clase
// Historial de revisiones
// 20/10/2022 - Actualización (primera versión) del P03_main.cc
// 20/10/2022 - Finalización práctica 3

#include <fstream>
#include <iostream>

#include "../include/Usage.h"

int main(int argc, char* argv[]) {
  const char EQUAL = '=';

  Usage(argc, argv);  // Comprobando que el número de argumentos es correcto.

  std::string input_1{argv[1]};

  std::ifstream input_file1{"./" + input_1};  // Abrir archivo de lectura 1

  if (!input_file1) {
    std::cerr << "Error: El fichero '" << input_1 << "' no se puede abrir. Pruebe de nuevo.\n" << std::endl;
    exit(EXIT_FAILURE);
  }
  std::cout << "Alfabeto: " << " Lenguaje:" << std::endl;

  Calculator mycalculator;
  while (!input_file1.eof()) {
    std::string lineLanguaje;
    getline(input_file1, lineLanguaje);
    // Contando el número de '=' en la línea.
    // Si solo hay un '=' en la línea, significa que la línea corresponde
    // a una especificación de idioma y no a una operación.
    if (std::count(lineLanguaje.begin(), lineLanguaje.end(), EQUAL) == 1) {
      // Creando un nuevo objeto de tipo Idioma con la línea del archivo como parámetro.
      Language language_line(lineLanguaje);
      std::cout << language_line << std::endl;
      mycalculator.Push_back(language_line);
    } else {
      std::cout << "Resultado de la expresión en 'Notacion postfija': ";
      std::cout << lineLanguaje << " : " << std::endl;
      std::cout << mycalculator.RPN(lineLanguaje) << std::endl;
    }
  }
  input_file1.close();

  exit(EXIT_SUCCESS);  // Una función que termina el programa.
}