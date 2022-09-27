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

class estado_t {
 private:
  std::string nombre_;
  bool esInicio_ = false;
  bool esAceptacion_ = false;

 public:
   /**
   * @brief Crea un esatdo
   * @param nombre_ Nombre del estado
   */
  estado_t(std::string nombre_);

  /**
   * @brief Da el nombre del estado
   * @return nombre_ Nombre del estado
   */
  std::string getNombre();

  /**
   * @brief Mira si es un estado de inicio
   * @return esInicio_ Nombre del estado de inicio
   */
  bool esInicio();

  /**
   * @brief Mira si es un estado de acceptacion
   * @return esAceptacion_ Nombre del estado de aceptacion
   */
  bool esAceptacion();

  /**
   * @brief Pone el estado como estado de inicio
   */
  void setInicio();

  /**
   * @brief Pone el estado como estado de aceptacion
   */
  void setAceptacion();
};
