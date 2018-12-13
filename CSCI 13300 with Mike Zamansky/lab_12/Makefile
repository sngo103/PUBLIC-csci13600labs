CXXFLAGS=-std=c++11

main: main.o social.o
	g++ -o main main.o social.o

main.o: main.c social.h
	g++ $(CXXFLAGS) -c main.c
social.o: social.cpp social.h
	g++ $(CXXFLAGS) -c social.cpp

tests: tests.o social.o
	g++ -o tests tests.o social.o
tests.o: tests.cpp
	g++ $(CXXFLAGS) -c tests.cpp

clean:
	rm -f main.o tests.o social.o main tests
