#include "sorted_vector_t.hpp"

#include <climits>
#include <iomanip>

namespace CyA
{

void sorted_vector_t::merge_sort(void)
{
   //merge_sort(0, size() - 1); //por defecto el elemento incial si no se le dice nada es el de la posición 0 y el final el del tamaño -1
}

void sorted_vector_t::write(ostream& os) const
{
    const int sz = size();

    os << "<";
    for(int i = 0; i < sz; i++)
        os << setw(5) << at(i);
    os << " >";
}

void sorted_vector_t::merge_sort(int l, int r)
{
    if (l < r) { //calculo si el vector tiene longitud

        int c = (l + r) / 2;

        merge_sort(l, c);

        merge_sort(c + 1, r);

        merge(l, c, r);
    }
}

////////////////////////////////////////////////////////////////////////////
// FUSIÓN CON CENTINELA
////////////////////////////////////////////////////////////////////////////

void sorted_vector_t::create_vector_sentinel(int l, int r, vector<string>& v) //el centinela le da a la ultima posición de cada vector un tamaño mas grande que a cualquiera(infinito) para que cuando ordene los ordene de mayor a menor correctamente
//INT_MAX v; en el elemento máximo lo usamos para el centinela
{
v.clear(); //borrar el vector por si viene con elemento previos

for(int i= l; i <= r; i++){ //introduzco todos los elementos añadiendole el centinela
    v.push_back(at(i)); //voy introduciendo elemento a elemento
}
  v.push_back(to_string(INT_MAX)); //le añado el centinela
}

//
void sorted_vector_t::merge(int l, int c, int d)
{
    vector<string> v1;
    vector<string> v2;

    create_vector_sentinel(l, c, v1);
    create_vector_sentinel(c + 1, d, v2);

    merge(v1, v2, l);
}

// Método para dividir en 2 vectores mas pequeños
void sorted_vector_t::merge(const vector<string>& v1, const vector<string>& v2, int l)
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
// Iterativo
////////////////////////////////////////////////////////////////////////////

void sorted_vector_t::merge_sort_ite(void){
  int sz_;
  int izquierda;
  int derecha;
  int center;

  for(sz_ = 1; sz_ < size(); sz_ *= 2 ){
    for(izquierda = 0; izquierda + sz_ > size(); izquierda += sz_){
      derecha = izquierda + sz_ -1;
      center = izquierda + sz_/2;
      merge(izquierda, center, derecha);
    }
  }

}
}

ostream& operator<<(ostream& os, const CyA::sorted_vector_t& v)
{
    v.write(os);
    return os;
}
