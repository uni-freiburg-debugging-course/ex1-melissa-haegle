[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/3MmVbb7f)
# Debugging 24/25 Exercise 1

Detailed instructions are in the exercise sheet. Following are your checkpoints:

- [x] Implement parser and evaluator
- [x] Implement a fuzzer
- [x] Generate *lots* of random instances with your fuzzer. Your evaluator and z3 must return the same result on generated instances
- [x] Provide detailed build instructions for your code so that we can evaluate it

## Build instructions
I included a **makefile**, so you should be able to compile, generate tests and run the tests using
```
make
```
There are several targets, which you can use:
- "make all": compiles everything and runs the fuzzer
- "make compile": compiles both the smt parser and the fuzzer
- "make fuzz": generates 1000 tests in "fuzzingTests.smt" and compares the results to z3
- "make clean": removes all temporary files, including binaries and tests (except the pre defined simp.smt2)

The binary of the smt **solver** is called "smtMain".
It can be called with:
```
./smtMain <smtFile>
```

The binary of the **fuzzer** is called "smtFuzz".
It can be called with:
```
./smtFuzz <numTests>
```
