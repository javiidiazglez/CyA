// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Símbolos, alfabetos y cadenas
// Autor: José Javier Díaz González
// Correo: alu0101128894@ull.es
// Fecha: 06/10/2022
// Archivo P01_main.cc
// Programa principal
// Historial de revisiones
// 06/10/2022 - Actualización (segunda versión) del P01_main.cc

#include <iostream>

#include "String.h"
#include "Usage.h"

const std::string EMPTY = "";

int main(int argc, char* argv[])
{
  Usage(argc, argv);  // Comprobando que el número de argumentos es correcto.

  std::string input_n = argv[1], output_n = argv[2];
  int opcode = atoi(argv[3]);

  std::fstream file_in, file_out;
  file_in.open(input_n, std::fstream::in);
  file_out.open(output_n, std::fstream::out);
  // Comprobando que se pueden abrir correctamente los ficheros
  CheckItsOk(file_in, file_out);  // Comprueba si los archivos están abiertos.

  std::vector<Strings> FILE;

  // Comprobando si el archivo está abierto.
  while (file_in)
  {
    Strings msg_string{file_in};
    FILE.push_back(msg_string);
  }

  Strings Dummy;
  std::vector<Strings> FILE_VECTOR;
  switch (opcode)
  {
    case 1:
      for (int pos_1 = 0; pos_1 < FILE.size(); pos_1++)
      {
        file_out << FILE[pos_1].GetLength();  // Escribir la longitud de la cadena en el archivo.
        file_out << ENDL;
      }
      std::cout << "1. Longitud. \n-> Fichero de salida: 'fileout.txt'\n";
      break;
    case 2:
      for (int pos_1 = 0; pos_1 < FILE.size(); pos_1++)
      {
        FILE[pos_1].GetReverse(Dummy);  // Llamando a la función GetReverse desde la clase Strings.
        Dummy.Write(file_out);
        file_out << ENDL;
      }
      std::cout << "2. Inversa. \n-> Fichero de salida: 'fileout.txt'\n";
      break;
    case 3:
      for (int pos_1 = 0; pos_1 < FILE.size(); pos_1++)
      {
        FILE[pos_1].GetPrefix(FILE_VECTOR);  // Llamando a la función GetPrefix desde la clase Strings.
        // Un bucle for que itera sobre los elementos del vector FILE_VECTOR.
        for (int pos_2 = 0; pos_2 < FILE_VECTOR.size(); pos_2++)
        {
          FILE_VECTOR[pos_2].Write(file_out);  // Escribiendo los elementos del vector FILE_VECTOR en el file_out.
          file_out << SPACE;
        }
        file_out << ENDL;
      }
      std::cout << "3. Prefijos. \n-> Fichero de salida: 'fileout.txt'\n";
      break;
    case 4:
      for (int pos_1 = 0; pos_1 < FILE.size(); pos_1++)
      {
        FILE[pos_1].GetSufix(FILE_VECTOR);  // Llamando a la función GetSufix desde la clase Strings.
        for (int pos_2 = 0; pos_2 < FILE_VECTOR.size(); pos_2++)
        {
          FILE_VECTOR[pos_2].Write(file_out);
          file_out << SPACE;
        }
        file_out << ENDL;
      }
      std::cout << "4. Sufijos. \n-> Fichero de salida: 'fileout.txt'\n";
      break;
    case 5:
      for (int pos_1 = 0; pos_1 < FILE.size(); pos_1++)
      {
        FILE[pos_1].GetSubString(FILE_VECTOR);  // Llamando a la función GetSubString desde la clase Strings.
        for (int pos_2 = 0; pos_2 < FILE_VECTOR.size(); pos_2++)
        {
          FILE_VECTOR[pos_2].Write(file_out);
          file_out << SPACE;
        }
        file_out << ENDL;
      }
      std::cout << "5. Subcadenas. \n-> Fichero de salida: 'fileout.txt'\n";
      break;
    default:
      std::cout << kOpcode;
      break;
  }
  return 0;
}
