/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: Lab 10
Task: Write functions using classes and structs to simulate a clock.
*/

#include "catch.hpp"
#include "timeFunctions.h"
#include "movieFunctions.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main(){
  cout << "=======================================================================================" << endl;
  cout << "Lab 10: Writing functions using classes and structs to simulate a clock" << endl;
  cout << "=======================================================================================" << endl;
  cout << "----- Testing [TASK A]minutesSinceMidnight() & minutesUntil()..." << endl;
  cout << "  minutesSinceMidnight( {10, 31} ) should be 631 -> " << minutesSinceMidnight({10,31}) << endl;
  cout << "  minutesUntil( {10, 30}, {13, 40} ) should be 190 -> " << minutesUntil( {10, 30}, {13, 40} ) << endl;
  cout << "----- Testing [TASK B]addMinutes()..." << endl;
  cout << "  addMinutes({8,10}, 75).h should be 9 -> " << addMinutes({8,10}, 75).h << endl;
  cout << "  addMinutes({8,10}, 75).m should be 25 -> " << addMinutes({8,10}, 75).m << endl;
  cout << "----- Testing [TASK C]printMovie() & printTimeSlot()..." << endl;
  cout << "  ";
  printMovie({"Back to the Future", COMEDY, 116});
  cout << "\n  ";
  TimeSlot morning = {{"Back to the Future", COMEDY, 116}, {9, 15}};
  TimeSlot daytime = {{"Black Panther", ACTION, 134}, {12, 15}};
  TimeSlot evening = {{"Black Panther", ACTION, 134}, {16, 45}};
  TimeSlot great = {{"Wonder Woman", ACTION, 141}, {18, 15}};
  TimeSlot alsoGreat = {{"Hidden Figures", DRAMA, 127}, {11, 45}};
  cout << "\n  ";
  printTimeSlot(morning);
  cout << endl;
  cout << "\n  ";
  printTimeSlot(daytime);
  cout << endl;
  cout << "\n  ";
  printTimeSlot(evening);
  cout << endl;
  cout << "\n  ";
  printTimeSlot(great);
  cout << endl;
  cout << "\n  ";
  printTimeSlot(alsoGreat);
  cout << endl;
  cout << "----- Testing [TASK D]scheduleAfter()..." << endl;
  Movie ratatouille = {"Ratatouille", COMEDY, 111};
  cout << " -The movie 'Ratatouille' should be scheduled right after 'Back to the Future,' which ends at 11:11." << endl;
  TimeSlot next = scheduleAfter(morning, ratatouille);
  cout << "   - It should start at 11:11 -> " << next.startTime.h << ":" << next.startTime.m << endl;
  cout << "----- Testing [TASK E]timeOverlap()..." << endl;
  TimeSlot ts1 = {{"Back to the Future I", COMEDY, 116}, {9, 15}};
  TimeSlot ts2 = {{"Back to the Future II", COMEDY, 116}, {10, 15}};
  cout << "  Back to the Future I & Back to the Future II are both 116 minutes long." << endl;
  cout << "    Back to the Future I starts at 9:15" << endl;
  cout << "    Back to the Future II starts at 10:15" << endl;
  cout << "  They should overlap and return true -> " << timeOverlap(ts1, ts2) << " = true" << endl;
  cout << "======================================================================================" << endl << endl;
  return 0;
}
