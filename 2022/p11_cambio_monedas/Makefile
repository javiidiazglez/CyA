CXX = g++
CXXFLAGS = -g -w
NAMEGLAGS = -o
SRC = main.cc monedas.cc tools.cc
PROGRAM_NAME = p11_cambio_monedas

make:
	$(CXX) $(CXXFLAGS) $(SRC) $(NAMEGLAGS) $(PROGRAM_NAME)

.PHONY: all clean

	$(CXX) $(CXXFLAGS) -c $<

clean :
	rm -f $(PROGRAM_NAME) *.o
	rm -rf *~ basura b i