// UNIVERSIDAD DE LA LAGUNA
// GRADO EN INGENIERIA INFORMATICA
// AUTOR: José Javier Díaz González
// FECHA: 18-11-2020
// E-MAIL: alu0101128894@ull.edu.es
// ASIGNATURA: Computabilidad y Algoritmia
// PRACTICA: P07 - DFA
// Referencias: https://es.wikipedia.org/wiki/Aut%C3%B3mata_finito_determinista
// Nombre del archivo: estado_t.cc

#include "estado_t.h"

estado_t::estado_t(std::string nombre_estado) {
  nombre_ = nombre_estado;
}

std::string estado_t::getNombre() { // Devuelve el nombre del estado
  return nombre_;
}

bool estado_t::esInicio() { // Devuelve el estado de inicio
  return esInicio_;
}

bool estado_t::esAceptacion() { // Devuelve el estado de aceptacion
  return esAceptacion_;
}

void estado_t::setInicio() { // Pone el estado de inicio
  esInicio_ = true;
}

void estado_t::setAceptacion() { // Pone el estado de aceptacion
  esAceptacion_ = true;
}
