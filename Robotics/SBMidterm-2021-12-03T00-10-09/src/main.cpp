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
// Drivetrain           drivetrain    1, 2, 21, 9, 4  
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;
float dX_1;
float dX_2;
void driveTo(float dc);
void turnTo(int dg);
void stopAndWait(int ms);
void turnRight();
void turnLeft();
void liftArm();
void lowerArm();
void openClaw();
void closeClaw();

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  for(int i = 0; i<=3; i++) {
    driveTo(dX_1);
    turnRight();
    driveTo(dX_2);
    liftArm();
    openClaw();
    stopAndWait(1000);
    closeClaw();
    turnTo(180);
    lowerArm();
    driveTo(dX_2);
    turnLeft();
    driveTo(dX_1);
    turnTo(360);
    turnTo(90);
    stopAndWait(1000);
    liftArm();
    stopAndWait(2000);
    openClaw();
    lowerArm();

  } //end while 1
} //end main loop
/*for (int i = 0; i <= 4; i++){
    Drivetrain.driveFor(forward, 12, inches);
    Drivetrain.turnFor(right, 90, degrees);
  }*/