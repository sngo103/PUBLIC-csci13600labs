/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: Lab 12
Task: Write functions using classes, structs, and constructors.
*/

#include "catch.hpp"
#include <iostream>
#include "social.h"

using std::cout;
using std::endl;
using std::to_string;

int main(){
  cout << "=======================================================================================" << endl;
  cout << "Lab 12: Writing functions using classes, structs, and constructors" << endl;
  cout << "=======================================================================================" << endl;
  cout << "----- Testing [TASK A]class Profile..." << endl;
  Profile p1("marco", "Marco");
  cout << "   p1.getUsername() should return" << endl;
  cout << "      marco ----> " << p1.getUsername() << endl; // marco
  cout << "   p1.getFullName() should return" << endl;
  cout << "      Marco (@marco) ----> " << p1.getFullName() << endl; // Marco (@marco)
  cout << "----- Testing [TASK B]class Network..." << endl;
  Network nw;
  cout << "   nw.addUser('mario', 'Mario Bro 1') should return true -----> " << nw.addUser("mario", "Mario") << " = true" << endl;
  cout << "   nw.addUser('luigi', 'Luigi') should return true -----> " << nw.addUser("luigi", "Luigi") << " = true" << endl;
  cout << "   nw.addUser('mario', 'Mario Bro 2') should return false -----> " << nw.addUser("mario", "Mario Bro 2") << " = false" << endl;
  cout << "----- Testing [TASK C]class  with following..." << endl;
  cout << "   nw.follow(\"mario\", \"luigi\") makes @mario follow @luigi - should be true ----> " << nw.follow("mario", "luigi") << " = true" << endl;
  cout << "   After creating a new network and adding various users that follow each other, the following digraph was produced: " << endl;
  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
  Network a;
  // add three users
  a.addUser("mario", "Mario");
  a.addUser("luigi", "Luigi");
  a.addUser("yoshi", "Yoshi");

  // make them follow each other
  a.follow("mario", "luigi");
  a.follow("mario", "yoshi");
  a.follow("luigi", "mario");
  a.follow("luigi", "yoshi");
  a.follow("yoshi", "mario");
  a.follow("yoshi", "luigi");

  // add a user who does not follow others
  a.addUser("wario", "Wario");

  // add clone users who follow @mario
  for(int i = 2; i < 6; i++) {
    string usrn = "mario" + to_string(i);
    string dspn = "Mario " + to_string(i);
    a.addUser(usrn, dspn);
    a.follow(usrn, "mario");
  }
  // additionally, make @mario2 follow @luigi
  a.follow("mario2", "luigi");

  a.printDot();
  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
  cout << " The digraph was then visualized on Graphviz as per the instructions and found that the resulting image matched the one shown on the instruction page." << endl << endl;
  return 0;
}
