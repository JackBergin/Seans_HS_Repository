/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Student                                          */
/*    Created:      Tue Feb 01 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// RILF                 line          F               
// MILF                 line          G               
// LELF                 line          H               
// leftFM               motor         1               
// leftBM               motor         9               
// rightFM              motor         21              
// rightBM              motor         2               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

float threshold = (62+4)/2; //is the average of the highest high and lowest low (62 = black, 45 = white)
void go(); //accelerates
void xVelocity(bool rightOrLeft); //dictates left or right velocity change (true == right
void straighten(); //sets default velocity
void sensorData(); //prints sensor data to brain screen
void lostMode(); //makes robot spiral until finds track

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  while(1){ //infinite run
    sensorData();

    while (LELF.value(analogUnits::pct) >= threshold){ //left sensor black
      //prints sensor data
      sensorData();

      //xVelocity(false); //turns right
      //task::sleep(50);
      leftBM.setVelocity(30, rpm);
      rightBM.setVelocity(30, rpm);
      leftFM.setVelocity(30, rpm);
      rightFM.setVelocity(30, rpm);
      Brain.Screen.printAt(100,100, "left");

      //goes forward go();
      leftFM.spin(reverse);
      rightFM.spin(reverse);
      leftBM.spin(reverse);
      rightBM.spin(reverse);
      
    } //end while(LELF)

    while (MILF.value(analogUnits::pct) >= threshold){ //mid sensor black
      //prints data
      sensorData();

      //sets velocity straighten(); //stays forward
      //task::sleep(50);
      leftBM.setVelocity(30, rpm);
      rightBM.setVelocity(30, rpm);
      leftFM.setVelocity(30, rpm);
      rightFM.setVelocity(30, rpm);

      //goes forward go();
      leftFM.spin(forward);
      rightFM.spin(reverse);
      leftBM.spin(forward);
      rightBM.spin(reverse);

    } //end while(MILF)

    while (RILF.value(analogUnits::pct) >= threshold){ //right sensor black
      //prints sensor data
      sensorData();

      //xVelocity(true); //turns left
      //task::sleep(50);
      leftBM.setVelocity(30, rpm);
      rightBM.setVelocity(30, rpm);
      leftFM.setVelocity(30, rpm);
      rightFM.setVelocity(30, rpm);
      Brain.Screen.printAt(100,80, "right");

      //goes forward go();
      leftFM.spin(forward);
      rightFM.spin(forward);
      leftBM.spin(forward);
      rightBM.spin(forward);

    } //end while(RILF)

    while (RILF.value(analogUnits::pct) < threshold && MILF.value(analogUnits::pct) < threshold && LELF.value(analogUnits::pct) < threshold){      
      leftBM.setVelocity(15, rpm);
      rightBM.setVelocity(15, rpm);
      leftFM.setVelocity(15, rpm);
      rightFM.setVelocity(15, rpm);

      leftFM.spin(reverse);
      rightFM.spin(forward);
      leftBM.spin(reverse);
      rightBM.spin(forward);
    }

  } //end while(1)

} //end main

/*
void go(){ //moves the wheel
  leftFM.spin(forward);
  rightFM.spin(reverse);
  leftBM.spin(forward);
  rightBM.spin(reverse);
} //end go

void straighten(){
  leftBM.setVelocity(10, rpm);
  rightBM.setVelocity(10, rpm);
  leftFM.setVelocity(10, rpm);
  rightFM.setVelocity(10, rpm);
} //end xVelocity

void xVelocity(bool rOrL){
  if (rOrL) { //turns right
    leftBM.setVelocity(15, rpm);
    rightBM.setVelocity(10, rpm);
    leftFM.setVelocity(15, rpm);
    rightFM.setVelocity(10, rpm);
    Brain.Screen.printAt(100,80, "right");
  } 
  if (rOrL == false){ //turns left
    leftBM.setVelocity(10, rpm);
    rightBM.setVelocity(15, rpm);
    leftFM.setVelocity(10, rpm);
    rightFM.setVelocity(15, rpm);
    Brain.Screen.printAt(100,100, "left");
  } //end if/else
} //end xVelocity*/

void sensorData(){
  Brain.Screen.clearScreen();
  Brain.Screen.printAt(100,60, "LELF = %d", LELF.value(analogUnits::pct));
  Brain.Screen.printAt(200,60, "MILF = %d", MILF.value(analogUnits::pct));
  Brain.Screen.printAt(300,60, "RILF = %d", RILF.value(analogUnits::pct));
  wait(5, msec);
}

