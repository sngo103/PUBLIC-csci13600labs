CXXFLAGS=-std=c++11

main: main.o math.o
		g++ -o main main.o math.o

main.o: main.cpp math.h
		g++ $(CXXFLAGS) -c main.cpp

math.o: math.cpp math.h
		g++ $(CXXFLAGS) -c math.cpp

tests: tests.o math.o
		g++ -o tests tests.o math.o

tests.o: tests.cpp
		g++ $(CXXFLAGS) -c tests.cpp

clean:
		rm -f main.o tests.o
