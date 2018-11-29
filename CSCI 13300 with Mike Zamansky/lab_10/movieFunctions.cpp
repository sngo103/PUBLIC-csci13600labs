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
#include "movieFunctions.h"
#include <cmath>

using std::string;
using std::cout;
using std::endl;

string genreToString(Genre g){
  string retStr;
  switch (g) {
      case ACTION   : retStr = "ACTION"; break;
      case COMEDY   : retStr = "COMEDY"; break;
      case DRAMA    : retStr = "DRAMA";  break;
      case ROMANCE  : retStr = "ROMANCE"; break;
      case THRILLER : retStr = "THRILLER"; break;
  }
  return retStr;
}

void printMovie(Movie mv){
    cout << mv.title << " " << genreToString(mv.genre) << " (" << mv.duration << " min)";
}

void printTimeSlot(TimeSlot ts){
  Time endTime;
  endTime = addMinutes(ts.startTime, ts.movie.duration);
  cout << ts.movie.title << " " << genreToString(ts.movie.genre) << " (" << ts.movie.duration << " min) "
       << "[starts at " << ts.startTime.h << ":" << ts.startTime.m << ", ends by " << endTime.h << ":"
       << endTime.m << "]";
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie){
  Time endTime;
  endTime = addMinutes(ts.startTime, ts.movie.duration);
  TimeSlot next = {nextMovie, {0,0}};
  next.startTime = endTime;
  return next;
}

// *This function assumes correct input and that ts1's startTime is before or
// at the same time as ts2's startTime, regardless of movie durations.
bool timeOverlap(TimeSlot ts1, TimeSlot ts2){
  Time endTime;
  endTime = addMinutes(ts1.startTime, ts1.movie.duration);
  if(minutesUntil(endTime, ts2.startTime) < 0){
    return true;
  } else {
    return false;
  }
}
