// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Simulacion de Autómatas Finitos
// Autor: José Javier Díaz González
// Correo: alu0101128894@ull.es
// Fecha: 10/11/2022
// Archivo usage.h
// Definición de la clase
// Historial de revisiones
// 10/11/2022 - Actualización (primera versión) del usage.h
// 10/11/2022 - Finalización practica 6

#ifndef TOOLS_H_
#define TOOLS_H_

#include <fstream>
#include <iostream>
#include <stdlib.h> 
#include <string>

const char kHelpText[] = "La simulación de Autómatas Finitos crea un automata basado en un fichero .fa\n\
Recibe 2 parametros:\n\
=> [1] Un fichero .fa que contiene:\n\
    - los simbolos del alfabeto en la primera linea\n\
    - numero total de estados del automata en la segunda linea\n\
    - estado de arranque del automata en la tercera linea\n\
    - definicion de cada estado y sus transiciones en las lineas siguientes.\n\
=> [2] Un fichero .txt que contiene:\n\
     - una cadena por linea\n";

const char kErrorHelp[] = "Modo de empleo: ./p06_automata_simulator input.fa input.txt\n\
    Pruebe ’p06_automata_simulator --help’ para más información.\n";
const char KFileError[] = "Error: Unos de los ficheros del programa no se pudo abrir correctamente.\n"; 
const char kHelp[] = "--help"; 

void Usage(int, char**); 
void Files_open(const std::ifstream&, const std::ifstream&); 

#endif 