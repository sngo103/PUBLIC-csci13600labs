/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: Lab 4B
Task: Given a width and a height, returns a string representing a rectangular
checkerboard of the requested size using asterisks and spaces
(alternating).
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "catch.hpp"
#include "checkerboard.h"

// To be changed when I get used to using the new form and after asking for
// some clarifications
using std::string;

// *Expects parameter to be corrected beforehand if necessary and then given in
// correct format; does not check if parameter is in correct format; does not
// check if start date is after end date.
string checkerboard(int width, int height){
  if(width < 0 || height <= 0){
    return "At least one of your parameters is invalid.";
  }

  string even = "";
  string odd = "";
  string retStr = "";

  // Build even string:
  bool star = true;
  for(int i = 0;i < width; i++){
    if(star){
      even += "*";
      star = false;
    } else {
      even += " ";
      star = true;
    }
  }
  even += "\n";

  // Build odd string:
  star = false;
  for(int i = 0;i < width; i++){
    if(star){
      odd += "*";
      star = false;
    } else {
      odd += " ";
      star = true;
    }
  }
  odd += "\n";

  for(int i = 0; i < height; i++){
    if((i % 2) == 0){
      retStr += even;
    } else {
      retStr += odd;
    }
  }

  return retStr;
}
