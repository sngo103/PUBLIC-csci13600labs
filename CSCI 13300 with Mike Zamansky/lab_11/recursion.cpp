/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: Lab 11
Task: Write functions using recursion.
*/

#include <string>
#include <iostream>
#include "recursion.h"

using std::string;
using std::cout;
using std::endl;

void printRange(int left, int right){
  if(left > right){
    return;
  } else if(left == right){
    cout << right << " ";
  } else {
    cout << left << " ";
    printRange(left + 1, right);
  }
}

int sumRange(int left, int right){
  if(left == right){
    return left;
  } else if(left > right){
    return sumRange(right, left);
  } else {
    return left + sumRange(left + 1, right);
  }
  return 0;
}

int sumArray(int *arr, int size){
  if(size == 0){
    return 0;
  } else if(size == 1){
    return arr[0];
  } else {
    return arr[size - 1] + sumArray(arr, size - 1);
  }
}

// 0-9 48-57
// a-z 65-90 & 97-122
bool isAlphanumeric(string s){
  if(s.length() == 0){
    return true;
  } else if(s.length() == 1){
    if((48 <= s[0] && s[0] <= 57) || (65 <= s[0] && s[0] <= 90) || (97 <= s[0] && s[0] <= 122)){
      return true;
    } else {
      return false;
    }
  } else {
    if((48 <= s[0] && s[0] <= 57) || (65 <= s[0] && s[0] <= 90) || (97 <= s[0] && s[0] <= 122)){
      return (true && isAlphanumeric(s.substr(1)));
    } else {
      return false;
    }
  }
}

bool nestedParens(string s){
  if(s.empty()){
    return true;
  } else if((s.length() % 2) != 0){
    return false;
  } else {
    if(s[0] == '(' && s[s.length()-1] == ')'){
      return (true && nestedParens(s.substr(1,s.length() - 2)));
    } else {
      return false;
    }
  }
}

int split = 0;
bool setup = false;

bool divisible(int *prices, int size){
  if(!setup){
    for(int x = 0, x < size; x++){
      split += prices[x];
    }
    if(split % 2 != 0){
      return false;
    } else {
      split = split/2;
      setup = true;
    }
  }

  [3,7,8,2]

  return false;
}
