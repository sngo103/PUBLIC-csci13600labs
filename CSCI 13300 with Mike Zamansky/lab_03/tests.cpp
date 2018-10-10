#include "catch.hpp"
#include "east-storage.h"
#include "minmax.h"
#include "compare.h"
#include "reverse-order.h"

TEST_CASE("Testing EAST-STORAGE.CPP..."){
  SECTION("NORMAL CASES"){
    CHECK(east_storage("05/20/2016") == 79.88);
    CHECK(east_storage("01/10/2016") == 72.37);
    CHECK(east_storage("01/11/2016") == 72.44);
  }
  SECTION("FIRST AND LAST DAY OF YEAR"){
  CHECK(east_storage("01/01/2016") == 71.99);
  CHECK(east_storage("12/31/2016") == 58.12);
  }
  SECTION("LEAP DAY"){
    CHECK(east_storage("02/29/2016") == 79.29);
  }

  SECTION("OUT OF RANGE"){
    CHECK(east_storage("05/20/2018") == -1);
    CHECK(east_storage("02/30/2016") == -1);
    CHECK(east_storage("02/31/2016") == -1);
  }
  SECTION("INCORRECT FORMAT"){
    CHECK(east_storage("05/2016") == -1);
    CHECK(east_storage("06") == -1);
    CHECK(east_storage("05/2016/20") == -1);
    CHECK(east_storage("012016/20") == -1);
    CHECK(east_storage("0121062016") == -1);
  }
}

TEST_CASE("Testing MINMAX.CPP..."){
  CHECK(min_storage() == 49.34);
  CHECK(max_storage() == 81);
}

TEST_CASE("Testing COMPARE.CPP..."){
  SECTION("NORMAL CASES"){
    CHECK(compare("10/01/2016", "10/03/2016") == "10/01/2016 West\n10/02/2016 West\n10/03/2016 West\n");
    CHECK(compare("01/10/2016", "01/11/2016") == "01/10/2016 West\n01/11/2016 West\n");
    CHECK(compare("05/17/2016", "05/20/2016") == "05/17/2016 West\n05/18/2016 West\n05/19/2016 West\n05/20/2016 West\n");
    CHECK(compare("06/16/2016", "06/17/2016") == "06/16/2016 East\n06/17/2016 East\n");
    CHECK(compare("09/15/2016", "09/15/2016") == "09/15/2016 Equal\n");
  }
  SECTION("OUT OF RANGE"){
    CHECK(compare("05/20/2018", "05/22/2018") == "One of your dates is incorrect.");
    }
  SECTION("INCORRECT FORMAT"){
    CHECK(compare("05/2016", "05/20/2018") == "One of your dates is incorrect.");
    CHECK(compare("06", "05/20/2018") == "One of your dates is incorrect.");
    CHECK(compare("05/2016/20", "05/20/28") == "One of your dates is incorrect.");
    CHECK(compare("012016/20", "05/20/2018") == "One of your dates is incorrect.");
    CHECK(compare("0121062016", "05/20/2018") == "One of your dates is incorrect.");
  }
}

TEST_CASE("Testing REVERSE-ORDER.CPP..."){
  SECTION("NORMAL CASES"){
    CHECK(reverse("10/01/2016", "10/03/2016") == "10/03/2016 572.07 ft\n10/02/2016 572.3 ft\n10/01/2016 572.53 ft\n");
    CHECK(reverse("01/10/2016", "01/11/2016") == "01/11/2016 584.56 ft\n01/10/2016 583.35 ft\n");
    CHECK(reverse("05/17/2016", "05/20/2016") == "05/20/2016 590.17 ft\n05/19/2016 590.21 ft\n05/18/2016 590.17 ft\n05/17/2016 590.16 ft\n");
    CHECK(reverse("06/16/2016", "06/17/2016") == "06/17/2016 585.98 ft\n06/16/2016 586.19 ft\n");
    CHECK(reverse("09/15/2016", "09/15/2016") == "09/15/2016 575.75 ft\n");
  }
  SECTION("OUT OF RANGE"){
    CHECK(reverse("05/20/2018", "05/22/2018") == "One of your dates is incorrect.");
    }
  SECTION("INCORRECT FORMAT"){
    CHECK(reverse("05/2016", "05/20/2018") == "One of your dates is incorrect.");
    CHECK(reverse("06", "05/20/2018") == "One of your dates is incorrect.");
    CHECK(reverse("05/2016/20", "05/20/28") == "One of your dates is incorrect.");
    CHECK(reverse("012016/20", "05/20/2018") == "One of your dates is incorrect.");
    CHECK(reverse("0121062016", "05/20/2018") == "One of your dates is incorrect.");
  }
}
