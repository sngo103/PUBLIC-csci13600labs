/*
Author: Samantha Ngo
Course: CSCI 13500
Instructor: Genady Maryash
Assignment: Project 2 Phase 1 & 2
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

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

string replace_phoneme(string word, string pronunciation){
  if(pronunciation == "Not found"){
    return "Not found";
  }

  string retStr = "";
  // Open the file for reading
  ifstream fin("cmudict.0.7a");
  if (fin.fail()){
    cerr << "rpFile cannot be opened for reading." << endl;
    exit(1); // Exit if file cannot be opened.
  }

  string p = pronunciation.substr(1);
  // cout << "Pronunciation:" << p << endl;
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

  string obj;
  string term;
  bool firstStrike;
  bool secondStrike;
  string before_new;
  string after_new;
  string before_p;
  string after_p;

  // For each line:
  while(getline(fin, obj)){
    p = pronunciation.substr(1);
    firstStrike = false;
    secondStrike = false;
    // Remove the word:
    splitOnSpace(obj, before_new, after_new);
    term = before_new;
    // cout << "Term: " << term << endl;

    after_new = after_new.substr(1);
    obj = after_new;
    // cout << "+++++=============================" << endl;
    // cout << "1Obj:" << obj << endl;
    // cout << "1Before_new:" << before_new << endl;
    // cout << "1After_new:" << after_new << endl;

    while(!firstStrike || !secondStrike){
      splitOnSpace(obj, before_new, after_new);
      // cout << "2After new:" << after_new << "|" << endl;
      obj = after_new;
      splitOnSpace(p, before_p, after_p);
      // cout << "2After p:" << after_p << "|" << endl;
      p = after_p;
      // cout << "2Before new:" << before_new << "|" << endl;
      // cout << "2Before p:" << before_p << "|" << endl;

      if(before_new == "" && before_p == ""){
        if(firstStrike && !secondStrike){
          // cout << "Word matches:" << term << endl;
          if(term.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ'") == string::npos){
            retStr += term;
            retStr += " ";
          }
          firstStrike = true;
          secondStrike = true;
        } else {
          //cout << "-----------" << match << doubleMatch << endl;
          firstStrike = true;
          secondStrike = true;
        }
        // cout << "A" << endl;
     } else if(before_p == "" || before_new == ""){
       // cout << "END" << endl;
       firstStrike = true;
       secondStrike = true;
       // cout << "B" << endl;

     } else if(before_new == before_p){
        // cout << "It matches" << endl;
        // cout << "C" << endl;

      } else if(firstStrike == true){
        secondStrike = true;
        // cout << "D Completely doesn't match." << endl;
      } else {
        // cout << "D" << endl;
        // cout << "No match" << endl;
        firstStrike = true;
      }
    }
    // cout << "+++++=============================" << endl;
  }

  // Close file after reading
  fin.close();

  // cout << "RETSTR: " << retStr << endl;
  return retStr;
}

string add_phoneme(string word, string pronunciation){
  if(pronunciation == "Not found"){
    return "Not found";
  }

  string retStr = "";
  // Open the file for reading
  ifstream fin("cmudict.0.7a");
  if (fin.fail()){
    cerr << "apFile cannot be opened for reading." << endl;
    exit(1); // Exit if file cannot be opened.
  }

  string p = pronunciation.substr(1);
  string line;
  string before;
  string after;

  // Get rid of header:
  int counter = 0;
  while(counter < 54){
    getline(fin, line);
    counter += 1;
  }

  string obj;
  string term;
  bool firstStrike;
  bool secondStrike;
  string before_new;
  string after_new;
  string before_p;
  string after_p;

  int z = 0;
  int pspace = 0;
  int nspace = 0;
  bool addSpace;

  // For each line:
  while(getline(fin, obj)){
    addSpace = false;
    p = pronunciation.substr(1);
    firstStrike = false;
    secondStrike = false;
    // Remove the word:
    splitOnSpace(obj, before_new, after_new);
    term = before_new;
    //cout << "Term: " << term << endl;

    after_new = after_new.substr(1);
    obj = after_new;

    pspace = 0;
    nspace = 0;
    //cout << "P:" << p << "|" << endl;
    //cout << "N:" << obj << "|" << endl;
    for (int c = 0; c < p.length(); c++){
      if(p.substr(c, 1) == " "){
        pspace += 1;
      }
    }
    //cout << "PSPACE: " << pspace << endl;

    for (int c = 0; c < obj.length(); c++){
      if(obj.substr(c, 1) == " "){
        nspace += 1;
      }
    }
    //cout << "NSPACE: " << nspace << endl;

    if( nspace == pspace + 1){
      while(!firstStrike || !secondStrike){
        //cout << "P:" << p << "|" << endl;
        //cout << "O:" << obj << "|" << endl;

        splitOnSpace(obj, before_new, after_new);
        obj = after_new;

        if(obj == p && !addSpace){
          p = "X " + p;
          addSpace = true;
        }

        splitOnSpace(p, before_p, after_p);
        p = after_p;

        //cout << "p:" << before_p << "|" << "" << after_p << "|" << endl;
        //cout << "n:" << before_new << "|" << "" << after_new << "|" << endl;
        // To move to next line: firstStrike and secondStrike must equal true
        if(((before_new == "" && before_p == "") && firstStrike) && !secondStrike){
          if(term.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ'") == string::npos){
            retStr += term;
            retStr += " ";
          }
          firstStrike = true;
          secondStrike = true;
          //cout << "A" << endl;
        } else if((before_p == "" && secondStrike) || (before_p == "" && before_new == "")){
          firstStrike = true;
          secondStrike = true;
          //cout << "B" << endl;
        } else if(before_new != before_p){
          if(firstStrike){
            //cout << "C" << endl;
            secondStrike = true;
          } else {
            //cout << "D" << endl;
            firstStrike = true;
          }
          // else, do nothing and move onto the next phoneme
        }
      }
    }
    z += 1;
    //cout << "+++++=============================" << endl;
  }

  // Close file after reading
  fin.close();

  //cout << "RETSTR: " << retStr << endl;
  return retStr;
}

string check(string pro){
  string retStr = "";

  // Open the file for reading
  ifstream fin("cmudict.0.7a");
  if (fin.fail()){
    cerr << "cFile cannot be opened for reading." << endl;
    exit(1); // Exit if file cannot be opened.
  }

  string line;
  string before;
  string after;

  // Get rid of header:
  int counter = 0;
  while(counter < 54){
    getline(fin, line);
    counter += 1;
  }

  string term;
  while(getline(fin, line)){
    splitOnSpace(line, before, after);
    term = before;
    //cout << "TERM:" << term << "|" << endl;
    //cout << "AFTER:" << after << "|" << endl;
    if(after.substr(1) == pro){
      retStr += term + " ";
    }
  }
  //cout << "RETSTR:" << retStr << "|" << endl;
  return retStr;
}

string remove_phoneme(string word, string pronunciation){
  if(pronunciation == "Not found"){
    return "Not found";
  }

  string retStr = "";
  // Open the file for reading
  ifstream fin("cmudict.0.7a");
  if (fin.fail()){
    cerr << "rmpFile cannot be opened for reading." << endl;
    exit(1); // Exit if file cannot be opened.
  }

  string newpronunciation = "";

  string p = pronunciation.substr(1);
  string line;
  string before;
  string after;

  //cout << "Pronunciation:" << p << "|" << endl;

  // Get rid of header:
  int counter = 0;
  while(counter < 54){
    getline(fin, line);
    counter += 1;
  }

  int spaces = 0;
  for(int x = 0; x < p.length(); x++){
    if(p[x] == ' '){
      spaces += 1;
    }
  }
  //cout << "SPACES: " << spaces << endl;
  int variations = spaces + 1;
  int startIndex = -1;
  int endIndex = -1;
  int iter = 0;
  for (int x = 0; x < variations; x++){
    if(x == 0){
      startIndex = 0;
      endIndex = p.find_first_of(" ");
      //cout << startIndex << " | " << endIndex << endl;
      newpronunciation = p.substr(endIndex + 1);
      //cout << "NEWPRO:" << newpronunciation << "|" << endl;

      retStr += check(newpronunciation);
    } else if(x == variations - 1){
      newpronunciation = p.substr(0, endIndex);
      //cout << "NEWPRO:" << newpronunciation << "|" << endl;
      retStr += check(newpronunciation);
    } else {
      startIndex = endIndex + 1;
      newpronunciation = p.substr(endIndex + 1);
      endIndex = newpronunciation.find_first_of(" ") + startIndex;
      newpronunciation = p.substr(0, startIndex) + p.substr(endIndex + 1);
      endIndex = endIndex;
      //cout << "NEWPRO:" << newpronunciation << endl;
      retStr += check(newpronunciation);
    }

  }

  string finalString = "";
  string term = "";
  fin.seekg(0);

  counter = 0;
  while(counter < 54){
    getline(fin, line);
    counter += 1;
  }
  retStr = " " + retStr + " ";
  while(getline(fin, line)){
    splitOnSpace(line, term, after);
    //cout << term << "|" << retStr << endl;
    //cout << "FINAL:" << retStr << endl; //retStr.find_first_of(term) << endl;
    if(retStr.find(" " + term + " ") != std::string::npos){
      if(term.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ' ") == string::npos){
        finalString += term + " ";
      }
    }
  }

  retStr = finalString;
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
  string p = identicalWords(word, x); // Passing the pronunciation, getting back the identical words
  identical += p;
  identical += "\n";

  // Handling adding a phoneme:
  p = add_phoneme(word, x);
  addPhoneme += p;
  addPhoneme += "\n";
  // Handling removing a phoneme:
  p = remove_phoneme(word,x);
  removePhoneme += p;
  removePhoneme += "\n";
  // Handlind replacing a phoneme:
  p = replace_phoneme(word, x);
  replacePhoneme += p;
  replacePhoneme += "\n";

  output += pronunciation;
  output += "\n";
  output += identical;
  output += addPhoneme;
  output += removePhoneme;
  output += replacePhoneme;
  cout << output << endl << endl;
  return 0;
}

// Main function for executing code
int main() {
  wordSearch();
  return 0;
}
