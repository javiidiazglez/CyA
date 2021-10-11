// UNIVERSIDAD DE LA LAGUNA
// GRADO EN INGENIERIA INFORMATICA
// AUTOR: José Javier Díaz González
// FECHA: 18-11-2020
// E-MAIL: alu0101128894@ull.edu.es
// ASIGNATURA: Computabilidad y Algoritmia
// PRACTICA: P07 - DFA
// Referencias: https://es.wikipedia.org/wiki/Aut%C3%B3mata_finito_determinista
// Nombre del archivo: transicion_t.h

#include <iostream>
#include <string>

class transicion_t {
 private:
  std::string estado_actual_;
  std::string estado_siguiente_;
  char entradas_;   // 0 1

 public:
  /**
   * @brief Crear una transicion
   * @param estado_actual_ Nombre del estado actual
   * @param entradas_ Nombre de la entradas
   * @param estado_siguiente_ Nombre del estado siguiente
   */
  transicion_t(std::string estado_actual, char entradas, std::string estado_siguiente);

  /**
   * @brief Nombre del estado actual
   * @return estado_actual_ Nombre del estado actual
   */
  std::string getEstadoActual();

  /**
   * @brief Simbolo de entrada
   * @return entrada_ Simbolo de entrada
   */
  char getEntrada();

  /**
   * @brief Nombre del estado siguiente
   * @return estado_siguiente_ Nombre del estado siguiente
   */
  std::string getEstadoSiguiente();
};
