/*
Author: Samantha Ngo
Course: CSCI 13500
Instructor: Genady Maryash
Assignment: Project 2 Phase 1 & 2
*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::ifstream;
using std::cerr;

// Given function:
void splitOnSpace(string s, string & before, string & after) {
  // reset strings
  before = "";
  after = "";
  // accumulate before space
  int i = 0;
  while (i < s.size() && not isspace(s[i])) { before += s[i]; i++; }
  // skip the space
  i++;
  // accumulate after space
  while (i < s.size()) { after += s[i]; i++; }
}

// Capitalize the word
string capitalize(string word){
  string retStr = "";
  for(int i = 0; i < word.length(); i++){
    if(word[i] >= 'a' && word[i] <= 'z'){
      retStr += (word[i] - ('a' - 'A'));
    } else {
      retStr += word[i];
    }
  }
  // cout << retStr;
  return retStr;
}

// Given the date, returns east basin Storage
// *Expects parameter to be corrected beforehand if necessary and then given in
// correct format; does not check if parameter is in correct format
string pronounce(string word){
  // Captialize word
  string target = word;
  string pronunciation;

  // Open the file for reading
  ifstream fin("cmudict.0.7a");
  if (fin.fail()){
    cerr << "pFile cannot be opened for reading." << endl;
    exit(1); // Exit if file cannot be opened.
  }

  // Initialize variables for manipulating each line
  string line;
  string before;
  string after;

  // Get rid of header:
  int counter = 0;
  while(counter < 54){
    getline(fin, line);
    counter += 1;
  }

  // Read the values line by line
  while(getline(fin, line)){
    // cout << line << endl;
    splitOnSpace(line, before, after);
    if(before == target){
      // cout << "After: " << after << endl;
      pronunciation = after;
      // cout << pronunciation;
      return pronunciation;
    }
  }

  // Close file after reading
  fin.close();

  pronunciation = "Not found";
  // cout << pronunciation;
  return pronunciation;
}

string identicalWords(string word, string pronunciation){
  if(pronunciation == "Not found"){
    return "Not found";
  }

  string retStr = "";
  // Open the file for reading
  ifstream fin("cmudict.0.7a");
  if (fin.fail()){
    cerr << "iFile cannot be opened for reading." << endl;
    exit(1); // Exit if file cannot be opened.
  }

  // Initialize variables for manipulating each line
  string line;
  string before;
  string after;

  // Get rid of header:
  int counter = 0;
  while(counter < 54){
    getline(fin, line);
    counter += 1;
  }

  // Read the values line by line
  while(getline(fin, line)){
    // cout << line << endl;
    splitOnSpace(line, before, after);
    if(after == pronunciation && before != word){
      // cout << "After: " << after << endl;
      retStr += before;
      retStr += " ";
      // cout << retStr;
    }
  }

  // Close file after reading
  fin.close();

  return retStr;
}

int wordSearch(){
  // Get word from user:
  string word;
  cin >> word;

  // Format word and initialize variables:
  word = capitalize(word);
  string pronunciation = "Pronunciation    :";
  string identical = "Identical        : ";
  string addPhoneme = "Add phoneme      : ";
  string removePhoneme = "Remove phoneme   : ";
  string replacePhoneme = "Replace phoneme  : ";
  string output = "";

  // Handling pronunciation:
  string x = pronounce(word);
  if( x == "Not found"){
    output = "Not found\n";
    cout << output;
    return 0;
  } else {
    pronunciation += x;
    pronunciation += "\n";
  }

  // Handling identical words:
  x = identicalWords(word, x); // Passing the pronunciation, getting back the identical words
  identical += x;
  identical += "\n";

  // Handling adding a phoneme:
  // ---To be coded
  // Handling removing a phoneme:
  // ---To be coded
  // Handlind replacing a phoneme:
  // ---To be coded

  output += pronunciation;
  output += "\n";
  output += identical;
  cout << output << endl;
  return 0;
}

// Main function for executing code
int main() {
  wordSearch();
  return 0;
}
