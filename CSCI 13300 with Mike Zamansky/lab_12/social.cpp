/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: Lab 12
Task: Write functions using classes, structs, and constructors.
*/

#include <string>
#include <iostream>
#include "social.h"

using std::string;
using std::cout;
using std::endl;

// CLASS PROFILE --------------------------------------------------------------------------
// Notes: loaded constructors are defined as such:
Profile::Profile(string usrn, string dspn){
  username = usrn;
  displayname = dspn;
}

// Notes: default constructors can be defined as such with no returntype:
Profile::Profile(): username(""), displayname("") {}

// Notes: class functions are defined as such:
string Profile::getUsername(){
  if(username == ""){
    return "Username not set.";
  }
  return username;
}

string Profile::getFullName(){
  if(displayname == ""){
    return "Display name not set.";
  }
  string retStr = displayname + " (@" + username + ")";
  return retStr;
}

void Profile::setDisplayName(string dspn){
  displayname = dspn;
  return;
}

// CLASS NETWORK --------------------------------------------------------------------------
Network::Network() {
  numUsers = 0;
  for(int row = 0; row < MAX_USERS; row++){
    for(int col = 0; col < MAX_USERS; col++){
      following[row][col] = false;
    }
  }
}

int Network::findID(string usrn){
  for(int x = 0; x < MAX_USERS; x++){
    if(profiles[x].getUsername() == usrn){
      return x;
    }
  }
  return -1;
}

bool Network::addUser(string usrn, string dspn){
  if(usrn == ""){
    return false;
  } else {
    if(isAlphanumeric(usrn)){
      if(findID(usrn) == -1){
        if(numUsers < MAX_USERS){
            Profile p = Profile(usrn, dspn);
            profiles[numUsers] = p;
            numUsers += 1;
            return true;
        } else {
          return false;
        }
      } else {
        return false;
      }
    } else {
      return false;
    }
  }
}

bool Network::follow(string usrn1, string usrn2){
  int user1Index = findID(usrn1);
  int user2Index = findID(usrn2);
  if(user1Index != -1 && user2Index != -1){
    following[user1Index][user2Index] = true;
    return true;
  } else {
    cout << "At least one of the usernames are not registered in the network." << endl;
    return false;
  }
}

void Network::printDot(){
  string retStr = "digraph {\n";
  for(int x = 0; x < numUsers; x++){
    retStr += "\t\"@" + profiles[x].getUsername() + "\"\n";
  }
  retStr += "\n\n";
  for(int row = 0; row < numUsers; row++){
    for(int col = 0; col < numUsers; col++){
      if(following[row][col]){
        retStr += "\t\"@" + profiles[row].getUsername() + "\" -> \"@" + profiles[col].getUsername() + "\"\n";
      }
    }
  }
  retStr += "}";
  cout << retStr << endl;
}

// HELPER FUNCTIONS ------------------------------------------------------------------------
// ASCII Notes: [0-9 48-57] [a-z 65-90] & [A-Z 97-122]
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
