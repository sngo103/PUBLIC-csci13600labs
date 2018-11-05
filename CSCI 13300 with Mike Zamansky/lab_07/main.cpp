/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: Lab 7
Task: Write a utility program that corrects indentation in
given code.
*/

#include "self_indent.h"
#include <iostream>
#include <string>

using std::cout;
using std::string;
using std::cin;
using std::endl;

// Reads in bad code from a text file and removes the leading spaces
// from each line.
// Returns unindented code.
string fixBadCode(){
  string retStr = "";
  string line;
  int braces = 0;

  while(getline(cin, line)){
    line = removeLeadingSpaces(line);
    //cout << line.substr(0,1) << "|" << endl;
    if(line.substr(0,1) == "}"){
      for(int x = 0; x < braces - 1; x++){
        retStr += "\t";
      }
    } else {
      for(int x = 0; x < braces; x++){
        retStr += "\t";
      }
    }
    braces += countChar(line, '{');
    braces += countChar(line, '}') * -1;
    retStr += line + "\n";
    //cout << braces << "|";
    //cout << removeLeadingSpaces(line) << "|" << endl;
    //retStr += removeLeadingSpaces(line) + "\n";
  }
  //cout << retStr << endl;
  return retStr;
}

int main(){
  cout << "====================================================================================================" << endl;
  cout << "Lab 7: Writing Indentation Utility Functions" << endl;
  cout << "====================================================================================================" << endl;
  cout << "Part A Testing..." << endl;
  cout << removeLeadingSpaces("       int x = 1;  ") << "|" << endl;
  cout << "..............................................." << endl;
  cout << "Part B Testing..." << endl;
  cout << fixBadCode() << endl;
  cout << "..............................................." << endl;
/*
  cout << "Testing test_ascii(string input)...................................................................." << endl;
  cout << "test_ascii('Cat :3 Dog'):" << endl;
  cout << test_ascii("Cat :3 Dog") << "\n" << endl;
  cout << "Testing char shiftChar(char c, int rshift).........................................................." << endl;
  cout << "shiftChar('h', 2) => " << shiftChar('h', 2) << " == j" << endl;
  cout << "shiftChar('X', 5) => " << shiftChar('X', 5) << " == C\n" << endl;
  cout << "Testing string encryptCaesar(string plaintext, int rshift).........................................." << endl;
  cout << "encryptCaesar( 'Way to Go!', 5 ) => " << encryptCaesar( "Way to Go!", 5 ) << " == 'Bfd yt Lt!'\n" << endl;
  cout << "Testing string encryptVigenere(string plaintext, string keyword)...................................." << endl;
  cout << "encryptVigenere( 'Hello, World!', 'cake') =>" << encryptVigenere( "Hello, World!", "cake" ) << " == 'Jevpq, Wyvnd!'\n" << endl;
  cout << "Testing string decryptCaesar(string plaintext, int rshift).........................................." << endl;
  cout << "decryptCaesar( 'Bfd yt Lt!' , 5 ) => " << decryptCaesar( "Bfd yt Lt!", 5 ) << " == 'Way to Go!'\n" << endl;
  cout << "Testing string decryptVigenere(string plaintext, string keyword)...................................." << endl;
  cout << "decryptVigenere( 'Jevpq, Wyvnd!' , 'cake') =>" << decryptVigenere( "Jevpq, Wyvnd!", "cake" ) << " == 'Hello, World!'" << endl;
*/
  return 0;

}
