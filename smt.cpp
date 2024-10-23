// Copyright 2024
// Author: Melissa Hägle <melissa.haegle@gmail.com>

#include "./smt.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// ____________________________________________________________________________
void smtSolver::readFile(std::string filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        exit(1);
    }

    std::cout << "reading file: " << filename << std::endl;
}

// ____________________________________________________________________________
void smtSolver::evaluate()
{
    std::cout << "evaluating..." << std::endl;
}

// ____________________________________________________________________________
smtSolver::~smtSolver()
{
    // todo: delete ast tree
}
