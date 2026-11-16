//Author: Nicole Rogers
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <string>
#include "colors.h"

using namespace std;

//function prototypes
void intro (char);
double RGBtoLinear (double);
vector<double> lineartoCIE (linearColors);
double angleFormula (vector<double>, vector<double>, double, double);
int colorGather (int&, rgb&);
int batchColorGather (int&, int&, rgb&);
void goodMatch (linearColors, linearColors);
void midMatch (linearColors, linearColors);
void badMatch (linearColors, linearColors);
double lightCheck (double, double, double);
double lightCompare (double, double);
void comparison (rgb, rgb, rgb,char);



int main () {
  rgb userColor1;
  rgb userColor2;
  rgb userColor3;
  rgb batchColor;
  rgb batchColor2;
  rgb batchColor3;
  string userFile;
  char blindType;
  char batchTestQuestion;
  int count = 0;

  intro('y');

  cout << "Now, which type of colorblindness would you like to check for?" << endl;
  cout << "A. Protanopia or B. Deuteranopia or C.Tritanopia" << endl;
  cout << "(A/B/C): " << endl;
  cin >> blindType;

  while (blindType != 'A' && blindType != 'B' && blindType != 'C') {
    cout << "Invalid entry. Please enter A, B, or C" << endl;
    cin >> blindType;
  }

  //Color Gathering
  cout << "Moving on then, would you like to input one set of 3 colors or multiple?" << endl;
  cout << "A. One set   B. Many sets" << endl;
  cout << "(A/B): " << endl;
  cin >> batchTestQuestion;

  if (batchTestQuestion == 'a' || batchTestQuestion == 'A') {
    cout << "Please input 3 colors in RGB format on the lines below." << endl;
    colorGather(count, userColor1);
    colorGather(count, userColor2);
    colorGather(count, userColor3);
    comparison (userColor1, userColor2, userColor3, blindType);
  }

  else if (batchTestQuestion == 'b' || batchTestQuestion == 'B') {
    cout << "For a color batch, please have 3 colors in RGB format per set." << endl;
    cout << "Each section of the color (R, G, and B) should be separated by a space or a new line." << endl;
    cout << endl << "Please upload a .txt file or fill in the provided template. (Example.txt)" << endl;
    cin >> userFile;
    fstream inputFile(userFile, ios::in);
    ofstream resultSetUp ("Results.txt", ios::out);
    resultSetUp << "Welcome to the Results Page. Here is a log of recent uses";
    resultSetUp << " and some additional information about your results." << endl; 
    resultSetUp.close();
    
    while (!inputFile.eof()) {
      inputFile >> batchColor.red >> batchColor.green >> batchColor.blue;
      inputFile >> batchColor2.red >> batchColor2.green >> batchColor2.blue;
      inputFile >> batchColor3.red >> batchColor3.green >> batchColor3.blue;
      comparison (batchColor, batchColor2, batchColor3, blindType);
    }
  }

  else {
    cout << "Invalid entry. Please enter A or B" << endl;
  }

  cout << "Thank you!" << endl << endl;

  cout << "For a backup of the colors you used, please look at the 'Results' file." << endl;
  cout << "Thank you for using the Color Blindness Palatte Checker!" << endl;

  }