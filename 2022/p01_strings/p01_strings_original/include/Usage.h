// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Símbolos, alfabetos y cadenas
// Autor: José Javier Díaz González
// Correo: alu0101128894@ull.es
// Fecha: 06/10/2022
// Archivo Usage.h
// Definición de funciones del programa
// Historial de revisiones
// 06/10/2022 - Actualización (segunda versión) del Usage.h

#ifndef USAGE_H
#define USAGE_H

#include <fstream>

const char kInstruction[] =
    "Instrucciones: Escriba: ./p01_stringsfilein.txt fileout.txt opcode \n \
    Para el Opcode: \n \
    1 = Fichero de salida la longitud de cada cadena de entrada.\n \
    2 = Fichero de salida la inversa de cada cadena de entrada. \n \
    3 = Fichero de salida el conjunto de cadenas que son prefijos \n \
    4 = Fichero de salida el conjunto de cadenas que son sufijos \n \
    5 =  Fichero de salida el conjunto de subcadenas \n";

const char kHelp[] = "--help";
const char kOpcode[] = "Error: Introduzca un Opcode válido. Porfavor\nPara más información use: './p01_strings --help'\n";

void Usage(int argc, char** argv);
void CheckItsOk(const std::fstream&, const std::fstream&);

#endif