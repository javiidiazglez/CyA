#include "fibonacci_words.h"

fibonacci_words::fibonacci_words(std::string filename)
{

  std::string word;
  std::ifstream infile;

  infile.open(filename, ios::in);

  infile >> word;
  wordqueue_.push(word);
  firstword_ = word;

  infile >> word;
  secondword_ = word;

  while (!infile.eof())
  {
    wordqueue_.push(word);
    infile >> word;
  }

  infile.close();
}

std::string fibonacci_words::return_word(int index)
{
  if (index == 1)
    return firstword_;
  if (index == 2)
    return secondword_;
  return return_word(index - 2) + return_word(index - 1);
}

int fibonacci_words::return_index(std::string word)
{
  for (int index = 1; index <= 15; index++)
  {
    if (word.compare(return_word(index)) == 0)
      return index;
  }
  return -1;
}

void fibonacci_words::write(std::string filename)
{
  ofstream outfile;
  outfile.open(filename, ios::out);

  int order = 0;

  while (!wordqueue_.empty())
  {
    order++;
    outfile << wordqueue_.front();
    if (return_index(wordqueue_.front()) != -1)
      outfile << " is the Fibonacci word number " << return_index(wordqueue_.front()) << " and the " << order << " word in the file" << endl;
    else
      outfile << " is not a Fibonacci word and is the " << order << " word in the file" << endl;
    wordqueue_.pop();
  }

  outfile.close();
}

int main(int argc, const char **argv)
{

  std::string inputfile, outputfile, help = "--help";

  if (argc != 3)
  {
    std::cout << "Usage: " << argv[0] << " "
              << "InputFile.txt OutputFile.txt" << endl;
    if (argc == 2)
    {
      inputfile = argv[1];
      if (inputfile.compare(help) == 0)
      {
        std::cout << "Copies an input file with characters in another file and says if they are Fibonacci Words" << endl;
        return 0;
      }
    }
    return 0;
  }

  inputfile = argv[1];
  outputfile = argv[2];

  fibonacci_words fibwords(inputfile);
  fibwords.write(outputfile);
}
