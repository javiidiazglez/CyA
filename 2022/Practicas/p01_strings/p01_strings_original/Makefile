# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Asignatura: Computabilidad y Algoritmia
# Curso: 2º
# Práctica 1: Símbolos, alfabetos y cadenas
# Autor: José Javier Díaz González
# Correo: alu0101128894@ull.es
# Fecha: 06/10/2022
# Archivo Makefile 
# Trabajar con la compilación de proyectos en C++.
# Historial de revisiones
# 06/10/2022 - Creación (primera versión) del Makefile

CXX		  := g++
CXX_FLAGS := -std=c++17

SRC		:= src
INCLUDE	:= include

EXECUTABLE	:= p01_strings

all: $(EXECUTABLE)

run: clean all
	clear
	./$(EXECUTABLE)

$(EXECUTABLE): $(SRC)/*.cc $(INCLUDE)/*.h
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $^ -o $@ 

clean:
	-rm $(EXECUTABLE)