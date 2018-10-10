#include "catch.hpp"
#include "pig.h"

TEST_CASE("Testing PigLatinify"){
  CHECK(piglatinify("hello")=="ellohay");
  CHECK(piglatinify("crazy")=="azycray");
  REQUIRE(piglatinify("world")=="orldway");
  REQUIRE(piglatinify("atlas")=="atlasay");
  REQUIRE(piglatinify("error")=="erroray");
}
