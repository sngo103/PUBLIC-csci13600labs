## lab_10
#### Samantha Ngo | CSCI 133 | 2018 November 24 | Hunter Daedalus Honors

##### This lab is a modified version of CSCI 136's lab_10, but practices implementing and using Catch2, Makefiles, and writing helper functions.

Notes:
- The helper functions printMovie(Movie m) and printTimeSlot(Timeslot ts) are tested briefly in main.c, but are not officially tested in tests.cpp because I didn't see a significant need to do so since they were mainly just printing functions.
- The function TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie) assumes input is correctly formatted and within the 24-hour bounds.
- The function bool timeOverlap(TimeSlot ts1, TimeSlot ts2) assumes correct input and that ts1's startTime is before or at the same time as ts2's startTime, regardless of movie durations.
