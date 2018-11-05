CXXFLAGS=-std=c++11

main: main.o self_indent.o
		g++ -o main main.o self_indent.o

main.o: main.cpp self_indent.h
		g++ $(CXXFLAGS) -c main.cpp

self_indent.o: self_indent.cpp self_indent.h
		g++ $(CXXFLAGS) -c self_indent.cpp

clean:
		rm -f main.o self_indent.o main
