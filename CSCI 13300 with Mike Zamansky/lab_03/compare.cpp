/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: Lab 3C
Task: Given a dataset in TSV form and two inputted dates, return
the name of the basin that has a greater elevation or equal if
both are equal.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "catch.hpp"
#include "compare.h"

// To be changed when I get used to using the new form and after asking for
// some clarifications
using namespace std;

// Given a range of dates, returns a string containing which elevation(east or
// west) is higher on each day.
// *Expects parameter to be corrected beforehand if necessary and then given in
// correct format; does not check if parameter is in correct format; does not
// check if start date is after end date.
string compare(string date1, string date2){
  if(!isCorrectFormat(date1) || !isCorrectFormat(date2)){
    return "One of your dates is incorrect.";
  }

  // Open the file for reading
  ifstream fin("Current_Reservoir_Levels.tsv");
  if (fin.fail()){
    cerr << "File cannot be opened for reading." << endl;
    exit(1); // Exit if file cannot be opened.
  }

  // Variable to store and remove(?) header
  string header;
  getline(fin, header);
  // cout << "Header: " << header << endl;

  // Initialize variables for holding the values
  string date;
  double eastStorage;
  double eastElevation;
  double westStorage;
  double westElevation;

  // Tells whether a date falls within the range inputted by
  // the user
  bool checkDate = false;

  std::cout << endl;
  string retStr = "";

  // Read the values line by line and place each extracted value (separated
  // by a tab) into in its associated holder variable:
  while(fin >> date >> eastStorage >> eastElevation >> westStorage >> westElevation){
    if(date == date1){
      checkDate = true;
    }
    if(checkDate){
      if(eastElevation > westElevation){
        retStr += date;
        retStr += " East\n";
      } else if(westElevation > eastElevation){
        retStr += date;
        retStr += " West\n";
      } else {
        retStr += date;
        retStr += " Equal\n";      }
    }
    if(date == date2){
      checkDate = false;
    }
  }

  // Close file after reading
  fin.close();

  return retStr;
}

bool isCorrectFormat(string input){
  if(input.length() != 10
     || input.substr(6) != "2016"
     || input.substr(3,1).find_first_not_of("0123") != string::npos
     || input == "02/30/2016"
     || input == "02/31/2016"){
    return false;
  } else {
    return true;
  }
}
