/*

Practica 2: Computabilidad y Algoritmia

Nombre Practica: erathostenes.cc

Uso: Usar comando make para compilar -> g++ -std=c++14 -g -Wall -o erathostenes erathostenes.cc erathostenes.hpp

Contenido: Diseñar un programa en C++ (erathostenes.cc) que imprima en pantalla 
todos los números primos menores o iguales que 1000

Lenguaje: C++

Autor: José Javier Díaz González

Correo: alu0101128894@ull.edu.es

Día: 10-10-2020

*/

#include <iostream>
#include <string>
#include "erathostenes.h"

int main(int argc, char* argv[]) {

    if(argv[1] != NULL) {

        if( std::string (argv[1]) == "--help" ) {
            std::cout << "\nPara escribir el comando correctamente. Escriba " << argv[0] << " seguido de 1 numero binario natural." << std::endl
                      << "\nEjemplo: " << argv[0] << " 5 " << std::endl
                      << "\nEsto quiere decir que me imprime una lista de 5 numeros y entre ellos me dice cuales son los primos y NO primos.\n" << std::endl;
            return 0;
        }
        
        const int kNumeroValores = atoi(argv[1]); // char a entero

        if ( ((int) atoi(argv[1]) ) && (argc <= 2) ) { // <= 2 argumenos a pasar
            if (kNumeroValores < 2) {
                std::cout << "\nERROR: Debes añadir un binario natural. Mira mas informacion en --help.\n" << std::endl;
                return 0;

            } else {
                std::cout << std::endl;

                std::cout << "En esta lista hay " << kNumeroValores << " numeros:" << std::endl << std::endl;

                std::vector<bool> primo; // vector bool -> no size

                primo.resize(kNumeroValores); //Para guardar la N -> resize

                ImprimirLista(kNumeroValores, primo);
                sieve(kNumeroValores, primo);
                MostrarPrimos(kNumeroValores, primo);
                MostrarNoPrimos(kNumeroValores, primo);

            }
        } else {
            std::cout << "\nERROR: Usa: " << argv[0] << " NumeroPrimeraPosicionDelPrimo. Mira mas informacion en --help.\n " << std::endl; 
            return 0;
        }
    }
    else {
        std::cout << "\nERROR: Debes añadir 1 argumento. Mira mas informacion en --help.\n" << std::endl;
        return 0;
    }
}
