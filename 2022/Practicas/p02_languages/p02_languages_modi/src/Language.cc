// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica #02: Operaciones con lenguajes
// Autor: José Javier Díaz González
// Correo: alu0101128894@ull.es
// Fecha: 12/10/2022
// Archivo Language.cc
// Definición de la clase
// Historial de revisiones
// 12/10/2022 - Actualización (primera versión) del Language.cc
// 12/10/2022 - Finalización práctica 2

#include "Language.h"

// Insertar una cadena en un idioma
void Language::InsertChain(const Chain& chain) { language_.insert(chain); }

// Concatenación de dos lenguaje.
Language Language::Concatenation(Language language_2) {
  Alphabet input_alphabet = alphabet_language_;
  std::set<Chain> vector_chain;
  // Iterando sobre el alfabeto del lenguaje_2.
  for (const auto symb : language_2.alphabet_language_.getAlphabet()) {
    // Insertar un símbolo en el alfabeto del lenguaje.
    input_alphabet.InsertSymbol(symb);
  }
  // Iterando sobre el conjunto de cadenas en el lenguaje.
  for (auto chain : language_) {
    // Iterando sobre el conjunto de cadenas del lenguaje_2.
    for (auto chain2 : language_2.language_) {
      // Concatenando las cadenas del lenguaje.
      vector_chain.insert(chain.ConcatenationChain(chain2));
    }
  }
  return Language(vector_chain, input_alphabet);  // Devolviendo un nuevo lenguaje con las cadenas3 y el input_alphabet.
}

// Unión de dos lenguaje.
Language Language::Union(Language& language_2) {
  // Alphabet input_alphabet = alphabet_language_;
  std::set<Chain> vector_chain = language_;
  if (alphabet_language_ != language_2.alphabet_language_) {
    std::cerr << "Error: No se puede hacer la unión de los lenguajes " << *this << " " << language_2 << " porque los alfabetos no son iguales" << std::endl;
    exit(EXIT_FAILURE);
  }
  // Union cadenas = Mismo lenguaje
  for (auto chain : language_) {
    for (auto chain2 : language_2.language_) {
      if (chain == chain2) {
        vector_chain.insert(chain2);  // Insertando chain2 en vector_chain.
      }
    }
  }
  return Language(vector_chain, alphabet_language_);
}

// Intersección de dos lenguaje.
Language Language::Intersection(Language& language_2) {
  std::set<Chain> vector_chain;
  if (alphabet_language_ != language_2.alphabet_language_) {
    std::cerr << "Error: No se puede hacer la intersección de los lenguajes " << *this << " " << language_2 << " porque los alfabetos no son iguales" << std::endl;
    exit(EXIT_FAILURE);
  }
  // Union cadenas = Mismo lenguaje
  for (auto chain : language_) {
    for (auto chain2 : language_2.language_) {
      if (chain == chain2) {
        vector_chain.insert(chain2);  // Union
      }
    }
  }
  return Language(vector_chain, alphabet_language_);
}

// Diferencia de dos lenguaje.
Language Language::Difference(Language& language_2) {
  std::set<Chain> vector_chain = language_;
  if (alphabet_language_ != language_2.alphabet_language_) {
    std::cerr << "Error: No se puede hacer la intersección de los lenguajes " << *this << " " << language_2 << " porque los alfabetos no son iguales" << std::endl;
    exit(EXIT_FAILURE);
  }
  // A-B , pertenece en A no en B
  for (auto chain : language_) {
    for (auto chain2 : language_2.language_) {
      if (chain == chain2) {
        vector_chain.erase(chain);  // Eliminar el elemento del conjunto.
      }
    }
  }
  return Language(vector_chain, alphabet_language_);
}

// Inversa de un lenguaje
Language Language::Inverse() {
  std::set<Chain> vector_chain;  // Llama al primer fichero.txt
  for (auto chain : language_) {
    vector_chain.insert(chain.InverseChain());
  }
  return Language(vector_chain, alphabet_language_);
}

// Potencia de un lenguaje
Language Language::Power(int power) {
  std::set<Chain> vector_chain;  // Llama al primer fichero.txt
  Symbol empty("&");
  Chain empty_chain(empty);

  if (power == 0) {
    vector_chain.insert(empty_chain);  // Union
  }
  if (power == 1) {
    vector_chain = language_;  // El mismo
  }
  if (power > 1) {
    // Crear un nuevo lenguaje con el mismo lenguaje y alfabeto que el actual.
    Language firstLanguage(language_, alphabet_language_);
    // Concatenando la primer lenguaje con la potencia del lenguaje menos 1.
    Language auxLanguage = firstLanguage.Concatenation(Power(power - 1));
    return auxLanguage;
  }
  return Language(vector_chain, alphabet_language_);
}

// Una función que sobrecarga el operador << para imprimir el lenguaje. ostream
std::ostream& operator<<(std::ostream& os, const Language& language_1) {
  os << language_1.alphabet_language_;
  os << " { ";
  for (const auto chain : language_1.language_) {
    os << chain << " ";
  }
  os << "}";
  return os;
}

// Una función que sobrecarga el operador << para imprimir el lenguaje. ofstream
std::ofstream& operator<<(std::ofstream& os, const Language& language_1) {
  os << language_1.alphabet_language_;
  os << " { ";
  for (const auto chain : language_1.language_) {
    os << chain << " ";
  }
  os << "}";
  return os;
}

// Sobrecargar el operador >> para leer el lenguaje de una secuencia. istream
std::istream& operator>>(std::istream& is, Language& language_1) {
  const char SPACE = ' ';
  const char OPEN_KEY = '{';
  const char CLOSE_KEY = '}';
  std::string pos;
  std::string aux_str;
  getline(is, pos);  // Leyendo la línea del archivo y guardándola en la cadena pos.

  // Lectura del alfabeto de la lengua.
  for (unsigned i{2}; i < pos.find_first_of(CLOSE_KEY) + 1; ++i) {
    // Comprobando si el carácter es un espacio.
    if (pos[i] == SPACE) {
      // Insertar un símbolo en el alfabeto del idioma.
      language_1.alphabet_language_.InsertSymbol(Symbol(aux_str));
      aux_str = "";
      // Comprobando si el carácter no es una tecla cerrada o una tecla abierta.
    } else if ((pos[i] != CLOSE_KEY) && (pos[i] != OPEN_KEY)) {
      aux_str += pos[i];
    }
  }
  // Lectura de las cadenas del lenguaje.
  for (unsigned i{pos.find_last_of(OPEN_KEY) + 2}; i < pos.find_last_of(CLOSE_KEY); ++i) {
    // Comprobando si el carácter es un espacio.
    if (pos[i] == SPACE) {
      language_1.language_.insert(Chain(aux_str, language_1.alphabet_language_));
      aux_str = "";
    } else {
      // Agregar el carácter a la cadena.
      aux_str += pos[i];
    }
  }
  return is;  // Devolviendo el objeto istream.
}

// Sobrecargar el operador >> para leer el lenguaje de una secuencia. ifstream
std::ifstream& operator>>(std::ifstream& is, Language& language_1) {
  const char SPACE = ' ';
  const char OPEN_KEY = '{';
  const char CLOSE_KEY = '}';
  std::string pos;
  std::string aux_str;
  getline(is, pos);  // Leyendo la línea del archivo y guardándola en la cadena pos.

  // Lectura del alfabeto de la lengua.
  for (unsigned i{2}; i < pos.find_first_of(CLOSE_KEY) + 1; ++i) {
    // Comprobando si el carácter es un espacio.
    if (pos[i] == SPACE) {
      // Insertar un símbolo en el alfabeto del idioma.
      language_1.alphabet_language_.InsertSymbol(Symbol(aux_str));
      aux_str = "";
      // Comprobando si el carácter no es una tecla cerrada o una tecla abierta.
    } else if ((pos[i] != CLOSE_KEY) && (pos[i] != OPEN_KEY)) {
      aux_str += pos[i];
    }
  }
  // Lectura de las cadenas del lenguaje.
  for (unsigned i{pos.find_last_of(OPEN_KEY) + 2}; i < pos.find_last_of(CLOSE_KEY); ++i) {
    // Comprobando si el carácter es un espacio.
    if (pos[i] == SPACE) {
      language_1.language_.insert(Chain(aux_str, language_1.alphabet_language_));
      aux_str = "";
    } else {
      // Agregar el carácter a la cadena.
      aux_str += pos[i];
    }
  }
  return is;  // Devolviendo el objeto istream.
}