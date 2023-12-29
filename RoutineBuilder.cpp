/*  Name: RoutineBuilder.cpp
Description: A library for Arduino Uno to create patterns on a multiplexed 3x3 LED Cube
By: Alec Glasford
Date Written: December 29th, 2023
Date(s) Modified: N/A
*/
#include "Arduino.h"
#include "RoutineBuilder.h"

        //The constructor function below is used to call an instance of the class and initalize the library.
        RoutineBuilder::RoutineBuilder (int nPinRowOne, int nPinRowTwo, int nPinRowThree, int pPinRowOneColOne, int pPinRowOneColTwo, int pPinRowOneColThree, int pPinRowTwoColOne, int pPinRowTwoColTwo, int pPinRowTwoColThree, int pPinRowThreeColOne, int pPinRowThreeColTwo, int pPinRowThreeColThree){
            
            //In the LED cube, each LED column has an output pin associated with it that will act as the positive voltage supply when output is set to high.
            //positivePinsTwoDPrivate is the two dimensional array that will store these pin values, to be usedf with coordinates
            int positivePinsTwoDPrivate[3][3] = {
                {pPinRowOneColOne, pPinRowOneColTwo, pPinRowOneColThree},
                {pPinRowTwoColOne, pPinRowTwoColTwo, pPinRowTwoColThree},
                {pPinRowThreeColOne, pPinRowThreeColTwo, pPinRowThreeColThree}
                };

            //positivePinsPrivate is a one dimensional array that stores the positive pin values for quicker access without coordinates.
            int positivePinsPrivate[9] = {pPinRowOneColOne, pPinRowOneColTwo, pPinRowOneColThree, pPinRowTwoColOne, pPinRowTwoColTwo, pPinRowTwoColThree, pPinRowThreeColOne, pPinRowThreeColTwo, pPinRowThreeColThree};

            //In the LED cube, each plane of 9 LEDs will share one pin to act as a ground when the output is set to low, these pin values are stored in negativePinsPrivate
            int negativePinsPrivate[3] = {nPinRowOne, nPinRowTwo, nPinRowThree};

            //Calls on the existing setters to set each value from the private arrays to public ones.    
            setPositivePinsTwoD(positivePinsTwoDPrivate);
            setPositivePins(positivePinsPrivate);
            setNegativePins(negativePinsPrivate);
        }

        //A function which sets all the required pins for the LED cube to output pins
        //Used in void setup()
        void RoutineBuilder::PinSetup(){

            for(int i = 0; i < 9; i++){
                pinMode(positivePins[i], OUTPUT);
            }

            for(int i = 0; i < 3; i++){
                pinMode(negativePins[i], OUTPUT);
            }
        }


        //Sets the 2-D array of positive pins from a private variable to public one
        void RoutineBuilder::setPositivePinsTwoD(int positivePinsTwoDPrivate[3][3]){
            for(int i = 0; i < 3; i++){
                for(int y = 0; y < 3; y++){
                    positivePinsTwoD[i][y] = positivePinsTwoDPrivate[i][y];
                }
            }
        }

        //Sets the array of positive pins from a private variable to public one
        void RoutineBuilder::setPositivePins(int positivePinsPrivate[9]){
            for(int i = 0; i < 9; i++){
                positivePins[i] = positivePinsPrivate[i];
            }
        }

        //Sets the array of negative pins from a private variable to a public one
        void RoutineBuilder::setNegativePins(int negativePinsPrivate[3]){
            for(int i = 0; i < 3;  i++){
                negativePins[i] = negativePinsPrivate[i];
            }
        }

        //Includes the appropriate getters for when the program needs to access information strored in the library
        int RoutineBuilder::getPositivePin(int xCoordinate, int yCoordinate){
            return positivePinsTwoD[xCoordinate][yCoordinate];
        }

        int RoutineBuilder::getNegativePin(int zCoordinate){
            return negativePins[zCoordinate];
        }

        //resetPins(): A function which turns off all LEDs in the cube
        void RoutineBuilder::resetPins(){
            for(int i=0; i < 3; i++){
                digitalWrite(negativePins[i], HIGH);
            }

            for(int i=0; i < 9; i++){
                digitalWrite(positivePins[i], LOW);
            }
        }

        //lightCube(): A function which turns on all LEDs in the cube
        void RoutineBuilder::lightCube(){
            for(int y = 0; y < 1000; y++){
                for(int i = 0; i < 3; i++){
                    for(int x = 0; x < 9; x++){
                        digitalWrite(negativePins[i], LOW);
                        digitalWrite(positivePins[x], HIGH);
                        resetPins();
                    }
                }
            }
        }

        /*lightVertLine(*): A function which, when given an x and a y coordinate, will light up 
        a single line of LEDs from the base of the cube to the top*/
        void RoutineBuilder::lightVertLine(int xCoordinate, int yCoordinate){
            for(int y = 0; y < 1000; y++){
                for(int i = 0; i < 3; i++){
                    digitalWrite(negativePins[i], LOW);
                    digitalWrite(positivePinsTwoD[xCoordinate, yCoordinate], HIGH);
                    resetPins();
                }
            }
        }

        /*lightHorizontalLine(*): A function which, when given a y and a z coordinate, will light up 
        a single line of LEDs across the z axis*/
        void RoutineBuilder::lightHorizontalLine(int yCoordinate, int zCoordinate){
            for(int y = 0; y < 1000; y++){   
                for(int i = 0; i < 3; i++){
                    digitalWrite(negativePins[zCoordinate], LOW);
                    digitalWrite(positivePinsTwoD[i][yCoordinate]);
                    resetPins();
                }
            }
        }

        /*invLightHorizontalLine(*): A function which, when given an x and a z coordinate, will light up 
        a single line of LEDs across the y axis*/
        void RoutineBuilder::invLightHorizontalLine(int xCoordinate, int zCoordinate){
            for(int y = 0; y < 1000; y++){   
                for(int i = 0; i < 3; i++){
                    digitalWrite(negativePins[zCoordinate], LOW);
                    digitalWrite(positivePinsTwoD[xCoordinate][i]);
                    resetPins();
                }
            }
        }

        //lightSingleLED(): Given its coordinates and a delay time, the function will light up one LED for the specified amount of time
        void RoutineBuilder::lightSingleLED(int xCoordinate, int yCoordinate, int zCoordinate, int delayTime){
            digitalWrite(negativePins[zCoordinate], LOW);
            digitalWrite(positivePinsTwoD[xCoordinate][yCoordinate], HIGH);
            delay(delayTime);
            resetPins();
        }
        