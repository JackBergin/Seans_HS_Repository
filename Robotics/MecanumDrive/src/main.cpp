/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\jbflot                                           */
/*    Created:      Wed Apr 21 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// FrontLeft            motor         1               
// BackLeft             motor         2               
// BackRight            motor         9               
// FrontRight           motor         10              
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  while(true) {
     FrontRight.spin(directionType::fwd,((Controller1.Axis3.value() - Controller1.Axis1.value() - Controller1.Axis4.value())/2), velocityUnits::pct);  
     BackRight.spin(directionType::fwd,((Controller1.Axis3.value() - Controller1.Axis1.value() + Controller1.Axis4.value())/2), velocityUnits::pct);
     FrontLeft.spin(directionType::fwd,((Controller1.Axis3.value() + Controller1.Axis1.value() + Controller1.Axis4.value())/2), velocityUnits::pct);
     BackLeft.spin(directionType::fwd,((Controller1.Axis3.value() + Controller1.Axis1.value() - Controller1.Axis4.value())/2), velocityUnits::pct);
   }
  
}
