// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica #03: Calculadora de lenguajes formales
// Autor: José Javier Díaz González
// Correo: alu0101128894@ull.es
// Fecha: 20/10/2022
// Archivo Usage.h
// Definición de la clase
// Historial de revisiones
// 20/10/2022 - Actualización (primera versión) del Usage.h
// 20/10/2022 - Finalización práctica 3

#ifndef TOOLS_H_
#define TOOLS_H_

#include <iostream>

#include "Chain.h"
#include "Language.h"
#include "Calculator.h"

const std::string kInstruction =
    "Instrucciones: Escriba: ./p03_calculator filein.txt filein2.txt \n \
    Para el filein.txt: \n \
    Es un fichero texto plano con numeros, lenguajes, cadenas y alfabetos.";

const char kOpcode[] = "Error: Introduzca un Opcode válido. Porfavor\nPara más información use: './p01_strings --help'\n";

void Usage(int argc, char *argv[]);
void PrintUsage(std::set<Chain> &, std::ofstream &);

#endif