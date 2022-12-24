/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Student                                          */
/*    Created:      Wed Mar 09 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// CAM                  vision        10              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  while(1){
    Brain.Screen.clearLine();

    //tell vision sensor to look and print properties
    CAM.takeSnapshot(CAM__SIG_1);

    //detects at least one color stored in SIG_1
    if(CAM.largestObject.exists){
      //display the x, y, width, and height of object
      Brain.Screen.print("CAM: X: %d", CAM.largestObject.originX);
      Brain.Screen.print(" Y: %d", CAM.largestObject.originY);
      Brain.Screen.print(" W: %d", CAM.largestObject.width);
      Brain.Screen.print(" H: %d", CAM.largestObject.height);
    } else {
      //... else, display that it did not find any objects
      Brain.Screen.print("CAM: Color signature not found");
    } //end if else CAM.largestObeject.exists

  } //end while(1)
} //end int main
