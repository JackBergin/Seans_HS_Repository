/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Student                                          */
/*    Created:      Fri Feb 18 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Vision10             vision        10              
// CM                   motor         8               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int CCX = 158; //claw center x
int CCY = 155; //claw center y

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  while(1){
    Vision10.takeSnapshot(Vision10__SIG_1);
    if (((abs(Vision10.largestObject.originX)-CCX) <= 3) && ((abs(Vision10.largestObject.originY)-CCY) <= 3)){
      CM.spin(reverse);
    }

  } //while 1
} //end of main
