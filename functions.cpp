#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>
#include "colors.h"
using namespace std;

double π = 3.14159265358979323846;

void intro (char  wantDefinition) {
  cout << "Hello and welcome to the Color Blindness Palette Checker!" << endl;
  cout << "Just input one of the available types of color blindness and 3 colors" << endl;
  cout << "and find out if your colors are visible to someone with that type of vision." << endl;
  
  do {
    cout << "Before continuing, would you like a brief definition of the three color blindness types this program uses?" << endl;
    cout << "(y/n): ";
    cin >> wantDefinition;

    if (wantDefinition == 'y' || wantDefinition == 'Y') {
      cout << "All right\n" << endl;
      cout << "Protanopia is also known as Red/Green color blindness, along with Deuteranopia." << endl << " People with ";
      cout << "these two types of color blindness struggle to differentiate between " << endl;
      cout << "reds, greens, browns, and oranges." << endl << endl;
      cout << "Tritanopia is also known as blue/yellow color blindness. People with" << endl;
      cout << " this kind of color blindness struggle to differentiate between blue," << endl;
      cout << " yellow, violet, red, blue, and green." << endl;
    }

    else if (wantDefinition == 'n' || wantDefinition == 'N') {
      cout << "All right, let's continue then." << endl;
    }

    else {
      cout << "Invalid entry" << endl << endl;
    }
  } while (wantDefinition != 'y' && wantDefinition != 'n' && wantDefinition != 'Y' && wantDefinition != 'N');
}

int colorGather (int& i,rgb& color) {
  i++;

  cout << "Color " << i << ":" << endl;
  cout << "   Red:";
  cin >> color.red;

  cout << "   Green:";
  cin >> color.green;

  cout << "   Blue:";
  cin >> color.blue;

  color.colorNumber = i;

  return i;
}

int batchColorGather (rgb& color) {
  int j = 0;

  for (j = 0; j < 3; j++)
  cout << "   Color " << j+1 << ":" << endl;
  cout << "       Red: " << color.red << endl;
  cout << "       Green: " << color.green << endl;
  cout << "       Blue: " << color.blue << endl;

  return j;
}

double RGBtoLinear (double r1) {
  r1 = r1/255;

  if (r1 < 0.04045) {
    r1 = r1/12.92;
  }
  
  else {
    r1 = pow(((r1 + 0.055)/1.055),2.4);
  }
    
  return r1;
}

double lightCheck (double r, double g, double b) {
  double red = r;
  double green = g;
  double blue = b;
  double lightLevel = 0.2126 * red + 0.7152 * green + 0.0722 * blue;
  return lightLevel;
}

double lightCompare (double light1, double light2) {
  double compare = abs(light1 - light2);
  return compare;
}

vector<double> lineartoCIE (linearColors color) {
  double color1X = 0.4124*color.red + 0.3576*color.green + 0.1805*color.blue;
  double color1Y = 0.2126*color.red + 0.7152*color.green + 0.0722*color.blue;
  double color1Z = 0.0193*color.red + 0.1192*color.green + 0.9505*color.blue;
  
  double total = color1X + color1Y + color1Z;
  color1X = color1X / total;
  color1Y = color1Y / total;
  return {color1X, color1Y};
}

double angleFormula (vector<double>cord1, vector<double>cord2, double x, double y) {
  double ux = cord1[0] - x;
  double uy = cord1[1] - y;
  double vx = cord2[0] - x;
  double vy = cord2[1] - y;

  double cross = ux * vy - uy * vx;
  double dot = ux * vx + uy * vy;
  double angle = atan2(abs(cross), abs(dot));
  return angle*180/π;
}

void goodMatch (linearColors color1, linearColors color2) {
  fstream resultFile("Results.txt", ios::app);

  cout << "Color " << color1.colorNumber << " & Color " << color2.colorNumber << " work together very well. They have a high";
  cout << " level of contrast that would make them easy to see!" << endl << endl;
  cout << "Your colors work well together. They can be safely used with little fear that they will be mistaken as the same";
  cout << " color by someone colorblind." << endl << endl;
  resultFile << "Color " << color1.colorNumber << " & Color " << color2.colorNumber << " work well togther." << endl << endl;
}

void midMatch (linearColors color1, linearColors color2) {
  fstream resultFile("Results.txt", ios::app);

  cout << "Color " << color1.colorNumber << " & Color " << color2.colorNumber << " can work together. They contrast,";
  cout << " but are still similar. Use with care." << endl << endl;
  cout << "Your colors work somewhat well togther.";
  cout << " Your colors can be used together, but be careful. There is some contrast, but they are starting to look similar." << endl;
  cout << " In a larger palette, they are fine - especially when not used next to each other. Be careful about using them in" << endl;
  cout << " smaller palettes or placing them near each other though." << endl << endl;

  resultFile.close();
}

void badMatch (linearColors color1, linearColors color2) {
  fstream resultFile("Results.txt", ios::out);

  cout << "Color " << color1.colorNumber << " & Color " << color2.colorNumber << " should not be used together. They";
  cout << " look very simlilar or near identitcal." << endl << endl;
  cout << "These colors do not work togther.";
  cout << "They should not be used in conjunction with one another. There is little to no contrast, and" << endl;
  cout << " someone with colorblindness would struggle to tell these two colors apart. Consider replacing one of" << endl;
  cout << " these colors with another. The colorblindness types definitions at the start of this program contain" << endl;
  cout << " color combinations to be wary of. It may be a place to start looking for alternatives." << endl << endl;
}



void comparison (rgb userColor1, rgb userColor2, rgb userColor3,char type) {
  linearColors color1;
  linearColors color2;
  linearColors color3;
  double compare1;
  double compare2;
  double compare3;

  
  color1.red = RGBtoLinear(userColor1.red);
  color1.green = RGBtoLinear(userColor1.green);
  color1.blue = RGBtoLinear(userColor1.blue);
  color1.colorNumber = 1;

  color2.red = RGBtoLinear(userColor2.red);
  color2.green = RGBtoLinear(userColor2.green);
  color2.blue = RGBtoLinear(userColor2.blue);
  color2.colorNumber = 2;

  color3.red = RGBtoLinear(userColor3.red);
  color3.green = RGBtoLinear(userColor3.green);
  color3.blue = RGBtoLinear(userColor3.blue);
  color3.colorNumber = 3;

  if (type == 'A' || type == 'a') { //Protan
    vector<double> result1 = lineartoCIE(color1);
    vector<double> result2 = lineartoCIE(color2);
    vector<double> result3 = lineartoCIE(color3);


    compare1 = angleFormula (result1, result2, 0.747, 0.253);
    compare2 = angleFormula (result1, result3, 0.747, 0.253);
    compare3 = angleFormula (result2, result3, 0.747, 0.253);
  }
  else if (type == 'B' || type == 'b') { //Deutan
    vector<double> result1 = lineartoCIE(color1);
    vector<double> result2 = lineartoCIE(color2);
    vector<double> result3 = lineartoCIE(color3);


    compare1 = angleFormula (result1, result2, 1.080, 0.800);
    compare2 = angleFormula (result1, result3, 1.080, 0.800);
    compare3 = angleFormula (result2, result3, 1.080, 0.800);
  }
  else { //Tritan
    vector<double> result1 = lineartoCIE(color1);
    vector<double> result2 = lineartoCIE(color2);
    vector<double> result3 = lineartoCIE(color3);


    compare1 = angleFormula (result1, result2, 0.171, 0.000);
    compare2 = angleFormula (result1, result3, 0.171, 0.000);
    compare3 = angleFormula (result2, result3, 0.171, 0.000);
  }

  double luminance = lightCheck (color1.red, color1.green, color1.blue);
  double luminance2 = lightCheck (color2.red, color2.green, color2.blue);
  double luminance3 = lightCheck (color3.red, color3.green, color3.blue);

  double lightCompare1 = lightCompare (luminance, luminance2);
  double lightCompare2 = lightCompare (luminance, luminance3);
  double lightCompare3 = lightCompare (luminance2, luminance3);

  cout << endl << endl << "Your results are..." << endl << endl;

  fstream resultFile("Results.txt", ios::out);

  resultFile << "Color 1: " << endl << "Red: " << userColor1.red << endl << "Green: " << userColor1.green << endl << "Blue: " << userColor1.blue << endl << endl;
  resultFile << "Color 2: " << endl << "Red: " << userColor2.red << endl << "Green: " << userColor2.green << endl << "Blue: " << userColor2.blue << endl << endl;
  resultFile << "Color 3: " << endl << "Red: " << userColor3.red << endl << "Green: " << userColor3.green << endl << "Blue: " << userColor3.blue << endl;
  resultFile << endl << endl;
  
  if (compare1 >= 10 && compare2 >= 10 && compare3 >= 10 && lightCompare1 > 1 && lightCompare2 > 1 && lightCompare3 > 1) {
    cout << "All three of your colors work great together! Feel free to change absolutely nothing!" << endl;
    resultFile << "All three of your colors work great together! Feel free to change absolutely nothing!" << endl;
  }

  if (compare1 <= 10 && lightCompare1 < 1) {
    if (compare1 <= 1 && lightCompare1 < 0.25) {
      badMatch (color1,color2);
    }
  else {
    midMatch (color1,color2);
  }
  }
  else {
    goodMatch (color1, color2);
  }


if (compare2 <= 10 && lightCompare2 < 1) {
  if (compare2 <=1 && lightCompare2 < 0.25) {
    badMatch (color1,color3);
  }
  else {
    midMatch (color1,color3);
  }
}
else {
  goodMatch (color1, color3);
}


if (compare3 <= 10 && lightCompare3 < 1) {
  if (compare3 <=1 && lightCompare3 < 0.25) {
    badMatch (color2,color3);
  }
  else {
    midMatch (color2,color3);
  }
}

else {
  goodMatch (color2, color3);
}
cout << endl;

resultFile.close();

}