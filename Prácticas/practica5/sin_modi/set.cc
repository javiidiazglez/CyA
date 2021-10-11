// UNIVERSIDAD DE LA LAGUNA
// GRADO EN INGENIERIA INFORMATICA
// AUTOR: José Javier Díaz González
// FECHA: 5-11-2020
// CORREO: alu0101128894@ull.edu.es
// ASIGNATURA: Computabilidad y Algoritmia
// PRACTICA: La clase Set
// Lenguaje: C++
// Contenido: Hay un archivo.txt con conjuntos y operaciones a hacer, que lo escribe en un fichero de salida
// Usamos el comando make para compilar -> g++ -std=c++14 -g -Wall -o set_calculator set_calculator.cc set.cc 
// Comando Ejecucion: ./set_calculator infile.txt outfile.txt

#include "set.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <cassert>
//#define kbitsLong 32
using namespace std;

//const int kBitsLong = 8 * sizeof(long); // 32 

// Constructor
Set::Set(const int KDigitos, const bool kVacio):
  numero_longs_(1),
  cantidad_cifras_(KDigitos), 
  conjunto_(NULL),
  si_vacio_(kVacio) {
    Build();
}

// Destructor
Set::~Set() {
  Destroy();
}

void Set::Build() {
  numero_longs_ = ceil(cantidad_cifras_ / (kBitsLong + 1)) + 1; // ceil = redondea hacia arriba
  //cout << "Ceil: " << ceil(cantidad_cifras_ / (kBitsLong)) << endl;
  //cout << "Numero de longs: " <<   numero_longs_ << endl;
  //cout << "Cantidad de cifras: " << cantidad_cifras_ << endl;
  conjunto_ = NULL;
  if (numero_longs_ != 0) {
    conjunto_ = new long[numero_longs_];
    assert(conjunto_ != NULL);
  }
  for (int i = 0; i < numero_longs_; i++) { // a 0
    conjunto_[i] = 0;
  }
  //cout << "Tamaño de long: " << sizeof(long) << endl;
}
void Set::Destroy() {
  if (conjunto_ != NULL) {
    delete[] conjunto_;
    conjunto_ = NULL;
  }
  numero_longs_ = 0;
  cantidad_cifras_ = 0;
}

void Set::Resize(const int numero_maximo, const bool si_es_vacio ) {
  Destroy();
  cantidad_cifras_ = numero_maximo;
  si_vacio_ = si_es_vacio;
  Build();
}

// GETTERS
int Set::get_cantidad_cifras() const {
  return cantidad_cifras_;
}

int Set::get_cantidad_longs() const { // Numero de longs, vector conjunto[]
  return numero_longs_;
}

int Set::get_size_conjunto() const {
  int size = sizeof(long) * numero_longs_;
  return size; 
}

long Set::get_vector(const int position) const { // El long que encuentre devuelve en la posicion que le pasa como parametro
  assert ((position >= 0) && (position < get_cantidad_longs()));
  return conjunto_[position];
}

bool Set::get_si_vacio() const { // Vacio
  return si_vacio_;
}

//SETTERS
void Set::set_cantidad_cifras(const int numero_fichero) {
  cantidad_cifras_ = numero_fichero;
}

//Insertar
void Set::Insertar(Set primer_valor, int numero_fichero) { 
  int iterar1 = ceil(numero_fichero / (kBitsLong)); // Que long estaría
  if(iterar1 > primer_valor.get_cantidad_longs()) { // mayor que el numero de longs que hay
    Resize(numero_fichero); // 32 > 40 -> resize
  } else {
    Resize (primer_valor.get_cantidad_cifras()); // <= 32
  }
  for(int iterar2 = 0; iterar2 < primer_valor.get_cantidad_longs(); iterar2++) {
    conjunto_[iterar2] = primer_valor.get_vector(iterar2);
  }
  int ajusto_numero = numero_fichero - iterar1 * kBitsLong; // añade el numero
  conjunto_[iterar1] = conjunto_[iterar1] | (1 << ajusto_numero); // con el OR
  if(numero_fichero > primer_valor.get_cantidad_cifras()) { //cambio el numero maximo en caso de ok
    cantidad_cifras_ = numero_fichero;
  }
}

void Set::Eliminar(int numero_fichero) {
  int iterar1 = ceil(numero_fichero / (kBitsLong)); // que long iria
  int ajusto_numero = numero_fichero - iterar1 * kBitsLong; // bit de la posicion

  conjunto_[iterar1] = ~conjunto_[iterar1]; // se niega todo
  for(int bit = 0; bit <= get_cantidad_cifras(); bit++) {
    int numero_fichero = conjunto_[iterar1] & (1 << bit); // trato de cambiar los bits de 0 a 1
    if(numero_fichero == 0) {
      if (bit != ajusto_numero) { // cuando lo elimino lo dejo, no lo toco
        conjunto_[iterar1] = conjunto_[iterar1] | (1 << bit);
      }
    }
  }
  int long_ceros = 0; // si solo tenia un elemento, pues se queda vacio
  for(int iterar2 = 0; iterar2 < get_cantidad_longs(); iterar2++) {
    if (conjunto_[iterar2] == 0) {
      long_ceros++;
    }
  }
  if(long_ceros == get_cantidad_longs()) {
    si_vacio_ = true;
  }
}

// Operaciones
void Set::Union(Set primer_valor, Set segundo_valor) {
  if(primer_valor.get_cantidad_cifras() > segundo_valor.get_cantidad_cifras()) {
    set_cantidad_cifras(primer_valor.get_cantidad_cifras());
    si_vacio_ = primer_valor.get_si_vacio();
  } else {
    set_cantidad_cifras(segundo_valor.get_cantidad_cifras());
    si_vacio_ = segundo_valor.get_si_vacio();
  }
  Resize(cantidad_cifras_, si_vacio_);

  for(int iterar1 = 0; iterar1 < get_cantidad_longs(); iterar1++) { // La union
    conjunto_[iterar1] = primer_valor.get_vector(iterar1) | segundo_valor.get_vector(iterar1);
  }
}

void Set::Interseccion(Set primer_valor, Set segundo_valor) {
  if(primer_valor.get_cantidad_cifras() < segundo_valor.get_cantidad_cifras()) {
    cantidad_cifras_ = primer_valor.get_cantidad_cifras();
    si_vacio_ = primer_valor.get_si_vacio();
  } else {
    cantidad_cifras_ = segundo_valor.get_cantidad_cifras();
    si_vacio_ = segundo_valor.get_si_vacio();
  }
  Resize(cantidad_cifras_, si_vacio_);

  for(int iterar1 = 0; iterar1 < get_cantidad_longs(); iterar1++) { // La interseccion
    conjunto_[iterar1] = primer_valor.get_vector(iterar1) & segundo_valor.get_vector(iterar1);
  }
}
void Set::ComplementoRelativo(Set primer_valor, Set segundo_valor) {

}

void Set::Complementacion(Set primer_valor) {
  if(primer_valor.get_si_vacio()) {
    Resize((kBitsLong), false);
    conjunto_[0] = 0;
    conjunto_[0] = ~conjunto_[0];
    set_cantidad_cifras(kBitsLong);
  } else {
    Resize(primer_valor.get_cantidad_cifras(), primer_valor.get_si_vacio());
    for(int iterar1 = 0; iterar1 < primer_valor.get_cantidad_longs(); iterar1++) {
      conjunto_[iterar1] = ~primer_valor.get_vector(iterar1);
    }
    int mayor_numero = 0; // mirar cual es el mayor numero maximo
    for(int iterar1 = 0; iterar1 < get_cantidad_longs(); ++iterar1) {
      for(int bit = 0; bit <= kBitsLong; ++bit) {
        int numero_fichero = conjunto_[iterar1] & (1 << bit);
        if (numero_fichero != 0) { // empieza a contar , mira si es !0
          int ajusto_numero = bit + iterar1 * (kBitsLong);
          if (ajusto_numero > mayor_numero) {
            mayor_numero = ajusto_numero;
            set_cantidad_cifras(ajusto_numero);
          }
        }
        if(bit == kBitsLong) {
          set_cantidad_cifras(kBitsLong * (iterar1 + 1));
        }
      }
    }
  }
}

// Read
void Set::Read (istream& is) {
  char caracter;
  int numero_fichero = 0;
  is.get(caracter);
  while (caracter != '}') {
    if ( (caracter != ',') && (caracter != '{')  && (caracter != ' ')) {
      int numero_anterior = caracter - '0';
      if ((numero_anterior >= 0) && (numero_anterior <= 9)) {
        numero_fichero = numero_fichero * 10 + numero_anterior;
      }
      char siguiente_caracter = is.peek();
      if ((siguiente_caracter == ',') || (siguiente_caracter == '}')) { // and
        //cout << "Numero: " << numero_fichero << endl; // Borrar esto luego
        int iterar1 = ceil(numero_fichero / (kBitsLong + 1));  // 33 / 32 + 1  = 1 iterar1     1 long = |32| 
          // Si el numero_fichero es 33, lo guarda en conjunto_[1]
          // Si es 32 -> conjunto_[0]
          // Si el numero_fichero >2 se ajustarlo para el nº de bits en un long (numero_fichero es el numero ajustado)
        numero_fichero = numero_fichero - iterar1 * kBitsLong; // 33 - 1 * 32 = 1 -> numero_fichero 1 , posicion long = 0
        //cout << "\tNumero ajustado: " << numero_fichero << endl;
        //cout << "\t\tConjunto antes de unir el numero_fichero: " << conjunto_[iterar1] << endl;
        conjunto_[iterar1] = conjunto_[iterar1] | (1 << numero_fichero);
        //cout << "\t\t\tNUMERO EN DECIMAL: " << conjunto_[iterar1] << endl;
        numero_fichero = 0; // guardo = borra (0)
      }
      if ((caracter == '{') && (siguiente_caracter == '}')) { // Para vacio
        conjunto_[0] = 0;
      } 
    } 
    is.get(caracter);
  }
}

void Set::Write (ostream& os) const {
  os << "{";
  int contador_numero = 0;
  if(si_vacio_ == true) {
    os << "}" << endl;
  } else {
    for (int iterar1 = 0; iterar1 < get_cantidad_longs(); ++iterar1) {
      for (int bit = 0; bit <= kBitsLong; ++bit) { // bit a bit si el numero está, 1 con la posicion 1
        int numero_fichero = conjunto_[iterar1] & (1 << bit);
        // Si el numero_fichero está en el segundo "intervalo" le suma 32
        if (numero_fichero != 0) { // si es !0 = hay un numero y lo ajustas
          int ajusto_numero = bit + iterar1 * kBitsLong; 
          //cout << "----- Write ----\n";
          //cout << "\tNumero: " << ajusto_numero << endl;
          //cout << "\titerador: " << iterar1 << endl;
          //cout << "\tkBitsLong: " << kBitsLong << endl;
          //cout << "\titerador * kBitsLong: " << iterar1 * kBitsLong << endl;
          //cout << "\tCantidad de longs: " << get_cantidad_longs() << endl;
          os << ajusto_numero;
          if ((contador_numero < get_cantidad_cifras()) && (get_cantidad_cifras() > 1)) { // solo 1 cifra {1,}
            //cout << "contador numero_fichero es: "<< contador_numero << endl;
            //cout << "cantidad cifras es: "<< get_cantidad_cifras() << endl;
            os << ", ";
          }   
        }
        contador_numero++;
      }
    }
    os << "}" << endl;
  }
}

// Sobrecarga de operadores
istream& operator>> (istream& is, Set& valor) {
  int posicion_primera = is.tellg(); // Se guarda la posicion en la que está (en el fichero)
  int numero_fichero = 0;
  int numero_maximo = 0;
  char caracter; 
  bool si_es_vacio = false;
  
  is.get(caracter); // Saco el primer caracter
  char siguiente_caracter = is.peek(); 
  //cout << "caracter: " << caracter << endl;
  //cout << "caracter siguiente: " << siguiente_caracter << endl;
  if ((caracter == '{') && (siguiente_caracter == '}')) { // Sabe que es un vacio, y le cambias el tamaño
    numero_maximo = 0;
    si_es_vacio = true;
    valor.Resize(numero_maximo, si_es_vacio); // cambias el tamaño , lo lees y devuelve -> 
    valor.Read(is);
    return is;
  } else {
    si_es_vacio = false;
    while (caracter != '}') {   // Se lee de { a } pero no ","
      if ((caracter != ',') && (caracter != '{') && (caracter != ' ')) { 
        int numero_anterior = caracter - '0';  // Transforma el caracter a un numero_fichero -> 33 - 30 = 3
        if ((numero_anterior >= 0) && (numero_anterior <= 9)) { // Compruebo por si acaso sea >= 0 y <= 9 (que no se me vaya) (solo numeros)
          numero_fichero = numero_fichero * 10 + numero_anterior;  // 6 4 -> 6 * 10 = 60 + 4 = (64)
        }
        numero_maximo = (numero_maximo < numero_fichero) ? numero_fichero : numero_maximo;  // Se guarda el numero_fichero mas grande (true) numero_fichero, (false) numero_maximo
      } else if (caracter == ',') { // si luego , pasa 
        numero_fichero = 0;
      }
      is.get(caracter); // Se saca el siguiente caracter
    }
  }
 
  if (numero_maximo > kBitsLong) { // Ya tengo la cantidad de longs que tendré que tener
    valor.Resize(numero_maximo, si_es_vacio); 
  } else {
    //valor.Resize(numero_maximo);
    valor.set_cantidad_cifras(numero_maximo);
  }
  
  is.seekg(posicion_primera, is.beg); // Vuelvo a la primera posicion en el fichero
  valor.Read(is); // Ahora todo perfecto su tamaño y meto dentro los numeros 
  return is;
}

ostream& operator<< (ostream& os, const Set& valor) {
  valor.Write(os);
  return os;
}
