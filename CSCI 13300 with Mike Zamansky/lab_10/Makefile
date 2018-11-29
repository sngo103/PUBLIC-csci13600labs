CXXFLAGS=-std=c++11

main: main.o timeFunctions.o movieFunctions.o
	g++ -o main main.o timeFunctions.o movieFunctions.o

main.o: main.c timeFunctions.h movieFunctions.h
	g++ $(CXXFLAGS) -c main.c
timeFunctions.o: timeFunctions.cpp timeFunctions.h
	g++ $(CXXFLAGS) -c timeFunctions.cpp
movieFunctions.o: movieFunctions.cpp movieFunctions.h timeFunctions.h
	g++ $(CXXFLAGS) -c movieFunctions.cpp

tests: tests.o timeFunctions.o movieFunctions.o
	g++ -o tests tests.o timeFunctions.o movieFunctions.o
tests.o: tests.cpp
	g++ $(CXXFLAGS) -c tests.cpp

clean:
	rm -f main.o tests.o timeFunctions.o movieFunctions.o main tests
