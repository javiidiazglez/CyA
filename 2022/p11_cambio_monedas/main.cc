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
 * @file main.cc: clase main
 * @brief Contiene definición de la clase
 *
 * 22/12/2022 - Actualización (finalizacion) del main.cc
 **/

#include "monedas.h"
#include "tools.h"

int main(int argc, char* argv[]) {
  Usage(argc, argv);
  std::vector<double> coins = {2.0, 1.0, 0.50, 0.20, 0.10, 0.05, 0.02, 0.01};  // Creando un vector de dobles con los valores de las monedas.
  std::vector<double> solutionMoney;

  if (argc == 2) {  // sin -o y -b
    std::string amount_str{argv[1]};
    double amount = std::stod(amount_str);
    Monedas exchange(amount, solutionMoney, coins);  // Creando un objeto de la clase Monedas con los parámetros cantidad, soluciónDinero y monedas.
    exchange.ReturnChange();
    std::cout << exchange;
  } else if (argc == 3) {  // == 3

    std::string option{argv[1]};
    std::string amount_str{argv[2]};

    double amount = std::stod(amount_str);  // Convertir la cadena en un doble.
    if (option == "-o") {
      Monedas exchange(amount, solutionMoney, coins);  // Creación de un objeto Monedas con los parámetros cantidad, soluciónDinero y monedas.
      exchange.EfficientChange();                      // Llamando al método EfficientChange() de la clase Monedas.
      std::cout << exchange;
    } else if (option == "-b") {
      std::vector<double> coins_or_bills = {500.0, 200.0, 100.0, 50.0, 20.0, 10.0, 5.0, 2.0, 1.0, 0.50, 0.20, 0.10, 0.05, 0.02, 0.01};  // Creando un vector con los valores de las monedas y billetes.
      Monedas exchange(amount, solutionMoney, coins_or_bills);                                                                          // Creando un objeto de la clase Monedas con los parámetros cantidad, soluciónDinero y monedas_o_billetes.
      exchange.ReturnChange();                                                                                                          // Llamando al método ReturnChange() de la clase Monedas.
      std::cout << exchange;
    } else {
      std::cout << "Opcion no soportada. \nUsa el comando '--help' para ver la ayuda. " << std::endl;
    }
  } else {
    std::cout << kHelpText << std::endl;
    exit(EXIT_SUCCESS);
  }
  return 0;
}