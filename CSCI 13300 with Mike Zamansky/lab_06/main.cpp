/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: Lab 6
Task: Write cryptographic functions
*/

#include "catch.hpp"
#include "crypto.h"
#include <iostream>

using std::cout;
using std::endl;

int main(){
  cout << "====================================================================================================" << endl;
  cout << "Lab 6: Writing Cryptography Functions" << endl;
  cout << "====================================================================================================" << endl;
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
  return 0;

}
