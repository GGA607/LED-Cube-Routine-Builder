/*  Name: RoutineBuilderExample.ino
Description: A library for Arduino Uno to create patterns on a multiplexed 3x3 LED Cube
By: Alec Glasford
Date Written: December 29th, 2023
Date(s) Modified: N/A
*/

//Include statement, tells arduino to communicate with the library in this sketch. Without this line, none of the following code will work.
//Can be added by going to Sketch -> Include Library -> LineFollowing in the toolbar.
#include <RoutineBuilder.h>


RoutineBuilder routineBuilder(2, 3, 4, 6, 7, 8, 9, 10, 11, 12, 13, A0);

void setup(){
  routineBuilder.PinSetup();
  
}
void loop(){
  digitalWrite(routineBuilder.getPositivePin(2, 2), HIGH);
  digitalWrite(routineBuilder.getNegativePin(0), LOW);
  

  routineBuilder.lightCube();

  routineBuilder.resetPins();
  
}
