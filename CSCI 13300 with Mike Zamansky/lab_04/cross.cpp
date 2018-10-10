/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: Lab 4C
Task: Given a size, returns a string representing a diagonal cross of
that dimension.
*/

#include <iostream>
#include <string>
#include "catch.hpp"
#include "cross.h"

using std::string;
using std::cout;
using std::endl;

// *Expects parameter to be corrected beforehand if necessary and then given in
// correct format; does not check if parameter is in correct format; does not
// check if start date is after end date.
string cross(int size){
  if(size <= 0){
    return "";
  }
  string retStr = "";

  // Create standard string with same number of spaces as size
  string standard = "";
  for (int i = 0; i < size; i++){
    standard += " ";
  }

  // Find the halfway point to start reversing the index
  int halfway;
  if(size % 2 == 0){
    halfway = size / 2;
  } else {
    halfway = (size / 2) + 1;
  }

  // Change the position of the stars for each line to their
  // correct locations and append to the return string
  int index1 = -1;
  int index2 = -1;
  string s;
  // Lines toward the center
  if(size % 2 == 0){
    // Lines away from the center
    for(int i = 0; i < halfway; i++){
      index1 = i;
      cout << "I1:" << index1 << "   ";
      index2 = size - 1 - i;
      cout << index2 << endl;
      s = standard;
      s.insert(index1, 1, '*');
      s.insert(index2, 1, '*');
      s += "\n";
      retStr += s;
    }
  } else {
    // Lines away from the center
    for(int i = 0; i <= halfway - 1; i++){
      if(i == halfway - 1){
        s = standard;
        s.insert(halfway - 1, 1, '*');
        s += "\n";
        retStr += s;
      } else {
        index1 = i;
        index2 = size - 1 - i;
        s = standard;
        s.insert(index1, 1, '*');
        s.insert(index2, 1, '*');
        s += "\n";
        retStr += s;
      }
    }
  }

  if(size % 2 == 0){
    // Lines away from the center
    for(int i = halfway - 1; i >= 0; i--){
      index1 = i;
      index2 = size - 1 - i;
      s = standard;
      s.insert(index1, 1, '*');
      s.insert(index2, 1, '*');
      s += "\n";
      retStr += s;
    }
  } else {
    // Lines away from the center
    for(int i = halfway - 2; i >= 0; i--){
      if(i == halfway){
        s = standard;
        s.insert(halfway, 1, '*');
        s += "\n";
        retStr += s;
      } else {
        index1 = i;
        index2 = size - 1 - i;
        s = standard;
        s.insert(index1, 1, '*');
        s.insert(index2, 1, '*');
        s += "\n";
        retStr += s;
      }
    }
  }// Lines away from the center

  // Return result
  return retStr;
}
