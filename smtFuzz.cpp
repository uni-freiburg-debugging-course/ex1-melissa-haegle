// Copyright 2024
// Author: Melissa Hägle <melissa.haegle@gmail.com>

#include <fstream>
#include <iostream>
#include <random>

void generateTests(int numTests) {
  // generate tests of the form "(simplify (<op> <int1> <int2>))"
  // and write them to a file called "fuzzingTests.smt"
  std::ofstream file("fuzzingTests.smt");
  if (!file.is_open()) {
    std::cerr << "Failed to open file for writing." << std::endl;
    exit(1);
  }
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int32_t> dist(0, UINT32_MAX);
  for (int i = 0; i < numTests; i++) {
    int op = rand() % 3;
    std::string opStr;
    switch (op) {
      case 0:
        opStr = "+";
        break;
      case 1:
        opStr = "-";
        break;
      case 2:
        opStr = "*";
        break;
    }
    int32_t int1 = dist(gen);
    int32_t int2 = dist(gen);
    file << "(simplify (" << opStr << " " << int1 << " " << int2 << "))"
         << std::endl;
  }
  file.close();
}

int main(int argc, char **argv) {
  // check for the correct number of command line arguments
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <numTests>" << std::endl;
    exit(1);
  }
  generateTests(atoi(argv[1]));
  return 0;
}
