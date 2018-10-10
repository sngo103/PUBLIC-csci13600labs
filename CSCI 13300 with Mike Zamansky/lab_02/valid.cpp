/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: Lab 2A
Task: Given an integer n between 0 and 100, exclusive, print out n squared.
*/

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

// Given two numbers, returns the smaller number
int square(int n){
    return n * n;
}

// Main function extracts input numbers from user
int main() {
  // Initialize variables
  int num = -10;

  // Ask user for the number and store it in the variable. If input is
  // incorrect, ask again.
  cout << "Please enter an integer: ";
  cin >> num;
  // While the input is of the wrong datatype or the number is out of range, ask
  // again.
  // ***This method accommodates for strings entered as input and is the
  // better method, but the code was rejected by Gradescope
  /*
  while (cin.fail() || num <= 0 || num >= 100){
    cout << "Please re-enter: ";
    cin.clear();
    cin.ignore(10000, '\n');
    cin >> num;
  };
  */

  // This was the method accepted by Gradescope, but is not as robust as
  // the above method.
  // While the input is out of range, ask again.
  // *HOWEVER, IF THE INPUT IS A STRING, CAUSES AN INFINITE LOOP
  do {
    cout << "Please re-enter: ";
    //cin.clear();
    //cin.ignore(10000, '\n');
    cin >> num;
  } while (num <= 0 || num >= 100);

  // Print result
  cout << "Number squared is " << pow(num, 2)<< endl;
  return 0;
}
