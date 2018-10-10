/*
Author: Samantha Ngo
Course: CSCI 13500
Instructor: Genady Maryash
Assignment: Project 1A
Task: Given a txt file with a sequence of integers, print out the sum
*/

#include <iostream>
#include <string.h>

// To be changed when I get used to using the new form and after asking for
// some clarifications
using namespace std;

// Given a file with a sequence of integers separated by whitespaces,
// prints out the sum of all the integers.
int getSum(){
  // For manipulating each number in the sequence
  int num;
  // For keeping track of the sum of all the integers
  int sum = 0;

  // While there are still integers to be read, continue reading it and
  // add the numbers to the sum.
  // *Notes: this method reads until it encounters a whitespace and then
  // stops reading --> therefore, must use a while loop
  while(cin >> num){
    sum += num;
  }

  // Print result
  std::cout << sum << endl;

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
