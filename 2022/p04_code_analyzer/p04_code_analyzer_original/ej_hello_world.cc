/*
 * José Javier Díaz González
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 4 Jun 2020
 * @brief The classical 'Hello World' first program in any language
 *
 * @see http://www.cplusplus.com/doc/tutorial/program_structure/
 * @see http://cpp.sh/2dd
 */

#include <iostream>

/*
hola
*/

int main () {
  // Is this your first C++ program ?
  // comment2

  for (int i = 0; i < 3; i++) {
    std::cout << "Hello World!" << std::endl;
  }

  int i = 0;
  float j = 0.1;
  double k = 0.1;
  int f;

  if (i == 0) {
    std::cout << "Hola" << std::endl;
    // algo
  }

  while (i < 3) {
    std::cout << "Hello World!" << std::endl;
    i++;
  }
  return 0;
}