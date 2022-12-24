/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\bswain                                         */
/*    Created:      Thu Sep 30 2021                                           */
/*    Description: On off Debounce Clawbot with tank drive.                                              */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// bumper1              bumper        A               
// L_motor              motor         1               
// R_motor              motor         10              
// Arm_motor            motor         3               
// Claw_motor           motor         8               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {// main line loop
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit(); 

  #include "robot-config.h"

    /*On Off Debounce / Tank Drive/ Claw Bot
     /Written By Kurt Lichtenwald for
      Coach L's Class 9/16/20*/

      // Make Local variables to record and hold data .
      signed char on_off_debounce = 0; // This will sart you in the stop loop.
    while (1){//run Loop forever
      Brain.Screen.clearScreen(){;//clear screen of info 
        // Bryan Ethan Robot screen 
      Brain.Screen.printAt(1,60, "Bryan's and Ethan's Program and Robot");// Bryan and Ethan
      //first # in above line is # of colums on the screen 1-470 andthe sencond in rows 1-240
  
}
