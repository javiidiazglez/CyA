// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica #03: Calculadora de lenguajes formales
// Autor: José Javier Díaz González
// Correo: alu0101128894@ull.es
// Fecha: 20/10/2022
// Archivo Language.cc
// Definición de la clase
// Historial de revisiones
// 20/10/2022 - Actualización (primera versión) del Language.cc
// 20/10/2022 - Finalización práctica 3

#include "../include/Language.h"

// Constructor lenguaje string
Language::Language(std::string lineLanguaje) {
  const char SPACE = ' ';
  const char KEY_OPEN = '{';
  const char KEY_CLOSE = '}';
  const char EMPTY_STRING = '&';
  const char COMMA = ',';
  const char EQUAL = '=';
  std::string aux_string_symb = "", aux_string_chain = "";
  // Iterando sobre la línea de la cuerda y buscando el primer espacio.
  for (int pos_1{0}; pos_1 < lineLanguaje.find_first_of(SPACE); ++pos_1) {
    id_ += (lineLanguaje[pos_1]);
  }
  // Iterando sobre la línea de la cadena y buscando el primer espacio.
  for (unsigned pos_1{lineLanguaje.find_first_of(KEY_OPEN) + 1}; pos_1 <= lineLanguaje.find_first_of(KEY_CLOSE); pos_1++) {
    if ((lineLanguaje[pos_1] == SPACE) || (lineLanguaje[pos_1] == KEY_CLOSE)) {
      if (aux_string_chain.size() != 0) {
        language_.insert(Chain(aux_string_chain, alphabet_language_));
        aux_string_chain = "";
      }
    } else if ((lineLanguaje[pos_1] != COMMA)) {
      aux_string_chain += lineLanguaje[pos_1];
      if ((lineLanguaje[pos_1] != EMPTY_STRING)) {
        aux_string_symb += lineLanguaje[pos_1];
        alphabet_language_.InsertSymbol(Symbol(aux_string_symb));
        aux_string_symb = "";
      }
    }
  }
}

// Sobrecarga del operador >> istream
std::istream& operator>>(std::istream& is, Language& language) {
  const char SPACE = ' ';
  const char KEY_OPEN = '{';
  const char KEY_CLOSE = '}';
  const char EMPTY_STRING = '&';
  const char COMMA = ',';
  const char EQUAL = '=';
  std::string input_string;
  std::string aux_string_symb = "", aux_string_chain = "";
  getline(is, input_string);

  // Iterando sobre la cadena y buscando la primera clave abierta y la primera clave cerrada.
  for (unsigned pos_1{input_string.find_first_of(KEY_OPEN) + 1}; pos_1 <= input_string.find_first_of(KEY_CLOSE); pos_1++) {
    if ((input_string[pos_1] == SPACE) || (input_string[pos_1] == KEY_CLOSE)) {
      if (aux_string_chain.size() != 0) {
        language.language_.insert(Chain(aux_string_chain, language.alphabet_language_));
        aux_string_chain = "";
      }
    } else if ((input_string[pos_1] != COMMA) && (input_string[pos_1] != EMPTY_STRING)) {
      aux_string_chain += input_string[pos_1];
      aux_string_symb += input_string[pos_1];
      language.alphabet_language_.InsertSymbol(Symbol(aux_string_symb));
      aux_string_symb = "";
    }
  }
  return is;
}

// Sobrecarga del operador >> ifstream
std::ifstream& operator>>(std::ifstream& is, Language& language) {
  const char SPACE = ' ';
  const char KEY_OPEN = '{';
  const char KEY_CLOSE = '}';
  const char EMPTY_STRING = '&';
  const char COMMA = ',';
  const char EQUAL = '=';
  std::string input_string;
  std::string aux_string_symb = "", aux_string_chain = "";
  getline(is, input_string);
  // Alfabeto y cadenas a la vez
  // Iterando sobre la cadena y buscando la primera clave abierta y la primera clave cerrada.
  for (unsigned pos_1{input_string.find_first_of(KEY_OPEN) + 1}; pos_1 <= input_string.find_first_of(KEY_CLOSE); pos_1++) {
    // Comprobando si el carácter es un espacio o un cierre de tecla.
    if ((input_string[pos_1] == SPACE) || (input_string[pos_1] == KEY_CLOSE)) {
      if (aux_string_chain.size() != 0) {
        // Insertar una cadena en un lenguaje.
        language.language_.insert(Chain(aux_string_chain, language.alphabet_language_));
        aux_string_chain = "";
      }
      // Comprobando si el carácter no es una coma o una cadena vacía.
    } else if ((input_string[pos_1] != COMMA) && (input_string[pos_1] != EMPTY_STRING)) {
      aux_string_chain += input_string[pos_1];
      aux_string_symb += input_string[pos_1];
      // Insertar un símbolo en el alfabeto del lenguaje.
      language.alphabet_language_.InsertSymbol(Symbol(aux_string_symb));
      aux_string_symb = "";
    }
  }
  return is;
}

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
  Alphabet input_alphabet = alphabet_language_;
  std::set<Chain> vector_chain = language_;

  for (const auto simbol : language_2.alphabet_language_.getAlphabet()) {
    input_alphabet.InsertSymbol(simbol);
  }
  // Union cadenas = Mismo lenguaje
  for (auto chain : language_) {
    for (auto chain2 : language_2.language_) {
      vector_chain.insert(chain2);  // Insertando chain2 en vector_chain.
    }
  }
  return Language(vector_chain, alphabet_language_);
}

// Intersección de dos lenguaje.
Language Language::Intersection(Language& language_2) {
  std::set<Chain> vector_chain;
  if ((alphabet_language_.getAlphabet().size() == 0 && language_.size() != 0) || (language_2.getAlphabetLanguage().getAlphabet().size() == 0 && language_2.language_.size() != 0) || alphabet_language_ == language_2.alphabet_language_) {
    for (const auto element : language_) {
      for (const auto element2 : language_2.language_) {
        if (element == element2) vector_chain.insert(element);
      }
    }
  } else {
    std::cerr << "Error: No se puede hacer la intersección de los lenguajes " << *this << " " << language_2 << " porque los alfabetos no son iguales" << std::endl;
    exit(EXIT_FAILURE);
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
  // quitar cadenas del lenguage 2 al lenguage1 que sean iguales
  //  al restar la cadena L1-L2 la cadena debe pertenecer a L1 pero no a L2
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
Language Language::InverseLanguage() {
  std::set<Chain> vector_chain;  // Llama al primer fichero.txt
  for (auto chain : language_) {
    vector_chain.insert(chain.InverseChain());
  }
  return Language(vector_chain, alphabet_language_);
}

// Potencia de un lenguaje
Language Language::PowerLanguage(int power) {
  std::set<Chain> vector_chain;  // Llama al primer fichero.txt
  Symbol empty("&");
  Chain emptyChain(empty);
  if (power == 0) {
    vector_chain.insert(emptyChain);  // Union
  }
  if (power == 1) {
    vector_chain = language_;  // El mismo
  }
  if (power > 1) {
    // Crear un nuevo lenguaje con el mismo lenguaje y alfabeto que el actual.
    Language firstLanguage(language_, alphabet_language_);
    // Concatenando la primer lenguaje con la potencia del lenguaje menos 1.
    Language auxLanguage = firstLanguage.Concatenation(PowerLanguage(power - 1));
    return auxLanguage.Difference(*this);
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
