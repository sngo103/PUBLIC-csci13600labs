/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: Lab 2B
Task: Given an upper bound and a lower bound, print all the numbers from the lower
bound to the upper bound, excluding the upper bound.
*/

#include <iostream>
#include <string>

using namespace std;

// Main function extracts input numbers from user
int main() {
  // Initialize variables
  int upper;
  int lower;

  // Record lower bound. If input is incorrect, ask again.
  cout << "Please enter L: ";
  cin >> lower;
  while (cin.fail() || lower != lower){
    cout << "***Please enter a numerical integer only." << endl;
    cout << "Please enter L: ";
    cin.clear();
    cin.ignore(10000, '\n');
    cin >> lower;
  };
  // Record upper bound. If input is incorrect, ask again.
  cout << "Please enter U: ";
  cin >> upper;
  while (cin.fail() || upper != upper){
    cout << "***Please enter a numerical integer only." << endl;
    cout << "Please enter U: ";
    cin.clear();
    cin.ignore(10000, '\n');
    cin >> upper;
  };

  // For debugging purposes
  // cout << "Lower: " << lower << endl;
  // cout << "Upper: " << upper << endl;

  // Print result through iteration
  // cout << "Interval: " << endl;
  // iteration:
  for(int i = lower; i < upper; i++){
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
