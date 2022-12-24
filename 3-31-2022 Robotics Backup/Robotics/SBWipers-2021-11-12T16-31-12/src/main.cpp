/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Sean Bergin                                               */
/*    Created:      Fri Nov 12 2021                                           */
/*    Description:  Wipes wiper at 6 different speeds.                         */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LimitSwitchF         limit         F               
// LimitSwitchH         limit         H               
// Controller1          controller                    
// Wiper                motor29       G               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;
void wipe(double cv); //initialized wipe method
int on_off_debounce = 0; //initializes and declares ood as 0
int level = 0; //makes default level stop loop
bool togHit = false; //makes wiper wipe towards LimitSwitchH
bool isInter; //checks if it is in the intermediate loop

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  while(1){ //allows for program to start
    Brain.Screen.printAt(0, 100, "Press X to Begin"); 

    if (Controller1.ButtonX.pressing()){ //when x is pressed
      Brain.Screen.clearScreen();
      on_off_debounce = 3;
    }

    while (on_off_debounce == 3){ //begins ood 3
      while (level == 0){ //stop level
        Brain.Screen.printAt(0, 100, "Level: Off"); //prints level
        vex::task::sleep(2000); //SPD (slow program down)

        if (Controller1.ButtonUp.pressing()){ //if up button pressed, then adjust accordingly
          level++; //faster
          Brain.Screen.clearScreen();
          Wiper.stop(); //stops wiper at start pos...
          vex::task::sleep(500); //...and waits for .5 seconds
        } else if (Controller1.ButtonDown.pressing()){
          Brain.Screen.printAt(0, 120, "Can't go lower than 0 speed"); //prevents level from going less than 0
          vex::task::sleep(200); //spd
          Brain.Screen.clearScreen();
        }
      } //end of stop

      while (level == 1){ //intermediate level
        Brain.Screen.printAt(0, 100, "Level: Intermediate"); //prints level
        isInter = true; //is intermediate level boolean
        wipe(60); //wipe at 60% power

        if (Controller1.ButtonUp.pressing()){
          level++; //level up
          Brain.Screen.clearScreen();
          isInter = false; //not intermediate anymore
          Wiper.stop(); //stops wiper at start pos...
          vex::task::sleep(500); //...and waits for .5 seconds
        } else if (Controller1.ButtonDown.pressing()){
          level--; //level down
          Brain.Screen.clearScreen();
          isInter = false; //not intermediate anymore
          Wiper.stop(); //stops wiper at start pos...
          vex::task::sleep(500); //...and waits for .5 seconds
        }
      } //end of int

      while (level == 2){ //low level
        Brain.Screen.printAt(0, 100, "Level: Slow"); //prints level
        wipe(60); //wipe at 60% power

        if (Controller1.ButtonUp.pressing()){
          level++; //level up
          Brain.Screen.clearScreen();
          Wiper.stop(); //stops wiper at start pos...
          vex::task::sleep(500); //...and waits for .5 seconds
        } else if (Controller1.ButtonDown.pressing()){
          level--; //level down
          Brain.Screen.clearScreen();
          Wiper.stop(); //stops wiper at start pos...
          vex::task::sleep(500); //...and waits for .5 seconds
        }
      } //end of low

      while (level == 3){ //med level
        Brain.Screen.printAt(0, 100, "Level: Medium"); //prints level
        wipe(70); //wipe at 70% power

        if (Controller1.ButtonUp.pressing()){
          level++; //level up
          Brain.Screen.clearScreen();
          Wiper.stop(); //stops wiper at start pos...
          vex::task::sleep(500); //...and waits for .5 seconds
        } else if (Controller1.ButtonDown.pressing()){
          level--; //level down
          Brain.Screen.clearScreen();
          Wiper.stop(); //stops wiper at start pos...
          vex::task::sleep(500); //...and waits for .5 seconds
        }
      } //end of med

      while (level == 4){ //high level
        Brain.Screen.printAt(0, 100, "Level: Fast"); //prints level
        wipe(87); //wipe at 87% power

        if (Controller1.ButtonUp.pressing()){
          level++; //level up
          Brain.Screen.clearScreen();
          Wiper.stop(); //stops wiper at start pos...
          vex::task::sleep(500); //...and waits for .5 seconds
        } else if (Controller1.ButtonDown.pressing()){
          level--; //level down
          Brain.Screen.clearScreen();
          Wiper.stop(); //stops wiper at start pos...
          vex::task::sleep(500); //...and waits for .5 seconds
        } 
      } //end of high

      while (level == 5){ //insane level
        Brain.Screen.printAt(0, 100, "Level: Insane"); //prints level
        wipe(100); //wipes at 100% power

        if (Controller1.ButtonUp.pressing()){
          level = 0; //resets back to stop loop
          Brain.Screen.clearScreen(); 
          Wiper.stop(); //stops wiper at start pos...
          vex::task::sleep(500); //...and waits for .5 seconds
        } else if (Controller1.ButtonDown.pressing()){
          level--; //level down
          Brain.Screen.clearScreen();
          Wiper.stop(); //stops wiper at start pos...
          vex::task::sleep(500); //...and waits for .5 seconds
        }
      } //end of ins

    } //end o_f_d 3
  } //end of while(1)
} //end of main

void wipe(double cervoSpeed) { //wiping action

  while (togHit == false) { //when LimitSwitchF is the last one hit...
    Wiper.spin(directionType::fwd, cervoSpeed, velocityUnits::pct); //...it spins wiper clockwise

    if (LimitSwitchH.pressing() == true){ //
      Wiper.stop(); //stops before direction change
      togHit = true; //changes direction
    } //end if LimitH
  } //end while togHit false
  while (togHit == true) { //when LimitSwitchH is the last one hit...
    Wiper.spin(directionType::rev, cervoSpeed, velocityUnits::pct); //spins wiper counterclockwise

    if (LimitSwitchF.pressing() == true){
      Wiper.stop(); //stops before direction change
      
      if (isInter) { //pauses on one side for intermediate level
        vex::task::sleep(3000); //the pause
      } 
      togHit = false; //changes direction
    } //end LimitF
  } //end while togHit false
} //end wipe method
