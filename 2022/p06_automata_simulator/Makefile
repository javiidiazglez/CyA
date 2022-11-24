CXX = g++
CXXFLAGS = -g -w
NAMEGLAGS = -o
SRC = p06_main.cc alphabet.cc language.cc nfa.cc state.cc strings.cc symbol.cc usage.cc
PROGRAM_NAME = p06_automata_simulator

make:
	$(CXX) $(CXXFLAGS) $(SRC) $(NAMEGLAGS) $(PROGRAM_NAME)

.PHONY: all clean

	$(CXX) $(CXXFLAGS) -c $<

clean :
	rm -f $(PROGRAM_NAME) *.o
	rm -rf *~ basura b i