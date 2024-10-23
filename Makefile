CXX = g++ -g -O3 -Wall -pedantic -std=c++17 -Wno-deprecated-declarations
MAIN_BINARY = $(basename $(wildcard *Main.cpp))
FUZZ_BINARY = $(basename $(wildcard *Fuzz.cpp))
HEADERS = $(wildcard *.h)
OBJECTS = $(addsuffix .o, $(basename $(filter-out %Main.cpp %Fuzz.cpp, $(wildcard *.cpp))))

.PRECIOUS: %.o
.SUFFIXES:
.PHONY: all compile fuzz clean

all: compile fuzz

compile: $(MAIN_BINARY) $(FUZZ_BINARY)

fuzz: $(FUZZ_BINARY)
	./$(FUZZ_BINARY)
	z3 fuzzingTests.smt > res1 && ./smtMain fuzzingTests.smt > res2 && cmp res1 res2; echo $$?

clean:
	rm -f *.o
	rm -f *.smt
	rm -f res1
	rm -f res2
	rm -f $(MAIN_BINARY)
	rm -f $(FUZZ_BINARY)

%Main: %Main.o $(OBJECTS)
	$(CXX) -o $@ $^

%Fuzz: %Fuzz.o $(OBJECTS)
	$(CXX) -o $@ $^

%.o: %.cpp $(HEADERS)
	$(CXX) -c $<