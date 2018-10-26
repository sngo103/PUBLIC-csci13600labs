/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: Lab 5
Task: Write Math functions to be reused as helper functions
*/

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "math.h"


TEST_CASE("Testing bool isDivisibleBy(int n, int d)..."){
  SECTION("NORMAL CASES"){
    CHECK(isDivisibleBy(100, 25) == true);
    CHECK(isDivisibleBy(35, 17) == false);
    CHECK(isDivisibleBy(4, 2) == true);
    CHECK(isDivisibleBy(4, 4) == true);
    CHECK(isDivisibleBy(2, 4) == false);
  }
  SECTION("EDGE CASES"){
    CHECK(isDivisibleBy(4, -4) == true);
    CHECK(isDivisibleBy(9, 0) == false);
    CHECK(isDivisibleBy(0, 9) == true);
    CHECK(isDivisibleBy(9, 3.7) == true);
  }
}

TEST_CASE("Testing bool isPrime(int n);..."){
  SECTION("NORMAL CASES"){
    CHECK(isPrime(4) == false);
    CHECK(isPrime(3) == true);
    CHECK(isPrime(29) == true);
    CHECK(isPrime(39) == false);
  }
  SECTION("EDGE CASES"){
    CHECK(isPrime(-5) == false);
    CHECK(isPrime(0) == false);
    CHECK(isPrime(1) == false);
    CHECK(isPrime(2) == true);
  }
}

TEST_CASE("Testing int nextPrime(int n)..."){
  SECTION("NORMAL CASES"){
    CHECK(nextPrime(2) == 3);
    CHECK(nextPrime(3) == 5);
    CHECK(nextPrime(17) == 19);
    CHECK(nextPrime(30) == 31);
  }
  SECTION("EDGE CASES"){
    CHECK(nextPrime(-13) == 2);
    CHECK(nextPrime(0) == 2);
    CHECK(nextPrime(1) == 2);
    CHECK(nextPrime(20) == 23);
  }
}

TEST_CASE("Testing int countPrimes(int a, int b);..."){
  SECTION("NORMAL CASES"){
    CHECK(countPrimes(3, 10) == 3);
    CHECK(countPrimes(0,100) == 25);
    CHECK(countPrimes(10, 20) == 4);
    CHECK(countPrimes(-4, 80) == 22);
  }
  SECTION("EDGE CASES"){
    CHECK(countPrimes(-9,-2) == 0);
    CHECK(countPrimes(2,2) == 1);
    CHECK(countPrimes(0,0) == 0);
    CHECK(countPrimes(0, 2) == 1);
    CHECK(countPrimes(2, 0) == -1);
  }
}

TEST_CASE("Testing bool isTwinPrime(int n);..."){
  SECTION("NORMAL CASES"){
    CHECK(isTwinPrime(1) == false);
    CHECK(isTwinPrime(3) == true);
    CHECK(isTwinPrime(5) == true);
    CHECK(isTwinPrime(19) == false);
    CHECK(isTwinPrime(23) == false);
  }
  SECTION("EDGE CASES"){
    CHECK(isTwinPrime(-9) == false);
    CHECK(isTwinPrime(0.5) == false);
    CHECK(isTwinPrime(-7) == false);
    CHECK(isTwinPrime(2) == false);
  }
}

TEST_CASE("Testing int nextTwinPrime(int n);..."){
  SECTION("NORMAL CASES"){
    CHECK(nextTwinPrime(2) == 3);
    CHECK(nextTwinPrime(3) == 5);
    CHECK(nextTwinPrime(4) == 5);
    // CHECK(nextTwinPrime(7) == 59);
  }
  SECTION("EDGE CASES"){
    CHECK(nextTwinPrime(-4) == 3);
    CHECK(nextTwinPrime(2) == 3);
    // CHECK(nextTwinPrime(2.5) == 3);
    // CHECK(nextTwinPrime(100) == 109);
  }
}

TEST_CASE("Testing int largestTwinPrime(int a, int b);..."){
  SECTION("NORMAL CASES"){
    CHECK(largestTwinPrime(0,10) == 5);
    CHECK(largestTwinPrime(10,17) == -1);
    CHECK(largestTwinPrime(0,3) == 3);
  }
  SECTION("EDGE CASES"){
    CHECK(largestTwinPrime(0, 0) == -1);
    CHECK(largestTwinPrime(0, 2) == -1);
    CHECK(largestTwinPrime(0, 1) == -1);
    CHECK(largestTwinPrime(-7,-3) == -1);
    CHECK(largestTwinPrime(-3,-7) == -1);
  }
}
