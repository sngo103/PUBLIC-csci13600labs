CXXFLAGS=-std=c++11

main: main.o tests.o box.o checkerboard.o cross.o lower_triangle.o upper_triangle.o trapezoid.o checkerboard3.o
		g++ -o main main.o tests.o box.o checkerboard.o cross.o lower_triangle.o upper_triangle.o trapezoid.o checkerboard3.o

main.o: main.cpp
		g++ $(CXXFLAGS) -c main.cpp

tests.o: tests.cpp
		g++ $(CXXFLAGS) -c tests.cpp

box.o: box.cpp
		g++ $(CXXFLAGS) -c box.cpp
checkerboard.o: checkerboard.cpp
		g++ $(CXXFLAGS) -c checkerboard.cpp
cross.o: cross.cpp
		g++ $(CXXFLAGS) -c cross.cpp
lower_triangle.o: lower_triangle.cpp
		g++ $(CXXFLAGS) -c lower_triangle.cpp
upper_triangle.o: upper_triangle.cpp
		g++ $(CXXFLAGS) -c upper_triangle.cpp
trapezoid.o: trapezoid.cpp
		g++ $(CXXFLAGS) -c trapezoid.cpp
checkerboard3.o: checkerboard3.cpp
		g++ $(CXXFLAGS) -c checkerboard3.cpp

runtests: tests.cpp
		g++ $(CXXFLAGS) -o tests tests.cpp
clean:
		rm -f main.o tests.o box.o checkerboard.o cross.o lower_triangle.o upper_triangle.o trapezoid.o checkerboard3.o
