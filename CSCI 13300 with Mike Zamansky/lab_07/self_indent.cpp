/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: Lab 7
Task: Write a utility program that corrects indentation in
given code.
*/

#include <string>
#include <iostream>
#include <cctype>
#include "self_indent.h"

using std::string;
using std::cout;
using std::endl;

int countChar(string line, char c){
  int count = 0;
  for(int x = 0; x < line.length(); x++){
    if(line[x] == c){
      count += 1;
    }
  }
  return count;
}

string removeLeadingSpaces(string line){
  string retStr = "";
  bool nonspaces = false;

  for(int x = 0; x < line.length(); x++){
    if(isspace(line[x]) == 0){
      nonspaces = true;
    }
    if(nonspaces){
      retStr += line[x];
    }
  }
  return retStr;
}
