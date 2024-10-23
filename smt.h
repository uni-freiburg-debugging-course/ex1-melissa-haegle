// Copyright 2024
// Author: Melissa Hägle <melissa.haegle@gmail.com>

#include <string>
#include <vector>

class smtSolver {
 private:
  // todo: add ast tree member
  std::vector<std::string> lex(std::string line);
  // evaluate one line
  void evaluate(std::vector<std::string> tokens);

 public:
  // destructor
  ~smtSolver();
  // parse a file and build the ast tree
  void readFile(std::string filename);
};
