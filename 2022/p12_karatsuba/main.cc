/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingenierıa Informatica
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 12: karatsuba
 *
 * @author José Javier Díaz González
 * Correo: alu0101128894@ull.edu.es
 *
 * @date 12/12/2022
 * @file main.cc: Programa cliente. Uso del algoritmo de Karatsuba
 * @brief Contiene definición de la clase
 *
 * 12/11/2023 - Actualización (finalizacion) del main.cc
 **/

#include <stdlib.h>

#include <chrono>
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std::chrono;

#include "BigInt.cc"

int contador = 0;

std::string appendZero(string str, int n);
std::string karatsuba(string x, string y);
std::string multiplyXY(string x, string y);
std::string addXY(string x, string y);
std::string subtractXY(string x, string y);
std::string removeZero(string str);
std::string multiply10(string str, int n);
int k2(string x, string y);
string k_cota(string x, string y, string cota);

string karatsuba(string x, string y) {
  if (x.length() == 1 && y.length() == 1) {
    return multiplyXY(x, y);
  }

  if (x.length() > y.length()) {
    y = appendZero(y, x.length() - y.length());
  } else {
    x = appendZero(x, y.length() - x.length());
  }
  if (x.length() % 2 != 0) {
    x = "0" + x;
    y = "0" + y;
  }

  string x_left, x_right, y_left, y_right, p1, p2, p3;
  int n = x.length();

  x_left = x.substr(0, x.length() / 2);
  x_right = x.substr(x.length() / 2);
  y_left = y.substr(0, y.length() / 2);
  y_right = y.substr(y.length() / 2);

  p1 = karatsuba(x_left, y_left);
  p2 = karatsuba(addXY(x_left, x_right), addXY(y_left, y_right));
  p3 = karatsuba(x_right, y_right);

  return addXY(addXY(multiply10(p1, n), multiply10(subtractXY(subtractXY(p2, p1), p3), n / 2)), p3);
}

int k2(string x, string y) {
  auto start = high_resolution_clock::now();
  if (x.length() > y.length()) {
    y = appendZero(y, x.length() - y.length());
  } else {
    x = appendZero(x, y.length() - x.length());
  }
  cout << "Resultado: " << removeZero(karatsuba(x, y)) << endl;

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout << "Duración algoritmo de Karatsuba: " << duration.count() << " microsegundos." << endl;  // Modificacion
  cout << "Número de llamadas a '*'= " << contador << endl;                                      // Modificacion
  return 0;
}

// COTA
string k_cota(string x, string y, string cota) {
  if (x.length() == 1 && y.length() == 1) {
    return multiplyXY(x, y);
  }

  if ((x.length() == 10) || (y.length() == 10)) {
    std::cout << "- SE HA LLEGADO AL VALOR DE LA COTA, SE VA REALIZAR LA MULTIPLICACIÓN DE BIGINT -" << std::endl;
    BigInt x2, y2, resultado;
    x2 = x;
    y2 = y;
    resultado = x2 * y2;
    std::cout << "El resultado es : " << resultado << std::endl;
    return 0;
  }
  if (x.length() > y.length()) {
    y = appendZero(y, x.length() - y.length());
  } else {
    x = appendZero(x, y.length() - x.length());
  }
  if (x.length() % 2 != 0) {
    x = "0" + x;
    y = "0" + y;
  }

  string x_left, x_right, y_left, y_right, p1, p2, p3;
  int n = x.length();

  x_left = x.substr(0, x.length() / 2);
  x_right = x.substr(x.length() / 2);
  y_left = y.substr(0, y.length() / 2);
  y_right = y.substr(y.length() / 2);

  p1 = karatsuba(x_left, y_left);
  p2 = karatsuba(addXY(x_left, x_right), addXY(y_left, y_right));
  p3 = karatsuba(x_right, y_right);

  return addXY(addXY(multiply10(p1, n), multiply10(subtractXY(subtractXY(p2, p1), p3), n / 2)), p3);
}

// APPENDZERO
std::string appendZero(string str, int n) {
  while (n > 0) {
    str = "0" + str;
    n--;
  }
  return str;
}
// MULTIPLYXY
std::string multiplyXY(string x, string y) {
  int product;
  product = ((int)x[0] - '0') * ((int)y[0] - '0');
  contador++;
  return to_string(product);
}

// ADDXY
std::string addXY(string x, string y) {
  if (x.length() > y.length()) {
    y = appendZero(y, x.length() - y.length());
  } else {
    x = appendZero(x, y.length() - x.length());
  }
  int carry = 0, sum;
  string result = "";
  for (int i = x.length() - 1; i >= 0; i--) {
    sum = ((int)x[i] - '0') + ((int)y[i] - '0') + carry;

    if (sum > 9) {
      result = to_string(sum % 10) + result;
      carry = sum / 10;
    } else {
      result = to_string(sum) + result;
      carry = 0;
    }
  }
  if (carry != 0) {
    result = to_string(carry) + result;
  }
  return result;
}

// subtractXY
std::string subtractXY(string x, string y) {
  if (x.length() > y.length()) {
    y = appendZero(y, x.length() - y.length());
  } else {
    x = appendZero(x, y.length() - x.length());
  }

  string result = "";
  int borrow = 0, a, b;
  for (int i = x.length() - 1; i >= 0; i--) {
    a = (int)x[i] - '0';
    b = (int)y[i] - '0';
    if (borrow == 1) {
      a = a - 1;
    }
    if (a >= b) {
      result = to_string(a - b) + result;
      borrow = 0;
    } else {
      a = a + 10;
      result = to_string(a - b) + result;
      borrow = 1;
    }
  }
  return removeZero(result);
}

// removeZero
std::string removeZero(string str) {
  reverse(str.begin(), str.end());
  for (int i = str.length() - 1; i >= 0; i--) {
    if (str[i] == '0') {
      str.pop_back();
    } else {
      break;
    }
  }
  if (str.empty()) {
    return "0";
  } else {
    reverse(str.begin(), str.end());
    return str;
  }
}

// multiply10
std::string multiply10(string str, int n) {
  while (n > 0) {
    str = str + "0";
    n--;
  }
  return str;
}

int main(int argc, char* argv[]) {
  std::ifstream file1, file2, file3;
  std::string prueba, prueba2, prueba3, opcion, opcion2, cota, n1, n2;
  int random;
  opcion = argv[1];
  opcion2 = argv[3];
  if (opcion == "-r") {
    BigInt bigint1, bigint2;
    std::string aux, random1, random2;
    random = std::stoi(argv[2]);
    srand(time(NULL));

    for (int i = 0; i < random; i++) {
      aux += std::to_string(std::rand() % 10);
    }
    random1 = aux;
    bigint1 = BigInt(aux);

    std::cout << "- Número random 1 = " << random1 << " ----" << endl;

    aux.clear();

    for (int i = 0; i < random; i++) {
      aux += std::to_string(std::rand() % 10);
    }
    random2 = aux;
    bigint2 = BigInt(aux);
    std::cout << "- Número random 2 = " << random2 << " ----" << endl;

    if (argc == 4) {
      opcion = argv[3];
      if (opcion == "-m") {
        auto start = high_resolution_clock::now();
        bigint1 = bigint1 * bigint2;
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        std::cout << "El resultado es: " << bigint1 << std::endl;
        auto duration2 = duration_cast<microseconds>(stop - start);
        cout << "Duración de la multiplicación de la clase BigInt: " << duration2.count() << " microsegundos." << endl;

        return 0;
      }
    }
    if (opcion2 == "-n") {
      std::cout << "- MODO COTA -" << std::endl;
      cota = argv[4];

      k_cota(random1, random2, cota);
    }
    k2(random1, random2); // devuelve la funcion
    return 0;
  }

  if (argc == 4) {
    file1.open(argv[1]);
    if (file1.fail()) {
      std::cout << "Fallo al abrir " << argv[1] << std::endl;
      return -1;
    }
    file1 >> prueba;

    file2.open(argv[2]);
    if (file2.fail()) {
      std::cout << "Fallo al abrir " << argv[2] << std::endl;
      return -1;
    }
    file2 >> prueba2;

    file3.open(argv[3]);
    if (file3.fail()) {
      std::cout << "Fallo al abrir " << argv[3] << std::endl;
      return -1;
    }
    file3 >> prueba3;
  }

  if (argc == 5) {
    opcion = argv[1];

    file1.open(argv[2]);
    if (file1.fail()) {
      std::cout << "Fallo al abrir " << argv[2] << std::endl;
      return -1;
    }
    file1 >> prueba;

    file2.open(argv[3]);
    if (file2.fail()) {
      std::cout << "Fallo al abrir " << argv[3] << std::endl;
      return -1;
    }
    file2 >> prueba2;

    file3.open(argv[4]);
    if (file3.fail()) {
      std::cout << "Fallo al abrir " << argv[4] << std::endl;
      return -1;
    }
    file3 >> prueba3;

    opcion = argv[1];

    if (opcion == "-m") {
      BigInt num1(prueba);
      BigInt num2(prueba2);
      BigInt mult(prueba3);
      BigInt result;
      auto start = high_resolution_clock::now();
      result = num1 * num2;
      auto stop = high_resolution_clock::now();
      auto duration = duration_cast<microseconds>(stop - start);

      if (result == mult) {
        std::cout << "El resultado es correcto: " << result << std::endl;
      }
      auto duration2 = duration_cast<microseconds>(stop - start);
      cout << "Duración de la multiplicación de la clase BigInt: " << duration2.count() << " microsegundos." << endl;
      return 0;
    }
  }

  BigInt num1(prueba);
  BigInt num2(prueba2);
  BigInt mult(prueba3);

  std::cout << "numero 1 (prueba): " << num1 << std::endl;
  std::cout << "numero 2 (prueba): " << num2 << std::endl;
  std::cout << "multipliacion (prueba): " << mult << std::endl;

  k2(prueba, prueba2); // ejemplo
}