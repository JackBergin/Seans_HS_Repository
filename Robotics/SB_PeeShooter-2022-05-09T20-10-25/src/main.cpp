/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Student                                          */
/*    Created:      Mon May 09 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// FBM                  motor         17              
// BBM                  motor         18              
// LSM                  motor         12              
// RSM                  motor         13              
// VS10                 vision        10              
// Drivetrain           drivetrain    1, 20, 2, 21, 4 
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

void setDanger(int speed);
void shootShit();
void halt();

int threatLevel = 0;
int boxX1 = 120;
int boxY2 = 183;
int centerFOVX = 159;
int centerFOVY = 114;
int offsetX = 39;
int offsetY = 39;

int main() {

  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  //while(threatLevel == 0){
    //halt();
  //}
  setDanger(600);
  while(1){ 
    setDanger(600);
    Brain.Screen.clearScreen();//clear line
    Brain.Screen.setOrigin(1,1);
    Brain.Screen.drawRectangle(0,0,316,212);
    VS10.takeSnapshot(VS10__OBALL);

    if (VS10.largestObject.exists){
      Brain.Screen.drawRectangle(VS10.largestObject.originX, 100,  1000, color::orange);

      if (VS10.largestObject.centerX > centerFOVX + offsetX){
        Drivetrain.setDriveVelocity(400, rpm);
        Drivetrain.turn(right);
      } //end of if right
      else if (VS10.largestObject.centerX < centerFOVX - offsetX){
        Drivetrain.setDriveVelocity(400, rpm);
        Drivetrain.turn(left);
      } //end of else if left
      /*else if (VS10.largestObject.centerY > centerFOVY + offsetY){
        Drivetrain.stop(); 
      } //end of else if ahead
      else if (VS10.largestObject.centerY > centerFOVY - offsetY){
        Drivetrain.stop(); 
      } //end of else if behind*/

      else{//if(VS10.largestObject.centerX > boxX1 && VS10.largestObject.centerX < boxY2 && VS10.largestObject.centerY > boxY2 && VS10.largestObject.centerY){
        //wait(1,sec);
        shootShit(); 
        Drivetrain.stop();
      } //end of if
    }

  }// end of while 1
  
} // end of main 

void setDanger(int s){
  LSM.setVelocity(s, rpm);
  RSM.setVelocity(s, rpm);
}

void shootShit(){ //rotates belt+shooters
  FBM.spin(forward);
  BBM.spin(forward);
  LSM.spin(forward);
  RSM.spin(forward);
}


void halt(){
  FBM.stop(brakeType::brake);
  BBM.stop(brakeType::brake);
  LSM.stop(brakeType::brake);
  RSM.stop(brakeType::brake);
}