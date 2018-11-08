/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: Lab 8
Task: Write programs to manipulate .pgm images; reads a PGM image from the file
"inImage.pgm", and outputs a modified image to "outImage.pgm"
*/


#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>
#include "lab-images.h"

using namespace std;

// Reads a PGM file.
// Notice that: height and width are passed by reference!
void readImage(int image[MAX_H][MAX_W], int &height, int &width) {
	char c;
	int x;
	ifstream instr;
	instr.open("inImage.pgm");

	// read the header P2
	instr >> c;
	assert(c == 'P');
	instr >> c;
	assert(c == '2');

	// skip the comments (if any)
	while ((instr>>ws).peek() == '#') {
		instr.ignore(4096, '\n');
	}

	instr >> width;
	instr >> height;

	assert(width <= MAX_W);
	assert(height <= MAX_H);
	int max;
	instr >> max;
	assert(max == 255);

	for (int row = 0; row < height; row++)
		for (int col = 0; col < width; col++)
			instr >> image[row][col];
	instr.close();
	return;
}


// Writes a PGM file
// Need to provide the array data and the image dimensions
void writeImage(string filename, int image[MAX_H][MAX_W], int height, int width) {
	ofstream ostr;
	ostr.open(filename); // Might need to change to c_str()
	if (ostr.fail()) {
		cout << "Unable to write file\n";
		exit(1);
	};

	// print the header
	ostr << "P2" << endl;
	// width, height
	ostr << width << ' ';
	ostr << height << endl;
	ostr << 255 << endl;

	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			assert(image[row][col] < 256);
			assert(image[row][col] >= 0);
			ostr << image[row][col] << ' ';
			ostr << endl;
		}
	}
	ostr.close();
	return;
}

void invert(int image[MAX_H][MAX_W], int height, int width){
	for(int row = 0; row < height; row++){
		for(int col = 0; col < width; col++){
			image[row][col] = 255 - image[row][col];
		}
	}
	writeImage("invert.pgm", image, height, width);
}

void invert_half(int image[MAX_H][MAX_W], int height, int width){
	for(int row = 0; row < height; row++){
		for(int col = width/2; col < width; col++){
			image[row][col] = 255 - image[row][col];
		}
	}
	writeImage("inverthalf.pgm", image, height, width);
}

void box(int image[MAX_H][MAX_W], int height, int width){
	for(int row = height/4 - 1; row < (height - height/4); row++){
		for(int col = width/4 - 1; col < (width - width/4); col++){
			image[row][col] = 255;
		}
	}
	writeImage("box.pgm", image, height, width);
}

void frame(int image[MAX_H][MAX_W], int height, int width){
	for(int row = height/4 - 1; row < (height - height/4); row++){
		if(row == (height/4 - 1) || row == (height - height/4 -1)){
			for(int col = width/4 - 1; col < (width - width/4); col++){
				image[row][col] = 255;
			}
		} else {
			image[row][width/4 - 1] = 255;
			image[row][width - width/4 - 1] = 255;
		}
	}
	writeImage("frame.pgm", image, height, width);
}

void scale(int image[MAX_H][MAX_W], int height, int width){
	/*
	int newH = height * 2;
	int newW = width * 2;
	cout << "NEW H " << newH << endl;
	cout << "NEW W " << newW << endl;
	cout << "H " << height << endl;
	cout << "W " << width << endl;
	int biggerImage[newH][newW];
	int bigRow = 0;
	int bigColumn = 0;
	int currentNum;
	bool secondRowNow = false; // False before the first row, true before the second row
	for(int row = 0; row < height; row++){
		cout << "Working on Row " << row << endl;
		for(int col = 0; col < width; col++){
			cout << "----------Working on Col " << col << endl;
			cout << "-----------------------Big Row " << bigRow << endl;
			currentNum = image[row][col];
			biggerImage[bigRow][bigColumn] = currentNum;
			biggerImage[bigRow][bigColumn + 1] = currentNum;
			bigColumn += 2;
		}
		bigRow += 1;
		bigColumn = 0;
		for(int col = 0; col < width; col++){
			cout << "----------Working on Col " << col << endl;
			cout << "-----------------------Big Row " << bigRow << endl;
			currentNum = image[row][col];
			biggerImage[bigRow][bigColumn] = currentNum;
			biggerImage[bigRow][bigColumn + 1] = currentNum;
			bigColumn += 2;
		}
		bigRow += 1;
		bigColumn = 0;
	}
	writeImage("scale.pgm", biggerImage, newH, newW);
	*/
}
