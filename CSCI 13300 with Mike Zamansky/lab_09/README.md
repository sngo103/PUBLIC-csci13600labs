## lab_09
#### Samantha Ngo | CSCI 133 | 2018 November 12 | Hunter Daedalus Honors

##### This lab is a modified version of CSCI 136's lab_09, but practices implementing and using Catch2, Makefiles, and writing helper functions.

Notes:
- Catch tests not provided for:
  - void move(Coord3D *ppos, Coord3D *pvel, double dt)
  - void deleteCoord3D(Coord3D *p)
  - poem.cpp/poem.h functions, but working memory is demonstrated in main.cpp
- The function Coord3D* createCoord3D(double x, double y, double z) is tested alongside the tests for the following functions:
  - double length(Coord3D *p)
  - Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2)
  