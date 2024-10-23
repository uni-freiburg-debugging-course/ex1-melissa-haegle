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
    if (tokens.size() == 0) {  // skip empty lines
      continue;
    }
    // evaluate the line
    evaluate(tokens);
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
void smtSolver::evaluate(std::vector<std::string> tokens) {
  // if the form is not as described in the exercise, we throw an error
  if (tokens.size() != 8 || tokens[0] != "(" || tokens[1] != "simplify" ||
      tokens[2] != "(" || tokens[6] != ")" || tokens[7] != ")") {
    std::cerr << "Error: Invalid syntax" << std::endl;
    exit(1);
  }
  std::string op = tokens[3];
  int64_t num1 = atoi(tokens[4].c_str());
  int64_t num2 = atoi(tokens[5].c_str());
  int64_t res;
  if (op == "+") {
    res = num1 + num2;
  } else if (op == "-") {
    res = num1 - num2;
  } else if (op == "*") {
    res = num1 * num2;
  } else {
    std::cerr << "Error: unknown operator" << op << std::endl;
    exit(1);
  }
  if (res < 0) {
    std::cout << "(- " << abs(res) << ")" << std::endl;
  } else {
    std::cout << res << std::endl;
  }
}

// ____________________________________________________________________________
smtSolver::~smtSolver() {
  // todo: delete ast tree
}
