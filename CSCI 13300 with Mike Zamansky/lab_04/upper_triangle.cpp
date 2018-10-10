/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: Lab 4E
Task: Given a length, returns a string representing the top-right half of a
square, given the side length.
*/

#include <iostream>
#include "catch.hpp"
#include "upper_triangle.h"

// To be changed when I get used to using the new form and after asking for
// some clarifications
using std::string;

// *Expects parameter to be corrected beforehand if necessary and then given in
// correct format; does not check if parameter is in correct format; does not
// check if start date is after end date.
string upper(int length){
  if(length <= 0){
    return "";
  }

  string retStr = "";

  int counter = length;
  string s = "";
  while (counter > 0){
    s = "";
    for(int i = 0; i < length; i++){
      if(i < counter){
        s += "*";
      } else {
        s += " ";
      }
    }
    retStr += s;
    retStr += "\n";
    counter -= 1;
  }

  return retStr;
}
