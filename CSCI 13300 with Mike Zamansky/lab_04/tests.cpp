#include "catch.hpp"
#include "box.h"
#include "checkerboard.h"
#include "cross.h"
#include "lower_triangle.h"
#include "upper_triangle.h"
#include "trapezoid.h"
#include "checkerboard3.h"

TEST_CASE("Testing BOX(WIDTH, HEIGHT)..."){
  SECTION("NORMAL CASES"){
    CHECK(box(7, 4) == "*******\n*******\n*******\n*******\n");
    CHECK(box(3, 2) == "***\n***\n");
    CHECK(box(1, 5) == "*\n*\n*\n*\n*\n");
    CHECK(box(-7, 4) == "At least one of your parameters is invalid.");
  }
  SECTION("EDGE CASES"){
    CHECK(box(0, 4) == "\n\n\n\n");
    CHECK(box(3, 0) == "At least one of your parameters is invalid.");
    CHECK(box(0, 0) == "At least one of your parameters is invalid.");
  }
}

TEST_CASE("Testing CHECKERBOARD(WIDTH, HEIGHT)..."){
  SECTION("NORMAL CASES"){
    CHECK(checkerboard(7, 4) == "* * * *\n * * * \n* * * *\n * * * \n");
    CHECK(checkerboard(3, 2) == "* *\n * \n");
    CHECK(checkerboard(1, 5) == "*\n \n*\n \n*\n");
  }
  SECTION("EDGE CASES"){
    CHECK(checkerboard(0, 4) == "\n\n\n\n");
    CHECK(checkerboard(3, 0) == "At least one of your parameters is invalid.");
    CHECK(checkerboard(0, 0) == "At least one of your parameters is invalid.");
    CHECK(checkerboard(-7, 4) == "At least one of your parameters is invalid.");
  }
}

TEST_CASE("Testing CROSS(SIZE)..."){
  SECTION("NORMAL CASES"){
    CHECK(cross(8) == "*      *\n *    * \n  *  *  \n   **   \n   **   \n  *  *  \n *    * \n*      *\n");
    CHECK(cross(7) == "*     *\n *   * \n  * *  \n   *   \n  * *  \n *   * \n*     *\n");
    CHECK(cross(6) == "*    *\n *  * \n  **  \n  **  \n *  * \n*    *\n");
    CHECK(cross(2) == "**\n**\n");
    CHECK(cross(3) == "* *\n * \n* *\n");
    CHECK(cross(1) == "*\n");
  }
  SECTION("EDGE CASES"){
    CHECK(cross(0) == "");
    CHECK(cross(-4) == "");
  }
}

TEST_CASE("Testing LOWER(LENGTH)..."){
  SECTION("NORMAL CASES"){
    CHECK(lower(8) == "*       \n**      \n***     \n****    \n*****   \n******  \n******* \n********\n");
    CHECK(lower(7) == "*      \n**     \n***    \n****   \n*****  \n****** \n*******\n");
    CHECK(lower(6) == "*     \n**    \n***   \n****  \n***** \n******\n");
    CHECK(lower(2) == "* \n**\n");
    CHECK(lower(3) == "*  \n** \n***\n");
    CHECK(lower(1) == "*\n");
  }
  SECTION("EDGE CASES"){
    CHECK(lower(0) == "");
    CHECK(lower(-4) == "");
  }
}

TEST_CASE("Testing UPPER(LENGTH)..."){
  SECTION("NORMAL CASES"){
    CHECK(upper(8) == "********\n******* \n******  \n*****   \n****    \n***     \n**      \n*       \n");
    CHECK(upper(7) == "*******\n****** \n*****  \n****   \n***    \n**     \n*      \n");
    CHECK(upper(6) == "******\n***** \n****  \n***   \n**    \n*     \n");
    CHECK(upper(2) == "**\n* \n");
    CHECK(upper(3) == "***\n** \n*  \n");
    CHECK(upper(1) == "*\n");
  }
  SECTION("EDGE CASES"){
    CHECK(upper(0) == "");
    CHECK(upper(-4) == "");
  }
}

TEST_CASE("Testing TRAPEZOID(WIDTH, HEIGHT)..."){
  SECTION("NORMAL CASES"){
    CHECK(trapezoid(12, 3) == "************\n ********** \n  ********  \n");
    CHECK(trapezoid(5, 3) == "*****\n *** \n  *  \n");
    CHECK(trapezoid(2, 1) == "**\n");
    CHECK(trapezoid(1, 1) == "*\n");
  }
  SECTION("EDGE CASES"){
    CHECK(trapezoid(0, 7) == "Impossible shape!");
    CHECK(trapezoid(-9, 10) == "Impossible shape!");
    CHECK(trapezoid(9, 0) == "Impossible shape!");
    CHECK(trapezoid(-9, -1) == "Impossible shape!");
    CHECK(trapezoid(3, 3) == "Impossible shape!");
    CHECK(trapezoid(8, 8) == "Impossible shape!");
    CHECK(trapezoid(1, 3) == "Impossible shape!");
  }
}

TEST_CASE("Testing CHECKERBOARD3(WIDTH, HEIGHT)..."){
  SECTION("NORMAL CASES"){
    CHECK(checkerboard3(12, 3) == "***   ***   \n***   ***   \n***   ***   \n");
    CHECK(checkerboard3(5, 3) == "***  \n***  \n***  \n");
    CHECK(checkerboard3(2, 1) == "**\n");
    CHECK(checkerboard3(1, 1) == "*\n");
    CHECK(checkerboard3(3, 3) == "***\n***\n***\n");
    CHECK(checkerboard3(8, 8) == "***   **\n***   **\n***   **\n   ***  \n   ***  \n   ***  \n***   **\n***   **\n");
    CHECK(checkerboard3(1, 3) == "*\n*\n*\n");
  }
  SECTION("EDGE CASES"){
    CHECK(checkerboard3(1, 1) == "*\n");
    CHECK(checkerboard3(0, 0) == "At least one of your parameters is invalid.");
    CHECK(checkerboard3(0, 7) == "At least one of your parameters is invalid.");
    CHECK(checkerboard3(-9, 10) == "At least one of your parameters is invalid.");
    CHECK(checkerboard3(9, 0) == "At least one of your parameters is invalid.");
    CHECK(checkerboard3(-9, -1) == "At least one of your parameters is invalid.");
  }
}
