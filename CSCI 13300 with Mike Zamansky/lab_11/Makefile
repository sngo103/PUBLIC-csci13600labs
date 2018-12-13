CXXFLAGS=-std=c++11

main: main.o recursion.o
	g++ -o main main.o recursion.o

main.o: main.c recursion.h
	g++ $(CXXFLAGS) -c main.c
recursion.o: recursion.cpp recursion.h
	g++ $(CXXFLAGS) -c recursion.cpp

tests: tests.o recursion.o
	g++ -o tests tests.o recursion.o
tests.o: tests.cpp
	g++ $(CXXFLAGS) -c tests.cpp

clean:
	rm -f main.o tests.o recursion.o main tests
