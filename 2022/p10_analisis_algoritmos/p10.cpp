#include <iostream>

using namespace std;

// poner aqui los ejemplos como funciones con el siguiente formato,
// donde 'X' es el numero de ejemplo
int ejemploX(const int n) {
int suma = 0;
for (int x = 1; x <= n; x++)
  for (int y = 1 ; y <= n - 1; y++)
    for (int z = y + 1 ; z <= n; z++)
      suma++;

  return suma;
}

int main() {  // pedir el valor de n
  int n;
  cout << "Introducir n: ";
  cin >> n;

  // invocar a cada ejemplo
  cout << "Ejemplo X: " << ejemploX(n) << endl;
  return 0;
}