/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\seanb                                            */
/*    Created:      Thu Dec 02 2021                                           */
/*    Description:  Allows for robot to drive in a square based on wheel      */
/*                  movement and degrees                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    1, 9, 21, 2     
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  for (int i = 1; i <= 4; i++){ //4 time for loop
    Brain.Screen.printAt(1,60,"For Loop"); //prints loop
    Brain.Screen.printAt(1,80,"i = %d", i); //prints variable
    Controller1.Screen.setCursor(1,1); //sets controller cursor to 1,1
    Controller1.Screen.print("i = %d", i); //prints action to controller
    Brain.Screen.printAt(1,100,"DRIVE A SQUARE"); //prints loop
    
    Brain.Screen.printAt(1,120,"Fwrd"); //prints action
    Controller1.Screen.setCursor(2,1); //sets controller cursor to 1,2
    Controller1.Screen.print("Fwrd"); //prints action to controller
    Drivetrain.driveFor(forward, 24, inches); //drive forward
    //Brain.Screen.clearLine(1, 120); //clears "forward"

    Brain.Screen.printAt(1,140,"Turn"); //prints action
    Controller1.Screen.setCursor(3,1); //sets controller cursor to 1,3
    Controller1.Screen.print("Turn"); //prints action to controller
    Drivetrain.turnFor(right, 90, degrees); //turn
    //Brain.Screen.clearLine(1, 20); //clears "turn"

    Brain.Screen.clearScreen(); //clears brain screen fully
    Controller1.Screen.clearScreen(); //clears brain screen fully
    vex::task::sleep(500); //SPD
  } //end for loop

}// end of main
