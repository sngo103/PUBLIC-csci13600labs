CXXFLAGS=-std=c++11

main: main.o crypto.o
		g++ -o main main.o crypto.o

main.o: main.cpp crypto.h
		g++ $(CXXFLAGS) -c main.cpp

crypto.o: crypto.cpp crypto.h
		g++ $(CXXFLAGS) -c crypto.cpp

tests: tests.o crypto.o
		g++ -o tests tests.o crypto.o

tests.o: tests.cpp
		g++ $(CXXFLAGS) -c tests.cpp

clean:
		rm -f main.o tests.o crypto.o main tests
