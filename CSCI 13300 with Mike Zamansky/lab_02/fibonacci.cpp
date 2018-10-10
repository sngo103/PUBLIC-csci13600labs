/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: Lab 2D
Task: Prints out all the fibonacci numbers from 0 to 59.
*/

#include <iostream>
#include <string>

using namespace std;

int fib[60];

// Prints out array using for loop
int displayArray(){
  cout << "Displaying array..." << endl;
  for (int i = 0; i < 60; i++){
    cout << fib[i] << endl << endl;
  }
  cout << "\n...complete." << endl;
  return 0;
}

int fibonacci(){
  for (int i = 0; i < 60; i++){
    if (i == 0){ // Base case
      fib[i] = 0;
    } else if(i == 1){ // Base case
      fib[i] = 1;
    } else { // Calculate fibonacci number
      fib[i] = fib[i - 1] + fib[i - 2];
    }
  }
  return 0;
}

// Main function for extracting input and running the program
int main() {
  // Call functions
  fibonacci();
  displayArray();

  // Observation of code:
  // I noticed that as the results started approaching two billion, the
  // program started to break down. The numbers began to turn into negatives
  // at some points and looked like they were decreasing. This is because the
  // numbers have become too big for the computer to store and it causes
  // overflow. The computer struggles to convert it into an INT by truncating
  // the numbers or negating them, which changes the answer to a point where it
  // becomes wholly incorrect. This issue can likely be solved temporarily by
  // changing the return type of the fibonacci function to a double or a long
  // long.

  return 0;
}
