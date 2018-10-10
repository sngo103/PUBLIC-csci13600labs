/*
Author: Samantha Ngo
Course: CSCI 13500
Instructor: Genady Maryash
Assignment: Project 1D
Task: Given a txt file with a simple math formula composed of positive integers,
minus signs, plus signs, carots, and semicolons, print out the sum
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

// To be changed when I get used to using the new form and after asking for
// some clarifications
using namespace std;

// Initialize variables
int totalSum = 0;
int currentNum = 0;
int signChange = 1;

// Given a file with a sequence of integers separated by whitespaces,
// and semicolons, prints out the sum of all the integers.
int getSum(){
  // For manipulating each number in the sequence
  char digit;
  int n;

  // While there are still integers to be read, continue reading it and
  // add the numbers to the sum.
  while(cin >> digit){
    // A sign indicates the end of one number and the start of
    // a new number
    if(digit == '+' || digit == '-'){
      // cout << currentNum << " " << signChange << endl;
      currentNum *= signChange;
      totalSum += currentNum;
      currentNum = 0;
      // cout << "=============================Sign: " << digit << endl;
      if(digit == '+'){
        signChange = 1;
      } else {
        signChange = -1;
      }
    } else if(digit == '^'){ // Carot indicates to square the current number
      // cout << currentNum << " " << signChange << endl;
      currentNum *= currentNum;
    } else if(digit == ';'){ // Semicolon indicates end of a statement
      // Add last number
      currentNum *= signChange;
      totalSum += currentNum;
      // Print result
      cout << totalSum << endl;
      // Reset variables
      totalSum = 0;
      currentNum = 0;
      signChange = 1;
    } else {
      n = digit - '0';
      currentNum *= 10;
      currentNum += n;
    }
    // cout << "Total: " << totalSum << endl;
    // cout << "Num: " << currentNum << endl;
  }
  // If the file does not end with a semicolon, add the last number to the
  // sum and print it out
  if(digit != ';'){
    currentNum *= signChange;
    totalSum += currentNum;
    cout << totalSum << endl;
  }
  // Function successful
  return 0;
}

// Main function for executing code
int main() {
  // Call function for sum
  getSum();

  // Function successful
  return 0;
}
