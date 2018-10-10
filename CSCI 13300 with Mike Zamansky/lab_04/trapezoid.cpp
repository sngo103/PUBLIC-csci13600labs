/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: Lab 4F
Task: Given a width and a height, returns as tring representing an upside-down
trapezoid of given width and height.
*/

#include <iostream>
#include "catch.hpp"
#include "trapezoid.h"

// To be changed when I get used to using the new form and after asking for
// some clarifications
using std::string;
using std::cout;
using std::endl;

// *Expects parameter to be corrected beforehand if necessary and then given in
// correct format; does not check if parameter is in correct format; does not
// check if start date is after end date.
string trapezoid(int width, int height){
  if(width <= 0 || height <= 0){
    return "Impossible shape!";
  } else if(width % 2 == 0){
    if (height > width / 2){
      return "Impossible shape!";
    }
  } else if(width % 2 == 1){
    if (height > ((width / 2) + 1)){
      return "Impossible shape!";
    }
  }

  string retStr = "";

  // Create standard string with same number of spaces as size
  string standard = "";
  for (int i = 0; i < width; i++){
    standard += " ";
  }

  // Find the halfway point to start reversing the index
  int halfway;
  if(width % 2 == 0){
    halfway = width / 2;
  } else {
    halfway = (width / 2) + 1;
  }

  // Change the position of the stars for each line to their
  // correct locations and append to the return string
  int index1 = -1;
  int index2 = -1;
  string s;

  for(int i = 0; i < height; i++){
    index1 = i;
    index2 = width - 1 - i;
    s = "";
    for(int i = 0; i < width; i++){
      if(i >= index1 && i <= index2){
        s += "*";
      } else {
        s += " ";
      }
    }
    s += "\n";
    retStr += s;
  }

  // Return result
  return retStr;
}
