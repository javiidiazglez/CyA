// UNIVERSIDAD DE LA LAGUNA
// GRADO EN INGENIERIA INFORMATICA
// AUTOR: José Javier Díaz González
// FECHA: 18-11-2020
// E-MAIL: alu0101128894@ull.edu.es
// ASIGNATURA: Computabilidad y Algoritmia
// PRACTICA: P07 - DFA
// Referencias: https://es.wikipedia.org/wiki/Aut%C3%B3mata_finito_determinista
// Nombre del archivo: dfa_simulation.cc

#include <iostream>
#include "dfa_t.h"

int main(int argc, char *argv[]) {
    if (argc > 1 && argc < 4 && std::string(argv[1]) != "--help") {
      std::cout << "\nError: Falta de argumentos." << std::endl << std::endl;
      std::cout << "Para más información ejecute el comando: " << argv[0] << " --help\n" << std::endl;
      exit(0);
    } else if (argc == 1) {
      std::cout << "\nError: Falta de argumentos [" << argv[0] << "]. Agregue un fichero de entrada y un fichero de salida" << std::endl;
      std::cout << "\nPruebe " << argv[0] << " --help para más información\n" << std::endl;
      exit(0);
    } else if (std::string(argv[1]) == "--help") {
      std::cout << "\nUsa: " << argv[0] << " [input.dfa] [input.txt] [output.txt]" << std::endl;
      std::cout << "\nEste programa dirá si las cadenas del input.txt son leídas por el propio DFA.\n" << std::endl;
      exit(0);
    }
    std::cout << "\nPractica 7: DFA" << std::endl;
    std::cout << "\n----------------------\n";
    char *archivo_entrada_dfa = argv[1];
    char *archivo_entrada = argv[2];
    char *archivo_salida = argv[3];
    dfa_t dfa(archivo_entrada_dfa);
    dfa.encontrar_cadenas(archivo_entrada, archivo_salida);
}
