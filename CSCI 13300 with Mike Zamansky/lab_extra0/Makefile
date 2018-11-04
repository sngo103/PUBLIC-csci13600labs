CXXFLAGS=-std=c++11

main: main.o caesar.o
		g++ -o main main.o caesar.o

main.o: main.cpp caesar.h
		g++ $(CXXFLAGS) -c main.cpp

caesar.o: caesar.cpp caesar.h
		g++ $(CXXFLAGS) -c caesar.cpp

clean:
		rm -f main.o caesar.o main
