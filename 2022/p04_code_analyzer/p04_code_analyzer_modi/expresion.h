// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica #04: Expresiones regulares
// Autor: José Javier Díaz González
// Correo: alu0101128894@ull.es
// Fecha: 27/10/2022
// Archivo expresion.h
// Definición de la clase
// Historial de revisiones
// 27/10/2022 - Actualización (primera versión) del expresions.h
// 27/10/2022 - Finalización práctica 4

#ifndef EXPRESION_H_
#define EXPRESION_H_
#include <string>
#include <vector>

#include "struct.h"

class Expresion {
 public:
  Expresion(std::string name);  // El constructor de la clase Programa.
  // Getter
  void GetDescription(std::string line_in, int &number_line, std::ifstream &file_in);  // Una función que obtiene la descripción del programa.
  void GetComment(std::string line_in, int &number_line, std::ifstream &file_in);      // Obtener el comentario de la línea de entrada.
  void GetLongComment(std::string line_in, int &number_line, std::ifstream &file_in);  // Obtener el comentario largo de la línea de entrada.
  void GetVariable(std::string line_in, int &number_line, std::ifstream &file_in);     // Obtener la variables de la línea de entrada.
  void GetStatement(std::string line_in, int &number_line, std::ifstream &file_in);    // Obtener la declaración de la línea de entrada.
  void GetMain(std::string line_in, int &number_line, std::ifstream &file_in);         // Consiguiendo la función principal del programa.
  // Setter
  void SetDescription(std::string text, int start, int end);        // Una función que establece la descripción del programa.
  void AddComment(std::string text, int line);                      // Añadir de un comentario al vector de comentarios.
  void AddLongComment(std::string text, int start, int end);        // Añadir un comentario largo al vector de comentarios largos.
  void HasMain();                                                   // Comprobación de si el programa tiene una función principal.
  void AddVariable(std::string type, std::string value, int line);  // Añadir de una variables al vector de variables.
  void AddStatement(std::string type, std::string name, int line);  // Añadir de una sentencia al vector de sentencias.

  void GetNoComents(std::string line_in, int &number_line, std::ifstream &file_in);

  friend std::ostream &operator<<(std::ostream &os, const Expresion &expresion);  // Una función amiga que sobrecarga el operador <<.

 private:
  std::string name_;                          // Una variables privada de la clase Programa.
  description description_;                   // Una variables de la descripción de la clase.
  std::vector<comments> comments_;            // Un vector de comentarios.
  std::vector<long_comments> long_comments_;  // Un vector de comentarios largos.
  std::vector<variables> variables_;          // Un vector de variables.
  std::vector<statements> statements_;        // Un vector de declaraciones.

  std::vector<std::string> no_coments_;
  
  bool has_main;  // Un boleano has_main.
};

#endif