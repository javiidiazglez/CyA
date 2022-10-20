// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica #03: Calculadora de lenguajes formales
// Autor: José Javier Díaz González
// Correo: alu0101128894@ull.es
// Fecha: 20/10/2022
// Archivo Calculator.cc
// Definición de la clase
// Historial de revisiones
// 20/10/2022 - Actualización (primera versión) del Calculator.cc
// 20/10/2022 - Finalización práctica 3

#include "../include/Calculator.h"

// Empujar una lengua al vector de las lenguas.
void Calculator::Push_back(const Language& language) { calculator_.push_back(language); }

// Comprobando si la calculadora es un operator.
bool Calculator::IsOperatorChar(const char& char_operator) {
  switch (char_operator) {
    case '+':
    case '|':
    case '^':
    case '-':
    case '!':
    case '*':
      return true;
    default:
      return false;
  }
}

// Comprobando si la cadena es un operator.
bool Calculator::IsOperatorString(std::string string_operator) {
  if (string_operator == "+" || string_operator == "|" || string_operator == "^" || string_operator == "-" || string_operator == "!" || string_operator == "*") {
    return true;  // string is an operator
  }
  return false;  // not an operator
}

// Comprobando si el carácter es un número.
int Calculator::IsOperatorInt(const char& int_operator) {
  int number;
  // Comprobando si el carácter es un número.
  if (int_operator >= '0' && int_operator <= '9') {
    // Convertir el carácter a un número entero.
    number = int_operator - '0';
    return number;
  }
  return -1;
}

// // Una función que devuelve el algoritmo RPN
Language Calculator::RPN(std::string& input_string) {
  const char SPACE = ' ';
  Language firstLanguage, secondLanguage;
  int powerLanguaje = 0;
  std::stack<Language> stack_1;
  std::string id;
  // Un bucle for que itera sobre la cadena de entrada.
  for (int pos_1{0}; pos_1 <= input_string.size(); pos_1++) {
    if ((input_string[pos_1] == SPACE) || (pos_1 == input_string.size())) {
      for (int pos_2{0}; pos_2 < calculator_.size(); pos_2++) {
        // Comparando el identificador del lenguaje con el id.
        if (calculator_[pos_2].getIdentifierLanguage() == id) {
          stack_1.push(calculator_[pos_2]);
        }
      }
      // Comprobando si la cadena es un operador y si la pila no está vacía.
      if ((IsOperatorString(id)) && (!stack_1.empty())) {
        // Comprobación del primer carácter de la cadena.
        switch (id[0]) {
          case '+':
            secondLanguage = stack_1.top();  // Elemento superior de la pila -> secondLanguage.
            stack_1.pop();                   // Eliminar el elemento superior de la pila.
            firstLanguage = stack_1.top();   // Elemento superior de la pila -> firstLanguage.
            stack_1.pop();                   // Eliminar el elemento superior de la pila.
            // Empujando el resultado de la concatenación de firstLanguage y secondLanguage en stack_1.    
            stack_1.push(firstLanguage.Concatenation(secondLanguage));
            stack_1.top();
            std::cout << "+";
            break;
          case '|':
            secondLanguage = stack_1.top();  // Elemento superior de la pila -> secondLanguage.
            stack_1.pop();                   // Eliminar el elemento superior de la pila.
            firstLanguage = stack_1.top();   // Elemento superior de la pila -> firstLanguage.
            stack_1.pop();                   // Eliminar el elemento superior de la pila.
            // Empujando el resultado de la union de firstLanguage y secondLanguage en stack_1.
            stack_1.push(firstLanguage.Union(secondLanguage));
            std::cout << "|";
            stack_1.top();
            break;
          case '^':
            secondLanguage = stack_1.top();
            stack_1.pop();
            firstLanguage = stack_1.top();
            stack_1.pop();
            stack_1.push(firstLanguage.Intersection(secondLanguage));
            std::cout << "^";
            stack_1.top();
            break;
          case '-':
            secondLanguage = stack_1.top();
            stack_1.pop();
            firstLanguage = stack_1.top();
            stack_1.pop();
            stack_1.push(firstLanguage.Difference(secondLanguage));
            std::cout << "-";
            stack_1.top();
            break;
          case '!':
            firstLanguage = stack_1.top();
            stack_1.pop();
            stack_1.push(firstLanguage.InverseLanguage());
            std::cout << "!";
            stack_1.top();
            break;
          case '*':
            firstLanguage = stack_1.top();
            stack_1.pop();
            stack_1.push(firstLanguage.PowerLanguage(powerLanguaje));
            std::cout << "*";
            stack_1.top();
          default:
            break;
        }
      }
      id = "";  // Limpiando la cadena.
    } else {
      id += (input_string[pos_1]);                           // Agregar el carácter de la cadena al id.
      if (IsOperatorInt(input_string[pos_1]) != -1) {        // Comprobando si el carácter es un número.
        powerLanguaje = IsOperatorInt(input_string[pos_1]);  // Conseguir la potencia del lenguaje.
      }
    }
  }
  // Comprobando si solo hay un elemento en la pila, si solo hay un elemento en la pila, es el resultado.
  if (stack_1.size() == 1) {
    return stack_1.top();  // Devolviendo el elemento superior de la pila.
  } else {
    std::cout << stack_1.size() << std::endl;
    std::cerr << "Error: Expresión incorrecta. ¡Revise las expresiones en el fichero filein.txt!\n"
              << std::endl;
    exit(EXIT_FAILURE);
  }
}