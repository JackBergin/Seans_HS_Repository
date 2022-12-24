/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Student                                          */
/*    Created:      Wed Mar 16 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// VS10                 vision        10              
// AM                   vision        8               
// CM                   motor         3               
// Drivetrain           drivetrain    1, 9, 21, 2     
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;
int main() {

int boxX1 = 157;
int boxX2 = 211;
int boxY1 = 144;
int boxY2 = 182;
int centerFOVX = 158;
int centerFOVY = 0;
int offsetX = 48;
int offsetY = 36;

int return2  = 1;
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  while(1){  
    CM.spin(reverse);
    Brain.Screen.clearScreen();// clear line
    Brain.Screen.setOrigin(1,1);
    Brain.Screen.drawRectangle(0,0,316,212);
    VS10.takeSnapshot(VS10__GBALL);

    if (VS10.largestObject.exists){
      Brain.Screen.drawCircle(VS10.largestObject.originX, VS10.largestObject.originY,  VS10.largestObject.height, color::green);
    } //end of if1
    if (VS10.largestObject.centerX > centerFOVX + offsetX){
      Drivetrain.turn(right);
    }// end of if 2
    else if (VS10.largestObject.centerX < centerFOVX - offsetX){
      Drivetrain.turn(left);
    } //end of else if 1
    else if (VS10.largestObject.centerY > centerFOVY + offsetY){
      Drivetrain.drive(forward); 
    } // end of else if 2
    else if (VS10.largestObject.centerY > centerFOVY - offsetY){
      Drivetrain.drive(forward);
    } // end of else if 3

    if(VS10.largestObject.centerX > boxX1 && VS10.largestObject.centerX < boxY2 && VS10.largestObject.centerY > boxY2 && VS10.largestObject.centerY){
      CM.spin(forward); // close CM
      wait(2,sec);
      Drivetrain.stop();
      Drivetrain.turnFor(right, 180, degrees); // turn around
    }//end of if

    while(return2==1){
      VS10.takeSnapshot(VS10__PINK); 
  
      if (VS10.largestObject.exists){
        Brain.Screen.clearScreen();// clear line
        Brain.Screen.setFillColor(red);
        Brain.Screen.drawRectangle(VS10.largestObject.originX, VS10.largestObject.originY,  VS10.largestObject.height,  VS10.largestObject.width);
      }
    }// end of while 2                        

  }// end of while 1
  
} // end of main 



