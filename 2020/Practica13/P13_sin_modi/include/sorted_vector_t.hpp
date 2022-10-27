#pragma once

#include <vector>
#include <iostream>

using namespace std;


namespace CyA
{

class sorted_vector_t: public vector<int>
{
public:
    sorted_vector_t(void):
    vector<int>() {} //constructor por defecto

    sorted_vector_t(const vector<int>& v): //constructor
    vector<int>(v) {}

    ~sorted_vector_t(void) {} //destructor

    void merge_sort(void); // calcula por defecto que el elemento mas a la izquierda es el de la posición 0 y el más a la derecha es el de la posición, tamaño -1
    void write(ostream& os) const;    //metodo para mostrar por consola o para escribir en un fichero
    void merge_sort_ite(void);


private:

    void create_vector_sentinel(int l, int r, vector<int>& v); //método para añadir el centinela
    void merge(const vector<int>& v1, const vector<int>& v2, int l); //método para dividir en 2 vectores mas pequeños


    void merge_sort(int l, int r); //calculo si el vector tiene longitud y si la tiene calculo el elemento central
    void merge(int l, int c, int d); //

};

}

ostream& operator<<(ostream& os, const CyA::sorted_vector_t& v);
