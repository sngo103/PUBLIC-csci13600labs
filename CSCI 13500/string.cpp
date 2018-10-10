/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: HW 4.2
Task: Complete tasks in HW 4.2
*/

#include <iostream>
#include <string>

// Using temporarily:
using namespace std;

// Main function for extracting input and running code
int main() {
  // Initialize variables
  std::string s;
  std::string c;
  std::string r = "";
  int i = 0;

  std::cout << "Enter a word: " << endl;
  cin >> s;

  while (cin.fail()){
    std::cout << "*** Please enter at least one character." << endl;
    std::cout << "Enter a word: " << endl;
    cin.clear();
    cin.ignore(10000, '\n');
    cin >> s;
  };

  while (i < s.length()){
    c = s.at(i);
    r = c + r;
    i++;
  }

  // Print result
  cout << r << endl;
  return 0;
}
