/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: Lab 9
Task: Write functions using pointers and dynamically-allocated memory
*/

#include <string>
#include <iostream>
#include <locale>
#include "3d-space.h"
#include <cmath>

using std::string;
using std::cout;
using std::endl;

double length(Coord3D *p){
  double l = sqrt(pow((*p).x, 2) + pow((*p).y, 2) + pow((*p).z, 2));
  return l;
}

Coord3D* fartherFromOrigin(Coord3D *p1, Coord3D *p2){
  // cout << length(p1) << "|" << length(p2) << endl;
  if(length(p1) >= length(p2)){
    return p1;
  } else {
    return p2;
  }
}

void move(Coord3D *ppos, Coord3D *pvel, double dt){
  (*ppos).x = (*ppos).x + (*pvel).x * dt;
  (*ppos).y = (*ppos).y + (*pvel).y * dt;
  (*ppos).z = (*ppos).z + (*pvel).z * dt;
}

Coord3D* createCoord3D(double x, double y, double z){
  Coord3D* retObject = new Coord3D;
  (*retObject).x = x;
  (*retObject).y = y;
  (*retObject).z = z;
 
  return retObject;
}

void deleteCoord3D(Coord3D *p){
  delete p;
  p = NULL;
}

