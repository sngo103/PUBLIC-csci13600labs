/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: Lab 9
Task: Write functions using pointers and dynamically-allocated memory
*/

#pragma once

class Coord3D {
public:
    double x;
    double y;
    double z;
};

double length(Coord3D *p);
Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2);
void move(Coord3D *ppos, Coord3D *pvel, double dt);
Coord3D* createCoord3D(double x, double y, double z);
void deleteCoord3D(Coord3D *p);
