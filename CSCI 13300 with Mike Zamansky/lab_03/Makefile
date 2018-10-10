CXXFLAGS=-std=c++11

main: main.o tests.o east-storage.o minmax.o compare.o reverse-order.o
		g++ -o main main.o tests.o east-storage.o minmax.o compare.o reverse-order.o

main.o: main.cpp
		g++ $(CXXFLAGS) -c main.cpp

tests.o: tests.cpp
		g++ $(CXXFLAGS) -c tests.cpp

east-storage.o: east-storage.cpp
		g++ $(CXXFLAGS) -c east-storage.cpp
minmax.o: minmax.cpp
		g++ $(CXXFLAGS) -c minmax.cpp
compare.o: compare.cpp
		g++ $(CXXFLAGS) -c compare.cpp
reverse-order.o: reverse-order.cpp
		g++ $(CXXFLAGS) -c reverse-order.cpp

runtests: tests.cpp
		g++ $(CXXFLAGS) -o tests tests.cpp
clean:
		rm -f main.o tests.o east-storage.o minmax.o compare.o reverse-order.o
