/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: Lab 9
Task: Write functions using pointers and dynamically-allocated memory
*/

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "3d-space.h"
#include "poem.h"

TEST_CASE("Testing double length(Coord3D *p) AND Coord3D* createCoord3D(double x, double y, double z)..."){
  SECTION("NORMAL CASES"){
    CHECK( length(createCoord3D(1, 2, 4)) == 4.58257569495584);
    CHECK( length(createCoord3D(7, 12, 4)) == 14.45683229480096);
    CHECK( length(createCoord3D(-1, 2, 24)) == 24.1039415863879);
    CHECK( length(createCoord3D(1, -2, -11)) == 11.224972160321824);
    CHECK( length(createCoord3D(-12, -3, -5)) == 13.341664064126334);
    CHECK( length(createCoord3D(-12, -3, 5)) == 13.341664064126334);
    CHECK( length(createCoord3D(2, -3, 15)) == 15.427248620541512);
    CHECK( length(createCoord3D(2.4, -6.7, 15)) == 16.602710622064098);
    CHECK( length(createCoord3D(0, 0, -5)) == 5);
    CHECK( length(createCoord3D(0, 0, 0)) == 0);
  }
}

TEST_CASE("Testing Coord3D* fartherFromOrigin(Coord3D *p1, Coord3D *p2) AND Coord3D* createCoord3D(double x, double y, double z)..."){
  SECTION("NORMAL CASES"){
    Coord3D* x = createCoord3D(7, 12, 4);
    CHECK( fartherFromOrigin(createCoord3D(1, 2, 4), x) == x);
    x = createCoord3D(-1, 2, 24);
    CHECK( fartherFromOrigin(x, createCoord3D(1, -2, -11)) == x);
    x = createCoord3D(1,1,1);
    Coord3D* y = createCoord3D(-1, -1, -1);
    CHECK( fartherFromOrigin(x, y) == x);
    x = createCoord3D(-12, -3, -5);
    CHECK( fartherFromOrigin(x, createCoord3D(-12, -3, 5)) == x);
    x = createCoord3D(0, 0, -5);
    CHECK( fartherFromOrigin(x, x) == x);
    x = createCoord3D(2.4, -6.7, 15);
    CHECK( fartherFromOrigin(x, createCoord3D(2, -3, 15)) == x);
  }
}
