// Copyright 2024
// Author: Melissa Hägle <melissa.haegle@gmail.com>

#include "./smt.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// ____________________________________________________________________________
void smtSolver::readFile(std::string filename) {
  std::ifstream file(filename.c_str());
  if (!file.is_open()) {
    std::cerr << "Error opening file: " << filename << std::endl;
    exit(1);
  }

  // initialize temporary string to store a line
  std::string line;

  while (true) {  // read lines until there are no more
    std::getline(file, line);
    if (file.eof()) {
      break;
    }

    // seperate line at whitespaces and brackets
    std::vector<std::string> tokens = lex(line);
  }
}

// ____________________________________________________________________________
std::vector<std::string> smtSolver::lex(std::string line) {
  // initialize string for storing the line seperated into tokens
  std::vector<std::string> tokens;

  std::string token;
  for (char c : line) {
    if (c == ' ' || c == '\t') {
      // if whitespace was found, we add the token to the list and move on to
      // the next one
      if (token != "") {
        tokens.push_back(token);
        token = "";
      }
    } else if (c == '(' || c == ')') {
      // if a bracket was found, we add it directly to the token list
      if (token != "") {
        tokens.push_back(token);
        token = "";
      }
      tokens.push_back(std::string(1, c));
    } else {
      // if the current character is not a whitespace or bracket, we rembember
      // it and move on to the next character
      token += c;
    }
  }
  // add last token
  if (token != "") {
    tokens.push_back(token);
  }
  return tokens;
}

// ____________________________________________________________________________
void smtSolver::evaluate() { std::cout << "evaluating..." << std::endl; }

// ____________________________________________________________________________
smtSolver::~smtSolver() {
  // todo: delete ast tree
}
