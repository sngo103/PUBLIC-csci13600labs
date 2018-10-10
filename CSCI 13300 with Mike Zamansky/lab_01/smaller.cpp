/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: Lab 1A
Task: Given two integers, returns the smaller of the two.
*/

#include <iostream>
#include <string>

using namespace std;

// Given two numbers, returns the smaller number
double retSmaller(double a, double b){
    if (a <= b){
      return a;
    } else {
      return b;
    }
}

// Main function extracts input numbers from user
int main() {
  // Initialize variables
  double firstNum;
  double secondNum;

  // Ask user for first number and store it in first variable. If input is
  // incorrect, ask again.
  cout << "Enter the first number: ";
  cin >> firstNum;
  while (cin.fail()){
    cout << "***Please enter a numerical value only." << endl;
    cout << "Enter the first number: ";
    cin.clear();
    cin.ignore(10000, '\n');
    cin >> firstNum;
  };

  // Ask user for second number and store it in second variable. If input is
  // incorrect, ask again.
  cout << "Enter the second number: ";
  cin >> secondNum;
  while (cin.fail()){
    cout << "***Please enter a numerical value only." << endl;
    cout << "Enter the second number: ";
    cin.clear();
    cin.ignore(10000, '\n');
    cin >> secondNum;
  };

  // Output for debugging
  cout << "First Number: " << firstNum << endl;
  cout << "Second Number: " << secondNum << endl;

  // Print result
  cout << "The smaller number is " << retSmaller(firstNum, secondNum) << endl;
  return 0;
}
