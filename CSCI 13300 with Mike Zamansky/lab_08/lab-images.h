/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: Lab 8
Task: Write programs to manipulate .pgm images; reads a PGM image from the file
"inImage.pgm", and outputs a modified image to "outImage.pgm"
*/

#pragma once
#include <cassert>
#include <cstdlib>
#include <fstream>
#include <string>

using std::string;

const int MAX_H = 512;
const int MAX_W = 512;

void readImage(int image[MAX_H][MAX_W], int &height, int &width);
void writeImage(string filename, int image[MAX_H][MAX_W], int height, int width);
void invert(int image[MAX_H][MAX_W], int height, int width);
void invert_half(int image[MAX_H][MAX_W], int height, int width);
void box(int image[MAX_H][MAX_W], int height, int width);
void frame(int image[MAX_H][MAX_W], int height, int width);
void scale(int image[MAX_H][MAX_W], int height, int width);
void pixelate(int image[MAX_H][MAX_W], int height, int width);
