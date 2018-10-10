/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: Lab 1D
Task: Given a month and a year in the Gregorian calendar, returns the number of
days in the month.
*/

#include <iostream>
#include <string>

using namespace std;

// Given a year, returns a boolean indicating whether or not it is a leap year.
bool isLeapYear(int year){
    if ((year % 400) == 0){
      return true;
    } else if ((year % 100) == 0){
      return false;
    } else if ((year % 4) == 0){
      return true;
    } else {
      return false;
    }
}

// Given a boolean, returns a string description.
string leapToString(bool retBool){
    if (retBool){
      return "Leap year";
    } else {
      return "Common year";
    }
}

// Given a month and a year, returns the number of days in that month.
int days(int month, int year){
  // If input is out of range, return -1 to signal incorrect input
  if(month < 1 || month > 12){
    return -1;
  } else if(month <= 7){ // Months 1-7
    if (month == 2){
      if(isLeapYear(year)){
        return 29;
      } else {
        return 28;
      }
    } else {
      if ((month % 2) == 1){
        return 31;
      } else {
        return 30;
      }
    }
  } else { // Months 8-12
    // cout << "Month before: " << month << endl;
    month += 1;
    // cout << "Month after: " << month << endl;
    if ((month % 2) == 1){
      return 31;
    } else {
      return 30;
    }
  }
}

// Main function for extracting input and running code
int main() {
  // Initialize variables
  int givenMonth;
  int givenYear;

  // Record year in variable. If input incorrect, ask again.
  cout << "Enter year: ";
  cin >> givenYear;
  // Year 1752 chosen because it is the first leap year in the Gregorian calendar
  while (cin.fail() || givenYear < 1752){
    cout << "*** Please enter a integer value greater than or equal to 1752 only." << endl;
    cout << "Enter year: ";
    cin.clear();
    cin.ignore(10000, '\n');
    cin >> givenYear;
  };

  // Record month in variable. If input incorrect, ask again.
  cout << "Enter month: ";
  cin >> givenMonth;
  while (cin.fail() || givenMonth < 1 || givenMonth > 12){
    cout << "*** Please enter a integer value between 1 and 12, inclusive, only." << endl;
    cout << "Enter month: ";
    cin.clear();
    cin.ignore(10000, '\n');
    cin >> givenMonth;
  };

  // Print result
  cout << "The number of days in the month " << givenMonth << " of the year " << givenYear << " is " << days(givenMonth,givenYear) << " days." << endl;
  return 0;
}
