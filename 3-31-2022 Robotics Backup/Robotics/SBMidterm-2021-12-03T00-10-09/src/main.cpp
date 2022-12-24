/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       SBMidterm                                                 */
/*    Author:       Sean Bergin                                               */
/*    Created:      Thu Dec 02 2021                                           */
/*    Description:  A program that allows for your robot to make turns and    */
/*                  fetches its owner a beer/soda.                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    1, 9, 21, 2, 11 
// Arm                  motor         8               
// Claw                 motor         3               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "cmath"
 
//comment functions
using namespace vex;
float dX_1 = 4; //leg a of triangle
float dX_2 = 2.666; //leg b of triangle
float dX_3 = (float) ((sqrt(pow(dX_1,2)+pow(dX_2+1,2)))+0.38); //hypotenuse: finds direct distance between beer and finish
void driveTo(float dc); //dc as in distance
void turnTo(int dg, bool l); //dg as in degree, l as in left
void stopAndWait(int ms); //ms as in milliseconds
void toggleArm(bool up); //up as in up
void toggleClaw(bool op); //op as in open

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  toggleClaw(true); //opens claw
  toggleClaw(false); //opens claw
  for(int i = 1; i<=3; i++) {
    Brain.Screen.printAt(1, 60, "i = %d", i); //prints action
    driveTo(dX_1); 
    turnTo(90, true); //turns 90 degrees left
    toggleArm(true); //lifts arm up
    toggleClaw(true); //opens claw 
    driveTo(dX_2);
    stopAndWait(1000);
    toggleClaw(false); //closes claw
    stopAndWait(1000);
    turnTo(120, true); //turns 120 degrees left
    toggleArm(false); //lowers arm
    driveTo(dX_3);
    turnTo(360+150, true);
    stopAndWait(1000);
    toggleArm(true); 
    stopAndWait(3000);
    toggleClaw(true); //opens claw
    stopAndWait(1000);
    toggleArm(false); //lowers arm
    toggleClaw(false); //closes claw
    driveTo(1); 
    stopAndWait(10000);

  } //end while 1
} //end main loop

void driveTo(float dX){ 
  Brain.Screen.printAt(1, 100, "Driving %d feet forward", dX); //prints action
  Drivetrain.driveFor(forward, (dX*12), inches); //drives forward "dX" feet
} //end driveTo

void turnTo(int deg, bool r){
  if (r){
    Brain.Screen.printAt(1, 80, "Turning %d degrees right", deg); //prints action
    Drivetrain.turnFor(right, deg, degrees); //turns for "deg" degrees
  } else{
    Brain.Screen.printAt(1, 100, "Turning %d degrees left", deg); //prints action
    Drivetrain.turnFor(left, deg, degrees); //turns for "deg" degrees
  }
} //end turnTo

void stopAndWait(int millisecs){
  Brain.Screen.printAt(1,120, "Waiting %d milliseconds ", millisecs);
  vex::task::sleep(millisecs); //waits for "millisecs" milliseconds
} //end stopAndWait

void toggleArm(bool up){
  Arm.setPosition(0, degrees);
  if (up){
    Brain.Screen.printAt(1,140, "Lifting Arm");
    Arm.spinFor(forward, 55*7, degrees); //gear ratio is 1:7
  } else {
    Brain.Screen.printAt(1,160, "Lowering Arm");
    Arm.spinFor(reverse, 55*7, degrees); //gear ratio is 1:7
  }
} //end toggleArm

void toggleClaw(bool op){
  Claw.setPosition(0, degrees);
  Brain.Screen.printAt(1,180, "OPEN = %d", op);
  if (op){
    Brain.Screen.printAt(1,200, "Opening Claw");
    Claw.spin(reverse); //gear ratio is 1:2 , 90*2, degrees
    vex::task::sleep(1000);
    Claw.stop();
  } else {
    Brain.Screen.printAt(1,220, "Closing Claw");
    Claw.spin(forward); //gear ratio is 1:2 , 90*2, degrees
    //vex::task::sleep(1000);
    //Claw.stop();
  }
} //end toggleArm


