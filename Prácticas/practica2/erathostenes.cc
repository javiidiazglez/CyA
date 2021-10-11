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
#include <vector>
#include <string>
#include "erathostenes.h"
#include "erathostenes_main.cc"

void MostrarPrimos(int kNumeroValores, std::vector<bool>& primo) {    // Muestro el resultado de los primos y lo imprimimos

    std::cout << "\nLos numeros primos de esta lista son: ";

    for (int i = 1; i <= kNumeroValores; i++) {
        if (primo[i] == true) {

            std::cout << i << "   ";
        }
    }
   std::cout << std::endl;
}

void MostrarNoPrimos(int kNumeroValores, std::vector<bool>& primo) { //Mostramos los numeros no primos y lo imprimimos

    std::cout << "\nLos numeros NO primos de esta lista son: ";

    for (int i = 1; i <= kNumeroValores; i++) {
        if (primo[i] == false) {

            std::cout << i << "   ";
        }
    }
    std::cout << std::endl << std::endl;
}

void eliminar(int i, int j, std::vector<bool>& primo) { // Eliminar arrays de falses = no primos -> eliminar
 
    primo[i * j] = false; // Cuando van pasando y recorres los ponemos como falsos
}

void remove(int kNumeroValores, std::vector<bool>& primo, int i) { //Todos los mutiplos elegidos como falses = no primos

    //Tachar los multiplos: i*2, i*3, i*4, i*5...
    for (int j = 2; i * j <= kNumeroValores; j++) { // ejemplo: 2*2 = 4 < que el numero mostrado (i * j < N)
    
        eliminar(i, j, primo);
    }
}

void sieve(int kNumeroValores, std::vector<bool>& primo) { // Lista de valores, localiza un valor primo e invoca la funcion remove para false
    primo[1] = false; // El numero 1 no es primo, lo ponemos como false

    for (int i = 1; i <= kNumeroValores; i++) {
        if (primo[i] == true) { //Marca todos los true y comprueba y va tachando los multiplos

            remove(kNumeroValores, primo, i);
        }
    }
}

void ImprimirLista(int kNumeroValores, std::vector<bool>& primo) {

    for (int i = 1; i <= kNumeroValores; i++) { // Empleo empezar por el 2 porque el 0 y el 1 no son primos
        primo[i] = true; // Indico en toda la tabla que todos los numeros son TRUE
        std::cout << i << "   ";
    }
    std::cout<< std::endl;
}
