/*
Author: Samantha Ngo
Course: CSCI-135
Instructor: Genady Maryash
Date: 2018 November 20
Assignment: Project 3B
Task: Improve the function onAction so that a dwarf collects at least 100 pieces of lumber per day.
*/

#include <cstdlib>
#include <cmath>
#include <iostream>
#include "bot.h"

using namespace std;

const int MAX_ROWS = 40;
const int MAX_COLS = 40;
const int MAX_NUM = 10;

int ROWS;  // global variables
int COLS;
int NUM;

/* onStart:
An Initialization procedure called at the start of the game.
You can use it to initialize certain global variables, or do
something else before the actual simulation starts.
Parameters:
    rows: number of rows
    cols: number of columns
    num:  number of dwarfs
    log:  a cout-like log */

void onStart(int rows, int cols, int num, std::ostream &log) {
  log << "Start!" << endl; // Print a greeting message

  ROWS = rows; // Save values in global variables
  COLS = cols;
  NUM = num;
}

/* onAction:
A procedure called each time an idle dwarf is choosing
their next action.
Parameters:
    dwarf:   dwarf choosing an action
    day:     day (1+)
    hours:   number of hours in 24-hour format (0-23)
&    minutes: number of minutes (0-59)
    log:     a cout-like log  */
void onAction(Dwarf &dwarf, int day, int hours, int minutes, ostream &log) {
  // Get current position of the dwarf
  int r = dwarf.row();
  int c = dwarf.col();
  int rr = 0;
  int cc = 0;

  if(hours <= 16){
    if (dwarf.look(r, c+1) == PINE_TREE || dwarf.look(r, c+1) == APPLE_TREE){
      // If there is a pine tree or fence, chop it
      log << "Found lumber on my east -- chop" << endl;
      dwarf.start_chop(EAST);
      return;
    } else if (dwarf.look(r, c-1) == PINE_TREE || dwarf.look(r, c-1) == APPLE_TREE){
      log << "Found lumber on my west -- chop" << endl;
      dwarf.start_chop(WEST);
      return;
    } else if (dwarf.look(r+1, c) == PINE_TREE || dwarf.look(r+1, c) == APPLE_TREE){
      log << "Found lumber on my south -- chop" << endl;
      dwarf.start_chop(SOUTH);
      return;
    } else if (dwarf.look(r-1, c) == PINE_TREE || dwarf.look(r-1, c) == APPLE_TREE){
      log << "Found lumber on my north -- chop" << endl;
      dwarf.start_chop(NORTH);
      return;
    } else {
      //ROW + 3

      if(c == COLS - 1 && r != ROWS - 3){
        if(dwarf.look(r+3, c-1) == EMPTY){
          dwarf.start_walk(r+3, c-1);
        } else {
          rr = rand() % ROWS;
          cc = rand() % COLS;
          while(dwarf.look(rr,cc) != EMPTY){
            rr = rand() % ROWS;
            cc = rand() % COLS;
          }
          dwarf.start_walk(rr, cc);
          log << "Walk RANDOMLY to " << rr << " " << cc << endl;
        }
      } else if(c == 0 && r != ROWS - 3){
        if(dwarf.look(r+3, 1) == EMPTY){
          dwarf.start_walk(r+3, 1);
        } else {
          rr = rand() % ROWS;
          cc = rand() % COLS;
          while(dwarf.look(rr,cc) != EMPTY){
            rr = rand() % ROWS;
            cc = rand() % COLS;
          }
        }
        dwarf.start_walk(rr, cc);
        log << "Walk to " << rr << " " << cc << endl;
      } else {
        if(r % 2 == 0 && dwarf.look(r, c+1) == EMPTY){
          dwarf.start_walk(r, c+1);
        } else if(r % 2 != 0 && dwarf.look(r, c-1) == EMPTY){
          dwarf.start_walk(r, c-1);
        } else if (r == 0) {
          rr = rand() % ROWS;
          cc = rand() % COLS;
          while(dwarf.look(rr,cc) != EMPTY){
            rr = rand() % ROWS;
            cc = rand() % COLS;
          }
          dwarf.start_walk(rr, cc);
          log << "Walk RANDOMLY to " << rr << " " << cc << endl;
        } else {
          rr = rand() % ROWS;
          cc = rand() % COLS;
          while(dwarf.look(rr,cc) != EMPTY){
            rr = rand() % ROWS;
            cc = rand() % COLS;
          }
          dwarf.start_walk(rr, cc);
          log << "Walk RANDOMLY to " << rr << " " << cc << endl;
        }
      }
    }
  } else {
    if (dwarf.look(r, c+1) == PINE_TREE || dwarf.look(r, c+1) == APPLE_TREE){
      // If there is a pine tree or fence, chop it
      log << "Found lumber on my east -- chop" << endl;
      dwarf.start_chop(EAST);
      return;
    } else if (dwarf.look(r, c-1) == PINE_TREE || dwarf.look(r, c-1) == APPLE_TREE){
      log << "Found lumber on my west -- chop" << endl;
      dwarf.start_chop(WEST);
      return;
    } else if (dwarf.look(r+1, c) == PINE_TREE || dwarf.look(r+1, c) == APPLE_TREE){
      log << "Found lumber on my south -- chop" << endl;
      dwarf.start_chop(SOUTH);
      return;
    } else if (dwarf.look(r-1, c) == PINE_TREE || dwarf.look(r-1, c) == APPLE_TREE){
      log << "Found lumber on my north -- chop" << endl;
      dwarf.start_chop(NORTH);
      return;
    } else if(r <= 15 && r >= 11 && c > 2 && c < MAX_COLS - 2){
      if(dwarf.look(r,c+1) == FENCE && dwarf.look(r,c-1) == FENCE){
	if(dwarf.look(r+1,c) == EMPTY){
	  dwarf.start_walk(r+1,c);
	} else if(dwarf.look(r-1,c) == EMPTY) {
	  dwarf.start_walk(r-1,c);
	}
	return;
      } else if (dwarf.look(r-1,c) == EMPTY && dwarf.look(r-1,c-1) == FENCE && dwarf.look(r-1, c+1) == FENCE){
	dwarf.start_build(NORTH);
	return;
      } else if(dwarf.look(r+1,c) == EMPTY && dwarf.look(r+1,c-1) == FENCE && dwarf.look(r+1, c+1) == FENCE){
	dwarf.start_build(SOUTH);
	return;
      }  else if (dwarf.look(r, c-1) == EMPTY){
        log << "Build fence on my west -- chop" << endl;
        dwarf.start_build(WEST);
        return;
      } else if(dwarf.look(r, c+1) == EMPTY){
	dwarf.start_walk(r,c+1);
	return;
      } else if(dwarf.look(r+1,c) == EMPTY && dwarf.look(r+2,c) == EMPTY){
	dwarf.start_walk(r+1,c);
	return;
      } else if(dwarf.look(r-1,c) == EMPTY && dwarf.look(r-2,c) == EMPTY){
	dwarf.start_walk(r-1,c);
	return;
      } else {
	rr = 15 - (rand() % 5);
	cc = rand() % 2;
	while(dwarf.look(rr,cc) != EMPTY){
          rr = 15 - (rand() % 5);
          cc = rand() % 2;
        }
        dwarf.start_walk(rr,cc);
        log << "Walk RANDOMLY to " << rr << " " << cc << endl;
      }
    } else {
      rr = 15 - (rand() % 4);
      cc = 3 + rand() % 6;
      while(dwarf.look(rr,cc) != EMPTY){
	rr = 15 - (rand() % 4);
	cc = 3 + rand() % 6;
      }
      dwarf.start_walk(rr,cc);
      log << "Walk RANDOMLY to " << rr << " " << cc << endl;
    }	

    /*
    log << "Now, we're going to build fences." << endl;
    if(dwarf.col() < 9){
      if (dwarf.look(r, c-1) == EMPTY){
        // If there is a pine tree or fence, chop it
        log << "Build fence on my west -- chop" << endl;
        dwarf.start_build(WEST);
        return;
      } else if (dwarf.look(r+1, c) == EMPTY){
        log << "Build fence on my south -- chop" << endl;
        dwarf.start_build(SOUTH);
        return;
      } else if (dwarf.look(r-1, c) == EMPTY){
        log << "Build fence on my north -- chop" << endl;
        dwarf.start_build(NORTH);
        return;
	} else if(dwarf.look(r, c+1) == EMPTY){
	dwarf.start_walk(r,c+1);
	return;
      }	else {
        rr = 12 - (rand() % 7);
        cc = 12 - (rand() % 7);
        while(dwarf.look(rr,cc) != EMPTY){
          rr = 12 - (rand() % 7);
          cc = 12 - (rand() % 7);
        }
        dwarf.start_walk(rr,cc);
        log << "Walk RANDOMLY to " << rr << " " << cc << endl;
      }
    } else {
      if (dwarf.look(r, c+1) == EMPTY){
        log << "Build fence on my east -- chop" << endl;
        dwarf.start_build(EAST);
        return;
      }  else if (dwarf.look(r+1, c) == EMPTY){
        log << "Build fence on my south -- chop" << endl;
        dwarf.start_build(SOUTH);
        return;
      } else if (dwarf.look(r-1, c) == EMPTY){
        log << "Build fence on my north -- chop" << endl;
        dwarf.start_build(NORTH);
        return;
      } else if(dwarf.look(r, c-1) == EMPTY){
	dwarf.start_walk(r,c-1);
	return;
      }	else {
        rr = 12 - (rand() % 7);
        cc = 12 - (rand() % 7);
        while(dwarf.look(rr,cc) != EMPTY){
          rr = 12 - (rand() % 7);
          cc = 12 - (rand() % 7);
        }
        dwarf.start_walk(rr,cc);
        log << "Walk RANDOMLY to " << rr << " " << cc << endl;
      }
    }
    */
  
  }
  return;
}
