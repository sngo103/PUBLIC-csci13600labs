/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: Lab 9
Task: Write functions using pointers and dynamically-allocated memory
*/

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

string* createAPoemDynamically() {
    string *p = new string;
    *p = "Roses are red, violets are blue";
    return p;
}
