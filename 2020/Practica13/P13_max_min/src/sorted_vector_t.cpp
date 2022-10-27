#include "sorted_vector_t.hpp"

#include <climits>
#include <iomanip>

namespace CyA
{

void sorted_vector_t::merge_sort_max(void)
{
    merge_sort_max(0, size() - 1); //por defecto el elemento incial si no se le dice nada es el de la posición 0 y el final el del tamaño -1
}

void sorted_vector_t::merge_sort_min(void)
{
    merge_sort_min(0, size() - 1); //por defecto el elemento incial si no se le dice nada es el de la posición 0 y el final el del tamaño -1
}

void sorted_vector_t::write(ostream& os) const
{
    const int sz = size();

    os << "<";
    for(int i = 0; i < sz; i++)
        os << setw(5) << at(i);
    os << " >";
}


void sorted_vector_t::merge_sort_max(int l, int r)
{
    if (l < r) { //calculo si el vector tiene longitud

        int c = (l + r) / 2;

        merge_sort_max(l, c);

        merge_sort_max(c + 1, r);

        merge_max(l, c, r);
    }
}

void sorted_vector_t::merge_sort_min(int l, int r)
{
    if (l < r) { //calculo si el vector tiene longitud

        int c = (l + r) / 2;

        merge_sort_min(l, c);

        merge_sort_min(c + 1, r);

        merge_min(l, c, r);
    }
}


////////////////////////////////////////////////////////////////////////////
// FUSIÓN CON CENTINELA
////////////////////////////////////////////////////////////////////////////

void sorted_vector_t::create_vector_sentinel_max(int l, int r, vector<int>& v) //el centinela le da a la ultima posición de cada vector un tamaño mas grande que a cualquiera(infinito) para que cuando ordene los ordene de mayor a menor correctamente
//INT_MAX v; en el elemento máximo lo usamos para el centinela
{
v.clear(); //borrar el vector por si viene con elemento previos

for(int i= l; i <= r; i++){ //introduzco todos los elementos añadiendole el centinela
    v.push_back(at(i)); //voy introduciendo elemento a elemento
}
  v.push_back(INT_MAX); //le añado el centinela
}

void sorted_vector_t::create_vector_sentinel_min(int l, int r, vector<int>& v) //el centinela le da a la ultima posición de cada vector un tamaño mas grande que a cualquiera(infinito) para que cuando ordene los ordene de mayor a menor correctamente
//INT_MAX v; en el elemento máximo lo usamos para el centinela
{
v.clear(); //borrar el vector por si viene con elemento previos

for(int i= l; i <= r; i++){ //introduzco todos los elementos añadiendole el centinela
    v.push_back(at(i)); //voy introduciendo elemento a elemento
}
  v.push_back(INT_MIN); //le añado el centinela
}


void sorted_vector_t::merge_max(int l, int c, int d)
{
    vector<int> v1;
    vector<int> v2;

    create_vector_sentinel_max(l, c, v1);
    create_vector_sentinel_max(c + 1, d, v2);

    merge_max(v1, v2, l);
}

void sorted_vector_t::merge_min(int l, int c, int d)
{
    vector<int> v1;
    vector<int> v2;

    create_vector_sentinel_min(l, c, v1);
    create_vector_sentinel_min(c + 1, d, v2);

    merge_min(v1, v2, l);
}


void sorted_vector_t::merge_max(const vector<int>& v1, const vector<int>& v2, int l)
{
    const int sz = v1.size() + v2.size() - 2;

    int inx_1 = 0;
    int inx_2 = 0;

    for(int i = 0; i < sz; i++)

        if (v1[inx_1] < v2[inx_2]) {

            at(l + i) = v1[inx_1];
            inx_1 ++;
        } else {

            at(l + i) = v2[inx_2];
            inx_2 ++;
        }
}
void sorted_vector_t::merge_min(const vector<int>& v1, const vector<int>& v2, int l)
{
    const int sz = v1.size() + v2.size() - 2;

    int inx_1 = 0;
    int inx_2 = 0;

    for(int i = 0; i < sz; i++)

        if (v1[inx_1] > v2[inx_2]) {

            at(l + i) = v1[inx_1];
            inx_1 ++;
        } else {

            at(l + i) = v2[inx_2];
            inx_2 ++;
        }
}

}

ostream& operator<<(ostream& os, const CyA::sorted_vector_t& v)
{
    v.write(os);
    return os;
}
