#liadi.haim@gmail.com
CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic -g

SRC_DEMO := Demo.cpp
SRC_TEST := test.cpp

BIN_DEMO := demo_bin
BIN_TEST := test_bin

.PHONY: all Main test valgrind clean

all: Main test

Main: $(BIN_DEMO)
	./$(BIN_DEMO)

test: $(BIN_TEST)
	./$(BIN_TEST)

valgrind: $(BIN_DEMO) $(BIN_TEST)
	valgrind --leak-check=full --track-origins=yes ./$(BIN_DEMO)
	valgrind --leak-check=full --track-origins=yes ./$(BIN_TEST)

clean:
	rm -f $(BIN_DEMO) $(BIN_TEST) *.o core

$(BIN_DEMO): $(SRC_DEMO) MyContainer.hpp doctest.hpp
	$(CXX) $(CXXFLAGS) -o $@ $<

$(BIN_TEST): $(SRC_TEST) MyContainer.hpp doctest.hpp
	$(CXX) $(CXXFLAGS) -o $@ $<
