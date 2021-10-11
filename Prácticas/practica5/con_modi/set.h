// UNIVERSIDAD DE LA LAGUNA
// GRADO EN INGENIERIA INFORMATICA
// AUTOR: José Javier Díaz González
// FECHA: 5-11-2020
// CORREO: alu0101128894@ull.edu.es
// ASIGNATURA: Computabilidad y Algoritmia
// PRACTICA: La clase Set
// Lenguaje: C++
// Contenido: Recibe un archivo con conjuntos y operaciones con los mismos
// Usamos el comando make para compilar -> g++ -std=c++14 -g -Wall -o set_calculator set_calculator.cc set.cc 
// Comando Ejecucion: ./set_calculator infile.txt outfile.txt

#include <iostream>
#define kBitsLong 32
using namespace std;

//const int kBitsLong =  sizeof(long); 

class Set {

  private:
    int numero_longs_;   // Numero de longs 
    int cantidad_cifras_; // Numero de cantidad de cifras
    long *conjunto_; // Puntero para el conjunto que es el numero de longs
    bool si_vacio_; // Si es 1 true 0 false

  public:
    Set(const int = kBitsLong, const bool = false); // defecto int = 1
    ~Set();

    // Getters
    int get_cantidad_cifras() const;
    int get_cantidad_longs() const;
    int get_size_conjunto() const;
    long get_vector(const int) const;
    bool get_si_vacio() const;
    // Setters
    void set_cantidad_cifras(const int);
    // Metodos
    void Insertar(Set primer_valor, int numero_fichero); // Insertar un elemento en un conjunto
    void Eliminar(int); // Eliminar un elemento de un conjunto (supuesto que ya pertenece al mismo).
    void Vaciar(); // Vaciar un conjunto(eliminar todos los elementos que lo componen)
    bool Vacio(); // Determinar si un conjunto está vacio
    bool Pertenece(int); // Determinar si un elemento pertenece al conjunto
    bool Iguales(Set primer_valor, Set segundo_valor); // Determina si dos conjuntos son iguales
    // Operaciones
    void Union(Set primer_valor, Set segundo_valor);
    void DiferenciaSimetrica(Set primer_valor, Set segundo_valor);
    void Interseccion(Set primer_valor, Set segundo_valor);
    void Complementacion(Set primer_valor);
    void Asignacion(Set primer_valor, Set segundo_valor);
    // Funciones
    void Resize (const int, const bool = false);
    void Write(ostream& = cout) const;
    void Read(istream& = cin);
  
    void Build(void);
    void Destroy(void);
};

ostream& operator<< (ostream& os, const Set& valor);
istream& operator>> (istream& is, Set& valor);
