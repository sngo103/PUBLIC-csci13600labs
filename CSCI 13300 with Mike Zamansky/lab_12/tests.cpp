/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: Lab 12
Task: Write functions using classes, structs, and constructors.
*/

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "social.h"

TEST_CASE("Testing CLASS Profile..."){
  SECTION("LOADED CONSTRUCTORS"){
    Profile p1("tarma1", "Tarma Roving");
    CHECK(p1.getUsername() == "tarma1");
    CHECK(p1.getFullName() == "Tarma Roving (@tarma1)");
    Profile p2("saraWithAnH", "Sarah Chen");
    CHECK(p2.getUsername() == "saraWithAnH");
    CHECK(p2.getFullName() == "Sarah Chen (@saraWithAnH)");
  }
  SECTION("DEFAULT CONSTRUCTORS"){
    Profile p1;
    CHECK(p1.getUsername() == "Username not set.");
    CHECK(p1.getFullName() == "Display name not set.");
  }
}

TEST_CASE("Testing CLASS Network..."){
  SECTION("[ALL CASES] bool addUser(string usrn, string dspn)"){
    Network n = Network();
    CHECK(n.addUser("user1", "user 1") == true);
    CHECK(n.addUser("user2", "user 2") == true);
    CHECK(n.addUser("user3", "user 3") == true);
    CHECK(n.addUser("user4", "user 4") == true);
    CHECK(n.addUser("user5", "user 5") == true);
    CHECK(n.addUser("user6", "user 6") == true);
    CHECK(n.addUser("user7", "user 7") == true);
    CHECK(n.addUser("user8", "user 8") == true);
    CHECK(n.addUser("user9", "user 9") == true);
    CHECK(n.addUser("user10", "user 10") == true);
    CHECK(n.addUser("user11", "user 11") == true);
    CHECK(n.addUser("user12", "user 12") == true);
    CHECK(n.addUser("user13", "user 13") == true);
    CHECK(n.addUser("user14", "user 14") == true);
    CHECK(n.addUser("user15", "user 15") == true);
    CHECK(n.addUser("user    16", "false user 1") == false);
    CHECK(n.addUser("super&man", "false user 2") == false);
    CHECK(n.addUser("12#12", "false user 3") == false);
    CHECK(n.addUser("c00lerthanU!", "false user 4") == false);
    CHECK(n.addUser("user15", "false user 5") == false);
    CHECK(n.addUser("user16", "user 16") == true);
    CHECK(n.addUser("user17", "user 17") == true);
    CHECK(n.addUser("user18", "user 18") == true);
    CHECK(n.addUser("user19", "user 19") == true);
    CHECK(n.addUser("", "No Name") == false);
    CHECK(n.addUser("user20", "user 20") == true);
    CHECK(n.addUser("superman", "Rejected superman") == false);
  }
}
