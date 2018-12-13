CXXFLAGS=-std=c++11

main: main.o
	g++ -o main main.o
main.o: main.c my_vector.h
	g++ $(CXXFLAGS) -c main.c

tests: tests.o my_vector.h
	g++ -o tests tests.o
tests.o: tests.cpp
	g++ $(CXXFLAGS) -c tests.cpp

clean:
	rm -f main.o tests.o main tests
