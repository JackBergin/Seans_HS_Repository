/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Brody Laing                                               */
/*    Created:      Tue Jan 25 2022                                           */
/*    Description:  Line Follower Robot                                       */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LLT                  line          A               
// CLT                  line          B               
// RLT                  line          C               
// BackLeft             motor         20              
// BackRight            motor         1               
// FrontLeft            motor         10              
// FrontRight           motor         2               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int threshold = 45; 

void Go(){
  FrontLeft.spin(forward);
  FrontRight.spin(forward);
  BackLeft.spin(forward);
  BackRight.spin(forward);
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  while (1) {  //run forever
    Brain.Screen.printAt(2, 50, "%d", LLT.value(analogUnits::pct));
    Brain.Screen.printAt(175, 50, "%d", CLT.value(analogUnits::pct));
    Brain.Screen.printAt(375, 50, "%d", RLT.value(analogUnits::pct));
    //end forever loop
  
  while (LLT.value(analogUnits::pct) > threshold){

    /*---------Set Velocity---------*/
     BackLeft.setVelocity(40, rpm);
     BackRight.setVelocity(40, rpm);
     FrontLeft.setVelocity(40, rpm);
     FrontRight.setVelocity(40, rpm);
    /*------------------------------*/
    Brain.Screen.printAt(2, 150, "Left Black");
    Brain.Screen.printAt(2, 50, "%d", LLT.value(analogUnits::pct));
    Brain.Screen.printAt(175, 50, "%d", CLT.value(analogUnits::pct));
    Brain.Screen.printAt(375, 50, "%d", RLT.value(analogUnits::pct));
    
     FrontLeft.spin(reverse);
     FrontRight.spin(forward);
     BackLeft.spin(reverse);
     BackRight.spin(forward);

  }
  while (CLT.value(analogUnits::pct) > threshold){

    /*---------Set Velocity---------*/
     BackLeft.setVelocity(40, rpm);
     BackRight.setVelocity(40, rpm);
     FrontLeft.setVelocity(40, rpm);
     FrontRight.setVelocity(40, rpm);
    /*------------------------------*/
    Brain.Screen.printAt(2, 150, "Center Black");
    Brain.Screen.printAt(2, 50, "%d", LLT.value(analogUnits::pct));
    Brain.Screen.printAt(175, 50, "%d", CLT.value(analogUnits::pct));
    Brain.Screen.printAt(375, 50, "%d", RLT.value(analogUnits::pct));

    FrontLeft.spin(forward);
    FrontRight.spin(forward);
    BackLeft.spin(forward);
    BackRight.spin(forward);
  }
  while (RLT.value(analogUnits::pct) > threshold){

    /*---------Set Velocity---------*/
     BackLeft.setVelocity(40, rpm);
     BackRight.setVelocity(40, rpm);
     FrontLeft.setVelocity(40, rpm);
     FrontRight.setVelocity(40, rpm);
    /*------------------------------*/
    Brain.Screen.printAt(2, 150, "Right Black");
    Brain.Screen.printAt(2, 50, "%d", LLT.value(analogUnits::pct));
    Brain.Screen.printAt(175, 50, "%d", CLT.value(analogUnits::pct));
    Brain.Screen.printAt(375, 50, "%d", RLT.value(analogUnits::pct));
    
    FrontLeft.spin(forward);
    FrontRight.spin(reverse);
    BackLeft.spin(forward);
    BackRight.spin(reverse);

  }
  }


}//end main 
