/*  Name: RoutineBuilder.h
Description: A library for Arduino Uno to create patterns on a multiplexed 3x3x3 LED Cube
By: Alec Glasford
Date Written: December 29th, 2023
Date(s) Modified: N/A
*/

//If this header file has not been defined already, define it. Otherwise skip to the end
#ifndef RoutineBuilder_h
#define RoutineBuilder_h
//Includes Arduino commands into this file
#include "Arduino.h"

//Creates a class that holds all public commands and private variables
class RoutineBuilder{

  public:
  //The constrictor function below is used when someone calls an insatance of the class
  RoutineBuilder (int nPinRowOne, int nPinRowTwo, int nPinRowThree, int pPinRowOneColOne, int pPinRowOneColTwo, int pPinRowOneColThree, int pPinRowTwoColOne, int pPinRowTwoColTwo, int pPinRowTwoColThree, int pPinRowThreeColOne, int pPinRowThreeColTwo, int pPinRowThreeColThree);

  void PinSetup();
  
  void setPositivePinsTwoD(int positivePinsTwoDPrivate[3][3]);

  void setPositivePins(int positivePins[9]);

  void setNegativePins(int negativePinsPrivate[3]);

  int getPositivePin(int xCoordinate, int yCoordinate);

  int getNegativePin(int zCoordinate);

  void resetPins();

  void lightCube();

  void lightSingleLED(int xCoordinate, int yCoordinate, int zCoordinate, int delayTime)

  void lightVertLine(int xCoordinate, int yCoordinate);

  void lightHorizontalLine(int yCoordinate, int zCoordinate);

  void invLightHorizontalLine(int xCoordinate, int zCoordinate);

  private:
  int positivePinsTwoD[3][3];
  int positivePins[3];
  int negativePins[3];

};

#endif
