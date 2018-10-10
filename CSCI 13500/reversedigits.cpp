/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: HW 4.2
Task: Complete tasks in HW 4.2
*/

#include <iostream>
#include <sstream>
#include <string>
using std::getline;
using std::string;

// Using temporarily:
using namespace std;

// Main function for extracting input and running code
int main() {
  // Initialize variables
  int n = 0;
  std::string s;
  std::string r = "";
  std::string c;
  int i = 0;

  cout << "Enter an integer: " << endl;
  getline(cin, s);

  while (cin.fail()
         || (s.find_first_not_of("0123456789-") != std::string::npos)){
    std::cout << "*** Please enter an integer only." << endl;
    std::cout << "Enter an integer: " << endl;
    cin.clear();
    //cin.ignore(10000, '\n');
    s = "";
    getline(cin,s);
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
