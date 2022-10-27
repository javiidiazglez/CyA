# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Asignatura: Computabilidad y Algoritmia
# Curso: 2º
# Práctica 03: Calculadora de lenguajes formales
# Autor: José Javier Díaz González
# Correo: alu0101128894@ull.es
# Fecha: 20/10/2022
# Archivo Makefile 
# Trabajar con la compilación de proyectos en C++.
# Historial de revisiones
# 20/10/2022 - Creación (primera versión) del Makefile

CXX = g++
CXXFLAGS = -g -w -std=c++17
NAMEGLAGS = -o
SRC = src
EXECUTABLE = p03_calculator

make:
	$(CXX) $(CXXFLAGS) ./$(SRC)/*.cc $(NAMEGLAGS) $(EXECUTABLE)

.PHONY: all clean

	$(CXX) $(CXXFLAGS) -c $<

clean :
	rm -f $(EXECUTABLE) *.o