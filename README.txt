/*  Name: RoutineBuilder.txt
Description: A library for Arduino Uno to create patterns on a multiplexed 3x3 LED Cube
By: Alec Glasford
Date Written: January 2nd, 2024
Date(s) Modified: N/A
*/

====================================--Setup--=====================================

1. To Install the library, copy the folder with all these files. Find 
and open the Arduino folder. Paste the LineFollowing folder into the 
folder named libraries.

2. Import the library with Sketch -> Include Library -> RoutineBuilder or type: #include <RoutineBuilder.h>

3. In Arduino IDE, initialize the with the following constructor:

RoutineBuilder RoutineBuilder(a, b, c, d, e, f, g, h, i, j, k, l);

Where, when looking at the LED cube from the front:

a = the pin number corresponding with the negative wire on the bottom plane of LEDs
b = the pin number corresponding with the negative wire on the middle plane of LEDs
c = the pin number corresponding with the negative wire on the top plane of LEDs
d = the pin number corresponding with the positive wire on the front left column of LEDs
e = the pin number corresponding with the positive wire on the front middle column of LEDs
f = the pin number corresponding with the positive wire on the front right column of LEDs
g = the pin number corresponding with the positive wire on the middle left column of LEDs
h = the pin number corresponding with the positive wire on the middle middle column of LEDs
i = the pin number corresponding with the positive wire on the middle right column of LEDs
j = the pin number corresponding with the positive wire on the back left column of LEDs
k = the pin number corresponding with the positive wire on the back middle column of LEDs
l = the pin number corresponding with the positive wire on the back right column of LEDs

====================================--Functions--=====================================

1. PinSetup(): Sets all pins that are going to be used in the project to output pins.
For use in void setup().

2. setPositivePinsTwoD(int positivePinsTwoDPrivate[3][3]): Setter for the two dimensional 
positive pin array. Can be used to change the pins used throughout a project.

3. setPositivePins(int positivePins[9]): Setter for the one dimensional 
positive pin array. Can be used to change the pins used throughout a project.

4. setNegativePins(int negativePinsPrivate[3]): Setter for the array of
negative pins. Can be used to change the pins used throughout a project.

5. getPositivePin(int xCoordinate, int yCoordinate): Returns the pin number from a specified
column of LEDs. This getter allows users to retrieve information from the arrays stored in the
library.

6. getNegativePin(int zCoordinate): Returns the pin number for the specified plane of LEDs.
This getter allows users to retrieve information from the arrays stored in the library.

7. resetPins(): Turns off all the LEDs that are currently on.

8. lightCube(): Lights all the LEDs in the cube.

9. lightSingleLED(int xCoordinate, int yCoordinate, int zCoordinate, int delayTime): Lights a single
LED based on its coordinates (0-2) and a given time to stay on.

10. lightVertLine(int xCoordinate, int yCoordinate): Given the x and y values of a column, it will
light a line of LEDs in that column.

11. lightHorizontalLine(int yCoordinate, int zCoordinate): Given the y and z values of a row, it will
light that row of LEDs.

12. invLightHorizontalLine(int xCoordinate, int zCoordinate): Given the x and z values of a row, it
will light that row of LEDs. This function is different from lightHorizontalLine() as the rows this function
lights are perpendicular to the rows lightHorizontalLine() lights.
