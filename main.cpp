//
// File: main.cpp
// Description: File name change
// Created: Sun. Feb 26, 2023
// Author: Noah Sanderson
// mail: Noahs6423@student.vvc.edu
//

/*A photographer is organizing a photo collection about the national parks in the US and would like to annotate the information about each of the photos into a separate set of files. Write a program that reads the name of a text file containing a list of photo file names. The program then reads the photo file names from the text file, replaces the "_photo.jpg" portion of the file names with "_info.txt", and outputs the modified file names.

Assume the unchanged portion of the photo file names contains only letters and numbers, and the text file stores one photo file name per line. If the text file is empty, the program produces no output. */

#include <iostream>
#include <cstring>
#include <fstream>

using std::cout;
using std:: endl;
using std::string;

string strReplace(string photoInfo) {
int pos1 = photoInfo.find("_photo.jpg");
  photoInfo = photoInfo.substr(0 , pos1) + "_info.txt";
  return photoInfo;
}

int main() {
  std::ifstream inFS;
  string nameOfFile;
  string photo;

  std::cin >> nameOfFile;
  inFS.open(nameOfFile);

  if(!inFS.is_open()) {
    cout << "could not open file: " << nameOfFile << endl;

    return 1;
  }

  while (!inFS.eof()) {
  inFS >> photo;
    if (!inFS.fail()) {
      photo = strReplace(photo);
      cout << photo << endl;
    }  
  }
 inFS.close();
  
   return 0;
}