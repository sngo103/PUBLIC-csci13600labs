/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: Lab 10
Task: Write functions using classes and structs to simulate a clock.
*/

#include <string>
#include <iostream>
#include <locale>
#include "timeFunctions.h"
#include <cmath>

using std::string;
using std::cout;
using std::endl;

int minutesSinceMidnight(Time time){
  if(time.h > 23 || time.h < 0 || time.m > 59 || time.m < 0){
    cout << "Invalid input.";
    return -1;
  }
  int input = time.h * 60 + time.m;
  return input;
}

int minutesUntil(Time earlier, Time later){
  if(earlier.h > 23 || earlier.h < 0 || earlier.m > 59 || earlier.m < 0 || later.h > 23 || later.h < 0 || later.m > 59 || later.m < 0){
    return -1;
  }

  /*
  int minutes;
  int earlierMin = minutesSinceMidnight(earlier);
  int laterMin = minutesSinceMidnight(later);
  if(laterMin < earlierMin){
    minutes = 1440 - laterMin + earlierMin;
  } else {
    minutes = laterMin - earlierMin;
  }
  return minutes;
  */

  return minutesSinceMidnight(later) - minutesSinceMidnight(earlier);
}

Time convertFromMinutes(int inputMinutes){
  int hours = inputMinutes / 60;
  int minutes = inputMinutes % 60;
  if(hours > 23){
    hours = hours - 24;
  }
  Time retTime = {hours, minutes};
  return retTime;
}

Time addMinutes(Time time0, int min){
  if(time0.h > 23 || time0.h < 0 || time0.m > 59 || time0.m < 0 || min < 0){
    Time incorrect = {-1,-1};
    return incorrect;
  } else if(min == 0){
    return time0;
  }
  int minutes = time0.h * 60 + time0.m + min;
  Time newTime = convertFromMinutes(minutes);
  Time retTime = newTime;
  return retTime;
}
