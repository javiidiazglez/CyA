<<<<<<< HEAD:Prácticas/practica3/sin_modif/main_palindrome_prod.cc
/*

Practica 3: Computabilidad y Algoritmia

Nombre Practica: main_palindrome_prod.cc

Uso: Usar comando make para compilar + make clean para eliminar archivos

Contenido: Multipliplicacion de capicuas de n digitos, y el resultado de esa capicua
en un fichero aparte 

Datos extras: Guias de ayuda con el comando --help

Lenguaje: C++

Autor: José Javier Díaz González

Correo: alu0101128894@ull.edu.es

Día: 14-10-2020

*/

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <vector>
#include "palindrome_prod.cc"

int main(int argc, char * argv[]) {

    if(argc == 3) { // palindrome_prod (numero) (fichero) = 3 argumentos

        if(atoi(argv[1]) <= 0) {
            std::cout << "\nERROR: Debes añadir un numero positivo mayor que 0 . Mira mas informacion en --help.\n" << std::endl;
            return 0;
        }
        
        else {
            double i, j, n_min, n_max, producto;
            // bool si_capicua;

            std::string fichero_salida;
            std::string numero_cadena = "";

            fichero_salida = argv[2];       // argumento 2 = fichero_salida
            double digitos = atoi(argv[1]); // array to int || argumento 1 = digito

            std::ofstream fs(fichero_salida);       // Llamada al fichero de salida

            n_min = 1 * pow(10.0, digitos - 1);    // 1 * 10 ^ digitos -1 = 1 * 10 ^ 2-1 = 10 (2 digitos)
            n_max = 1 * pow(10.0, digitos);        // 1 * 10 ^ digitos    = 1 * 10 ^ 2   = 100 (2 digitos)

            for (i = n_min; i < n_max; i++) {
                for (j = n_min; j < n_max; j++) {
                    if (i <= j) {                   // No se dupliquen i y j -> no multiplica si el numero es menor igual que el numero

                        producto = i * j;           // 11 * 91 = 1001

                        //si_capicua = capicua(producto, digitos);
                        //if (si_capicua == true)

                        if (capicua(producto, digitos)) {  // (1001 , 2)

                            std::string numero1 = std::to_string((int) i);  // numero 1 = de comillas a numero i
                            std::string numero2 = std::to_string((int) j);
                            numero_cadena = std::to_string((int) producto);     // string = comillas -> to_string (el numero a comillas)
                        
                            fs << numero_cadena << " = " << i << " x "<< j << std::endl; // resultado = i * j

                        }
                    } 
                }
            }

            fs.close();
            return 0;

        }
    }
    
    else if (std::string (argv[1]) == "--help" ) { // si el argumento = 2 y argumento 1 = --help
    
        std::cout << "\nPara escribir el comando correctamente. Escriba " << argv[0] << " (NUMERO) (FICHERO.TXT)." << std::endl
            << "\nEjemplo: " << argv[0] << " 2 output.txt" << std::endl
            << "\nEsto quiere decir que me hace la multiplicacion de capicuas de 2 digitos en un fichero aparte\n" << std::endl;
        return 0;
    }

    else {      // Caso contrario
        std::cout << "\nERROR: Debes añadir 2 argumentos validos. Usa: " << argv[0] << " (NUMERO) (FICHERO.TXT). Mira mas informacion en --help.\n" << std::endl;
            return 0;
    }

    return 0;
=======
/*
Practica 3: Computabilidad y Algoritmia. Modificacion
Universidad de La Laguna
Nombre Practica: main_palindrome_prod.cc
Uso: Usar comando make para compilar + make clean para eliminar archivos
Contenido: Multipliplicacion de capicuas de n digitos, y el resultado de esa capicua
en un fichero aparte 
Datos extras: Guias de ayuda con el comando --help
Lenguaje: C++
Autor: José Javier Díaz González
Correo: alu0101128894@ull.edu.es
Día: 14-10-2020
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <vector>
#include "palindrome_prod_exercise.cc"

int main(int argc, char * argv[]) {

    if(argc == 5) { // palindrome_prod_exercise (numero) (numero) (numero) (fichero) = 5 argumentos
        if(atoi(argv[1]) <= 0) {
            std::cout << "\nERROR: Debes añadir un numero positivo mayor que 0 . Mira mas informacion en --help.\n" << std::endl;
            return 0;
        }
        else {
            double i, j, numero_minimo, numero_maximo, producto;
            //std::string cadena_fichero_salida;
            //cadena_fichero_salida = argv[2];       // argumento 2 = cadena_fichero_salida

            std::string resultado = "";
            double digitos = atoi(argv[1]); // array to int || argumento 1 = digito
            const int digitos1 = atoi(argv[2]);
            const int digitos2 = atoi(argv[3]);

            std::ofstream fichero_salida(argv[4]);       // Llamada al fichero de salida
            
            numero_minimo = 1 * pow(10.0, digitos - 1);    // 1 * 10 ^ digitos -1 = 1 * 10 ^ 2-1 = 10 (2 digitos)
            numero_maximo = 1 * pow(10.0, digitos);        // 1 * 10 ^ digitos    = 1 * 10 ^ 2   = 100 (2 digitos)

            for (i = numero_minimo; i < numero_maximo; i++) {
                for (j = numero_minimo; j < numero_maximo; j++) {
                    if (i <= j) {                   // No se dupliquen i y j -> no multiplica si el numero es menor igual que el numero
                        producto = i * j;           // 11 * 91 = 1001

                        if (capicua(producto, digitos)) {  // (1001 , 2)
                            if( argc == 1 && argc == 2 ) {

                            std::string numero1 = std::to_string((int) i);  // numero 1 = de comillas a numero i
                            std::string numero2 = std::to_string((int) j);
                            resultado = std::to_string((int) producto);     // string = comillas -> to_string (el numero a comillas)
                            
                            
                            //std::cout << "Contenido de " << argv[4] << std::endl;

                            fichero_salida << resultado << " = " << i << " x "<< j << std::endl; // resultado = i * j
                            }
                        }
                    } 
                }
            }
            fichero_salida.close();
            return 0;
        }
    }
    else if (argc == 2 && std::string (argv[1]) == "--help" ) { //  argumento 1 = --help
    
        std::cout << "\nThis program finds palindromic numbers of a certain length obtained as the product of two integer numbers within the specified range, and writes them to an output file."
                    << std::endl << "\nUsage: ./palindrome_prod_exercise Digits LowerLimit UpperLimit OutputFile. " << std::endl;
        return 0;
    }
    else {      // Caso contrario
        std::cout << "\nERROR: Debes añadir 4 argumentos validos. Usa: " << argv[0] << " (NUMERO) (FICHERO.TXT). Mira mas informacion en --help.\n" << std::endl;
            return 0;
    }

    return 0;
>>>>>>> 7d6fe4544994445ecceba564d5544610075ad34d:practicas/practica3/modificacion/main_palindrome_prod.cc
}