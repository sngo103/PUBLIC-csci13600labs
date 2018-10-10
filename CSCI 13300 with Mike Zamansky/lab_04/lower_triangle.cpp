/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: Lab 4D
Task: Given a dataset in TSV form and two inputted dates, return
the name of the basin that has a greater elevation or equal if
both are equal.
*/

#include <iostream>
#include "catch.hpp"
#include "lower_triangle.h"

// To be changed when I get used to using the new form and after asking for
// some clarifications
using std::string;

// *Expects parameter to be corrected beforehand if necessary and then given in
// correct format; does not check if parameter is in correct format; does not
// check if start date is after end date.
string lower(int length){
  if(length <= 0){
    return "";
  }
  
  string retStr = "";

  int counter  = 0;
  string s = "";
  while (counter < length){
    s = "";
    for(int i = 0; i < length; i++){
      if(i <= counter){
        s += "*";
      } else {
        s += " ";
      }
    }
    retStr += s;
    retStr += "\n";
    counter += 1;
  }

  return retStr;
}
