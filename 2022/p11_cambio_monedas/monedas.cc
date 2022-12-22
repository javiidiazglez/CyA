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
 * @file monedas.cc: clase monedas
 * @brief Contiene definiciones de las funciones de la clase moneda
 *
 * 22/12/2022 - Actualización (finalizacion) del monedas.cc
 **/

#include "monedas.h"

// El constructor de la clase Monedas.
Monedas::Monedas(double& amount_set, std::vector<double>& solution_set, std::vector<double>& coins_set) {
  amount_set_ = amount_set;
  solution_set_ = solution_set;
  coins_set_ = coins_set;
}

void Monedas::ReturnChange() {
  double sum = 0.0;
  int index = 0;
  while (sum != amount_set_) {                     // Comprobando si la suma de las monedas es igual a la cantidad de dinero que queremos cambiar.
    if (sum + coins_set_[index] <= amount_set_) {  // Comprobando si la suma de las monedas es menor que la cantidad de dinero que queremos cambiar.
      solution_set_.push_back(coins_set_[index]);  // Añadiendo un elemento al final del vector solution_set_.
      sum += coins_set_[index];                    // Sumando el valor de la moneda actual al valor de la suma.
    } else {
      index++;
    }
  }
}

void Monedas::EfficientChange() {
  std::vector<double> vector_aux = coins_set_;  // Creando una copia del vector coins_set_ y almacenándolo en vector_aux.
  double sum = 0.0;
  int aux;
  for (int pos_i = 0; pos_i < vector_aux.size(); pos_i++) {  // Iterando a través del vector vector_aux.
    aux = (amount_set_ - sum) / vector_aux[pos_i];           // Cálculo del número de monedas de cada tipo que se utilizarán para realizar el cambio.
    if (aux > 0) {                                           // Comprueba si el número de monedas de cada tipo que se utilizarán para realizar el cambio es mayor que 0.
      for (int pos_k = 0; pos_k < aux; pos_k++) {            // Cantidad de monedas de cada tipo que se usarán para realizar el cambio en el vector solution_set_.
        solution_set_.push_back(vector_aux[pos_i]);          // Esta instrucción agrega un elemento al final del vector solution_set_.
      }
      sum += aux * vector_aux[pos_i];  // Suma el número de monedas de cada tipo que se utilizarán para realizar el cambio multiplicado x valor de la moneda actual.
    }
  }
  if (sum != amount_set_) {  // Ccomprueba si la suma de las monedas no es igual a la cantidad de dinero que queremos cambiar.
    solution_set_.push_back(amount_set_ - sum);
  }
}

std::ostream& operator<<(std::ostream& os, const Monedas& coins) {
  int tipos = 0;
  os << "Solución: ";
  for (int pos_i = 0; pos_i < coins.solution_set_.size(); pos_i++) {  // Iterar a través del conjunto de soluciones.
    int counter = 0;
    for (int pos_j = 0; pos_j < coins.solution_set_.size(); pos_j++) {  // Contar el número de veces que aparece una moneda en el conjunto de soluciones.
      if (coins.solution_set_[pos_i] == coins.solution_set_[pos_j]) {   // Verifica si el elemento actual del conjunto de soluciones es igual al siguiente elemento del conjunto de soluciones.
        counter++;
      }
    }
    if (coins.solution_set_[pos_i] != coins.solution_set_[pos_i - 1]) {  // Esta instrucción if verifica si el elemento actual del conjunto de soluciones es diferente del anterior.
      if (counter != 1) {                                                // Comprueba si el elemento actual del conjunto de soluciones es diferente del anterior.
        os << counter << "x" << coins.solution_set_[pos_i] << "€  ";
        tipos++;
      } else {
        os << coins.solution_set_[pos_i] << "€  ";
        tipos++;
      }
    }
  }
  os << std::endl;
  os << "Total monedas: " << coins.solution_set_.size() << std::endl;  // Imprimiendo el número total de monedas utilizadas para realizar el cambio.
  os << "Total tipos: " << tipos << std::endl;
}