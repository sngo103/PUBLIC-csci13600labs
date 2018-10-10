/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: Lab 1C
Task: Given a year in the Gregorian calendar, returns whether it is a leap year
or a common year.
*/

#include <iostream>
#include <string>

using namespace std;

// Given a year, returns a string indicating whether it is a leap year or a
// common year.
string isLeapYear(int year){
    if ((year % 400) == 0){
      return "Leap year";
    } else if ((year % 100) == 0){
      return "Common year";
    } else if ((year % 4) == 0){
      return "Leap year";
    } else {
      return "Common year";
    }
}

// Main function for extracting input and running the program
int main() {
  // Initialize variables
  int givenYear;

  // Record input for year. If input is incorrect, ask again.
  cout << "Enter year: ";
  cin >> givenYear;
  while (cin.fail() || givenYear < 1752){
    // Year 1752 chosen because it is the first leap year in the Gregorian calendar
    cout << "*** Please enter a integer value greater than or equal to 1752 only." << endl;
    cout << "Enter year: ";
    cin.clear();
    cin.ignore(10000, '\n');
    cin >> givenYear;
  };

  // Print result
  cout << "The given year is a " << isLeapYear(givenYear) << endl;
  return 0;
}
