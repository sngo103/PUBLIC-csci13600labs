/*
Author: Samantha Ngo
Course: CSCI 13500
Instructor: Genady Maryash
Assignment: Project 1B
Task: Given a txt file with a simple math formula composed of positive integers,
minus signs, and plus signs, print out the sum
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
    } else {
      // Convert char to int
      n = digit - '0';
      // Calculate the next digit in the number
      currentNum *= 10;
      currentNum += n;
    }
    // cout << "Total: " << totalSum << endl;
    // cout << "Num: " << currentNum << endl;

  }
  // Once there are no more digits, add the last number stored to the
  // total sum.
  currentNum *= signChange;
  totalSum += currentNum;

  // Print result
  cout << totalSum << endl;

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
