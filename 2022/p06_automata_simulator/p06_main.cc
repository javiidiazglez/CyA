// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Simulacion de Autómatas Finitos
// Autor: José Javier Díaz González
// Correo: alu0101128894@ull.es
// Fecha: 10/11/2022
// Archivo p06_main.cc
// Definición de la clase
// Historial de revisiones
// 10/11/2022 - Actualización (primera versión) del p06_main.cc
// 10/11/2022 - Finalización practica 6

#include "language.h"
#include "nfa.h"
#include "usage.h"

int main(int argc, char* argv[]) {
  Usage(argc, argv);
  std::string input_DFAn = argv[1], input_txt = argv[2];
  std::ifstream input_file_DFA(input_DFAn, std::ifstream::in), input_file_txt(input_txt, std::ifstream::in);


  Files_open(input_file_DFA, input_file_txt);
  NFA dfa(input_file_DFA);

  Language container;
  std::string line;
  
  std::cout << "Práctica 6. Simulación de Autómatas Finitos. José Javier Díaz González\n" << std::endl;
  
  while (input_file_txt) {
    Strings string(input_file_txt);
    container.InsertStrings(string);
  }
  Language accepted, rejected;
  int cont_size = container.GetSize();
  for (int i = 0; i < cont_size; i++) {
    if (i != 0) {
      std::cout << kCharEndL;
    }
    std::cout << container.GetString(i);
    if (dfa.Evaluate(container.GetString(i))) {        // Evaluación de la cadena con el DFA.
      accepted.InsertStrings(container.GetString(i));  // Insertando la cadena en el idioma aceptado.
      std::cout << kAccepted;
    } else {
      rejected.InsertStrings(container.GetString(i));  // Insertando la cadena en el idioma rechazado.
      std::cout << kRejected;
    }
  }
  std::cout << std::endl;
  return 0;
}