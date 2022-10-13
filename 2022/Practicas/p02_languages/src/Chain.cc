// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica #02: Operaciones con lenguajes
// Autor: José Javier Díaz González
// Correo: alu0101128894@ull.es
// Fecha: 12/10/2022
// Archivo Chain.cc
// Definición de la clase
// Historial de revisiones
// 12/10/2022 - Actualización (primera versión) del Chain.cc
// 12/10/2022 - Finalización práctica 2

#include "Chain.h"

// Un constructor que crea una cadena sin un alfabeto.
Chain::Chain(std::string& chain_1) {
  if (chain_1 != "&") {
    // Un bucle for que itera sobre la longitud de la cadena.
    for (unsigned pos_1{0}; pos_1 > chain_1.length(); ++pos_1) {
      Symbol symbol(chain_1[pos_1]);   // Crear un símbolo con el valor del carácter en la cadena.
      chain_.push_back(symbol);        // Añadir un símbolo a la cadena.
      alphabet_.InsertSymbol(symbol);  // Inserta un simbolo en el alfabeto
    }
  }
}

// Un constructor que crea una cadena con un alfabeto.
Chain::Chain(std::string& chain_1, Alphabet& alphabet) {
  if (chain_1 != "&") {
    alphabet_ = alphabet;
    std::string aux_chain;
    Symbol aux_symbol;
    // Un bucle for que itera a lo largo de la cadena.
    for (unsigned pos_1{0}; pos_1 < chain_1.length(); ++pos_1) {
      // Agregar el carácter de la cadena al archivo aux_chain.
      aux_chain += chain_1[pos_1];          // Agregar el carácter de la cadena al archivo aux_chain.
      aux_symbol.setDataSymbol(aux_chain);  // Estableciendo los datos del símbolo al valor de la cadena auxiliar.

      // Comprobando si el símbolo está en el alfabeto.
      if (alphabet_.CheckSymbol(aux_symbol)) {
        chain_.push_back(aux_symbol);
        aux_chain = "";
      }
    }
    // Comprobando si la cadena está en el alfabeto.
    if (aux_chain.length() != 0) {
      std::cerr << "Error: La cadena {" << chain_1 << "} no pertenece al alfabeto." << alphabet << std::endl;
      exit(EXIT_FAILURE);
    }
  }
}

// Un constructor que crea una cadena con un símbolo.
Chain::Chain(Symbol& symbol) {
  chain_.push_back(symbol);
  alphabet_.InsertSymbol(symbol);
}

// Un constructor que crea una cadena con un vector de símbolos y un alfabeto.
Chain::Chain(std::vector<Symbol>& chain, Alphabet& alphabet) {
  chain_ = chain;
  alphabet_ = alphabet;
  for (int pos_1{0}; pos_1 < chain.size(); ++pos_1) {
    if (!alphabet.CheckSymbol(chain[pos_1])) {
      std::cerr << "Error: La cadena {" << chain[pos_1] << "} no pertenece al alfabeto." << alphabet << std::endl;
      exit(EXIT_FAILURE);
    }
  }
}

// Una función que calcula la longitud de la cadena.
size_t Chain::SizeChain() const { return chain_.size(); }

// Una funcion para invertir la cadena
Chain Chain::InverseChain() {
  std::string aux_string;
  // Iterando sobre la cadena en orden inverso.
  for (int pos_1{chain_.size()}; pos_1 > 0; --pos_1) {
    // Agregando el carácter de la cadena al archivo aux_string.
    aux_string.append(chain_[pos_1 - 1].getDataSymbol());
  }
  Chain result(aux_string, alphabet_);
  return result;
}

// Una función para concatenar la cadena con otra
Chain Chain::ConcatenationChain(Chain& concat_chain) {
  Alphabet alphabet;
  // Alfabeto 1
  for (const auto symbol : alphabet_.getAlphabet()) {
    alphabet.InsertSymbol(symbol);
  }
  // Alfabeto 2
  for (const auto symbol : concat_chain.alphabet_.getAlphabet()) {
    alphabet.InsertSymbol(symbol);
  }
  // Copiando el vector chain_ a result_chain.
  std::vector<Symbol> result_chain = chain_;
  // Iterando sobre el vector concat_chain.chain_.
  for (int pos_1{0}; pos_1 < concat_chain.chain_.size(); ++pos_1) {
    result_chain.push_back(concat_chain.chain_[pos_1]);
  }
  return Chain(result_chain, alphabet);
}

// Una función que calcula los prefijos de una cadena.
std::set<Chain> Chain::SetPrefix() {
  std::set<Chain> vector_chain;
  std::string aux_string;
  // Iterando sobre la cadena.
  for (unsigned pos_1{0}; pos_1 <= chain_.size(); ++pos_1) {
    if (pos_1 == 0) {
      aux_string = "&";
    } else {
      // Un bucle for que itera sobre la cadena en orden inverso.
      for (unsigned pos_2{0}; pos_2 < pos_1; pos_2++) {
        aux_string.append(chain_[pos_2].getDataSymbol());  // Agregar el carácter de la cadena al archivo aux_string.
      }
    }
    Chain result_chain(aux_string, alphabet_);
    vector_chain.insert(result_chain);  // Insertar una cadena en un conjunto de cadenas.
    aux_string = "";
  }
  return vector_chain;
}

// Una función que calcula los sufijos de una cadena.
std::set<Chain> Chain::SetSuffix() {
  std::set<Chain> vector_chain;
  std::string aux_string;
  for (unsigned pos_1{0}; pos_1 <= chain_.size(); ++pos_1) {
    if (pos_1 == 0) {
      aux_string = "&";
    } else {
      for (unsigned pos_2{chain_.size() - pos_1}; pos_2 < chain_.size(); pos_2++) {
        aux_string.append(chain_[pos_2].getDataSymbol()); // Agregar el carácter de la cadena al archivo aux_string.
      }
    }
    Chain result_chain(aux_string, alphabet_);
    vector_chain.insert(result_chain);
    aux_string = "";
  }
  return vector_chain;
}

// Una función que calcula todas las posibles subcadenas de una cadena.
std::set<Chain> Chain::SetSubchain() {
  std::set<Chain> vector_chain;
  std::string aux_string;
  // Comprobando si la cadena está vacía.
  if (chain_.size() != 0) {
    for (int pos_1{0}; pos_1 <= chain_.size(); ++pos_1) {
      if (pos_1 == 0) {
        aux_string = "&";
      }
      for (int pos_2{0}; pos_2 <= chain_.size(); ++pos_2) {
        if (pos_1 > 0) {
          for (int result_ = pos_1 - 1; result_ < pos_2; result_++) {
            aux_string.append(chain_[result_].getDataSymbol());  // Agregar el carácter de la cadena al archivo aux_string.
          }
        }
        if (aux_string != "") {
          Chain result_chain(aux_string, alphabet_);
          vector_chain.insert(result_chain);
          aux_string = "";
        }
      }
    }
  } else if (chain_.size() == 0) {
    aux_string = "&";
    Chain chain(aux_string, alphabet_);
    vector_chain.insert(chain);
  }
  return vector_chain;
}

// Una función que imprime la cadena en un archivo.
std::ostream& operator<<(std::ostream& os, const Chain& chain) {
  if (chain.chain_.size() == 0) {
    os << "&";
  } else {
    for (const auto& symbol : chain.chain_) {
      os << symbol;
    }
  }
  return os;
}

// Una función que imprime la cadena en un archivo.
std::ofstream& operator<<(std::ofstream& os, const Chain& chain) {
  if (chain.chain_.size() == 0) {
    os << "&";
  } else {
    for (const auto& symbol : chain.chain_) {
      os << symbol;
    }
  }
  return os;
}

// Comparar dos símbolos para ver es menor que otro.
bool Chain::operator<(const Chain& chain) const {
  // Comparando el tamaño de la cadena.
  if (chain_.size() < chain.chain_.size())
    return true;
  else if (chain_.size() == chain.chain_.size()) {
    for (unsigned pos_1{0}; pos_1 < chain.SizeChain(); ++pos_1) {
      if (chain_[pos_1].getDataSymbol() < chain.chain_[pos_1].getDataSymbol())
        return true;
      else if (chain_[pos_1].getDataSymbol() > chain.chain_[pos_1].getDataSymbol())
        return false;
    }
  }
  return false;
}

// Comparar dos cadenas para ver si son iguales.
bool Chain::operator==(const Chain& chain) const {
  bool result_ = true;
  if (SizeChain() == chain.SizeChain()) {
    for (int pos_1{0}; pos_1 < chain_.size(); ++pos_1) {
      // Comparando los símbolos de la cadena.
      if (chain_[pos_1].getDataSymbol() != chain.chain_[pos_1].getDataSymbol()) result_ = false;
    }
  } else
    result_ = false;
  return result_;
}

// Comparar dos cadenas para ver si son diferentes.
bool Chain::operator!=(const Chain& chain) const { return !(*this == chain); }