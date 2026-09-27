#include <iostream>
#include <cmath>
using namespace std;

   double π = 3.14159265358979323846;

void intro (char  wantDefinition) {
    cout << "Hello, and welcome to my Color Blindness Project." << endl;
   
    do {
    cout << "This program can check for Protanopia, Deuteranopia, and Tritanopia. Would you like a brief description of these types of colorblindness?" << endl;
    cout << "(y/n): ";
    cin >> wantDefinition;

    if (wantDefinition == 'y' || wantDefinition == 'Y') {
        cout << "All right\n";
        cout << "Protanopia is also known as Red/Green color blindness, along with Deuteranopia. People with these two types of color blindness struggle to differentiate between reds, greens, browns, and oranges." << endl;
        cout << "Tritanopia is also known as blue/yellow color blindness. People with this kind of color blindness struggle to differentiate between blue, yellow, violet, red, blue, and green." << endl << endl;
    }
    else if (wantDefinition == 'n' || wantDefinition == 'N') {
        cout << "All right, let's continue then." << endl;
    }
    else {
        cout << "Invalid entry" << endl << endl;
    }
    } while (wantDefinition != 'y' && wantDefinition != 'n' && wantDefinition != 'Y' && wantDefinition != 'N');
    return;
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

vector<double> lineartoCIE (double r1, double g1, double b1) {
    double color1X = 0.4124*r1 + 0.3576*g1 + 0.1805*b1;
    double color1Y = 0.2126*r1 + 0.7152*g1 + 0.0722*b1;
    double color1Z = 0.0193*r1 + 0.1192*g1 + 0.9505*b1;
        
    double total1 = color1X + color1Y + color1Z;
    color1X = color1X / total1;
    color1Y = color1Y / total1;
    return {color1X, color1Y};
}

double angleFormulaProtan (vector<double>cord1, vector<double>cord2) {
    double ux = cord1[0] - 0.747;
    double uy = cord1[1] - 0.253;
    double vx = cord2[0] - 0.747;
    double vy = cord2[1] - 0.253;
    double cross = ux * vy - uy * vx;
    double dot = ux * vx + uy * vy;
    double angle = atan2(abs(cross), abs(dot));
    return angle*180/π;
}

double angleFormulaDeuter (vector<double>cord1, vector<double>cord2) {
    double ux = cord1[0] - 1.080;
    double uy = cord1[1] + 0.800;
    double vx = cord2[0] - 1.080;
    double vy = cord2[1] + 0.800;
    double cross = ux * vy - uy * vx;
    double dot = ux * vx + uy * vy;
    double angle = atan2(abs(cross), abs(dot));
    return angle*180/π;
}

double angleFormulaTritan (vector<double>cord1, vector<double>cord2) {
    double ux = cord1[0] - 0.171;
    double uy = cord1[1] - 0.000;
    double vx = cord2[0] - 0.171;
    double vy = cord2[1] - 0.000;
    double cross = ux * vy - uy * vx;
    double dot = ux * vx + uy * vy;
    double angle = atan2(abs(cross), abs(dot));
    return angle*180/π;
}

int main () {
   char blindType;
   double r1;
   double g1;
   double b1;

   double r2;
   double g2;
   double b2;

   double r3;
   double g3;
   double b3;

   int c1Red;
   int c1Green;
   int c1Blue;

   int c2Red;
   int c2Green;
   int c2Blue;

   int c3Red;
   int c3Green;
   int c3Blue;

   vector<double>result;

   vector<double> result1;
   vector<double> result2;
   vector<double> result3;

double compare1;
double compare2;
double compare3;

intro('y');

cout << "Which type of colorblindness would you like to check for?" << endl;
cout << "A. Protanopia or B. Deuteranopia or C.Tritanopia" << endl;
cin >> blindType;

while (blindType != 'A' && blindType != 'B' && blindType != 'C') {
    cout << "Invalid entry. Please enter A, B, or C" << endl;
    cin >> blindType;
}

cout << "Thank you" << endl;

//Color Gathering
cout << "Please input 3 colors in RGB format on the lines below." << endl;
    cout << "Color 1: " << endl;
    cout << "   Red: ";
    cin >> c1Red;
    cout << "   Green: ";
    cin >> c1Green;
    cout << "   Blue: ";
    cin >> c1Blue;
    cout << endl;

    cout << "Color 2: " << endl;
    cout << "   Red: ";
    cin >> c2Red;
    cout << "   Green: ";
    cin >> c2Green;
    cout << "   Blue: ";
    cin >> c2Blue;
    cout << endl;

    cout << "Color 3: " << endl;
    cout << "   Red: ";
    cin >> c3Red;
    cout << "   Green: ";
    cin >> c3Green;
    cout << "   Blue: ";
    cin >> c3Blue;
    cout << endl;
cout << "Thank you!" << endl << endl;

    r1 = RGBtoLinear(c1Red);
    g1 = RGBtoLinear(c1Green);
    b1 = RGBtoLinear(c1Blue);

    r2 = RGBtoLinear(c2Red);
    g2 = RGBtoLinear(c2Green);
    b2 = RGBtoLinear(c2Blue);

    r3 = RGBtoLinear(c3Red);
    g3 = RGBtoLinear(c3Green);
    b3 = RGBtoLinear(c3Blue);

if (blindType == 'A') {
    result1 = lineartoCIE(r1, g1, b1);
    result2 = lineartoCIE(r2, g2, b2);
    result3 = lineartoCIE(r3, g3, b3);


    compare1 = angleFormulaProtan (result1, result2);
    compare2 = angleFormulaProtan (result1, result3);
    compare3 = angleFormulaProtan (result2, result3);
}
else if (blindType == 'B') {
    result1 = lineartoCIE(r1, g1, b1);
    result2 = lineartoCIE(r2, g2, b2);
    result3 = lineartoCIE(r3, g3, b3);


    compare1 = angleFormulaDeuter (result1, result2);
    compare2 = angleFormulaDeuter (result1, result3);
    compare3 = angleFormulaDeuter (result2, result3);
}
else {
    result1 = lineartoCIE(r1, g1, b1);
    result2 = lineartoCIE(r2, g2, b2);
    result3 = lineartoCIE(r3, g3, b3);


    compare1 = angleFormulaTritan (result1, result2);
    compare2 = angleFormulaTritan (result1, result3);
    compare3 = angleFormulaTritan (result2, result3);
}


if ((c1Red <= 100 && c1Green <=100 && c1Blue <=100) && (c2Red <=100 && c2Green <= 100 && c2Blue<= 100) && (c3Red <= 100 && c3Green <= 100 && c3Blue <= 100)) {
    cout << "All colors are too dark and would be hard to see together." << endl;
}
else if ((c1Red <= 100 && c1Green <=100 && c1Blue <=100) && (c2Red <=100 && c2Green <= 100 && c2Blue<= 100)) {
     cout << "Color 1 and Color 2 are too dark to be seen together." << endl;
}
else if ((c1Red <= 100 && c1Green <=100 && c1Blue <=100) && (c3Red <= 100 && c3Green <= 100 && c3Blue <=100)) {
    cout << "Color 1 and Color 3 are too dark to be seen together." <<endl;
}
else if ((c2Red <=100 && c2Green <= 100 && c2Blue<=100) && (c3Red <= 100 && c3Green <= 100 && c3Blue <=100)) {
    cout << "Color 2 and Color 3 are too dark to be seen together." <<endl;
}

cout << endl;

if (compare1 >= 10) {
    cout << "Color 1 & Color 2 are very well contrasted. Feel free to use them in a color-blind frinedly palette." << endl;
}
else if (compare1 < 10 && compare1 > 5) {
    cout << "Color 1 Color 2 are similar but have enough contrast to be used in a color-friendly palette" <<endl;
}
else if (compare1 <=5 && compare1 >= 1) {
    cout << "Color 1 & Color 2 are similar but are still usable with care." <<endl;
}
else {
    cout << "Colors 1 & 2 are too similar to work in a color friendly palette." << endl;
}



if (compare2 >= 10) {
    cout << "Color 1 & Color 3 are very well contrasted. Feel free to use them in a color-blind frinedly palette." << endl;
}
else if (compare2 < 10 && compare2 > 5) {
    cout << "Color 1 Color 3 are similar but have enough contrast to be used in a color-friendly palette" <<endl;
}
else if (compare2 <=5 && compare2 >= 1) {
    cout << "Color 1 & Color 3 are similar but are still usable with care." <<endl;
}
else {
    cout << "Colors 1 & 3 are too similar to work in a color friendly palette." << endl;
}



if (compare3 >= 10) {
    cout << "Color 2 & Color 3 are very well contrasted. Feel free to use them in a color-blind frinedly palette." << endl;
}
else if (compare3 < 10 && compare3 > 5) {
    cout << "Color 2 Color 3 are similar but have enough contrast to be used in a color-friendly palette" <<endl;
}
else if (compare3 <=5 && compare3 >= 1) {
    cout << "Color 2 & Color 3 are similar but are still usable with care." <<endl;
}
else {
    cout << "Colors 2 & 3 are too similar to work in a color friendly palette." << endl;
}
}