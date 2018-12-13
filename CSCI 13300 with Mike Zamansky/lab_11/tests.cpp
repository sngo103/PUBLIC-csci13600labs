/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: Lab 11
Task: Write functions using recursion.
*/

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "recursion.h"

TEST_CASE("Testing int sumRange(int left, int right)..."){
  SECTION("NORMAL CASES"){
    CHECK( sumRange(1, 4) == 10);
    CHECK( sumRange(2, 11) == 65);
    CHECK( sumRange(-4, 14) == 95);
    CHECK( sumRange(21, 28) == 196);
  }
  SECTION("EDGE CASES"){
    CHECK( sumRange(4, 4) == 4);
    CHECK( sumRange(4, 1) == 10);
    CHECK( sumRange(-1, -4) == -10);
  }
}

TEST_CASE("Testing int sumArray(int *arr, int size)..."){
  SECTION("NORMAL CASES"){
    int arrayA[10] = {12, 17, -5, 3, 7, -15, 27, 5, 13, -21};
    int *a = arrayA;
    CHECK( sumArray(a, 10) == 43);
    int arrayB[10] = {1, 17, -5, 3, 7, 5, 4, 3, 2, -1};
    int *b = arrayB;
    CHECK( sumArray(b, 10) == 36);
    int arrayC[3] = {12, 17, -5};
    int *c = arrayC;
    CHECK( sumArray(c, 3) == 24);
    int arrayD[14] = {12, 17, -5, 3, 7, -15, 27, 5, 13, -21, 5, 5, 9, 12};
    int *d = arrayD;
    CHECK( sumArray(d, 14) == 74);
    int arrayE[6] = {-12, -17, -5, -3, -7, -15};
    int *e = arrayE;
    CHECK( sumArray(e, 6) == -59);
  }
  SECTION("EDGE CASES"){
    int arrayA[10] = {12};
    int *a = arrayA;
    CHECK( sumArray(a, 1) == 12);
    int arrayB[1];
    int *b = arrayB;
    CHECK( sumArray(b, 0) == 0);
  }
}

TEST_CASE("Testing bool isAlphanumeric(string s)..."){
  SECTION("NORMAL CASES"){
    CHECK(isAlphanumeric("1234567890") == true);
    CHECK(isAlphanumeric("abcdefghijklmnopqrstuvwxyz") == true);
    CHECK(isAlphanumeric("ABCDEFGHIJKLMNOPQRSTUVWXYZ") == true);
    CHECK(isAlphanumeric("hello world") == false);
    CHECK(isAlphanumeric("helloworld") == true);
    CHECK(isAlphanumeric("helloWORLD301") == true);
    CHECK(isAlphanumeric("it's") == false);
    CHECK(isAlphanumeric("(so)") == false);
    CHECK(isAlphanumeric("a()") == false);
    CHECK(isAlphanumeric("a~!@#") == false);
    CHECK(isAlphanumeric("a*&") == false);
    CHECK(isAlphanumeric("a*") == false);
    CHECK(isAlphanumeric("a&") == false);
    CHECK(isAlphanumeric("a``") == false);
    CHECK(isAlphanumeric("a~") == false);
    CHECK(isAlphanumeric("a@") == false);
    CHECK(isAlphanumeric("a!") == false);
    CHECK(isAlphanumeric("a#") == false);
    CHECK(isAlphanumeric("a$") == false);
    CHECK(isAlphanumeric("a%") == false);
    CHECK(isAlphanumeric("a^") == false);
    CHECK(isAlphanumeric("a(") == false);
    CHECK(isAlphanumeric("a)") == false);
    CHECK(isAlphanumeric("a-") == false);
    CHECK(isAlphanumeric("a=") == false);
    CHECK(isAlphanumeric("a+") == false);
    CHECK(isAlphanumeric("a_") == false);
    CHECK(isAlphanumeric("a}") == false);
    CHECK(isAlphanumeric("a[]") == false);
    CHECK(isAlphanumeric("a>") == false);
    CHECK(isAlphanumeric("a,") == false);
  }
  SECTION("EDGE CASES"){
    CHECK(isAlphanumeric("") == true);
    CHECK(isAlphanumeric("'a'") == false);
  }
}

TEST_CASE("Testing bool nestedParens(string s)..."){
  SECTION("NORMAL CASES"){
    CHECK(nestedParens("()") == true);
    CHECK(nestedParens("()()") == false);
    CHECK(nestedParens("((()))") == true);
    CHECK(nestedParens("a()") == false);
    CHECK(nestedParens("()a") == false);
    CHECK(nestedParens("((())") == false);
    CHECK(nestedParens("(((") == false);
    CHECK(nestedParens("((0))") == false);
    CHECK(nestedParens("((-))") == false);
  }
  SECTION("EDGE CASES"){
    CHECK(nestedParens("") == true);
    CHECK(nestedParens("(a)") == false);
    CHECK(nestedParens("()(())") == false);
  }
}
