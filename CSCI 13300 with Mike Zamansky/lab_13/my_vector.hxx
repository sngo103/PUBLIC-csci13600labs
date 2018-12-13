/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: Lab 13
Task: Write a template class
*/

#pragma once
#include <string>

using std::string;
using std::cout;
using std::endl;

template <class T>
my_vector<T>::my_vector(){
  storageCapacity = 5;
  numItems = 0;
}

template <class T>
my_vector<T>::my_vector(T a, T b, T c, T d, T e){
    data[0] = a;
    data[1] = b;
    data[2] = c;
    data[3] = d;
    data[4] = e;
    storageCapacity = 5;
    numItems = 5;
}

template <class T>
void my_vector<T>::print(){
    for (int i = 0; i < numItems; i++) {
      std::cout << data[i] << " | ";
    }
    std::cout << "\n";
};

template <class T>
// Get max storage capacity
int my_vector<T>::getCapacity(){
  return storageCapacity;
}

template <class T>
// Get number of items in array
int my_vector<T>::getNumItems(){
  return numItems;
}

template <class T>
// Find index of item; -1 if not found
int my_vector<T>::find(T item){
  for(int i = 0; i < numItems; i++){
    if(data[i] == item){
      return i;
    }
  }
  return -1;
}

template <class T>
// Get item at index i
T my_vector<T>::get(int i){
  if(i < 0 || i >= numItems){
    T nullItem;
    cout << "Error: Index out of range for get() -- null item returned: " << nullItem << endl;
    return nullItem;
  } else {
    return data[i];
  }
}

template <class T>
// Set item at index i to new item; returns old item
T my_vector<T>::set(T item, int i){
  if(i < 0 || i >= numItems){
    T nullItem;
    cout << "Error: Index out of range for set() -- null item returned: " << nullItem << endl;
    return nullItem;
  } else {
    T oldItem = data[i];
    data[i] = item;
    return oldItem;
  }
}

template <class T>
// Add at end; if array too small, resize
bool my_vector<T>::add(T item){
  if(numItems == storageCapacity){
    resize(storageCapacity * 2);
  }
  data[numItems] = item;
  numItems += 1;
  return true;
}

template <class T>
// Add item at index; if array too small, resize
bool my_vector<T>::add(T item, int i){
  if(i < 0 || i > numItems){
    return false;
  } else if(i == numItems){
    resize(i + 1);
  }
  if(i >= numItems){
    data[i] = item;
  } else {
    for(int x = numItems; x > i; x--){
      data[x] = data[x-1];
    }
    data[i] = item;
  }
  numItems += 1;
  return true;
}

template <class T>
// Remove item at index
T my_vector<T>::remove(int i){
  if(i < 0 || i >= numItems){
    T nullItem;
    cout << "Error: Index out of range for remove() -- null item returned: " << nullItem << endl;
    return nullItem;
  }
  T removedItem = data[i];
  for(int x = i; x < numItems - 1; x++){
      data[x] = data[x+1];
  }
  numItems -= 1;
  return removedItem;
}

template <class T>
// PRIVATE: resize array to new size
// Assumes new size is greater than current max capacity; otherwise, do nothing
// Returns true if data successfully resized, false if failed and/or nothing has
// changed.
bool my_vector<T>::resize(int newSize){
  if (newSize <= storageCapacity){
    return false;
  } else {
    T *newArr = new T[newSize];
    for (int i = 0; i < numItems; i++) {
      newArr[i] = data[i];
    }
    data = newArr;
    newArr = nullptr;
    storageCapacity = newSize;
    return false;
  }
}












  // End here
