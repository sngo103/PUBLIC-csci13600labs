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

template <class T>
class my_vector{
  public:
    // Constructors
    my_vector();
    my_vector(T a, T b, T c, T d, T e);
    // Display
    void print();
    // Accessors
    int getCapacity(); // Get max storage capacity
    int getNumItems(); // Get number of items in array
    int find(T item); // Find index of item; -1 if not found
    T get(int i); // Get item at index i
    // Mutators
    T set(T item, int i); // Set item at index i to new item
    bool add(T item); // Add at end; if array too small, resize
    bool add(T item, int i); // Add item at index; if array too small, resize
    T remove(int i); // Remove item
  private:
    T *data = new T[5];
    int numItems;
    int storageCapacity;
    bool resize(int newSize);
};

#include "my_vector.hxx"
