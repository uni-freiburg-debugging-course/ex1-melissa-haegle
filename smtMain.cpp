// Copyright 2024
// Author: Melissa Hägle <melissa.haegle@gmail.com>

#include <iostream>

#include "./smt.h"

int main(int argc, char **argv) {
  smtSolver solver;
  // check for the correct number of command line arguments
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
    exit(1);
  }
  solver.readFile(argv[1]);
  return 0;
}
