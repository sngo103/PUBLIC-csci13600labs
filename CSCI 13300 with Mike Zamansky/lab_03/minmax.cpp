/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: Lab 3B
Task: Given a dataset in TSV form, find the minimum and maximum
East basin storage for the entire year of 2016.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "catch.hpp"
#include "minmax.h"

// To be changed when I get used to using the new form and after asking for
// some clarifications
using namespace std;
using std::cout;
using std::string;

// Finds the minimum and maximum and stores it in the array; sets
// up the array
double getMinMax(string type){
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
  std::string date;
  double eastStorage;
  double eastElevation;
  double westStorage;
  double westElevation;

  double max = 0;
  double min = 100;

  // Read the values line by line and place each extracted value (separated
  // by a tab) into in its associated holder variable:
  while(fin >> date >> eastStorage >> eastElevation >> westStorage >> westElevation){
    if (eastStorage >= max){
      max = eastStorage;
    }
    if (eastStorage <= min){
      min = eastStorage;
    }
  }

  // Close file after reading
  fin.close();

  if(type == "min"){
    return min;
  }
  if(type == "max"){
    return max;
  }

  return 0;
}

// Final functions
double min_storage(){
  return getMinMax("min");
}

double max_storage(){
  return getMinMax("max");
}
