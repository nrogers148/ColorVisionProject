
# Nicki's CIE Colorblindness Palette Evaluator
## **Version 2.1**
Provided a palette of 3 colors and a choice
of 3 types of colorblindness, determines similarity
between the colors in relation to each other from the
persepctive of someone with the selected type of colorblindness.

## New in v2.1:
- The program can now do batches of palettes
- Refined readability and program messages
- Adjusted parameters for the comparisons

## To be added:
- Variability in color palette size
- Add more detail to Results Text


## Developer

Nicole Rogers

## Example
There is an example file with some random numbers that can be used to test the batch testing feature. Additional files should be formatted similarly

## Example Input
255 0 0

0 255 0

0 0 255


100 10 1

2 20 200

50 100 150

## Example Output
Using the first color example,
here is an example of the program running:

```
Hello and welcome to the Color Blindness Palette Checker!
Just input one of the available types of color blindness and 3 colors
and find out if your colors are visible to someone with that type of vision.
Before continuing, would you like a brief definition of the three color blindness types this program uses?
(y/n): n
All right, let's continue then.
Now, which type of colorblindness would you like to check for?
A. Protanopia or B. Deuteranopia or C.Tritanopia
(A/B/C): 
A
Moving on then, would you like to input one set of 3 colors or multiple?
A. One set   B. Many sets
(A/B): 
A
Please input 3 colors in RGB format on the lines below.
Color 1:
   Red:255
   Green:0
   Blue:0
Color 2:
   Red:0
   Green:255
   Blue:0
Color 3:
   Red:0
   Green:0
   Blue:255


Your results are...

Color 1 & Color 2 can work together. They contrast, but are still similar. Use with care.

Your colors work somewhat well togther. Your colors can be used together, but be careful. There is some contrast, but they are starting to look similar.
 In a larger palette, they are fine - especially when not used next to each other. Be careful about using them in
 smaller palettes or placing them near each other though.

Color 1 & Color 3 work together very well. They have a high level of contrast that would make them easy to see!

Your colors work well together. They can be safely used with little fear that they will be mistaken as the same color by someone colorblind.

Color 2 & Color 3 work together very well. They have a high level of contrast that would make them easy to see!

Your colors work well together. They can be safely used with little fear that they will be mistaken as the same color by someone colorblind.


Thank you!

For a backup of the colors you used, please look at the 'Results' file.
Thank you for using the Color Blindness Palatte Checker!
```
