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
 * @file tools.h
 * @brief Contiene texto de ayuda
 *
 * 22/12/2022 - Actualización (finalizacion) del tools.h
 **/

#ifndef TOOLS_H_
#define TOOLS_H_

#include <iostream>

const std::string kHelpText =
    "./p11_cambio_monedas -- Algoritmos Voraces (Greedy). Cambio de Monedas \n\
Modo de uso: ./p11_cambio_monedas [-o] [-b] cantidad_n \n\
    => cantidad_n: Sin ninguna opción especificada resolverá el cambio de monedas\n\
    => [-o] Resuelve el cambio de monedas con el algoritmo alternativo\n\
    => [-b] Considera tanto monedas como billetes para resolver el cambio\n";

void Usage(int argc, char *argv[]);

#endif