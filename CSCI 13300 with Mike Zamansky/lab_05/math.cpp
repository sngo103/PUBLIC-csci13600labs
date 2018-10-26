/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: Lab 5A-G
Task: Write Math functions to be reused as helper functions
*/

/*
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "catch.hpp"
*/
#include "math.h"

bool isDivisibleBy(int n, int d){
  if(d == 0){
    return false;
  }
  if((n % d) == 0){
    return true;
  } else {
    return false;
  }
}

bool isPrime(int n){
  if(n < 2){
    return false;
  } else if(n == 2){
    return true;
  } else if(isDivisibleBy(n, 2)){
    return false;
  }
  int counter = 3;
  while (counter < n){
    if(isDivisibleBy(n,counter)){
      return false;
    }
    counter += 2;
  }
  return true;
}

int nextPrime(int n){
  int num = n + 1;
  while(!isPrime(num)){
    num += 1;
  }
  return num;
}

int countPrimes(int a, int b){
  if(a > b){
    return -1;
  }
  int counter = 0;
  for(int x = a; x <= b; x++){
    if(isPrime(x)){
      counter  += 1;
    }
  }
  return counter;
}

// For anynumber n, return whether n is a twin prime. Negative numbers are
// considered neither prime nor twin prime; in this function, n does not have
// to be prime to find the next twin prime.
bool isTwinPrime(int n){
  if(n < 3){
    return false;
  } else if(n == 3){
    return true;
  }
  if(isPrime(n) && isPrime(n-2) && isPrime(n+2)){
    return true;
  } else {
    return false;
  }
}

// For any number n greater than 0, return the next twin prime number greater than n.
int nextTwinPrime(int n){
  int num  = n + 1;
  while(!isTwinPrime(num)){
    num += 1;
  }
  return num;
}

int largestTwinPrime(int a, int b){
  if(a > b){
    return -1;
  }
  for (int x = b; x >= a; x--){
    if(isTwinPrime(x)){
      return x;
    }
  }
  return -1;
}
