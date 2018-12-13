/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: Lab 13
Task: Write a template classes
*/

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "my_vector.h"
#include <string>

using std::string;

TEST_CASE("TESTING DOUBLES..."){
  my_vector<double> doubles;
  // ADDING --------------------------
  CHECK(doubles.getCapacity() == 5);
  CHECK(doubles.getNumItems() == 0);
  CHECK(doubles.add(35.1) == true);
  CHECK(doubles.getNumItems() == 1);
  CHECK(doubles.add(35.2) == true);
  CHECK(doubles.getNumItems() == 2);
  CHECK(doubles.add(35.2132) == true);
  CHECK(doubles.getNumItems() == 3);
  CHECK(doubles.add(-35.6) == true);
  CHECK(doubles.getNumItems() == 4);
  CHECK(doubles.add(-8) == true);
  CHECK(doubles.getNumItems() == 5);
  CHECK(doubles.add(10345.9) == true);
  CHECK(doubles.getNumItems() == 6);
  CHECK(doubles.getCapacity() == 10);
  // FINDING & REMOVING -----------------------
  CHECK(doubles.get(3) == -35.6);
  CHECK(doubles.remove(doubles.find(-35.6)) == -35.6);
  CHECK(doubles.get(3) == -8);
  CHECK(doubles.getNumItems() == 5);
  CHECK(doubles.remove(0) == 35.1);
  CHECK(doubles.getNumItems() == 4);
  CHECK(doubles.remove(doubles.find(10345.9)) == 10345.9);
  CHECK(doubles.getNumItems() == 3);
  CHECK(doubles.remove(doubles.find(35.2)) == 35.2);
  CHECK(doubles.getNumItems() == 2);
  CHECK(doubles.remove(doubles.find(-8)) == -8);
  CHECK(doubles.getNumItems() == 1);
  CHECK(doubles.remove(doubles.find(35.2132)) == 35.2132);
  CHECK(doubles.getNumItems() == 0);
  //CHECK(doubles.remove(0) == 0.0);
  CHECK(doubles.getCapacity() == 10);
  // ADDING AT AN INDEX ------------------------
  CHECK(doubles.getNumItems() == 0);
  CHECK(doubles.add(-1.1) == true);
  CHECK(doubles.getNumItems() == 1);
  CHECK(doubles.add(-2.2) == true);
  CHECK(doubles.getNumItems() == 2);
  CHECK(doubles.add(-4.4) == true);
  CHECK(doubles.getNumItems() == 3);
  CHECK(doubles.add(-5.5) == true);
  CHECK(doubles.getNumItems() == 4);
  CHECK(doubles.add(91,0) == true);
  CHECK(doubles.get(0) == 91);
  CHECK(doubles.getNumItems() == 5);
  CHECK(doubles.add(92,3) == true);
  CHECK(doubles.get(3) == 92);
  CHECK(doubles.getNumItems() == 6);
  CHECK(doubles.add(93, 5) == true);
  CHECK(doubles.get(5) == 93);
  CHECK(doubles.getNumItems() == 7);
  CHECK(doubles.add(94,7) == true);
  CHECK(doubles.get(7) == 94);
  CHECK(doubles.getNumItems() == 8);
  CHECK(doubles.add(94,70) == false);
  CHECK(doubles.getNumItems() == 8);
  CHECK(doubles.add(94,8) == true);
  CHECK(doubles.getNumItems() == 9);
  doubles.print();
  // SETTING AT AN INDEX ------------------------
  CHECK(doubles.set(94.1,0) == 91);
  CHECK(doubles.get(0) == 94.1);
  CHECK(doubles.set(1,1) == -1.1);
  CHECK(doubles.get(1) == 1);
  CHECK(doubles.set(2,2) == -2.2);
  CHECK(doubles.get(2) == 2);
  CHECK(doubles.set(3,3) == 92);
  CHECK(doubles.get(3) == 3);
}

TEST_CASE("TESTING INTS..."){
  my_vector<int> ints;
  // ADDING --------------------------
  CHECK(ints.getCapacity() == 5);
  CHECK(ints.getNumItems() == 0);
  CHECK(ints.add(35) == true);
  CHECK(ints.getNumItems() == 1);
  CHECK(ints.add(36) == true);
  CHECK(ints.getNumItems() == 2);
  CHECK(ints.add(36132) == true);
  CHECK(ints.getNumItems() == 3);
  CHECK(ints.add(-35) == true);
  CHECK(ints.getNumItems() == 4);
  CHECK(ints.add(-8) == true);
  CHECK(ints.getNumItems() == 5);
  CHECK(ints.add(-3) == true);
  CHECK(ints.getNumItems() == 6);
  CHECK(ints.getCapacity() == 10);
  // FINDING & REMOVING -----------------------
  CHECK(ints.get(3) == -35);
  CHECK(ints.remove(ints.find(-35)) == -35);
  CHECK(ints.get(3) == -8);
  CHECK(ints.getNumItems() == 5);
  CHECK(ints.remove(0) == 35);
  CHECK(ints.getNumItems() == 4);
  CHECK(ints.remove(ints.find(-3)) == -3);
  CHECK(ints.getNumItems() == 3);
  CHECK(ints.remove(ints.find(36)) == 36);
  CHECK(ints.getNumItems() == 2);
  CHECK(ints.remove(ints.find(-8)) == -8);
  CHECK(ints.getNumItems() == 1);
  CHECK(ints.remove(ints.find(36132)) == 36132);
  CHECK(ints.getNumItems() == 0);
  //CHECK(ints.remove(0) == 0.0);
  CHECK(ints.getCapacity() == 10);
  // ADDING AT AN INDEX ------------------------
  CHECK(ints.getNumItems() == 0);
  CHECK(ints.add(1) == true);
  CHECK(ints.getNumItems() == 1);
  CHECK(ints.add(-2) == true);
  CHECK(ints.getNumItems() == 2);
  CHECK(ints.add(-4) == true);
  CHECK(ints.getNumItems() == 3);
  CHECK(ints.add(-5) == true);
  CHECK(ints.getNumItems() == 4);
  CHECK(ints.add(91,0) == true);
  CHECK(ints.get(0) == 91);
  CHECK(ints.getNumItems() == 5);
  CHECK(ints.add(92,3) == true);
  CHECK(ints.get(3) == 92);
  CHECK(ints.getNumItems() == 6);
  CHECK(ints.add(93, 5) == true);
  CHECK(ints.get(5) == 93);
  CHECK(ints.getNumItems() == 7);
  CHECK(ints.add(94,7) == true);
  CHECK(ints.get(7) == 94);
  CHECK(ints.getNumItems() == 8);
  CHECK(ints.add(94,70) == false);
  CHECK(ints.getNumItems() == 8);
  CHECK(ints.add(94,8) == true);
  CHECK(ints.getNumItems() == 9);
  ints.print();
  // SETTING AT AN INDEX ------------------------
  CHECK(ints.set(94,0) == 91);
  CHECK(ints.get(0) == 94);
  CHECK(ints.set(1,1) == 1);
  CHECK(ints.get(1) == 1);
  CHECK(ints.set(2,2) == -2);
  CHECK(ints.get(2) == 2);
  CHECK(ints.set(3,3) == 92);
  CHECK(ints.get(3) == 3);
  // FIND
  CHECK(ints.find(39) == -1);
}

TEST_CASE("TESTING STRINGS..."){
  my_vector<string> strings;
  // ADDING --------------------------
  CHECK(strings.getCapacity() == 5);
  CHECK(strings.getNumItems() == 0);
  CHECK(strings.add("hello") == true);
  CHECK(strings.getNumItems() == 1);
  CHECK(strings.add("it's me") == true);
  CHECK(strings.getNumItems() == 2);
  CHECK(strings.add("I've been wondering") == true);
  CHECK(strings.getNumItems() == 3);
  CHECK(strings.add("about") == true);
  CHECK(strings.getNumItems() == 4);
  CHECK(strings.add("the way") == true);
  CHECK(strings.getNumItems() == 5);
  CHECK(strings.add("things used to be") == true);
  CHECK(strings.getNumItems() == 6);
  CHECK(strings.getCapacity() == 10);
  // FINDING & REMOVING -----------------------
  CHECK(strings.get(3) == "about");
  CHECK(strings.remove(strings.find("about")) == "about");
  CHECK(strings.get(3) == "the way");
  CHECK(strings.getNumItems() == 5);
  CHECK(strings.remove(0) == "hello");
  CHECK(strings.getNumItems() == 4);
  CHECK(strings.remove(strings.find("things used to be")) == "things used to be");
  CHECK(strings.getNumItems() == 3);
  CHECK(strings.remove(strings.find("it's me")) == "it's me");
  CHECK(strings.getNumItems() == 2);
  CHECK(strings.remove(strings.find("the way")) == "the way");
  CHECK(strings.getNumItems() == 1);
  CHECK(strings.remove(strings.find("I've been wondering")) == "I've been wondering");
  CHECK(strings.getNumItems() == 0);
  CHECK(strings.remove(0) == "");
  CHECK(strings.getCapacity() == 10);
  // ADDING AT AN INDEX ------------------------
  CHECK(strings.getNumItems() == 0);
  CHECK(strings.add("ice cream") == true);
  CHECK(strings.getNumItems() == 1);
  CHECK(strings.add("popcorn") == true);
  CHECK(strings.getNumItems() == 2);
  CHECK(strings.add("watermelon") == true);
  CHECK(strings.getNumItems() == 3);
  CHECK(strings.add("strawberries") == true);
  CHECK(strings.getNumItems() == 4);
  CHECK(strings.add("blueberries",0) == true);
  CHECK(strings.get(0) == "blueberries");
  CHECK(strings.getNumItems() == 5);
  CHECK(strings.add("I like rice.",3) == true);
  CHECK(strings.get(3) == "I like rice.");
  CHECK(strings.getNumItems() == 6);
  CHECK(strings.add("but I also like tamales.", 5) == true);
  CHECK(strings.get(5) == "but I also like tamales.");
  CHECK(strings.getNumItems() == 7);
  CHECK(strings.add("",7) == true);
  CHECK(strings.get(7) == "");
  CHECK(strings.getNumItems() == 8);
  CHECK(strings.add("and mushrooms.",70) == false);
  CHECK(strings.getNumItems() == 8);
  CHECK(strings.add("and korean pancakes.",8) == true);
  CHECK(strings.get(8) == "and korean pancakes.");
  CHECK(strings.getNumItems() == 9);
  strings.print();
  // SETTING AT AN INDEX ------------------------
  CHECK(strings.set("bubbles",0) == "blueberries");
  CHECK(strings.get(0) == "bubbles");
  CHECK(strings.set("buttercup",1) == "ice cream");
  CHECK(strings.get(1) == "buttercup");
  CHECK(strings.set("blossom",2) == "popcorn");
  CHECK(strings.get(2) == "blossom");
  CHECK(strings.set("lavender",3) == "I like rice.");
  CHECK(strings.get(3) == "lavender");
  // FIND
  CHECK(strings.find("mushrooms") == -1);
}
