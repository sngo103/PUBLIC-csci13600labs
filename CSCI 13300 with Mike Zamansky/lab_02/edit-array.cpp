/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: Lab 2C
Task: Creates an array of 10 integers and a simple interface for the user to change
the values within the array.
*/

#include <iostream>
#include <string>

using namespace std;

// Initialize array
int myData[10];

// Sets up array with 1s.
int setupArray(){
  for (int i = 0; i < 10; i++){
    myData[i] = 1;
  }
  return 0;
}

// Prints out array using for loop
int displayArray(){
  // cout << "Displaying array..." << endl
  cout << endl;
  for (int i = 0; i < 10; i++){
    cout << myData[i] << " ";
  }
  cout << endl << endl;
  // cout << "\n...complete." << endl;
  return 0;
}

// Given a correct index and value, changes array at designated location and
// returns previous value in designated location.
int editArray(int index, int value){
  int oldValue = myData[index];
  myData[index] = value;
  // cout << "Array edited.";
  displayArray();
  return oldValue;
}

// Main function for extracting input and running code
int main() {
  // Initialize variables
  int index = 0;
  int value = 1;

  // Sets up array with 1s.
  setupArray();

  // While loop checks if index in range before executing edit. If not in range,
  // exits.
  while((index < 10) && (index >= 0)){
    editArray(index, value);

    // Record input index in variable. If input incorrect type, ask again.
    cout << "Input index: ";
    cin >> index;
    while (cin.fail()){
      cout << "*** Please enter an integer value only." << endl;
      cout << "Input index: ";
      cin.clear();
      cin.ignore(10000, '\n');
      cin >> index;
    };
    
    if(index >= 10 || index < 0){
      break;
    }

    // Record input index in variable. If input incorrect type, ask again.
    cout << "Input value: ";
    cin >> value;
    while (cin.fail() || false){
      cout << "*** Please enter an integer value only." << endl;
      cout << "Input value: ";
      cin.clear();
      cin.ignore(10000, '\n');
      cin >> value;
    };
  }

  // Exit statement
  cout << "\nIndex out of range. Exit." << endl;
  return 0;
}
