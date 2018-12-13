/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: Lab 11
Task: Write functions using recursion.
*/

#include "catch.hpp"
#include <iostream>
#include "recursion.h"

using std::cout;
using std::endl;
using std::cin;

int main(){
  cout << "=======================================================================================" << endl;
  cout << "Lab 11: Writing functions using recursion" << endl;
  cout << "=======================================================================================" << endl;
  cout << "----- Testing [TASK A]printRange()..." << endl;
  cout << "[CASE 1: Normal]" << endl;
  cout << "   printRange(-2,10)" << endl;
  cout << "   EXPECTED: -2 -1 0 1 2 3 4 5 6 7 8 9 10 " << endl;
  cout << "   RECEIVED: ";
  printRange(-2,10);
  cout << endl;
  cout << "   printRange(89,94)" << endl;
  cout << "   EXPECTED: 89 90 91 92 93 94 " << endl;
  cout << "   RECEIVED: ";
  printRange(89,94);
  cout << endl;
  cout << "[CASE 2: left > right]" << endl;
  cout << "   printRange(7,5)" << endl;
  cout << "   EXPECTED: " << endl;
  cout << "   RECEIVED: ";
  printRange(7,5);
  cout << endl;
  cout << "[CASE 3: left == right]" << endl;
  cout << "   printRange(6, 6)" << endl;
  cout << "   EXPECTED: 6 " << endl;
  cout << "   RECEIVED: ";
  printRange(6,6);
  cout << endl;
  cout << "   printRange(-2,-2)" << endl;
  cout << "   EXPECTED: -2 " << endl;
  cout << "   RECEIVED: ";
  printRange(-2,-2);
  cout << endl;
  cout << "----- Testing [TASK B]sumRange()..." << endl;
  cout << "   sumRange(-2, 4) = 7 ----> " << sumRange(-2,4) << endl;
  cout << "----- Testing [TASK C]sumArray()..." << endl;
  int array[10] = {12, 17, -5, 3, 7, -15, 27, 5, 13, -21};
  int *arr = array;
  cout << "   sumArray(arr, size) = 43 ----> " << sumArray(arr, 10) << endl;
  cout << "----- Testing [TASK D]isAlphanumeric()..." << endl;
  cout << "   isAlphanumeric('helloHELLO123456789') should be true ------> " << isAlphanumeric("helloHELLO123456789") << " = true"<< endl;
  cout << "----- Testing [TASK E]nestedParens()..." << endl;
  cout << "   nestedParens('((()))') should be true ------> " << nestedParens("((()))") << " = true"<< endl;
  cout << "   nestedParens('(((a)))') should be false ------> " << nestedParens("(((a)))") << " = false"<< endl;

  return 0;
}
