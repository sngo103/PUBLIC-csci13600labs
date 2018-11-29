CXXFLAGS=-std=c++11

main: main.o 3d-space.o poem.o
	g++ -o main main.o 3d-space.o poem.o

main.o: main.cpp 3d-space.h poem.h
	g++ $(CXXFLAGS) -c main.cpp
3d-space.o: 3d-space.cpp 3d-space.h
	g++ $(CXXFLAGS) -c 3d-space.cpp
poem.o: poem.cpp poem.h
	g++ $(CXXFLAGS) -c poem.cpp

tests: tests.o 3d-space.o poem.o
	g++ -o tests tests.o 3d-space.o poem.o
tests.o: tests.cpp
	g++ $(CXXFLAGS) -c tests.cpp

clean:
	rm -f main.o tests.o 3d-space.o poem.o main tests
