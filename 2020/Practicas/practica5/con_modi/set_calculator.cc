// UNIVERSIDAD DE LA LAGUNA
// GRADO EN INGENIERIA INFORMATICA
// AUTOR: José Javier Díaz González
// FECHA: 5-11-2020
// CORREO: alu0101128894@ull.edu.es
// ASIGNATURA: Computabilidad y Algoritmia
// PRACTICA: La clase Set
// Lenguaje: C++
// Contenido: Recibe un archivo con conjuntos y operaciones con los mismos
// Usamos el comando make para compilar -> g++ -std=c++14 -g -Wall -o set_calculator set_calculator.cc set.cc 
// Comando Ejecucion: ./set_calculator infile.txt outfile.txt

#include "set.h"
#include <iostream>
#include <fstream>
using namespace std;

int main (int argc, char *argv[]) {
  if (argc != 3) {
    if ((argc > 1) && (string (argv[1]) == "--help")) {
      cout << "This program is a set calculator, which supports operations between sets of natural numbers.";
      cout << endl << "It requires two parameters indicating the names for the input and output files. ";
      cout << endl << endl << "Usage: ./set_calculator input.txt output.txt" << endl;

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
        Set conjunto1, conjunto2; // nuevo conjunto
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
          case '\':
            resultado.DiferenciaSimetrica(conjunto1,conjunto2);
            fichero_salida << resultado;
            break;
        }
      }     
    }
    fichero_entrada.close();
    fichero_salida.close();  
  } 
}
