/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// leftLT               line          H               
// midLT                line          G               
// rightLT              line          F               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

float threshold;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  while (true) {
    Brain.Screen.printAt(1, 100, "LLT = %d", leftLT.reflectivity()); 
    Brain.Screen.printAt(200, 100, "MLT = %d", midLT.reflectivity()); 
    Brain.Screen.printAt(300, 100, "RLT = %d", rightLT.reflectivity()); 
    wait(5, msec);
  }
}
