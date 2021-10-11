// UNIVERSIDAD DE LA LAGUNA
// GRADO EN INGENIERIA INFORMATICA
// AUTOR: José Javier Díaz González
// FECHA: 5-11-2020
// CORREO: alu0101128894@ull.edu.es
// ASIGNATURA: Computabilidad y Algoritmia
// PRACTICA: La clase Set
// Lenguaje: C++
// Contenido: Hay un archivo.txt con conjuntos y operaciones a hacer, que lo escribe en un fichero de salida
// Usamos el comando make para compilar -> g++ -std=c++14 -g -Wall -o set_calculator set_calculator.cc set.cc 
// Comando Ejecucion: ./set_calculator infile.txt outfile.txt

#include "set.h"
#include <iostream>
#include <fstream>
using namespace std;

int main (int argc, char *argv[]) {
  if (argc != 3) {
    if ((argc > 1) && (string (argv[1]) == "--help")) {
      cout << "Para usar el comando correctamente: ";
      cout << "./set_calculator [Fichero Entrada] [Fichero Salida]";
      cout << endl;
      cout << "Dato extra: ";
      cout << endl << "-- El ficheros de Entrada son conjuntos creados por (Uniones, Interseccion, etc)" << endl;
      cout << "-- El fichero de Salida se guardan los resultados de los conjuntos creado por el fichero de Entrada ";
      cout << endl;
    } else {
      cout << "Opcion incorrecta: " << endl;
      cout << "Usa'./set_calculator --help' para mas informacion" << endl;
    }
  } else {
    ifstream fichero_entrada(argv[1]);
    ofstream fichero_salida(argv[2]);
    
    char caracter;
    char operacion;
    char siguiente_caracter;
    while (!fichero_entrada.eof()) { // Leo el fichero de entrada
      fichero_entrada.get(caracter); // Saco solo el primer caracter
      // Si recibe un ! la operación será con un único cjto
      if ((caracter == '!') ||(siguiente_caracter == '!')) {
        operacion = caracter;
        Set conjunto1;
        fichero_entrada >> conjunto1; // El resto de la cadena se lee con >>
        
        Set conjunto_resultado;
        conjunto_resultado.Complementacion(conjunto1);
        fichero_salida << conjunto_resultado;
        fichero_entrada.get(caracter);
      } else {  //if (caracter == '{') {
        // Crea un nuevo conjunto
        Set conjunto1, conjunto2;
        //cout << "Primero" << endl;
        fichero_entrada >> conjunto1;
        fichero_entrada.get(caracter);
        //cout << "Siguiente caracter: " << caracter << endl;
        // leer la operacion
        siguiente_caracter = fichero_entrada.peek();
        if ((caracter == ' ') && (siguiente_caracter != ' ')) {
          fichero_entrada.get(caracter); // Guardar la operacion
          operacion = caracter;
          //cout << "operacion: " << caracter << endl;
          fichero_entrada.get(caracter);
        }
        
        fichero_entrada >> conjunto2;
        fichero_entrada.get(caracter);
        Set resultado;
    
        switch (operacion) {   // switch -> conjuntos
          case '+':
            resultado.Union(conjunto1,conjunto2);
            fichero_salida << resultado;
            break;
          case '*':
            resultado.Interseccion(conjunto1,conjunto2);
            fichero_salida << resultado;
            break;
          case '-':
            resultado.ComplementoRelativo(conjunto1,conjunto2);
            fichero_salida << resultado;
            break;
        }
      }     
    }
    fichero_entrada.close();
    fichero_salida.close();  
  } 
}
