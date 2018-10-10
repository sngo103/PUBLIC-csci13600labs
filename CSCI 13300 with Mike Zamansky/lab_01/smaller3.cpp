/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: Lab 1B
Task: Given three integers, returns the smallest of the three.
*/

#include <iostream>
#include <string>

using namespace std;

// Given three numbers, returns the smallest number
double retSmallest(double a, double b, double c){
  // Check a against other numbers
    if (a <= b){
      if (a <= c){
        return a;
      }
    }
    // Check b against other numbers
    else if (b <= a){
      if (b <= c){
        return b;
      }
    }
    // If all fails, the smallest number is c
    else {
        return c;
      }
}

// Main function extracts input numbers from user
int main() {
  // Initialize variables
  double firstNum;
  double secondNum;
  double thirdNum;

  // Record first number. If input is incorrect, ask again.
  cout << "Enter the first number: ";
  cin >> firstNum;
  while (cin.fail()){
    cout << "***Please enter a numerical value only." << endl;
    cout << "Enter the first number: ";
    cin.clear();
    cin.ignore(10000, '\n');
    cin >> firstNum;
  };
  // Record second number. If input is incorrect, ask again.
  cout << "Enter the second number: ";
  cin >> secondNum;
  while (cin.fail()){
    cout << "***Please enter a numerical value only." << endl;
    cout << "Enter the second number: ";
    cin.clear();
    cin.ignore(10000, '\n');
    cin >> secondNum;
  };
  // Record third number. If input is incorrect, ask again.
  cout << "Enter the third number: ";
  cin >> thirdNum;
  while (cin.fail()){
    cout << "***Please enter a numerical value only." << endl;
    cout << "Enter the third number: ";
    cin.clear();
    cin.ignore(10000, '\n');
    cin >> thirdNum;
  };

  // For debugging purposes
  cout << "First Number: " << firstNum << endl;
  cout << "Second Number: " << secondNum << endl;
  cout << "Third Number: " << thirdNum << endl;

  // Print result
  cout << "The smallest number is " << retSmallest(firstNum, secondNum, thirdNum) << endl;
  return 0;
}
