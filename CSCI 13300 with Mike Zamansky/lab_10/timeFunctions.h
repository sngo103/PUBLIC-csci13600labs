/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: Lab 10
Task: Write functions using classes and structs to simulate a clock.
*/

#pragma once

class Time {
public:
    int h;
    int m;
};

int minutesSinceMidnight(Time time);
int minutesUntil(Time earlier, Time later);
Time convertFromMinutes(int inputMinutes);
Time addMinutes(Time time0, int min);
