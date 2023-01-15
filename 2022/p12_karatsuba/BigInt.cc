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
 * @file BigInt.cc: 
 *
 * 12/11/2023 - Actualización (finalizacion) del BigInt.cc
 **/

#include <bits/stdc++.h>

using namespace std;

class BigInt {
  string digits;

 public:
  // Constructores
  BigInt(unsigned long long n = 0);
  BigInt(string &);
  BigInt(const char *);
  BigInt(BigInt &);

  // Helper Functions
  friend void divide_by_2(BigInt &a);
  friend bool Null(const BigInt &);
  friend int Length(const BigInt &);
  int operator[](const int) const;

  // Direct assignment
  BigInt &operator=(const BigInt &);

  // Post/Pre - Incrementation
  BigInt &operator++();
  BigInt operator++(int temp);
  BigInt &operator--();
  BigInt operator--(int temp);

  // Addition and Subtraction
  friend BigInt &operator+=(BigInt &, const BigInt &);
  friend BigInt operator+(const BigInt &, const BigInt &);
  friend BigInt operator-(const BigInt &, const BigInt &);
  friend BigInt &operator-=(BigInt &, const BigInt &);

  // Comparison operators
  friend bool operator==(const BigInt &, const BigInt &);
  friend bool operator!=(const BigInt &, const BigInt &);

  friend bool operator>(const BigInt &, const BigInt &);
  friend bool operator>=(const BigInt &, const BigInt &);
  friend bool operator<(const BigInt &, const BigInt &);
  friend bool operator<=(const BigInt &, const BigInt &);

  // Multiplication and Division
  friend BigInt &operator*=(BigInt &, const BigInt &);
  friend BigInt operator*(const BigInt &, const BigInt &);
  friend BigInt &operator/=(BigInt &, const BigInt &);
  friend BigInt operator/(const BigInt &, const BigInt &);

  // Una función amiga que devuelve el resto de la división de dos BigInts.
  friend BigInt operator%(const BigInt &, const BigInt &);
  friend BigInt &operator%=(BigInt &, const BigInt &);

  // Cálculo de la potencia de un BigInt.
  friend BigInt &operator^=(BigInt &, const BigInt &);
  friend BigInt operator^(BigInt &, const BigInt &);

  // Cálculo de la raíz cuadrada de un BigInt.
  friend BigInt sqrt(BigInt &a);

  // Read and Write
  friend ostream &operator<<(ostream &, const BigInt &);
  friend istream &operator>>(istream &, BigInt &);

  // Others
  friend BigInt NthCatalan(int n);
  friend BigInt NthFibonacci(int n);
  friend BigInt Factorial(int n);
};

BigInt::BigInt(string &s) {
  digits = "";
  int n = s.size();
  for (int pos_i = n - 1; pos_i >= 0; pos_i--) {
    if (!isdigit(s[pos_i]))
      throw("ERROR");
    digits.push_back(s[pos_i] - '0');
  }
}
BigInt::BigInt(unsigned long long nr) {
  do {
    digits.push_back(nr % 10);
    nr /= 10;
  } while (nr);
}
BigInt::BigInt(const char *s) {
  digits = "";
  for (int pos_i = strlen(s) - 1; pos_i >= 0; pos_i--) {
    if (!isdigit(s[pos_i]))
      throw("ERROR");
    digits.push_back(s[pos_i] - '0');
  }
}
BigInt::BigInt(BigInt &a) {
  digits = a.digits;
}

bool Null(const BigInt &a) {
  if (a.digits.size() == 1 && a.digits[0] == 0)
    return true;
  return false;
}
int Length(const BigInt &a) {
  return a.digits.size();
}
int BigInt::operator[](const int index) const {
  if (digits.size() <= index || index < 0)
    throw("ERROR");
  return digits[index];
}
bool operator==(const BigInt &a, const BigInt &b) {
  return a.digits == b.digits;
}
bool operator!=(const BigInt &a, const BigInt &b) {
  return !(a == b);
}
bool operator<(const BigInt &a, const BigInt &b) {
  int n = Length(a), m = Length(b);
  if (n != m)
    return n < m;
  while (n--)
    if (a.digits[n] != b.digits[n])
      return a.digits[n] < b.digits[n];
  return false;
}
bool operator>(const BigInt &a, const BigInt &b) {
  return b < a;
}
bool operator>=(const BigInt &a, const BigInt &b) {
  return !(a < b);
}
bool operator<=(const BigInt &a, const BigInt &b) {
  return !(a > b);
}

BigInt &BigInt::operator=(const BigInt &a) {
  digits = a.digits;
  return *this;
}

BigInt &BigInt::operator++() {
  int pos_i, n = digits.size();
  for (pos_i = 0; pos_i < n && digits[pos_i] == 9; pos_i++)
    digits[pos_i] = 0;
  if (pos_i == n)
    digits.push_back(1);
  else
    digits[pos_i]++;
  return *this;
}
BigInt BigInt::operator++(int temp) {
  BigInt aux;
  aux = *this;
  ++(*this);
  return aux;
}

BigInt &BigInt::operator--() {
  if (digits[0] == 0 && digits.size() == 1)
    throw("UNDERFLOW");
  int pos_i, n = digits.size();
  for (pos_i = 0; digits[pos_i] == 0 && pos_i < n; pos_i++)
    digits[pos_i] = 9;
  digits[pos_i]--;
  if (n > 1 && digits[n - 1] == 0)
    digits.pop_back();
  return *this;
}
BigInt BigInt::operator--(int temp) {
  BigInt aux;
  aux = *this;
  --(*this);
  return aux;
}

BigInt &operator+=(BigInt &a, const BigInt &b) {
  int t = 0, s, pos_i;
  int n = Length(a), m = Length(b);
  if (m > n)
    a.digits.append(m - n, 0);
  n = Length(a);
  for (pos_i = 0; pos_i < n; pos_i++) {
    if (pos_i < m)
      s = (a.digits[pos_i] + b.digits[pos_i]) + t;
    else
      s = a.digits[pos_i] + t;
    t = s / 10;
    a.digits[pos_i] = (s % 10);
  }
  if (t)
    a.digits.push_back(t);
  return a;
}
BigInt operator+(const BigInt &a, const BigInt &b) {
  BigInt temp;
  temp = a;
  temp += b;
  return temp;
}

BigInt &operator-=(BigInt &a, const BigInt &b) {
  if (a < b)
    throw("UNDERFLOW");
  int n = Length(a), m = Length(b);
  int pos_i, t = 0, s;
  for (pos_i = 0; pos_i < n; pos_i++) {
    if (pos_i < m)
      s = a.digits[pos_i] - b.digits[pos_i] + t;
    else
      s = a.digits[pos_i] + t;
    if (s < 0)
      s += 10,
          t = -1;
    else
      t = 0;
    a.digits[pos_i] = s;
  }
  while (n > 1 && a.digits[n - 1] == 0)
    a.digits.pop_back(),
        n--;
  return a;
}
BigInt operator-(const BigInt &a, const BigInt &b) {
  BigInt temp;
  temp = a;
  temp -= b;
  return temp;
}

BigInt &operator*=(BigInt &a, const BigInt &b) {
  if (Null(a) || Null(b)) {
    a = BigInt();
    return a;
  }
  int n = a.digits.size(), m = b.digits.size();
  vector<int> v(n + m, 0);
  for (int pos_i = 0; pos_i < n; pos_i++)
    for (int pos_j = 0; pos_j < m; pos_j++) {
      v[pos_i + pos_j] += (a.digits[pos_i]) * (b.digits[pos_j]);
    }
  n += m;
  a.digits.resize(v.size());
  for (int s, pos_i = 0, t = 0; pos_i < n; pos_i++) {
    s = t + v[pos_i];
    v[pos_i] = s % 10;
    t = s / 10;
    a.digits[pos_i] = v[pos_i];
  }
  for (int pos_i = n - 1; pos_i >= 1 && !v[pos_i]; pos_i--)
    a.digits.pop_back();
  return a;
}
BigInt operator*(const BigInt &a, const BigInt &b) {
  BigInt temp;
  temp = a;
  temp *= b;
  return temp;
}

BigInt &operator/=(BigInt &a, const BigInt &b) {
  if (Null(b))
    throw("Arithmetic Error: Division By 0");
  if (a < b) {
    a = BigInt();
    return a;
  }
  if (a == b) {
    a = BigInt(1);
    return a;
  }
  int pos_i, lgcat = 0, cc;
  int n = Length(a), m = Length(b);
  vector<int> cat(n, 0);
  BigInt t;
  for (pos_i = n - 1; t * 10 + a.digits[pos_i] < b; pos_i--) {
    t *= 10;
    t += a.digits[pos_i];
  }
  for (; pos_i >= 0; pos_i--) {
    t = t * 10 + a.digits[pos_i];
    for (cc = 9; cc * b > t; cc--)
      ;
    t -= cc * b;
    cat[lgcat++] = cc;
  }
  a.digits.resize(cat.size());
  for (pos_i = 0; pos_i < lgcat; pos_i++)
    a.digits[pos_i] = cat[lgcat - pos_i - 1];
  a.digits.resize(lgcat);
  return a;
}
BigInt operator/(const BigInt &a, const BigInt &b) {
  BigInt temp;
  temp = a;
  temp /= b;
  return temp;
}

BigInt &operator%=(BigInt &a, const BigInt &b) {
  if (Null(b))
    throw("Arithmetic Error: Division By 0");
  if (a < b) {
    return a;
  }
  if (a == b) {
    a = BigInt();
    return a;
  }
  int pos_i, lgcat = 0, cc;
  int n = Length(a), m = Length(b);
  vector<int> cat(n, 0);
  BigInt t;
  for (pos_i = n - 1; t * 10 + a.digits[pos_i] < b; pos_i--) {
    t *= 10;
    t += a.digits[pos_i];
  }
  for (; pos_i >= 0; pos_i--) {
    t = t * 10 + a.digits[pos_i];
    for (cc = 9; cc * b > t; cc--)
      ;
    t -= cc * b;
    cat[lgcat++] = cc;
  }
  a = t;
  return a;
}
BigInt operator%(const BigInt &a, const BigInt &b) {
  BigInt temp;
  temp = a;
  temp %= b;
  return temp;
}

BigInt &operator^=(BigInt &a, const BigInt &b) {
  BigInt Exponent, Base(a);
  Exponent = b;
  a = 1;
  while (!Null(Exponent)) {
    if (Exponent[0] & 1)
      a *= Base;
    Base *= Base;
    divide_by_2(Exponent);
  }
  return a;
}
BigInt operator^(BigInt &a, BigInt &b) {
  BigInt temp(a);
  temp ^= b;
  return temp;
}

void divide_by_2(BigInt &a) {
  int add = 0;
  for (int pos_i = a.digits.size() - 1; pos_i >= 0; pos_i--) {
    int digit = (a.digits[pos_i] >> 1) + add;
    add = ((a.digits[pos_i] & 1) * 5);
    a.digits[pos_i] = digit;
  }
  while (a.digits.size() > 1 && !a.digits.back())
    a.digits.pop_back();
}

BigInt sqrt(BigInt &a) {
  BigInt left(1), right(a), v(1), mid, prod;
  divide_by_2(right);
  while (left <= right) {
    mid += left;
    mid += right;
    divide_by_2(mid);
    prod = (mid * mid);
    if (prod <= a) {
      v = mid;
      ++mid;
      left = mid;
    } else {
      --mid;
      right = mid;
    }
    mid = BigInt();
  }
  return v;
}

BigInt NthCatalan(int n) {
  BigInt a(1), b;
  for (int pos_i = 2; pos_i <= n; pos_i++)
    a *= pos_i;
  b = a;
  for (int pos_i = n + 1; pos_i <= 2 * n; pos_i++)
    b *= pos_i;
  a *= a;
  a *= (n + 1);
  b /= a;
  return b;
}

BigInt NthFibonacci(int n) {
  BigInt a(1), b(1), c;
  if (!n)
    return c;
  n--;
  while (n--) {
    c = a + b;
    b = a;
    a = c;
  }
  return b;
}

BigInt Factorial(int n) {
  BigInt f(1);
  for (int pos_i = 2; pos_i <= n; pos_i++)
    f *= pos_i;
  return f;
}

istream &operator>>(istream &in, BigInt &a) {
  string s;
  in >> s;
  int n = s.size();
  for (int pos_i = n - 1; pos_i >= 0; pos_i--) {
    if (!isdigit(s[pos_i]))
      throw("INVALID NUMBER");
    a.digits[n - pos_i - 1] = s[pos_i];
  }
  return in;
}

ostream &operator<<(ostream &out, const BigInt &a) {
  for (int pos_i = a.digits.size() - 1; pos_i >= 0; pos_i--)
    cout << (short)a.digits[pos_i];
  return cout;
}