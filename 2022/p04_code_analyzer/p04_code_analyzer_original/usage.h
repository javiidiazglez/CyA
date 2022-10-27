// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica #04: Expresiones Regulares
// Autor: José Javier Díaz González
// Correo: alu0101128894@ull.es
// Fecha: 27/10/2022
// Archivo usage.h
// Definición de la clase
// Historial de revisiones
// 27/10/2022 - Actualización (primera versión) del usage.h
// 27/10/2022 - Finalización práctica 4

#ifndef USAGE_H_
#define USAGE_H_

#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>

const char kHelp[] = "--help";
const char kInstruction[] =
    "Instrucciones: Escriba: ./p04_code_analyzer code.cc codescheme.txt \n \
    Para el code.cc: \n \
      - Contiene un código escrito en C++: \n \
    Para el codescheme.txt: \n \
      - Es un fichero texto plano con comentarios, variables, descripciones.\n";

const char kParameter[] = "Error: Introduzca un parámetro válido. Porfavor\nPara más información use: './p04_code_analyzer --help'\n";

void Usage(int, char**);

#endif