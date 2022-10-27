# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Asignatura: Computabilidad y Algoritmia
# Curso: 2º
# Práctica 04: Expresiones Regulares
# Autor: José Javier Díaz González
# Correo: alu0101128894@ull.es
# Fecha: 27/10/2022
# Archivo Makefile 
# Trabajar con la compilación de proyectos en C++.
# Historial de revisiones
# 27/10/2022 - Creación (primera versión) del Makefile


CXX = g++
CXXFLAGS = -g -std=c++17
NAMEGLAGS = -o
SRC = p04_main.cc expresion.cc usage.cc
EXECUTABLE = p04_code_analyzer

make:
	$(CXX) $(CXXFLAGS) $(SRC) $(NAMEGLAGS) $(EXECUTABLE)

.PHONY: all clean

	$(CXX) $(CXXFLAGS) -c $<

clean :
	rm -f $(EXECUTABLE) *.o