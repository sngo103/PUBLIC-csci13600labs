/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: Lab 4G
Task: Given a width and height, returns a string representing a checkerboard of
3 by 3 squares (It should work even if the input dimensions are not a multiple
of three).
*/

#include <iostream>
#include <string>
#include "catch.hpp"
#include "checkerboard3.h"

// To be changed when I get used to using the new form and after asking for
// some clarifications
using std::string;
using std::find_first_of;
using std::replace;
using std::cout;
using std::endl;

// *Expects parameter to be corrected beforehand if necessary and then given in
// correct format; does not check if parameter is in correct format; does not
// check if start date is after end date.
string checkerboard3(int width, int height){
  if(width <= 0 || height <= 0){
    return "At least one of your parameters is invalid.";
  }

  string even = "";
  string odd = "";
  string retStr = "";

  int counter = 0;

  // Build even string:
  bool star = true;
  for(int i = 0;i < width; i++){
    if(star){
      even += "*";
      counter += 1;
      if(counter == 3){
        star = false;
        counter = 0;
      }
    } else {
      even += " ";
      counter += 1;
      if(counter == 3){
        star = true;
        counter = 0;
      }
    }
  }
  even += "\n";

  // Build odd string:
  odd = even;
  while(odd.find_first_of('*') != string::npos){
    odd.replace(odd.find_first_of('*'), 1, "x");
  }
  while(odd.find_first_of(' ') != string::npos){
    odd.replace(odd.find_first_of(' '), 1, "*");
  }
  while(odd.find_first_of('x') != string::npos){
    odd.replace(odd.find_first_of('x'), 1, " ");
  }

  // Build full checkboard - handling height
  counter = 0;
  star = true;
  for(int i = 0; i < height; i++){
    if(star){
      retStr += even;
      counter += 1;
      if(counter == 3){
        star = false;
        counter = 0;
      }
    } else {
      retStr += odd;
      counter += 1;
      if(counter == 3){
        star = true;
        counter = 0;
      }
    }
  }

  return retStr;
}
