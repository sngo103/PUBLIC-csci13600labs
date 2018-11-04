/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: Extra Lab 0
Task: Use rotational cipher and letter frequencies to decode encrypted text.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <math.h>

using std::string;
using std::cout;
using std::endl;
using std::ifstream;
using std::cerr;

// Wikipedia Frequencies:
// double freqs[] = {8.167,1.49,2.782,4.253,12.702,2.228,2.015,6.094,6.966,0.153,0.772,4.025,2.406,6.749,7.507,1.929,0.095,5.987,6.327,9.056,2.758,0.978,2.360,0.150,1.974,0.07};

// "A Tale of Two Cities" Calculated Frequencies:
//double freqs[] = { 8.06681, 1.39503, 2.26677, 4.71078, 12.4917, 2.25426, 2.07738, 6.57476, 6.81918, 0.106611, 0.794271, 3.69129, 2.55764, 7.08057, 7.73275, 1.62025, 0.112267, 6.16323, 6.30275, 8.98071, 2.77961, 0.868145, 2.3715, 0.114153, 2.0311, 0.0365084 };

double freqs[26];
int reading_total_characters = 0;

int readFrequencies(){
  cout << "CALCULATING FREQUENCIES FROM: ";
  cout << "Tale of Two Cities";
  cout << endl;

  // Read in Gutenberg Book:
  ifstream fin("taleOfTwoCities.txt");
  if (fin.fail()){
    cerr << "File cannot be opened for reading." << endl;
    exit(1); // Exit if file cannot be opened.
  }

  string line;
  char letter;
  while(getline(fin, line)){
    //cout << line.length() << "|";
    //cout << "LINE:" << line << "|" << endl;
    for(int x = 0; x < line.length(); x++){
      letter = line[x];
      letter = tolower(letter);
      if((letter >= 'a') && (letter <= 'z')){
        freqs[letter - 97] += 1;
        reading_total_characters += 1;
      }
    }
  }

  // Calculate and print out frequencies:
  cout << "Tale of Two Cities -> { ";
  for(int x = 0; x < 26; x++){
    freqs[x] = (freqs[x]/(reading_total_characters * 1.0)) * 100;
    if(x == 25){
      cout << freqs[x] << " }" << endl;
      cout << endl;
    } else {
      cout << freqs[x] << ", ";
    }
  }

  fin.close();
  return 0;
}

int readFrequenciesSpanish(){
  cout << "CALCULATING FREQUENCIES FROM: ";
  cout << "The Alchemist en Espanol";
  cout << endl;

  // Read in Spanish Book:
  ifstream fin("theAlchemistInSpanish.txt");
  if (fin.fail()){
    cerr << "File cannot be opened for reading." << endl;
    exit(1); // Exit if file cannot be opened.
  }

  string line;
  char letter;
  while(getline(fin, line)){
    //cout << line.length() << "|";
    //cout << "LINE:" << line << "|" << endl;
    for(int x = 0; x < line.length(); x++){
      letter = line[x];
      letter = tolower(letter);
      if((letter >= 'a') && (letter <= 'z')){
        freqs[letter - 97] += 1;
        reading_total_characters += 1;
      }
    }
  }

  // Calculate and print out frequencies:
  cout << "The Alchemist en Espanol -> { ";
  for(int x = 0; x < 26; x++){
    freqs[x] = (freqs[x]/(reading_total_characters * 1.0)) * 100;
    if(x == 25){
      cout << freqs[x] << " }" << endl;
      cout << endl;
    } else {
      cout << freqs[x] << ", ";
    }
  }

  fin.close();
  return 0;
}

string encode(string s, int r){
  char c;
  string result="";
  for (int i = 0; i < s.length(); ++i) {
    c = s[i];
    if (c >= 'a' && c<='z'){
      c  = c - 'a';
      c = (c + r)%26;
      c = c + 'a';
    }
    else if (c >= 'A' && c<='Z'){
      c  = c - 'A';
      c = (c + r)%26;
      c = c + 'A';
    }
    result = result + c;
  }
  return result;
}


double distance(double a[], double b[], int len){
  double sum = 0;
    for (int i = 0; i < len; ++i) {
      sum = sum + (b[i] - a[i]) * (b[i] - a[i]);
    }
    return sqrt(sum);
}

int count_letters(string s, char c){
  int count = 0;
  for (int i = 0; i < s.length(); ++i) {
    if (s[i]==c)
      count++;
  }
  return count;
}

string decode(string s, double freqs[]){
  string test_string;
  int total_letters;
  double test_vector[26];
  double min_dist = 1000;
  double min_index = 0;
  int i;
  double d;

  total_letters = s.length();
  int j = total_letters;
  for (i = 0; i < j; ++i) {
    if (s[i]==' ')
      total_letters--;
  }
  for (i = 0; i < 26; ++i) {
    test_string = encode(s,i);
    for (j = 0; j < 26; j++) {
      d = 1.0*count_letters(test_string,'a'+j) / total_letters;
      test_vector[j] = d;
    }
    double test_distance = distance(freqs,test_vector,26);
    if (test_distance < min_dist){
      min_dist = test_distance;
      min_index = i;
    }
  }

  string decoded = encode(s,min_index);
  return decoded;
}
