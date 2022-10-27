// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica #04: Expresiones regulares
// Autor: José Javier Díaz González
// Correo: alu0101128894@ull.es
// Fecha: 27/10/2022
// Archivo expresion.cc
// Definición de la clase
// Historial de revisiones
// 27/10/2022 - Actualización (primera versión) del expresion.cc
// 27/10/2022 - Finalización práctica 4

#include "expresion.h"

#include <fstream>
#include <iostream>
#include <regex>

// El constructor de la clase Programa con una cadena.
Expresion::Expresion(std::string name) {
  name_ = name;
  has_main = false;  // Inicializa la variables has_main a false.

  std::ifstream file_in(name);
  int number_line{0};
  std::string line_in;
  getline(file_in, line_in);  // Lee una linea del fichero de entrada
  number_line++;
  GetDescription(line_in, number_line, file_in);  // El código anterior obtiene la descripción de la línea de entrada.

  while (!file_in.eof()) {
    std::string line_in;
    getline(file_in, line_in);  // Lee una linea del fichero de entrada
    number_line++;
    GetComment(line_in, number_line, file_in);
    GetLongComment(line_in, number_line, file_in);
    GetVariable(line_in, number_line, file_in);
    GetStatement(line_in, number_line, file_in);
    GetMain(line_in, number_line, file_in);
    GetNoComents(line_in, number_line, file_in); // Nuevo
  }
}

void Expresion::GetNoComents(std::string line_in, int &number_line, std::ifstream &file_in) {
  std::string text1(line_in + "\n");
  no_coments_.push_back(text1);
}

// Esta función obtiene la descripción del programa.
// - line_in - linea del fichero de entrada
// - number_line - linea del fichero
// - file_in - fichero de entrada
void Expresion::GetDescription(std::string line_in, int &number_line, std::ifstream &file_in) {
  std::regex start_description{"^((\\s)*/\\*.*)"};  // Busca una cadena que comience con "/*"
  std::regex end_description{".*(\\*/)"};           // Busca una cadena que termine con "*/"
  if (std::regex_match(line_in, start_description)) {
    std::string text{line_in + "\n"};
    int start{number_line};
    while (!std::regex_match(line_in, end_description)) {
      getline(file_in, line_in);
      number_line++;
      text = text + line_in + "\n";  // Concatenar la línea de entrada con el texto y un salto de línea.
    }
    SetDescription(text, start, number_line);
  }
}

// Getter comentarios
void Expresion::GetComment(std::string line_in, int &number_line, std::ifstream &file_in) {
  std::regex comment_regex{"^(\\s*(//.*))"};  // Busca una cadena que comience con "//"
  if (std::regex_match(line_in, comment_regex)) {
    AddComment(std::regex_replace(line_in, std::regex("^\\s*"), ""), number_line);  // Reemplazar cualquier blanco o barra por ""
  }
}

// Getter comentario largo
void Expresion::GetLongComment(std::string line_in, int &number_line, std::ifstream &file_in) {
  // "^((\\s)*/\\*.*)"
  // Busca una cadena que comience con "*/""
  // Cantidad de caracteres de espacio en blanco antes de la /
  // Número de caracteres después de la /*
  std::regex start_long_comment{"^((\\s)*/\\*.*)"};
  std::regex end_long_comment{".*(\\*/)"};  // cadena que termina con */
  if (std::regex_match(line_in, start_long_comment)) {
    std::string text{line_in + "\n"};
    int start{number_line};
    while (!std::regex_match(line_in, end_long_comment)) {
      getline(file_in, line_in);
      number_line++;
      text = text + line_in + "\n";
    }
    AddLongComment(text, start, number_line);
  }
}
// Getter variable
void Expresion::GetVariable(std::string line_in, int &number_line, std::ifstream &file_in) {
  // ^\\s*(int|float|double)\\s*&?\\s*([^,;]*?)[,;].*$
  //  - int, flotante o doble
  //  - seguido de un & opcional
  //  - seguido de cualquier número de caracteres que no sean una coma o un punto y coma
  //  - seguido de una coma o punto y coma
  //  - seguido de cualquier número de caracteres
  std::regex variable_regex{"^\\s*(int|float|double)\\s*&?\\s*([^,;]*?)[,;].*$"};

  if (std::regex_match(line_in, variable_regex)) {
    std::string type, value;
    if (std::regex_search(line_in, std::regex("int"))) {  // "int" es una expresión regular que busca la cadena "int" en la línea de entrada.
      type = "INT";
      value = std::regex_replace(line_in, std::regex("\\s*int\\s"), "");  // Elimina cualquier espacio en blanco antes de int y después de int.
    } else if (std::regex_search(line_in, std::regex("float"))) {
      type = "FLOAT";
      value = std::regex_replace(line_in, std::regex("\\s*float\\s"), "");  // Elimina cualquier espacio en blanco antes de float y después de float.
    } else if (std::regex_search(line_in, std::regex("double"))) {
      type = "DOUBLE";
      value = std::regex_replace(line_in, std::regex("\\s*double\\s"), "");
    }
    value = std::regex_replace(value, std::regex(";"), "");
    AddVariable(type, value, number_line);
  }
}

// Getter if, for, whiles
void Expresion::GetStatement(std::string line_in, int &number_line, std::ifstream &file_in) {
  std::regex statement_regex{"^(\\s*(if|for|while).*)"};  // Busca una cadena que comience con "if", "for" o "while"
  if (std::regex_match(line_in, statement_regex)) {
    std::string type, name;
    if (std::regex_search(line_in, std::regex("^\\s*if"))) {
      type = "CONDITIONAL";
      name = "if";
    } else if (std::regex_search(line_in, std::regex("^\\s*(while|for)"))) {
      type = "LOOP";
      if (std::regex_search(line_in, std::regex("for"))) {
        name = "for";
      } else
        name = "while";
    }
    AddStatement(type, name, number_line);
  }
}

// Getter main
void Expresion::GetMain(std::string line_in, int &number_line, std::ifstream &file_in) {
  std::regex main_regex{"^(\\s*int\\smain.*)"};  // Busca una cadena que comience con "int main"

  if (std::regex_match(line_in, main_regex)) {
    HasMain();
  }
}

// Setter descripción
void Expresion::SetDescription(std::string text, int start, int end) {
  description_.text = text;
  description_.start = start;
  description_.end = end;
}

// Obtener comentarios
void Expresion::AddComment(std::string text, int line) {
  comments comments{text, line};
  comments_.emplace_back(comments);  // Añade una nueva variable al final del vector.
}

// Obtener comentarios largos
void Expresion::AddLongComment(std::string text, int start, int end) {
  // Creando una nueva variable de tipo long_comments e inicializándola con los valores de texto, inicio y final.
  long_comments comments{text, start, end};
  long_comments_.emplace_back(comments);  // Añade una nueva variable al final del vector.
}

// Función que establece la variable has_main en verdadero.
void Expresion::HasMain() {
  has_main = true;
}

// Funcion para añadir variables
void Expresion::AddVariable(std::string type, std::string value, int line) {
  // Creando una nueva variable de tipo variables e inicializándola con los valores de tipo, valor y línea.
  variables variables{type, value, line};
  variables_.push_back(variables);  // Añade una nueva variable al final del vector.s
}

// Funicón que agrega una nueva sentencia al vector de sentencias.
void Expresion::AddStatement(std::string type, std::string name, int line) {
  // Creando una nueva variable de tipo statements e inicializándola con los valores de tipo, nombre y línea.
  statements statements{type, name, line};
  statements_.push_back(statements);
}

// Sobrecarga del operador <<
std::ostream &operator<<(std::ostream &os, const Expresion &expresion) {

  for (int pos_i{0}; pos_i < expresion.no_coments_.size(); ++pos_i) {
    os << expresion.no_coments_[pos_i];

  }
  return os;

  // os << "PROGRAM: " << expresion.name_ << "\n";
  // os << "DESCRIPTION: \n"
  //    << expresion.description_.text << "\n";

  // os << "VARIABLES: \n";
  // for (int pos_i{0}; pos_i < expresion.variables_.size(); ++pos_i) {
  //   os << "[Line " << expresion.variables_[pos_i].line << "] "
  //      << expresion.variables_[pos_i].type << ": "
  //      << expresion.variables_[pos_i].value << "\n";
  // }
  // os << "\n";

  // os << "STATEMENTS: \n";
  // for (int pos_i{0}; pos_i < expresion.statements_.size(); ++pos_i) {
  //   os << "[Line " << expresion.statements_[pos_i].line << "] "
  //      << expresion.statements_[pos_i].type << ": "
  //      << expresion.statements_[pos_i].name << "\n";
  // }
  // os << "\n";

  // os << "MAIN: ";
  // if (expresion.has_main) {
  //   os << "true\n\n";
  // } else
  //   os << "false\n\n";

  // os << "COMMENTS: \n";
  // os << "[Lines " << expresion.description_.start << " - "
  //    << expresion.description_.end << "] DESCRIPTION\n";
  // for (int pos_i{0}; pos_i < expresion.long_comments_.size(); ++pos_i) {
  //   os << "[Lines " << expresion.long_comments_[pos_i].start
  //      << " - "
  //      << expresion.long_comments_[pos_i].end << "]\n"
  //      << expresion.long_comments_[pos_i].text;
  // }
  // for (int pos_i{0}; pos_i < expresion.comments_.size(); ++pos_i) {
  //   os << "[Line " << expresion.comments_[pos_i].line << "] "
  //      << expresion.comments_[pos_i].text << "\n";
  // } 
}