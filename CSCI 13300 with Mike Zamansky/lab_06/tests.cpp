/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: Lab 6
Task: Write cryptographic functions
*/

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "crypto.h"


TEST_CASE("Testing char shiftChar(char c, int rshift)..."){
  SECTION("NORMAL CASES"){
    CHECK( shiftChar('a', 1) == 'b');
    CHECK( shiftChar('a', 2) == 'c');
    CHECK( shiftChar('a', 3) == 'd');
    CHECK( shiftChar('z', 4) == 'd');
    CHECK( shiftChar('d', 3) == 'g');
    CHECK( shiftChar('D', 3) == 'G');
    CHECK( shiftChar('F', 0) == 'F');
  }
  SECTION("EDGE CASES"){
    CHECK( shiftChar(' ', 1) == ' ');
    CHECK( shiftChar('-', 1) == '-');
    CHECK( shiftChar('y', 5) == 'd');
    CHECK( shiftChar('a', -1) == 'a');
  }
}

TEST_CASE("Testing string encryptCaesar(string plaintext, int rshift)..."){
  SECTION("NORMAL CASES"){
    CHECK( encryptCaesar( "Way to Go!", 5 ) == "Bfd yt Lt!");
    CHECK( encryptCaesar( "How are you?", 1 ) == "Ipx bsf zpv?");
    CHECK( encryptCaesar( "Who in the world ", 4 ) == "Als mr xli asvph ");
  }
  SECTION("EDGE CASES"){
    CHECK( encryptCaesar("", 10 ) == "");
  }
}

TEST_CASE("Testing string encryptVigenere(string plaintext, string keyword)..."){
  SECTION("NORMAL CASES"){
    CHECK( encryptVigenere( "Hello, World!", "cake" ) == "Jevpq, Wyvnd!");
    CHECK( encryptVigenere( "text to encode", "key" ) == "divd xm orayhc");
    CHECK( encryptVigenere( "Let the great world spin...", "welcome" ) == "Hie vvq knilv kavhh drwz...");
  }
  SECTION("EDGE CASES"){
    CHECK( encryptVigenere("", "popcorn" ) == "");
    CHECK( encryptVigenere("popcorn", "" ) == "popcorn");
  }
}

TEST_CASE("Testing string decryptCaesar(string ciphertext, int rshift)..."){
  SECTION("NORMAL CASES"){
    CHECK( decryptCaesar( "Bfd yt Lt!", 5 ) == "Way to Go!");
    CHECK( decryptCaesar( "Ipx bsf zpv?", 1 ) == "How are you?");
    CHECK( decryptCaesar( "Als mr xli asvph ", 4 ) == "Who in the world " );
  }
  SECTION("EDGE CASES"){
    CHECK( decryptCaesar("", 10 ) == "");
  }
}

TEST_CASE("Testing string decryptVigenere(string ciphertext, string keyword)..."){
  SECTION("NORMAL CASES"){
    CHECK( decryptVigenere( "Jevpq, Wyvnd!", "cake" ) == "Hello, World!");
    CHECK( decryptVigenere( "divd xm orayhc", "key" ) == "text to encode");
    CHECK( decryptVigenere( "Hie vvq knilv kavhh drwz...", "welcome" ) == "Let the great world spin...");
  }
  SECTION("EDGE CASES"){
    CHECK( decryptVigenere("", "popcorn" ) == "");
    CHECK( decryptVigenere("popcorn", "" ) == "popcorn");
  }
}
