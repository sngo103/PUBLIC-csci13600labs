/*
Author: Samantha Ngo
Course: CSCI 13300
Instructor: Mike Zamansky
Assignment: Lab 8
Task: Write programs to manipulate .pgm images.
*/

#include "lab-images.h"
#include <iostream>
#include <string>

using std::cout;
using std::string;
using std::cin;
using std::endl;

int main(){
  cout << "====================================================================================================" << endl;
  cout << "Lab 8: Writing Image Manipulation Functions" << endl;
  cout << "====================================================================================================" << endl;
	int img[MAX_H][MAX_W];
	int h, w;

	readImage(img, h, w); // read it from the file "inImage.pgm"
	// h and w were passed by reference and
	// now contain the dimensions of the picture
	// and the 2-dimesional array img contains the image data

	// Now we can manipulate the image the way we like
	// for example we copy its contents into a new array
	int out[MAX_H][MAX_W];

  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
      out[row][col] = img[row][col];
    }
  }

	// and save this new image to file "outImage.pgm"
	writeImage("outImage.pgm", out, h, w);
  invert(out, h, w);

  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
      out[row][col] = img[row][col];
    }
  }
  invert_half(out, h, w);

  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
      out[row][col] = img[row][col];
    }
  }
  box(out, h, w);

  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
      out[row][col] = img[row][col];
    }
  }
  frame(out, h, w);

  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
      out[row][col] = img[row][col];
    }
  }
  writeImage("scale.pgm",out, h * 2, w * 2);
  scale(out, h, w);

  return 0;

}
