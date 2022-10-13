// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica #02: Operaciones con lenguajes
// Autor: José Javier Díaz González
// Correo: alu0101128894@ull.es
// Fecha: 12/10/2022
// Archivo Usage.h
// Definición de la clase
// Historial de revisiones
// 12/10/2022 - Actualización (primera versión) del Usage.h
// 12/10/2022 - Finalización práctica 2

#ifndef USAGE_H_
#define USAGE_H_

#include <iostream>

#include "Chain.h"
#include "Language.h"

const std::string kInstruction =
    "Instrucciones: Escriba: ./p02_languages filein.txt filein2.txt fileout.txt opcode \n \
    Para el Opcode: \n \
    1 = Fichero de salida la concatenación de dos lenguajes.\n \
    2 = Fichero de salida la unión de dos lenguajes. \n \
    3 = Fichero de salida la intersección de dos lenguajes.\n \
    4 = Fichero de salida la diferencia de dos lenguajes.\n \
    5 = Fichero de salida la inversa del lenguaje con el filein.txt\n \
    6 = Fichero de salida la potencia del lenguaje con el filein.txt";

const char kOpcode[] = "Error: Introduzca un Opcode válido. Porfavor\nPara más información use: './p01_strings --help'\n";

void Usage(int argc, char *argv[]);
void PrintUsage(std::set<Chain> &, std::ofstream &);

#endif