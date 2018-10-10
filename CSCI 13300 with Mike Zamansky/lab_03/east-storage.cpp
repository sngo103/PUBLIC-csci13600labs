/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: Lab 3A
Task: Given a dataset in TSV form and an inputted date, return
the East basin storage for that date.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "catch.hpp"
#include "east-storage.h"

// To be changed when I get used to using the new form and after asking for
// some clarifications
using namespace std;

// Given the date, returns east basin Storage
// *Expects parameter to be corrected beforehand if necessary and then given in
// correct format; does not check if parameter is in correct format
double east_storage(string s){
  if( s.length() != 10
     || s.substr(6) != "2016"
     || s.substr(3,1).find_first_not_of("0123") != string::npos
     || s == "02/30/2016"
     || s == "02/31/2016"){
    return -1;
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

  // Read the values line by line and place each extracted value (separated
  // by a tab) into in its associated holder variable:
  while(fin >> date >> eastStorage >> eastElevation >> westStorage >> westElevation){
    if(date == s){
      cout << "East basin storage: " << eastStorage << " billion gallons" << endl << endl;
      return eastStorage;
    }
  }

  // Close file after reading
  fin.close();
  return -1;
}

/*
// Main function for executing code
int main() {

  // Initialize variable as a standard string for holding user input
  std::string inputDate;

  // Ask user for the number and store it in the variable. If input is
  // of the wrong type or incorrect format, ask again.
  cout << "Please enter date: ";
  cin >> inputDate;

  // Fails to catch errors if dates are semantically incorrect or if the order
  // of the characters aren't correct, such as "//12345678"
  while (cin.fail() || (inputDate.find_first_not_of("0123456789/") != string::npos)
                    || (inputDate.find(' ') != string::npos)
                    || (inputDate.length() != 10)){
    // cout << inputDate.length() << endl;
    cout << "Please enter a valid date..." << endl;
    cout << " - in 2016 the form of MM/DD/2016" << endl;
    cout << " - without any spaces ANYWHERE" << endl;
    cout << "Enter date: ";
    cin.clear();
    cin.ignore(10000, '\n');
    cin >> inputDate;
  };

  east_storage(inputDate);

  // cout << "What you inputted: " << inputDate << endl;

  return 0;
}
*/
