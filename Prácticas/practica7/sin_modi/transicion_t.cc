// UNIVERSIDAD DE LA LAGUNA
// GRADO EN INGENIERIA INFORMATICA
// AUTOR: José Javier Díaz González
// FECHA: 18-11-2020
// E-MAIL: alu0101128894@ull.edu.es
// ASIGNATURA: Computabilidad y Algoritmia
// PRACTICA: P07 - DFA
// Referencias: https://es.wikipedia.org/wiki/Aut%C3%B3mata_finito_determinista
// Nombre del archivo: transicion_t.cc

#include "transicion_t.h"

transicion_t::transicion_t(std::string estado_actual, char entradas, std::string estado_siguiente) { // Instancio todas las 3 trasnsiciones
  estado_actual_ = estado_actual; 
  estado_siguiente_ = estado_siguiente;
  entradas_ = entradas;
}

std::string transicion_t::getEstadoActual() { // Nombre del estado actual
  return estado_actual_;
}

char transicion_t::getEntrada() { // Simbolo de entrada
  return entradas_;
}

std::string transicion_t::getEstadoSiguiente() { // Nombre del estado siguiente
  return estado_siguiente_;
}
