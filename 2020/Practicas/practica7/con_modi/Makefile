
CC=g++
CXXFLAGS=-g -std=c++14

OBJS = dfa_simulation.o dfa_t.o estado_t.o transicion_t.o

all: ${OBJS}
	$(CC) $(CXXFLAGS) -o dfa_simulation ${OBJS}

clean: 
	rm -rf *.o dfa_simulation output.txt
