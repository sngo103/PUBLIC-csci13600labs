/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: Lab 6
Task: Write cryptographic functions
*/

/*
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "catch.hpp"
*/
#include <string>
#include <iostream>
#include <locale>
#include "crypto.h"

using namespace std;
using std::string;
using std::cout;
using std::endl;
using std::isalpha;

string test_ascii(string input){
  string retStr;
  char c;
  for(int x = 0; x < input.length(); x++){
    c = input[x];
    retStr += c;
    retStr += " ";
    retStr += std::to_string(((int)c));
    retStr += "\n";
  }
  return retStr;
}

// A helper function to shift one character by rshift
// If rshift is less than 0, will return character unchanged
char shiftChar(char c, int rshift){
  string lowercase = "abcdefghijklmnopqrstuvwxyz";
  string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  int startIndex = -1;
  int newIndex = -1;
  char retChar;
  string x = string(1, c);
  if(rshift <= 0){
    return c;
  }
  if(x.find_first_not_of(lowercase) == string::npos){
    startIndex = lowercase.find_first_of(x);
    newIndex = (startIndex + rshift) % 26;
    return lowercase[newIndex];
  } else if (x.find_first_not_of(uppercase) == string::npos){
    startIndex = uppercase.find_first_of(x);
    newIndex = (startIndex + rshift) % 26;
    return uppercase[newIndex];
  } else {
    return c;
  }
}

// Caesar cipher encryption
string encryptCaesar(string plaintext, int rshift){
  if(plaintext.empty()){
    return "";
  }
  string retStr;
  for (int x = 0; x < plaintext.length(); x++){
    retStr += shiftChar(plaintext[x], rshift);
  }
  return retStr;
}

// Given an alphabetic character, returns the index of the character in the
// alphabet
int alphaIndex(char c){
  string lowercase = "abcdefghijklmnopqrstuvwxyz";
  string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  string x = string(1, c);
  int index = -1;
  if(x.find_first_not_of(lowercase) == string::npos){
    index = lowercase.find_first_of(x);
  } else if (x.find_first_not_of(uppercase) == string::npos){
    index = uppercase.find_first_of(x);
  }
  return index;
}

string encryptVigenere(string plaintext, string keyword){
  if(plaintext.empty()){
    return "";
  } else if(keyword.empty()){
    return plaintext;
  }
  string retStr;
  int counter = 0;
  int alphaNum = 0;
  string y;
  for(int x = 0; x < plaintext.length(); x++){
    if(isalpha(plaintext[x])){
      y = string(1, plaintext[x]);
      alphaNum = alphaIndex(keyword[counter % keyword.length()]);
      retStr += encryptCaesar(y, alphaNum);
      counter += 1;
    } else {
      retStr += plaintext[x];
    }
  }
  return retStr;
}

string decryptCaesar(string ciphertext, int rshift){
  if(ciphertext.empty()){
    return "";
  }
  string retStr;
  for (int x = 0; x < ciphertext.length(); x++){
    retStr += shiftChar(ciphertext[x], 26 - rshift);
  }
  return retStr;
}

string decryptVigenere(string ciphertext, string keyword){
  if(ciphertext.empty()){
    return "";
  } else if(keyword.empty()){
    return ciphertext;
  }

  string retStr;
  int counter = 0;
  int alphaNum = 0;
  string y;
  for(int x = 0; x < ciphertext.length(); x++){
    if(isalpha(ciphertext[x])){
      y = string(1, ciphertext[x]);
      alphaNum = alphaIndex(keyword[counter % keyword.length()]);
      retStr += encryptCaesar(y, 26 - alphaNum);
      counter += 1;
    } else {
      retStr += ciphertext[x];
    }
  }
  return retStr;
}
