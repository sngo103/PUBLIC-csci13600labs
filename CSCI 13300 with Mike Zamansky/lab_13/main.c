/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: Lab 13
Task: Write a template class
*/

#include "catch.hpp"
#include <iostream>
#include <string>
#include "my_vector.h"

using std::cout;
using std::endl;

int main(){
  cout << "=======================================================================================" << endl;
  cout << "Lab 13: Writing a template class" << endl;
  cout << "=======================================================================================" << endl;
  my_vector<int> ints(5,4,3,2,1);
  my_vector<std::string> strings("Hello","World","!", "and", "all");
  my_vector<double> doubles(1.1,2.2,3.3,4.4,5.9);
  cout << "Testing print()..." << endl;
  cout << "   "; ints.print();
  cout << "   "; strings.print();
  cout << "   "; doubles.print();
  cout << "Testing get(i)..." << endl;
  cout << "   doubles.get(0) should be 1.1 --> " << doubles.get(0) << endl;
  cout << "Testing get(i) OUT OF BOUNDS..." << endl;
  cout << "   strings.get(11) should be out of range --> " << strings.get(11) << endl;
  cout << "   ints.get(11) should be out of range --> " << ints.get(11) << endl;
  cout << "   doubles.get(11) should be out of range --> " << doubles.get(11) << endl;
  cout << "Testing find(item)..." << endl;
  cout << "   "; doubles.print();
  cout << "   doubles.find(2.2) should return 1 --> " << doubles.find(2.2) << endl;
  cout << "Testing set(item, i)..." << endl;
  cout << "   "; doubles.print();
  cout << "   doubles.set(10.7, 0) should be changed in the array:" << endl;
  doubles.set(10.7,0);
  cout << "   "; doubles.print();
  cout << "Testing add(item)..." << endl;
  cout << "   "; doubles.print();
  cout << "   doubles.add(88.9) should be added to the end of the array:" << endl;
  doubles.add(88.9);
  cout << "   "; doubles.print();
  cout << "Testing add(item, i)..." << endl;
  cout << "   "; doubles.print();
  cout << "   doubles.add(1.5, 0) should be added in the array at index 0:"; doubles.add(1.5,0); cout << endl;
  cout << "   "; doubles.print();
  cout << "Testing remove(i)..." << endl;
  cout << "   "; doubles.print();
  cout << "   doubles.remove(doubles.find(2.2)) should remove 2.2 from the array and return it: " << doubles.remove(doubles.find(2.2)) << endl;
  cout << "   "; doubles.print();
  cout << "=======================================================================================" << endl;
  return 0;
}
