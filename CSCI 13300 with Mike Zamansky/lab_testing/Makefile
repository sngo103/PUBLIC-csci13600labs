CXXFLAGS=-std=c++11

main: main.o tests.o pig.o
		g++ -o main main.o tests.o pig.o
		
main.o: main.cpp
		g++ $(CXXFLAGS) -c main.cpp
tests.o: tests.cpp
		g++ $(CXXFLAGS) -c tests.cpp
pig.o: pig.cpp
		g++ $(CXXFLAGS) -c pig.cpp

clean:
		rm -f tests.o pig.o main.o
