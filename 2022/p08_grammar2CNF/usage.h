/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingenierıa Informatica
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 8: Gramáticas en Forma Normal de Chomsky
 *
 * @author José Javier Díaz González
 * Correo: alu0101128894@ull.edu.es
 *
 * @date 24/11/2022
 * @file usage.h
 * @brief Contiene texto de ayuda
 *
 * 24/11/2022 - Actualización (finalizacion) del usage.h
 **/

#ifndef USAGE_H_
#define USAGE_H_

#include <iostream>

const std::string kHelpText =
    "./Grammar2CNF -- Gramatica Forma Normal de Chomsky \n\
Modo de uso: ./Grammar2CNF input.fa output.gra \n \n\
    => input.fa: Un fichero de gramática de entrada.\n\
    => output.gra: Un fichero de gramática de salida. \n";

void Usage(int argc, char *argv[]);

#endif