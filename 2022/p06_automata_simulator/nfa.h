// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Simulacion de Autómatas Finitos
// Autor: José Javier Díaz González
// Correo: alu0101128894@ull.es
// Fecha: 10/11/2022
// Archivo nfa.h
// Definición de la clase
// Historial de revisiones
// 10/11/2022 - Actualización (primera versión) del nfa.h
// 10/11/2022 - Finalización practica 6

#ifndef NFA_H_
#define NFA_H_

#include "state.h"
#include "strings.h"

const char kAccepted[] = " -- Accepted";
const char kRejected[] = " -- Rejected";

class NFA {
 public:
  NFA() {}                                                        // El constructor predeterminado de la clase.
  NFA(const Alphabet&, const State&, const std::vector<State>&);  // Un constructor que recibe un alfabeto, un estado y un vector de estados.
  NFA(std::ifstream&);                                            // Un constructor que recibe un archivo y crea un NFA a partir de él.

  bool Evaluate(const Strings&);  // La función que se llamará para evaluar una cadena.

 private:
  Alphabet inputs_;            //   Un vector de cadenas que contiene los símbolos que se pueden usar para transitar entre estados.
  State current_;              //   El estado que recibirá el siguiente símbolo a atravesar.
  State start_;                //   El estado inicial de la NFA.
  std::vector<State> states_;  //   Un vector de estados que se utilizará para almacenar los estados de la NFA.
  // bool EstadodeMuerte(std::vector<State>&);

  bool Traverse(const Strings& string, const int pos_i = 0);  // Una función recursiva que intenta encontrar un camino que los autómatas puedan reconocer.
};

#endif
