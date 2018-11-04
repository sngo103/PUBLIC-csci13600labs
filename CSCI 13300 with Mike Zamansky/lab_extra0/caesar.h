/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: Extra Lab 0
Task: Use rotational cipher and letter frequencies to decode encrypted text.
*/

#ifndef __caesar_h__
#define __caesar_h__
extern double freqs[26];
#endif

#pragma once
using std::string;

int readFrequencies();
int readFrequenciesSpanish();
string encode(string s, int r);
double distance(double a[], double b[], int len);
int count_letters(string s, char c);
string decode(string s, double freqs[]);
