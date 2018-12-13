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

void randomizeWalk(Dwarf &dwarf){
  int rr = rand() % ROWS;
  int cc = rand() % COLS;
  while(dwarf.look(rr,cc) != EMPTY){
    rr = rand() % ROWS;
    cc = rand() % COLS;
  }
  dwarf.start_walk(rr, cc);
  return;
}

bool chopPine(Dwarf &dwarf){
  int r = dwarf.row();
  int c = dwarf.col();

  if (dwarf.look(r, c+1) == PINE_TREE){
    dwarf.start_chop(EAST);
    return true;
  } else if (dwarf.look(r, c-1) == PINE_TREE){
    dwarf.start_chop(WEST);
    return true;
  } else if (dwarf.look(r+1, c) == PINE_TREE){
    dwarf.start_chop(SOUTH);
    return true;
  } else if (dwarf.look(r-1, c) == PINE_TREE){
    dwarf.start_chop(NORTH);
    return true;
  } else {
    return false;
  }
}

bool chopApple(Dwarf &dwarf){
  int r = dwarf.row();
  int c = dwarf.col();

  if (dwarf.look(r, c+1) == APPLE_TREE){
    dwarf.start_chop(EAST);
    return true;
  } else if (dwarf.look(r, c-1) == APPLE_TREE){
    dwarf.start_chop(WEST);
    return true;
  } else if (dwarf.look(r+1, c) == APPLE_TREE){
    dwarf.start_chop(SOUTH);
    return true;
  } else if (dwarf.look(r-1, c) == APPLE_TREE){
    dwarf.start_chop(NORTH);
    return true;
  } else {
    return false;
  }
}

bool pickApple(Dwarf &dwarf){
  int r = dwarf.row();
  int c = dwarf.col();

  if (dwarf.look(r, c+1) == APPLE_TREE){
    dwarf.start_pick(EAST);
    return true;
  } else if (dwarf.look(r, c-1) == APPLE_TREE){
    dwarf.start_pick(WEST);
    return true;
  } else if (dwarf.look(r+1, c) == APPLE_TREE){
    dwarf.start_pick(SOUTH);
    return true;
  } else if (dwarf.look(r-1, c) == APPLE_TREE){
    dwarf.start_pick(NORTH);
    return true;
  } else {
    return false;
  }
}

bool pickPumpkin(Dwarf &dwarf){
  int r = dwarf.row();
  int c = dwarf.col();

  if (dwarf.look(r, c+1) == PUMPKIN){
    dwarf.start_pick(EAST);
    return true;
  } else if (dwarf.look(r, c-1) == PUMPKIN){
    dwarf.start_pick(WEST);
    return true;
  } else if (dwarf.look(r+1, c) == PUMPKIN){
    dwarf.start_pick(SOUTH);
    return true;
  } else if (dwarf.look(r-1, c) == PUMPKIN){
    dwarf.start_pick(NORTH);
    return true;
  } else {
    return false;
  }
}

void selfDefense(Dwarf &dwarf){
  int r = dwarf.row();
  int c = dwarf.col();
  
  if(dwarf.look(r, c+1) == EMPTY){
    dwarf.start_build(EAST);
    return;
  } else if(dwarf.look(r, c-1) == EMPTY){
    dwarf.start_build(WEST);
    return;
  } else if(dwarf.look(r+1,c) == EMPTY){
    dwarf.start_build(SOUTH);
    return;
  } else if(dwarf.look(r-1,c) == EMPTY){
    dwarf.start_build(NORTH);
    return;
  } else {
    pickApple(dwarf);
    return;
  }
}

void breakDefense(Dwarf &dwarf){
  int r = dwarf.row();
  int c = dwarf.col();

  if(dwarf.look(r, c+1) == FENCE){
    dwarf.start_chop(EAST);
    return;
  } else if(dwarf.look(r, c-1) == FENCE){
    dwarf.start_chop(WEST);
    return;
  } else if(dwarf.look(r+1,c) == FENCE){
    dwarf.start_chop(SOUTH);
    return;
  } else if(dwarf.look(r-1,c) == FENCE){
    dwarf.start_chop(NORTH);
    return;
  }
}

void searchPine(Dwarf &dwarf){
  int r = dwarf.row();
  int c = dwarf.col();

  if(!chopPine(dwarf)){
    if(c == COLS - 1 && r != ROWS - 3){
      if(dwarf.look(r+3, c-1) == EMPTY){
	dwarf.start_walk(r+3, c-1);
      } else {
	randomizeWalk(dwarf);
      }
    } else if(c == 0 && r != ROWS - 3){
      if(dwarf.look(r+3, 1) == EMPTY){
	dwarf.start_walk(r+3, 1);
      } else {
	randomizeWalk(dwarf);
      }
    } else {
      if(r % 2 == 0 && dwarf.look(r, c+1) == EMPTY){
	dwarf.start_walk(r, c+1);
      } else if(r % 2 != 0 && dwarf.look(r, c-1) == EMPTY){
	dwarf.start_walk(r, c-1);
      } else {
	randomizeWalk(dwarf);
      }
    }
  }
  return;
}

void searchPickApple(Dwarf &dwarf){
  int r = dwarf.row();
  int c = dwarf.col();

  if(!pickApple(dwarf)){
    if(c == COLS - 1 && r != ROWS - 3){
      if(dwarf.look(r+3, c-1) == EMPTY){
	dwarf.start_walk(r+3, c-1);
      } else {
	randomizeWalk(dwarf);
      }
    } else if(c == 0 && r != ROWS - 3){
      if(dwarf.look(r+3, 1) == EMPTY){
	dwarf.start_walk(r+3, 1);
      } else {
	randomizeWalk(dwarf);
      }
    } else {
      if(r % 2 == 0 && dwarf.look(r, c+1) == EMPTY){
	dwarf.start_walk(r, c+1);
      } else if(r % 2 != 0 && dwarf.look(r, c-1) == EMPTY){
	dwarf.start_walk(r, c-1);
      } else {
	randomizeWalk(dwarf);
      }
    }
  }
  return;
}

void searchPumpkin(Dwarf &dwarf){
  int r = dwarf.row();
  int c = dwarf.col();

  if(!pickPumpkin(dwarf)){
    if(c == COLS - 1 && r != ROWS - 3){
      if(dwarf.look(r+3, c-1) == EMPTY){
	dwarf.start_walk(r+3, c-1);
      } else {
	randomizeWalk(dwarf);
      }
    } else if(c == 0 && r != ROWS - 3){
      if(dwarf.look(r+3, 1) == EMPTY){
	dwarf.start_walk(r+3, 1);
      } else {
	randomizeWalk(dwarf);
      }
    } else {
      if(r % 2 == 0 && dwarf.look(r, c+1) == EMPTY){
	dwarf.start_walk(r, c+1);
      } else if(r % 2 != 0 && dwarf.look(r, c-1) == EMPTY){
	dwarf.start_walk(r, c-1);
      } else {
	randomizeWalk(dwarf);
      }
    }
  }
  return;
}

// Facilitates looking for and chopping down apple trees
void searchApple(Dwarf &dwarf){
  int r = dwarf.row();
  int c = dwarf.col();

  if(!chopApple(dwarf)){
    if(c == COLS - 1 && r != ROWS - 3){
      if(dwarf.look(r+3, c-1) == EMPTY){
	dwarf.start_walk(r+3, c-1);
      } else {
	randomizeWalk(dwarf);
      }
    } else if(c == 0 && r != ROWS - 3){
      if(dwarf.look(r+3, 1) == EMPTY){
	dwarf.start_walk(r+3, 1);
      } else {
	randomizeWalk(dwarf);
      }
    } else {
      if(r % 2 == 0 && dwarf.look(r, c+1) == EMPTY){
	dwarf.start_walk(r, c+1);
      } else if(r % 2 != 0 && dwarf.look(r, c-1) == EMPTY){
	dwarf.start_walk(r, c-1);
      } else {
	randomizeWalk(dwarf);
      }
    }
  }
  return;
}

void handleFencing(Dwarf &dwarf){
  int r = dwarf.row();
  int c = dwarf.col();

  if(r > ROWS/2 || r < ROWS/4 || c > COLS/2){
    int rr = ROWS/2 - (rand() % 4);
    int cc = 3 + (rand() % 3);
    while(dwarf.look(rr,cc) != EMPTY){
      rr = ROWS/2 - (rand() % 4);
      cc = 3 + (rand() % 3);
    }
    dwarf.start_walk(rr, cc);
  } else if(dwarf.look(r,c+1) == FENCE && dwarf.look(r,c-1) == FENCE){
    if(dwarf.look(r+1,c) == EMPTY){
      dwarf.start_walk(r+1,c);
      return;
    } else if(dwarf.look(r-1,c) == EMPTY) {
      dwarf.start_walk(r-1,c);
      return;
    }
  } else if (dwarf.look(r-1,c) == EMPTY && dwarf.look(r-1,c-1) == FENCE && dwarf.look(r-1, c+1) == FENCE){
    dwarf.start_build(NORTH);
    return;
  } else if(dwarf.look(r+1,c) == EMPTY && dwarf.look(r+1,c-1) == FENCE && dwarf.look(r+1, c+1) == FENCE){
    dwarf.start_build(SOUTH);
    return;
  } else if (dwarf.look(r, c-1) == EMPTY){
    dwarf.start_build(WEST);
    return;
  } else if(dwarf.look(r,c+1) == EMPTY){
    dwarf.start_walk(r,c+1);
    return;
  } else if(dwarf.look(r+1,c) == EMPTY && dwarf.look(r+2,c) == EMPTY){
    dwarf.start_walk(r+2,c);
    return;
  } else if(dwarf.look(r-1,c) == EMPTY && dwarf.look(r-2,c) == EMPTY){
    dwarf.start_walk(r-2,c);
    return;
  } else {
    int rr = ROWS/2 - (rand() % 4);
    int cc = 3 + (rand() % 3);
    while(dwarf.look(rr,cc) != EMPTY){
      rr = ROWS/2 - (rand() % 4);
      cc = 3 + (rand() % 3);
    }
  }
  return;
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
  if(hours < 8 && day == 1){
    searchPine(dwarf);
  } else if(hours >= 18 || hours < 8){
    selfDefense(dwarf);
  } else if(hours < 9){
    breakDefense(dwarf);
  } else {
    if(day < 4){
      searchPine(dwarf);
    } else if(day < 5){
      searchPickApple(dwarf);
    } else if (day <= 6 && dwarf.lumber() > 350){
      handleFencing(dwarf);
    } else {
      searchPumpkin(dwarf);
    }
    return;
  }
  
  //selfDefense(dwarf);
  //breakDefense(dwarf);
  //chopPine(dwarf);
  return;
}
