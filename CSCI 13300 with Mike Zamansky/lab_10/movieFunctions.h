/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: Lab 10
Task: Write functions using classes and structs to simulate a clock.
*/

#pragma once
#include <string>
#include "timeFunctions.h"

using std::string;

enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

class Movie {
public:
    string title;
    Genre genre;     // only one genre per movie
    int duration;    // in minutes
};

class TimeSlot {
public:
    Movie movie;     // what movie
    Time startTime;  // when it starts
};

string genreToString(Genre g);
void printMovie(Movie m);
void printTimeSlot(TimeSlot ts);
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie);
bool timeOverlap(TimeSlot ts1, TimeSlot ts2); 
