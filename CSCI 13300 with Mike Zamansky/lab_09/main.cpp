/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: Lab 9
Task: Write functions using pointers and dynamically-allocated memory
*/

#include "catch.hpp"
#include "3d-space.h"
#include "poem.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main(){
  cout << "=======================================================================================" << endl;
  cout << "Lab 9: Writing Functions Using Pointers and Dynamically-Allocated Memory" << endl;
  cout << "=======================================================================================" << endl;
  cout << "----- Testing [Task A]length function..." << endl;
  Coord3D pointP = {10, 20, 30};
  cout << "length(&pointP) should equal 37.4166 => " << length(&pointP) << endl << endl;

  cout << "----- Testing [Task B]fartherFromOrigin function..." << endl;
  pointP = {10, 20, 30};
  Coord3D pointQ = {-20, 21, -22};

  cout << "Address of P: " << &pointP << endl;
  cout << "Length to P: " << length(&pointP) << endl;
  cout << "Address of Q: " << &pointQ << endl;
  cout << "Length to Q: " << length(&pointQ) << endl << endl;

  Coord3D * ans = fartherFromOrigin(&pointP, &pointQ);
   
  cout << "ans = Point P => " << ans << endl;
  cout << "---------------------" << endl;

  pointP = {7, 21, 14};
  pointQ = {-3, 7, -2};

  cout << "Address of P: " << &pointP << endl;
  cout << "Length to P: " << length(&pointP) << endl;
  cout << "Address of Q: " << &pointQ << endl;
  cout << "Length to Q: " << length(&pointQ) << endl << endl;

  ans = fartherFromOrigin(&pointP, &pointQ);
   
  cout << "ans = Point P => " << ans << endl << endl;

  cout << "----- Testing [Task C]move function..." << endl;
  Coord3D pos = {0, 0, 100.0};
  Coord3D vel = {1, -5, 0.2};

  move(&pos, &vel, 2.0); // object pos gets changed
  cout << "X: 2 == " << pos.x << "|Y: -10 == " << pos.y << "|Z: 100.4 == " << pos.z << endl << endl;
  // prints: 2 -10 100.4

  cout << "----- Testing [Task D]poem.cpp..." << endl;
  cout << "*A loop will run poem.cpp 1000 times, allocating dynamic memory each time and then deleting it to show the importance of deleting allocated memory when it is no longer in use." << endl;
  cout << " - FUNCTION RUN: ";
  for(int i = 0; i < 1000; i++){
    cout << i << " ";
    string *p;
    p = createAPoemDynamically();
    delete p;
    p = NULL;
    // assume that the poem p is not needed at this point
  }
  cout << endl << endl;
  
  cout << "----- Testing [Task E]createCoord3D & deleteCoord3D function..." << endl;
  double x, y, z;
  cout << "Entering position (10, 20, 30) | velocity (5.5, -1.4, 7.77) | dt = 10 sec:" << endl;
  Coord3D *ppos = createCoord3D(10, 20, 30);
  Coord3D *pvel = createCoord3D(5.5, -1.4, 7.77);

  move(ppos, pvel, 10.0);

  cout << "     " << (*ppos).x << " " << (*ppos).y << " " << (*ppos).z << " should be 65 6 107.7" << endl << endl;
  cout << "Deleting dynamically-allocated memory..." << endl;
  deleteCoord3D(ppos); // release memory
  deleteCoord3D(pvel);
  cout << "...complete." << endl << endl;
  
  return 0;
}
