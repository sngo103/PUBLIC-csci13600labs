/*
Author: Samantha Ngo
Course: CSCI 13500
Instructor: Genadiy Maryash
Assignment: Exercise 5.16
Task: Given a day, month, and year, returns the day of the week the date falls
on.
*/

#include <iostream>

// To be changed when I get used to using the new form and after asking for
// some clarifications
using namespace std;
using std::cout;
using std::string;

// *Expects parameter to be corrected beforehand if necessary and then given in
// correct format; does not check if parameter is in correct format
string calcWeekday(int day, int month, int year){
  string retDay;
  int weekday = -1;
  weekday = (day + 5 + ((26 * (month + 1))/10) + ((5 * (year % 100))/4)
                    + ((21 * (year/100))/4)) % 7;
  if(month == 13 || month == 14){
    weekday = ((day + 5 + ((26 * (month + 1))/10) + ((5 * (year % 100))/4)
                      + ((21 * (year/100))/4)) - 1 ) % 7;

  }
  if(weekday == 0){
    return "Monday";
  } else if( weekday == 1){
    return "Tuesday";
  } else if( weekday == 2){
    return "Wednesday";
  } else if( weekday == 3){
    return "Thursday";
  } else if( weekday == 4){
    return "Friday";
  } else if( weekday == 5){
    return "Saturday";
  } else if( weekday == 6){
    return "Sunday";
  }
}

int getDay(){
  cout << "Enter day: ";
  int day;
  cin >> day;
  while(cin.fail() || day < 1 || day > 31){
    cout << "Please enter a correct integer.\n";
    cout << "Enter day: ";
    cin.clear();
    cin.ignore(10000, '\n');
    cin >> day;
  }
  return day;
}

int getMonth(){
  cout << "Enter month in the form of an integer 1-12: ";
  int month;
  cin >> month;
  while(cin.fail() || month < 1 || month > 12){
    cout << "Please enter a correct integer in the given range.\n";
    cout << "Enter month: ";
    cin.clear();
    cin.ignore(10000, '\n');
    cin >> month;
  }
  if(month == 1){
    return 13;
  } else if(month == 2){
    return 14;
  } else {
    return month;
  }
}

int getYear(){
  cout << "Enter year: ";
  int year;
  cin >> year;
  while(cin.fail() || year < 1582){
    cout << "Please enter a correct year greater than 1581.\n";
    cout << "Enter year: ";
    cin.clear();
    cin.ignore(10000, '\n');
    cin >> year;
  }
  return year;
}

int zeller(){
  cout << "This date falls on a " << calcWeekday(getDay(), getMonth(), getYear()) << "." << endl;
  return 0;
}

int main(){
  while(true){
    zeller();
  }
  return 0;
}
