// UNIVERSIDAD DE LA LAGUNA
// GRADO EN INGENIERIA INFORMATICA
// AUTOR: José Javier Díaz González
// FECHA: 18-11-2020
// E-MAIL: alu0101128894@ull.edu.es
// ASIGNATURA: Computabilidad y Algoritmia
// PRACTICA: P07 - DFA
// Referencias: https://es.wikipedia.org/wiki/Aut%C3%B3mata_finito_determinista
// Nombre del archivo: dfa_t.cc

#include "dfa_t.h"

dfa_t::dfa_t(char* archivo_entrada_dfa) {     // Lee linea a linea del .dfa
  std::ifstream input_(archivo_entrada_dfa);
  if (!input_.is_open()) {
    std::cout << "\nEl fichero no se ha abierto correctamente.\n" << std::endl;
    exit(1);
  } else {

    // Numero de simbolos y simbolos del alfabeto
    int numeros_simbolos;
    char simbolo;
    input_ >> numeros_simbolos; // 2 (el primero de todo en el input.dfa)

    for (int iterador = 0; iterador < numeros_simbolos; iterador++) {
      input_ >> simbolo;          // 0 ... 1
      alfabeto_.insert(simbolo);  // Inserta dentro del simbolo
    }

    // Numero de estados, los meto en un vector. Nombre de los estados
    input_ >> numeros_estados; // 5
    std::string nombres_estados; // declaramos el nombre los nombres de los estados
    for (int iterador = 0; iterador < numeros_estados; iterador++) {
      input_ >> nombres_estados; // q0, cero...
      estado_t estado_nuevo(nombres_estados);
      estados_.push_back(estado_nuevo);    // elementos vector = pushback , elementos caracter = insert
    }
    
    // Estado inicial
    input_ >> nombres_estados; // el siguiente, que es q0
    for (unsigned int iterador = 0; iterador < estados_.size(); iterador++) {
      if (estados_[iterador].getNombre() == nombres_estados) // cero == q0...
        estados_[iterador].setInicio();  // coincide el primero = q0 inciio
    }

    // Estados de aceptacion
    int numeros_estados_aceptacion;
    input_ >> numeros_estados_aceptacion;   // 2
    for (int iterador = 0; iterador < numeros_estados_aceptacion; iterador++) {
      input_ >> nombres_estados; // cero, ..
      for (unsigned int iterador = 0; iterador < estados_.size(); iterador++) {
        if (estados_[iterador].getNombre() == nombres_estados) {   // nombre de los estados de acptacion == nombre estado
          estados_[iterador].setAceptacion();    // lo acepta
        }
      }
    }

    // Transiciones
    input_ >> numeros_transiciones;
    std::string estado_actual, estado_siguiente;
    char entrada;
    for (int iterador = 0; iterador < numeros_transiciones; iterador++) {
      input_ >> estado_actual;
      input_ >> entrada;
      input_ >> estado_siguiente;
      transicion_t transicion_nueva(estado_actual, entrada, estado_siguiente);  // metemos en un nuevo vector las 3 transiciones
      transiciones_.push_back(transicion_nueva);                                // transiciones_ un push back a la nueva transicion
    }
  }
}

void dfa_t::encontrar_cadenas(char* input, char* output) {
  std::ifstream input_(input);
  std::ofstream output_(output); // No sobreescribimos, no Append
  std::string cadena;
  std::string estado_actual;
  bool si_pertenece_alfabeto = false;

  while (!input_.eof()) {
    getline(input_, cadena);      // leer linea
     if (cadena.size() == 0) {    // si el tamaño de la cadena == 0 continua   
      continue;
    }
    for (unsigned int iterador = 0; iterador < estados_.size(); iterador++) {
      if (estados_[iterador].esInicio()) { //q0 (estado inicial)
        estado_actual = estados_[iterador].getNombre(); // estado actual = de todos , el primero es el que le pasa (q0)
      }
    }
    for (unsigned int posicion_j = 0; posicion_j < cadena.size(); posicion_j++) {
      si_pertenece_alfabeto = alfabeto_.find(cadena[posicion_j]) != alfabeto_.end(); // cadena posicion_j != {0,1}
      if(!si_pertenece_alfabeto) {                                          // no pertenece = error
        std::cout << "Error: '" << cadena[posicion_j] << "' no pertenece al alfabeto." << std::endl;
        break;
      } 
      for (unsigned int iterador = 0; iterador < transiciones_.size(); iterador++) {
        if (transiciones_[iterador].getEstadoActual() == estado_actual) {    // si el estado actual transicion = al estado actual
          if (transiciones_[iterador].getEntrada() == cadena[posicion_j]) {           // entrada transicion == cadena del fichero
            std::cout << estado_actual << " -> " << cadena[posicion_j] << " -> ";
            estado_actual = transiciones_[iterador].getEstadoSiguiente();
            std::cout << estado_actual << std::endl;
            break;     
          }
        }
      }
    }
    dfa_t::imprimir_cadenas(input, output, cadena, estado_actual, si_pertenece_alfabeto);
  }
}

void dfa_t::imprimir_cadenas(char* input, char* output, std::string cadena, std::string estado_actual, bool si_pertenece_alfabeto = false) {
  std::ifstream input_(input);
  std::ofstream output_(output, std::fstream::app); // Usamos el append para sobreescribir el fichero cuando le pasamos la funcion
  std::cout << "----------------------";
    for (unsigned int iterador = 0; iterador < estados_.size(); iterador++) {
      if (estados_[iterador].getNombre() == estado_actual) {     // el nombre == al propio estado, salta
        if (!si_pertenece_alfabeto) {                     // si no pertenece = error
          output_ << "Error" << std::endl;
        } else if (estados_[iterador].esAceptacion()) {        // Si acepta (true) = si
          output_ << "Si" << std::endl;
        } else {
          output_ << "No" << std::endl;                 // caso contrario = no
        }
      }
    }
    std::cout << std::endl;
}
