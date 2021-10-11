#pragma once

#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

class fibonacci_words
{
public:
  /** Class that serves this program's utility.
     *  A file name is required for the constructor
     *  and it creates a string queue with the
     *  fibonacci words from said file. */
  ///@param filename name of the input file
  fibonacci_words(std::string filename);
  ~fibonacci_words(){};

  /// Returns the fibonacci word for a given index
  ///@param index of the fib. word
  std::string return_word(int index);

  /// Returns the index for a given fibonacci word.
  ///@param word the fibonacci word
  int return_index(std::string word);

  /** Writes the queue in an output file that is
    *  passed as an argument. It also writes if 
    *  the character sequences are fibonacci words
    *  or not. */
  ///@param filename name of the output file
  void write(std::string filename);

private:
  /// Queue that stores all character sequences.
  std::queue<std::string> wordqueue_;
  std::string firstword_;
  std::string secondword_;
};
