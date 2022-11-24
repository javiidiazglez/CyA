/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingenierıa Informatica
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 7: Gramática Regular a partir de un DFA
 *
 * @author José Javier Díaz González
 * Correo: alu0101128894@ull.edu.es
 *
 * @date 17/11/2022
 * @file usage.h
 * @brief Contiene texto de ayuda
 *
 * 17/11/2022 - Actualización (finalizacion) del usage.h
 **/


#ifndef USAGE_H_
#define USAGE_H_

#include <iostream>

const std::string kHelpText =
    "./p07_dfa2grammar -- Dfa a Gramatica \n\
Modo de uso: ./p06_automata_simulator input.fa output.gra \n \n\
    => input.fa: Fichero de texto en el que figura la especificación de un autómata finito determinista (NFA).\n\
    => output.gra: Fichero de texto con extensión .gra en el que se mostrara la gramatica correspondiente al Dfa del fichero input.fa \n";

void Usage(int argc, char *argv[]);

#endif