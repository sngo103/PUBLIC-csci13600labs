/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: Lab 12
Task: Write functions using classes, structs, and constructors.
*/

#pragma once
#include <string>

using std::string;

class Profile{
  private:
    string displayname;
    string username;
  public:
    Profile(string username, string dspn);
    Profile();
    string getUsername();
    string getFullName();
    void setDisplayName(string dspn);
};

class Network{
  private:
    static const int MAX_USERS = 20;
    Profile profiles[MAX_USERS];
    int numUsers;
    bool following[MAX_USERS][MAX_USERS];

    int findID(string usrn);
  public:
    Network();
    bool addUser(string usrn, string dspn);
    bool follow(string usrn1, string usrn2);
    void printDot();
};

bool isAlphanumeric(string s);
