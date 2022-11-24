/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingenierıa Informatica
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 8: Gramáticas en Forma Normal de Chomsky
 *
 * @author José Javier Díaz González
 * Correo: alu0101128894@ull.edu.es
 *
 * @date 24/11/2022
 * @file chain.cc: clase cadena
 * @brief Contiene definicion de la clase chain.cc
 *
 * 24/11/2022 - Actualización (finalizacion) del chain.cc
 **/

#include "chain.h"

std::string Chain::getChain() const {
  std::string chain_string = "";
  for (int pos_i = 0; pos_i < chain_.size(); pos_i++) {
    chain_string += chain_[pos_i].getData();
  }
  return chain_string;
}

/** Constructor de la clase cadenan
 */
Chain::Chain(std::string& chain_string) {
  if (chain_string != "&") {
    for (unsigned pos_i{0}; pos_i < chain_string.length(); ++pos_i) {
      Symbol symbol(chain_string[pos_i]);
      chain_.push_back(symbol);
      alphabet_.insert(symbol);
    }
  }
}

/** Constructor de la clase cadena
 * @param chain_string cadena en un string
 * @param alphabet alphabet
 */
Chain::Chain(std::string& chain_string, Alphabet& alphabet) {
  if (chain_string != "&") {
    alphabet_ = alphabet;
    std::string aux;
    Symbol aux_symbol;
    for (unsigned pos_i{0}; pos_i < chain_string.length(); ++pos_i) {
      aux += chain_string[pos_i];
      aux_symbol.setData(aux);
      if (alphabet_.check(aux_symbol)) {
        chain_.push_back(aux_symbol);
        aux = "";
      }
    }
    if (aux.length() != 0) {
      std::cerr << "La cadena {" << chain_string << "} no pertence al alfabeto "
                << alphabet << "!" << std::endl;
      exit(EXIT_FAILURE);
    }
  }
}

/** Constructor de la clase cadena
 * @param chain vector de cadenas
 * @param alphabet	alphabet
 */
Chain::Chain(std::vector<Symbol>& chain, Alphabet& alphabet) {
  chain_ = chain;
  alphabet_ = alphabet;
  for (unsigned pos_i{0}; pos_i < chain.size(); ++pos_i) {
    if (!alphabet.check(chain[pos_i])) {
      std::cerr << "La cadena {" << *this << "} no pertence al alfabeto "
                << alphabet << "!" << std::endl;
      exit(EXIT_FAILURE);
    }
  }
}

/** Constructor de la clase cadena
 * @param symbol symbol
 */
Chain::Chain(Symbol& symbol) {
  chain_.push_back(symbol);
  alphabet_.insert(symbol);
}

/** Creación de un SubConjunto de cadenas.
 * @return size of the chain
 */
size_t Chain::size() const { return chain_.size(); }

/** Creación del inverso de la cadena
 * @return inverted chain
 */
Chain Chain::inverse() {
  std::string aux_string;
  for (int pos_i{chain_.size()}; pos_i > 0; --pos_i) {
    aux_string.append(chain_[pos_i - 1].getData());
  }
  Chain result(aux_string, alphabet_);
  return result;
}

/** Creación de prefijos de cadenas.
 */
std::set<Chain> Chain::SetPrefixs() {
  std::set<Chain> vector_chains;
  std::string aux_string;
  for (unsigned pos_i{0}; pos_i <= chain_.size(); ++pos_i) {
    if (pos_i == 0) {
      aux_string = "&";
    } else {
      for (unsigned pos_j{0}; pos_j < pos_i; pos_j++) {
        aux_string.append(chain_[pos_j].getData());
      }
    }
    Chain chains(aux_string, alphabet_);
    vector_chains.insert(chains);
    aux_string = "";
  }
  return vector_chains;
}

/** Creación de un Sufijo de cadenas.
 */
std::set<Chain> Chain::SetSuffixs() {
  std::set<Chain> vector_chains;
  std::string aux_string;
  for (unsigned pos_i{0}; pos_i <= chain_.size(); ++pos_i) {
    if (pos_i == 0) {
      aux_string = "&";
    } else {
      for (unsigned pos_j{chain_.size() - pos_i}; pos_j < chain_.size(); pos_j++) {
        aux_string.append(chain_[pos_j].getData());
      }
    }
    Chain chains(aux_string, alphabet_);
    vector_chains.insert(chains);
    aux_string = "";
  }
  return vector_chains;
}

/** Creación de un SubConjunto de cadenas.
 */
std::set<Chain> Chain::SetSubchains() {
  std::set<Chain> vector_chains;
  std::string aux_string;
  if (chain_.size() != 0) {
    for (int pos_i{0}; pos_i <= chain_.size(); ++pos_i) {
      if (pos_i == 0) {
        aux_string = "&";
      }
      for (int pos_j{0}; pos_j <= chain_.size(); ++pos_j) {
        if (pos_i > 0) {
          for (int k = pos_i - 1; k < pos_j; k++) {
            aux_string.append(chain_[k].getData());
          }
        }
        if (aux_string != "") {
          Chain chains(aux_string, alphabet_);
          vector_chains.insert(chains);
          aux_string = "";
        }
      }
    }
  } else if (chain_.size() == 0) {
    aux_string = "&";
    Chain chain(aux_string, alphabet_);
    vector_chains.insert(chain);
  }
  return vector_chains;
}

/** Una sobrecarga de operador para el operador << para imprimir la cadena
 */
std::ostream& operator<<(std::ostream& out, const Chain& chain) {
  if (chain.chain_.size() == 0) {
    out << "&";
  } else {
    for (const auto& symbol : chain.chain_) {
      out << symbol;
    }
  }
  return out;
}
/** Una sobrecarga de operador para el operador <<
 */
std::ofstream& operator<<(std::ofstream& out, const Chain& chain) {
  if (chain.chain_.size() == 0) {
    out << "&";
  } else {
    for (const auto& symbol : chain.chain_) {
      out << symbol;
    }
  }
  return out;
}

/** Una sobrecarga de operador para el operador <
 */
bool Chain::operator<(const Chain& chain) const {
  if (chain_.size() < chain.chain_.size())
    return true;
  else if (chain_.size() == chain.chain_.size()) {
    for (unsigned pos_i{0}; pos_i < chain.size(); ++pos_i) {
      if (chain_[pos_i].getData() < chain.chain_[pos_i].getData())
        return true;
      else if (chain_[pos_i].getData() > chain.chain_[pos_i].getData())
        return false;
    }
  }
  return false;
}

/** Una sobrecarga de operador para el operador ==
 * @return Verdaderas si son iguales, falso en otro caso
 */
bool Chain::operator==(const Chain& chain) const {
  bool result = true;
  if (size() == chain.size()) {
    for (int pos_i{0}; pos_i < chain_.size(); ++pos_i) {
      if (chain_[pos_i].getData() != chain.chain_[pos_i].getData()) result = false;
    }
  } else
    result = false;
  return result;
}

/** Una sobrecarga de operador para el operador !=.
 * @return Verdaderas si son iguales, falso en otro caso
 */
bool Chain::operator!=(const Chain& chain) const { return !(*this == chain); }

/** Función para concatenar la cadena
 * @param chain Cadena que va a ser concatenada
 * @return Cadenas concatenadas
 */
Chain Chain::concatenate(Chain& chain) {
  Alphabet alphabet;
  // Alfabeto 1
  for (const auto symbol : alphabet_.getAlphabet()) {
    alphabet.insert(symbol);
  }
  // Alfabeto 2
  for (const auto symbol : chain.alphabet_.getAlphabet()) {
    alphabet.insert(symbol);
  }
  std::vector<Symbol> chain_result = chain_;
  for (unsigned pos_i{0}; pos_i < chain.chain_.size(); ++pos_i) {
    chain_result.push_back(chain.chain_[pos_i]);
  }
  return Chain(chain_result, alphabet);
}

/** Función para concatenar la misma cadena
 * @param x Cantidad de veces que se va a elevar la cadena
 */
Chain Chain::pow(int x) {
  if (x == 0)
    return Chain();
  else {
    std::string aux = "";
    for (unsigned pos_i{0}; pos_i < x; ++pos_i) {
      for (unsigned pos_j{0}; pos_j < chain_.size(); ++pos_j) {
        aux += chain_[pos_j].getData();
      }
    }
    return Chain(aux, alphabet_);
  }
}

Symbol Chain::at(int pos) {
  return chain_[pos];
}

void Chain::substr(int pos, int length = 1) {
  std::vector<Symbol>::iterator it = chain_.begin() + pos;
  std::vector<Symbol>::iterator it2 = chain_.begin() + pos + length;
  chain_.erase(it, it2);
}

Chain Chain::operator+(const Chain& chain2) {
  std::string chain3_string;
  chain3_string = this->getChain();
  chain3_string += chain2.getChain();
  Chain chain3(chain3_string);
  return chain3;
}