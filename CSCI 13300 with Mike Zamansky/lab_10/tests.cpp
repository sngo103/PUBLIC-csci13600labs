/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: Lab 10
Task: Write functions using classes and structs to simulate a clock.
*/

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "timeFunctions.h"
#include "movieFunctions.h"

TEST_CASE("Testing int minutesSinceMidnight(Time time)..."){
  SECTION("NORMAL CASES"){
    Time x = {10, 40};
    CHECK( minutesSinceMidnight(x) == 640);
    x = {1,40};
    CHECK( minutesSinceMidnight(x) == 100);
    x = {2,0};
    CHECK( minutesSinceMidnight(x) == 120);
    x = {14,14};
    CHECK( minutesSinceMidnight(x) == 854);
    x = {7,57};
    CHECK( minutesSinceMidnight(x) == 477);
  }
  SECTION("INCORRECT INPUT CASES"){
    Time x = {-9,40};
    CHECK( minutesSinceMidnight(x) == -1);
    x = {24,0};
    CHECK( minutesSinceMidnight(x) == -1);
    x = {2,60};
    CHECK( minutesSinceMidnight(x) == -1);
    x = {3,-3};
    CHECK( minutesSinceMidnight(x) == -1);
  }
  SECTION("EDGE CASES"){
    Time x = {23,59};
    CHECK( minutesSinceMidnight(x) == 1439);
    x = {12,0};
    CHECK( minutesSinceMidnight(x) == 720);
    x = {0,0};
    CHECK( minutesSinceMidnight(x) == 0);
    x = {0,1};
    CHECK( minutesSinceMidnight(x) == 1);
  }
}

TEST_CASE("Testing int minutesUntil(Time earlier, Time later)..."){
  SECTION("NORMAL CASES"){
    Time x = {10, 40};
    Time y = {10, 50};
    CHECK( minutesUntil(x, y) == 10);
    x = {1,40};
    y = {2,39};
    CHECK( minutesUntil(x, y) == 59);
    x = {1,0};
    y = {23,0};
    CHECK( minutesUntil(x, y) == 1320);
    x = {10,14};
    y = {11,40};
    CHECK( minutesUntil(x, y) == 86);
    x = {7,57};
    y = {17,57};
    CHECK( minutesUntil(x, y) == 600);
  }
  SECTION("INCORRECT INPUT CASES"){
    Time x = {-9,40};
    Time y = {1,40};
    CHECK( minutesUntil(x, y) == -1);
    x = {24,0};
    y = {1,40};
    CHECK( minutesUntil(x, y) == -1);
    x = {2,60};
    y = {1,40};
    CHECK( minutesUntil(x, y) == -1);
    x = {3,-3};
    y = {1,40};
    CHECK( minutesUntil(x, y) == -1);
    x = {3,3};
    y = {1,400};
    CHECK( minutesUntil(x, y) == -1);
  }
  SECTION("EDGE CASES"){
    Time x = {23,0};
    Time y = {1,0};
    CHECK( minutesUntil(x, y) == -1320);
    x = {23,59};
    y = {0,0};
    CHECK( minutesUntil(x, y) == -1439);
    x = {2,0};
    y = {1,40};
    CHECK( minutesUntil(x, y) == -20);
    x = {1,40};
    y = {1,40};
    CHECK( minutesUntil(x, y) == 0);
  }
}

TEST_CASE("Testing HELPER FUNCTION: Time convertFromMinutes(int inputMinutes)..."){
  SECTION("NORMAL CASES"){
    CHECK(convertFromMinutes(120).h == 2);
    CHECK(convertFromMinutes(1550).h == 1);
  }
}

TEST_CASE("Testing Time addMinutes(Time time0, int min)..."){
  SECTION("NORMAL CASES"){
    CHECK( addMinutes({0,0}, 70).h == 1);
    CHECK( addMinutes({0,0}, 70).m == 10);
    CHECK( addMinutes({0,24}, 70).h == 1);
    CHECK( addMinutes({0,24}, 70).m == 34);
    CHECK( addMinutes({8,10}, 75).h == 9);
    CHECK( addMinutes({8,10}, 75).m == 25);
    CHECK( addMinutes({9,37}, 100).h == 11);
    CHECK( addMinutes({9,37}, 100).m == 17);
  }
  SECTION("INCORRECT INPUT CASES"){
    CHECK( addMinutes({24,0}, 70).h == -1);
    CHECK( addMinutes({24,0}, 70).m == -1);
    CHECK( addMinutes({0,0}, -70).h == -1);
    CHECK( addMinutes({0,0}, -70).m == -1);
  }
  SECTION("EDGE CASES"){
    CHECK( addMinutes({12,56}, 0).h == 12);
    CHECK( addMinutes({12,56}, 0).m == 56);
    CHECK( addMinutes({0,0}, 0).h == 0);
    CHECK( addMinutes({0,0}, 0).m == 0);
    CHECK( addMinutes({23,59}, 1).h == 0);
    CHECK( addMinutes({23,59}, 1).m == 0);
  }
}

TEST_CASE("Testing TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie)..."){
  SECTION("NORMAL CASES"){
    Movie m = {"Ratatouille", COMEDY, 111};
    TimeSlot t = {{"Back to the Future", COMEDY, 116}, {9, 15}};
    CHECK( scheduleAfter(t, m).startTime.h == 11);
    CHECK( scheduleAfter(t, m).startTime.m == 11);
    m = {"Next Movie", COMEDY, 111};
    t = {{"Back to the Future", COMEDY, 90}, {9, 35}};
    CHECK( scheduleAfter(t, m).startTime.h == 11);
    CHECK( scheduleAfter(t, m).startTime.m == 5);
    m = {"Next Movie", COMEDY, 111};
    t = {{"Back to the Future", COMEDY, 155}, {19, 45}};
    CHECK( scheduleAfter(t, m).startTime.h == 22);
    CHECK( scheduleAfter(t, m).startTime.m == 20);
  }
  SECTION("EDGE CASES"){
    Movie m = {"Ratatouille", COMEDY, 111};
    TimeSlot t = {{"Back to the Future", COMEDY, 116}, {23, 15}};
    CHECK( scheduleAfter(t, m).startTime.h == 1);
    CHECK( scheduleAfter(t, m).startTime.m == 11);
    m = {"Next Movie", COMEDY, 111};
    t = {{"Back to the Future", COMEDY, 0}, {19, 35}};
    CHECK( scheduleAfter(t, m).startTime.h == 19);
    CHECK( scheduleAfter(t, m).startTime.m == 35);
  }
}

TEST_CASE("Testing bool timeOverlap(TimeSlot ts1, TimeSlot ts2)..."){
  SECTION("NORMAL CASES"){
    TimeSlot ts1 = {{"Back to the Future", COMEDY, 116}, {9, 15}};
    TimeSlot ts2 = {{"Back to the Future", COMEDY, 116}, {10, 15}};
    CHECK( timeOverlap(ts1, ts2) == true);
    ts1 = {{"Back to the Future", COMEDY, 116}, {9, 15}};
    ts2 = {{"Back to the Future", COMEDY, 116}, {11, 15}};
    CHECK( timeOverlap(ts1, ts2) == false);
    ts1 = {{"Back to the Future", COMEDY, 0}, {9, 15}};
    ts2 = {{"Back to the Future", COMEDY, 10}, {9, 25}};
    CHECK( timeOverlap(ts1, ts2) == false);
    ts1 = {{"Back to the Future", COMEDY, 200}, {19, 30}};
    ts2 = {{"Back to the Future", COMEDY, 116}, {22, 15}};
    CHECK( timeOverlap(ts1, ts2) == true);
  }
  SECTION("EDGE CASES"){
    TimeSlot ts1 = {{"Back to the Future", COMEDY, 116}, {9, 15}};
    TimeSlot ts2 = {{"Back to the Future", COMEDY, 116}, {11, 11}};
    CHECK( timeOverlap(ts1, ts2) == false);
    ts1 = {{"Back to the Future", COMEDY, 116}, {9, 15}};
    ts2 = {{"Back to the Future", COMEDY, 116}, {11, 10}};
    CHECK( timeOverlap(ts1, ts2) == true);
  }
}
