// Copyright 2024
// Author: Melissa Hägle <melissa.haegle@gmail.com>

#include <string>
#include <vector>

class smtSolver {
 private:
  // todo: add ast tree member
  std::vector<std::string> lex(std::string line);
  // todo: add parse function
 public:
  // destructor
  ~smtSolver();
  // parse a file and build the ast tree
  void readFile(std::string filename);
  // evaluate the given input
  void evaluate();
};
