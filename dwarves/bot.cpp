/*
Author: Samantha Ngo
Course: CSCI-135
Instructor: Genady Maryash
Date: 2018 November 20
Assignment: Project 3A
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
    minutes: number of minutes (0-59)
    log:     a cout-like log  */

/*
void onAction(Dwarf &dwarf, int day, int hours, int minutes, ostream &log) {
  // Get current position of the dwarf
  int r = dwarf.row();
  int c = dwarf.col();

  // Look if there is a tree on the right from the dwarf
  if (dwarf.look(r, c+1) == PINE_TREE) {
    // If there is a pine tree, chop it
    log << "Found a tree -- chop" << endl;
    dwarf.start_chop(EAST);
    return;
  }
  else {
    // Otherwise, move to a random location
    int rr = rand() % ROWS;
    int cc = rand() % COLS;
    log << "Walk to " << rr << " " << cc << endl;
    dwarf.start_walk(rr, cc);
    return;
  }
}
*/

void onAction(Dwarf &dwarf, int day, int hours, int minutes, ostream &log) {
  // Get current position of the dwarf
  int r = dwarf.row();
  int c = dwarf.col();
  int rr = 0;
  int cc = 0;

  if (dwarf.look(r, c+1) == PINE_TREE || dwarf.look(r, c+1) == FENCE){
    // If there is a pine tree or fence, chop it
    log << "Found lumber on my east -- chop" << endl;
    dwarf.start_chop(EAST);
    return;
  } else if (dwarf.look(r, c-1) == PINE_TREE || dwarf.look(r, c-1) == FENCE){
    log << "Found lumber on my west -- chop" << endl;
    dwarf.start_chop(WEST);
    return;
  } else if (dwarf.look(r+1, c) == PINE_TREE || dwarf.look(r+1, c) == FENCE){
    log << "Found lumber on my south -- chop" << endl;
    dwarf.start_chop(SOUTH);
    return;
  } else if (dwarf.look(r-1, c) == PINE_TREE || dwarf.look(r-1, c) == FENCE){
    log << "Found lumber on my north -- chop" << endl;
    dwarf.start_chop(NORTH);
    return;
  } else {
    //ROW + 3

    if(c == COLS - 1 && r != ROWS - 3){
	if(dwarf.look(r+3, c-1) == EMPTY){
	  dwarf.start_walk(r+3, c-1);
	} else {
	  rr = r - rand() % 4;
	  cc = c - rand() % 4;
	  while(dwarf.look(rr,cc) != EMPTY){
	    rr = r - rand() % 4;
	    cc = c - rand() % 4;
	  }
	  dwarf.start_walk(rr, cc);
	  log << "Walk RANDOMLY to " << rr << " " << cc << endl;
	}
    } else if(c == 0 && r == ROWS - 3){
      if(dwarf.look(r+3, 1) == EMPTY){
	dwarf.start_walk(r+3, 1);
      } else {
	rr = r - rand() % 4;
	cc = c - rand() % 4;
	while(dwarf.look(rr,cc) != EMPTY){
	  rr = r - rand() % 4;
	  cc = c - rand() % 4;
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
	rr = r + rand() % 4;
	cc = c + rand() % 4;
	while(dwarf.look(rr,cc) != EMPTY){
	  rr = r + rand() % 4;
	  cc = c + rand() % 4;
	}
	dwarf.start_walk(rr, cc);
	log << "Walk RANDOMLY to " << rr << " " << cc << endl;
      } else {
	rr = r - rand() % 4;
	cc = c - rand() % 4;
	while(dwarf.look(rr,cc) != EMPTY){
	  rr = r - rand() % 4;
	  cc = c - rand() % 4;
	}
	dwarf.start_walk(rr, cc);
	log << "Walk RANDOMLY to " << rr << " " << cc << endl;
      }
    }
  }
    /*
    if(c == COLS - 1 && r != ROWS - 1 && dwarf.look(r+1, c-1) == EMPTY){
      dwarf.start_walk(r+1, c-1);
      log << "Reached end of row" << endl;
    } else if(c == 0 && r != ROWS - 1 && dwarf.look(r+1, c+1) == EMPTY){
      dwarf.start_walk(r+1, c+1);
      log << "Reached beginning of row" << endl;
    } else if(c % 2 != 0 && r != ROWS - 1 && dwarf.look(r, c+1) == EMPTY){
      dwarf.start_walk(r, c+1);
      log << "Move right" << endl;
    } else if(c % 2 == 0 && r != ROWS - 1 && dwarf.look(r, c-1) == EMPTY){
      dwarf.start_walk(r, c-1);
      log << "Move left" << endl;
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

    if((c == COLS - 2) && r != ROWS - 2){
	if(dwarf.look(r+2, 1) == EMPTY){
	  dwarf.start_walk(r+2, 1);
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
    } else if((c == COLS - 2 || c == 0) && r == ROWS - 2){
      rr = rand() % ROWS;
      cc = rand() % COLS;
      while(dwarf.look(rr,cc) != EMPTY){
	rr = rand() % ROWS;
	cc = rand() % COLS;
      }
      dwarf.start_walk(rr, cc);
      log << "Walk to " << rr << " " << cc << endl;
    } else {
      if(dwarf.look(r, c+2) == EMPTY){
	dwarf.start_walk(r, c+2);
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
    
    if((c == COLS - 2 || c == 0) && r != ROWS - 2){
      if(c == COLS - 2){
	if(dwarf.look(r+2, c-1) == EMPTY){
	  dwarf.start_walk(r+2, c-1);
	} else {
	  rr = rand() % ROWS;
	  cc = rand() % COLS;
	  while(dwarf.look(rr,cc) != EMPTY){
	    rr = rand() % ROWS;
	    cc = rand() % COLS;
	  }
	  dwarf.start_walk(rr, cc);
	  log << "Walk to " << rr << " " << cc << endl;
	}
      } else {
	if(dwarf.look(r+2, c+1) == EMPTY){
	  dwarf.start_walk(r+2, c+1);
	} else {
	  rr = rand() % ROWS;
	  cc = rand() % COLS;
	  while(dwarf.look(rr,cc) != EMPTY){
	    rr = rand() % ROWS;
	    cc = rand() % COLS;
	  }
	  dwarf.start_walk(rr, cc);
	  log << "Walk to " << rr << " " << cc << endl;
	}
      }
    } else if((c == COLS - 2 || c == 0) && r == ROWS - 2){
      rr = rand() % ROWS;
      cc = rand() % COLS;
      while(dwarf.look(rr,cc) != EMPTY){
	rr = rand() % ROWS;
	cc = rand() % COLS;
      }
      dwarf.start_walk(rr, cc);
      log << "Walk to " << rr << " " << cc << endl;
    } else {
      if(dwarf.look(r, c+1) == EMPTY){
	dwarf.start_walk(r, c+1);
      } else {
	rr = rand() % ROWS;
	cc = rand() % COLS;
	while(dwarf.look(rr,cc) != EMPTY){
	  rr = rand() % ROWS;
	  cc = rand() % COLS;
	}
	dwarf.start_walk(rr, cc);
	log << "Walk to " << rr << " " << cc << endl;
      }
      
      if(r % 2 == 0){
	if(dwarf.look(r, c+1) == EMPTY){
	  dwarf.start_walk(r, c+1);
	} else {
	   rr = rand() % ROWS;
	   cc = rand() % COLS;
	   while(dwarf.look(rr,cc) != EMPTY){
	     rr = rand() % ROWS;
	     cc = rand() % COLS;
	   }
	   dwarf.start_walk(rr, cc);
	   log << "Walk to " << rr << " " << cc << endl;
	}
      } else if(dwarf.look(r, c-1) == EMPTY){
	if(dwarf.look(r, c-1) == EMPTY){
	  dwarf.start_walk(r, c-1);
	} else {
	  rr = rand() % ROWS;
	  cc = rand() % COLS;
	  while(dwarf.look(rr,cc) != EMPTY){
	    rr = rand() % ROWS;
	    cc = rand() % COLS;
	  }
	  dwarf.start_walk(rr, cc);
	  log << "Walk to " << rr << " " << cc << endl;
	}
      } else {
	  rr = rand() % ROWS;
	  cc = rand() % COLS;
	  while(dwarf.look(rr,cc) != EMPTY){
	    rr = rand() % ROWS;
	    cc = rand() % COLS;
	  }
	  dwarf.start_walk(rr, cc);
	  log << "Walk to " << rr << " " << cc << endl;
      }
    }
      */
  return;
}



