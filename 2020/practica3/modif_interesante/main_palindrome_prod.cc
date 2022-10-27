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

using namespace std;

int main(int argc, char * argv[]) {

    if(argc == 4) { // palindrome_prod (numero) (fichero1) (fichero2) = 4 argumentos

        if(atoi(argv[1]) <= 0) {
            cout << "\nERROR: Debes añadir un numero positivo mayor que 0 . Mira mas informacion en --help.\n" << endl;
            return 0;
        }
        
        else {
            double i, j, n_min, n_max, producto;
            // bool si_capicua;
           // string fichero_entrada;
            //string fichero_salida;
            string numero_cadena = "";

            //fichero_entrada = argv[2];       // argumento 2 = fichero_entrada
            //fichero_salida = argv[3];
            double digitos = atoi(argv[1]); // array to int || argumento 1 = digito


            ifstream fe(argv[2]);       
            ofstream fs(argv[3]);       // Llamada al fichero de salida

            n_min = 1 * pow(10.0, digitos - 1);    // 1 * 10 ^ digitos -1 = 1 * 10 ^ 2-1 = 10 (2 digitos)
            n_max = 1 * pow(10.0, digitos);        // 1 * 10 ^ digitos    = 1 * 10 ^ 2   = 100 (2 digitos)


            for (i = n_min; i < n_max; i++) {
                for (j = n_min; j < n_max; j++) {
                    if (i <= j) {                   // No se dupliquen i y j -> no multiplica si el numero es menor igual que el numero

                        producto = i * j;           // 11 * 91 = 1001

                        //si_capicua = capicua(producto, digitos);
                        //if (si_capicua == true)

                        if (capicua(producto, digitos)) {  // (1001 , 2)

                            fe.seekg(0, fe.beg);
                            while(!fe.eof()) {
                                char char_del_numero[100];
                                fe >> char_del_numero;
                                int int_del_numero = atoi(char_del_numero);
                                if(producto == int_del_numero) {

                                    string numero1 = to_string((int) i);  // numero 1 = de comillas a numero i
                                    string numero2 = to_string((int) j);
                                    numero_cadena = to_string((int) producto);     // string = comillas -> to_string (el numero a comillas)
                                
                                    fs << numero_cadena << " = " << i << " x "<< j << endl; // resultado = i * j

                                }
                            }
                        }
                    } 
                }
            }

            fs.close();
            fe.close();

            int elementos_por_linea = 5;
            int elementos_mostrados = 0;
            ifstream lectura_fichero_salida(argv[3]); 
            char cadena_de_texto[150];
            cout << "Contenido de " << argv[3] << endl;
            while ( !lectura_fichero_salida.eof()) {
                ++elementos_mostrados;
                lectura_fichero_salida >> cadena_de_texto;
                cout << cadena_de_texto << " ";
                if (elementos_mostrados == elementos_por_linea) {
                    cout << endl;
                    elementos_mostrados = 0;
                }
            }
            lectura_fichero_salida.close();
        }
        return 0;

    }
    
    else if (string (argv[1]) == "--help" ) { // si el argumento = 2 y argumento 1 = --help
    
        cout << "\nPara escribir el comando correctamente. Escriba " << argv[0] << " (NUMERO) (FICHERO.TXT) (FICHERO2.TXT)." << endl
            << "\nEjemplo: " << argv[0] << " 2 input.txt output.txt\n" << endl;
        return 0;
    }

    else {      // Caso contrario
        cout << "\nERROR: Debes añadir 3 argumentos validos. Usa: " << argv[0] << " (NUMERO) (FICHERO.TXT) (FICHERO2.TXT). Mira mas informacion en --help.\n" << endl;
            return 0;
    }

    return 0;
}