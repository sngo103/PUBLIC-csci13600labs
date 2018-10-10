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
#include <string.h>
#include <stdio.h>
#include <cmath>
#include <fstream>
#include <cstdlib>

// To be changed when I get used to using the new form and after asking for
// some clarifications
using namespace std;

// Given the date, returns east basin Storage
// *Expects parameter to be corrected beforehand if necessary and then given in
// correct format; does not check if parameter is in correct format; does not
// check if start date is after end date.
double getEastStor(string inputStart, string inputEnd){
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

  // Read the values line by line and place each extracted value (separated
  // by a tab) into in its associated holder variable:
  while(fin >> date >> eastStorage >> eastElevation >> westStorage >> westElevation){
    if(date == inputStart){
      checkDate = true;
    }
    if(checkDate){
      if(eastElevation > westElevation){
        std::cout << date << " East" << endl;
      } else if(westElevation > eastElevation){
        std::cout << date << " West" << endl;
      } else {
        std::cout << date << " Equal" << endl;
      }
    }
    if(date == inputEnd){
      checkDate = false;
    }
  }

  // Close file after reading
  fin.close();
}

// Main function for executing code
int main() {

  // Initialize variable as a standard string for holding user input
  std::string inputStart;
  std::string inputEnd;

  // Ask user for the number and store it in the variable. If input is
  // of the wrong type or incorrect format, ask again.
  cout << "Enter starting date: ";
  cin >> inputStart;

  // Fails to catch errors if dates are semantically incorrect or if the order
  // of the characters aren't correct, such as "//12345678"
  while (cin.fail() || (inputStart.find_first_not_of("0123456789/") != string::npos)
                    || (inputStart.find(' ') != string::npos)
                    || (inputStart.length() != 10)){
    // cout << inputStart.length() << endl;
    cout << "Please enter a valid date..." << endl;
    cout << " - in 2016 the form of MM/DD/2016" << endl;
    cout << " - without any spaces ANYWHERE" << endl;
    cout << "Enter starting date: ";
    cin.clear();
    cin.ignore(10000, '\n');
    cin >> inputStart;
  };

  // Ask user for the number and store it in the variable. If input is
  // of the wrong type or incorrect format, ask again.
  cout << "Enter ending date: ";
  cin >> inputEnd;

  // Fails to catch errors if dates are semantically incorrect or if the order
  // of the characters aren't correct, such as "//12345678"
  while (cin.fail() || (inputEnd.find_first_not_of("0123456789/") != string::npos)
                    || (inputEnd.find(' ') != string::npos)
                    || (inputEnd.length() != 10)){
    // cout << inputEnd.length() << endl;
    cout << "Please enter a valid date..." << endl;
    cout << " - in 2016 the form of MM/DD/2016" << endl;
    cout << " - without any spaces ANYWHERE" << endl;
    cout << "Enter ending date: ";
    cin.clear();
    cin.ignore(10000, '\n');
    cin >> inputEnd;
  };

  getEastStor(inputStart, inputEnd);

  // cout << "What you inputted: " << inputDate << endl;

  return 0;
}
