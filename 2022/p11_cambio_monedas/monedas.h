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
 * @file monedas.h
 * @brief Contiene declaracion de la clase monedas
 *
 * 22/12/2022 - Actualización (finalizacion) del monedas.h
 **/
#ifndef MONEDAS_H_
#define MONEDAS_H_

#include <iostream>
#include <vector>

class Monedas {
 public:
  Monedas() : amount_set_(), solution_set_(), coins_set_(){};    // El constructor de la clase Monedas.
  Monedas(double&, std::vector<double>&, std::vector<double>&);  // Un constructor con parámetros.
  ~Monedas(){};

  // Getters y setter
  double getAmount() const { return amount_set_; }
  void setAmount(double amount_set) { amount_set = amount_set; }
  std::vector<double> getSolutionSet() const { return solution_set_; }
  void setSolutionSet(std::vector<double> solution_set) { solution_set_ = solution_set; }
  std::vector<double> getCoinsSet() const { return coins_set_; }
  void setCoinsSet(std::vector<double> coins_set) { coins_set_ = coins_set; }

  // Funciones
  void ReturnChange();
  void EfficientChange();

  // Sobrecarga
  friend std::ostream& operator<<(std::ostream&, const Monedas&);

 private:
  double amount_set_;                 // Una variable privada de la clase Monedas.
  std::vector<double> solution_set_;  // Un vector de dobles.
  std::vector<double> coins_set_;     // Un vector de dobles.
};
#endif