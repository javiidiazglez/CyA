CXX = g++
CXXFLAGS = -g -w
NAMEGLAGS = -o
SRC = p07_main.cc alphabet.cc automata.cc chain.cc grammar.cc production.cc state.cc symbol.cc usage.cc transition.cc
PROGRAM_NAME = p07_dfa2grammar

make:
	$(CXX) $(CXXFLAGS) $(SRC) $(NAMEGLAGS) $(PROGRAM_NAME)

.PHONY: all clean

	$(CXX) $(CXXFLAGS) -c $<

clean :
	rm -f $(PROGRAM_NAME) *.o
	rm -rf *~ basura b i