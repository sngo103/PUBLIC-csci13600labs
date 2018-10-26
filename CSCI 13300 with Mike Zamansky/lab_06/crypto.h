/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: Lab 6
Task: Write cryptographic functions
*/

#pragma once
using std::string;

string test_ascii(string input);
char shiftChar(char c, int rshift);
string encryptCaesar(string plaintext, int rshift);
string encryptVigenere(string plaintext, string keyword);
string decryptCaesar(string ciphertext, int rshift);
string decryptVigenere(string ciphertext, string keyword);
