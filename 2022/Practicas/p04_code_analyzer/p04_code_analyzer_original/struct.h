// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica #04: Expresiones regulares
// Autor: José Javier Díaz González
// Correo: alu0101128894@ull.es
// Fecha: 27/10/2022
// Archivo struct.h
// Definición de la clase
// Historial de revisiones
// 27/10/2022 - Actualización (primera versión) del struct.h
// 27/10/2022 - Finalización práctica 4

// Se define una estructura llamada description que contiene un string 
// llamado text, un entero llamado start y un entero llamado end.
struct description {
  std::string text;
  int start;
  int end;
};

// Se define una estructura llamada comments que contiene un string 
// llamado text, un entero llamado line.
struct comments {
  std::string text;
  int line;
};

// Definiendo una estructura llamada long_comments que contiene una cadena 
// llamada text, un entero llamado start y un entero llamado end.
struct long_comments {
  std::string text;
  int start;
  int end;
};

// Definición de una estructura llamada variables que contiene una cadena 
// llamada tipo, una cadena llamada valor y un número entero llamado línea.
struct variables {
  std::string type;
  std::string value;
  int line;
};

// Definición de una declaración llamada statements que contiene una cadena 
// llamada tipo, una cadena llamada nombre y un número entero llamado línea.
struct statements {
  std::string type;
  std::string name;
  int line;
};