/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: Lab 4A
Task: Given a width and a height, print out a rectangle of the
requested size.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "catch.hpp"
#include "box.h"

// To be changed when I get used to using the new form and after asking for
// some clarifications
using std::string;

// *Expects parameter to be corrected beforehand if necessary and then given in
// correct format; does not check if parameter is in correct format; does not
// check if start date is after end date.
string box(int width, int height){
  string retStr = "";
  if(width < 0 || height <= 0){
    return "At least one of your parameters is invalid.";
  }
  if(width == 0){
    for(int i = 0; i < height; i++){
      retStr += "\n";
    }
    return retStr;
  }
  for (int i = 0; i < height; i++){
    for (int i = 0; i < width; i++){
      retStr += "*";
    }
    retStr += "\n";
  }
  return retStr;
}
