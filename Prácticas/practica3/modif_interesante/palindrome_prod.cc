<<<<<<< HEAD:Prácticas/practica3/modif_interesante/palindrome_prod.cc
/*

Practica 3: Computabilidad y Algoritmia

Nombre Practica: palindrome_prod.cc

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
#include <vector>
#include <cmath>
#include <string>
#include <fstream>

// 4 6 5 4
// 0 1 2 3 -> posiciones

bool capicua(double n, double d) {                  

    bool es = true;
    int numero = (int) n; 
    int digitos = (int) d;
    int i, j, divisor;
    std::vector <int> numero_vector;

    for (i = 0; i < digitos * 2; i++) {             // 0 posiciones hasta (digitos * 2) -> 2 digitos (el maximo 4) 
        if (numero > 0) {                           // Si el numero > 0 sale de la secuencia
            divisor = numero % 10;                  // 345 % 10 = 5                 
            numero_vector.push_back(divisor);       // Me lo guardo en el vector -> 5 4 3 (de atrás en adelante)
            numero = numero / 10;                   // 345 / 10 = 34 (numero entero = 34)
        }                                           
    }                                               

    j = numero_vector.size() - 1;                           // j = devuelve tamaño del vector = 3, devuelve la ultima posicion (0 1 2) = 3-1 = 2
    for (i = 0; i < (int)numero_vector.size(); i++, j--) {  // i = 0, i < ultima posicion del vector (entero) i++ (incrementando)
        if (i < j) {                                        // 345 => i=3 , j= 5 (La I hacia la derecha y la J hacia la izquierda) (Posiciones)
            if (numero_vector[i] != numero_vector[j]) {     // No cumple = false
                es = false;
            }
        }
        //j--; // La j va para la izquierda
    }
    return es; // Retorna un true
}
=======
/*

Practica 3: Computabilidad y Algoritmia
Nombre Practica: palindrome_prod.cc
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
#include <vector>
#include <cmath>
#include <string>
#include <fstream>

bool capicua(double n, double d) {                  
    bool es = true;
    int numero = (int) n; 
    int digitos = (int) d;
    int i, j, divisor;
    std::vector <int> numero_vector;

    for (i = 0; i < digitos * 2; i++) {             // 0 posiciones hasta (digitos * 2) -> 2 digitos (el maximo 4) 
        if (numero > 0) {                           // Si el numero > 0 sale de la secuencia
            divisor = numero % 10;                  // 345 % 10 = 5                 
            numero_vector.push_back(divisor);       // Me lo guardo en el vector -> 5 4 3 (de atrás en adelante)
            numero = numero / 10;                   // 345 / 10 = 34 (numero entero = 34)
        }                                           
    }                                               

    j = numero_vector.size() - 1;                           // j = devuelve tamaño del vector = 3, devuelve la ultima posicion (0 1 2) = 3-1 = 2
    for (i = 0; i < (int)numero_vector.size(); i++, j--) {  // i = 0, i < ultima posicion del vector (entero) i++ (incrementando)
        if (i < j) {                                        // 345 => i=3 , j= 5 (La I hacia la derecha y la J hacia la izquierda) (Posiciones)
            if (numero_vector[i] != numero_vector[j]) {     // No cumple = false
                es = false;
            }
        }
        //j--; // La j va para la izquierda
    }
    return es; // Retorna un true
}
>>>>>>> 7d6fe4544994445ecceba564d5544610075ad34d:practicas/practica3/modificacion/palindrome_prod_exercise.cc
