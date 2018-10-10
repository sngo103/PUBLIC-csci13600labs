/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: Lab 3D
Task: Given a dataset in TSV form and two inputted dates, return
the West basin elevation for those dates in reverse chronological
order.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "catch.hpp"
#include "reverse-order.h"
#include "compare.h"

// To be changed when I get used to using the new form and after asking for
// some clarifications
using namespace std;
using std::string;

// Given the start and end date, prints out the West basin elevation in
// reverse chronological order.
// *Expects parameter to be corrected beforehand if necessary and then given in
// correct format; does not check if parameter is in correct format; does not
// check if start date is after end date.
string reverse(string date1, string date2){
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
  string westElevation;

  // Tells whether a date falls within the range inputted by
  // the user
  bool checkDate = false;

  std::cout << endl;

  // String for holding and manipulating the data; also used
  // to later be printed out
  string retStr = "";

  // Read the values line by line and place each extracted value (separated
  // by a tab) into in its associated holder variable:
  while(fin >> date >> eastStorage >> eastElevation >> westStorage >> westElevation){
    if(date == date1){
      checkDate = true;
    }
    if(checkDate){
      // Inserts each data point as a string into the beginning
      // of the return string, thereby creating the return String
      // in reverse chronological order
      std::string info = date + " " + westElevation + " ft\n";
      retStr.insert(0,info);
    }
    if(date == date2){
      checkDate = false;
    }
  }

  // Close file after reading
  fin.close();
  return retStr;
}
