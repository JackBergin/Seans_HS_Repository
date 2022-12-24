/*----------------------------------------------------------------------------*/
/*                                                                            */
/*  Module:     main.cpp                                                      */
/*  Author:     C:\Users\ckarvelas                                            */
/*  Created:    {9/22/21}                                                     */
/*  Description:  On Off debounce clawbotwith tank drive.                     */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Bumper1              bumper        A               
// L_motor              motor         1               
// R_motor              motor         21              
// Arm_motor            motor         3               
// Claw_motor           motor         8               
// L2_motor             motor         9               
// R2_motor             motor         2               
// ---- END VEXCODE CONFIGURED DEVICES ----
using namespace vex;
// R2 DOES NOT WORK, IT DOES NOT LOWER THE CLAW
// L2 CLOSES AND LOWERS CLAW?
// NEED TO MAKE IF BUMPER PRESSED AGAIN IT RE-ENABLES PROGRAM IF IT DOESNT ALREADY
 
int main() { // Main Loop
// Initializes Robot Config, **DONT REMOVE**
//vexcodeInit();
#include "robot-config.h"
// On/Off / Tank Drive / Clawbot
// Makes Local variables to record + hold data
signed char on_off_debounce = 1; // This starts the stop loop
 
 
while (1) { // Runs loop forever
Brain.Screen.clearScreen();
Brain.Screen.printAt(1, 60, "Sean bergin and Chris Karvelas Program & Robot");
Brain.Screen.printAt(1, 80, "Primary Loop"); // Prints to the Robot's screen
task::sleep(2000); // Waits for 2 seconds, every 1000 = 1 second
Brain.Screen.clearScreen();
 
 
   while (on_off_debounce == 1) { // The drive loop
        Brain.Screen.printAt(1, 80, "Manual Control Tank Drive / Clawbot Loop");
        Brain.Screen.printAt(1, 100, "on_off_debounce = %d", on_off_debounce);
        Brain.Screen.printAt(1, 120, "Bumper1= 1");
        // Updates the printed values on screen
        //L_motor.spin(directionType::rev, Controller1.Axis2.value(), velocityUnits::pct); // One joystick per motor
        //R_motor.spin(directionType::fwd, Controller1.Axis3.value(), velocityUnits::pct); // One joystick per motor

        //mechanum wheel drive
        R_motor.spin(directionType::rev, ((Controller1.Axis3.value() - Controller1.Axis1.value() - Controller1.Axis4.value()) / 3), velocityUnits::pct);
        L2_motor.spin(directionType::fwd, ((Controller1.Axis3.value() - Controller1.Axis1.value() + Controller1.Axis4.value()) / 3), velocityUnits::pct);
        L_motor.spin(directionType::fwd, ((Controller1.Axis3.value() + Controller1.Axis1.value() + Controller1.Axis4.value()) / 3), velocityUnits::pct);
        R2_motor.spin(directionType::rev, ((Controller1.Axis3.value() + Controller1.Axis1.value() - Controller1.Axis4.value()) / 3), velocityUnits::pct);

 
 
        if (Bumper1.pressing()) { // If bumperA switch is pressed do this otherwise continue down, goes till its let go
           
            while (Bumper1.pressing()) {
                vex::task::sleep(100); // Makes it wait
            } // End of While loop for button press
 
         on_off_debounce = 0;
         L_motor.stop(brakeType::brake); // Stops motor
         R_motor.stop(brakeType::brake);
         //Updates printed value of the variable
         Brain.Screen.printAt(1, 100, "on_off_debounce = %d", on_off_debounce);
         Brain.Screen.printAt(1, 120, "Bumper1= 0");
         Brain.Screen.printAt(100, 150, "Bumper1 Hit");
         vex::task::sleep(1000);
        } // End of BumperA press
 
        // Arm is controlled by left button on controller
        if (Controller1.ButtonL1.pressing()) {
            Arm_motor.spin(directionType::fwd,50,::rpm); // Raises arm if top left button
        } // End of Arm Raise
 
        else if (Controller1.ButtonL2.pressing()) { // Left bottom button press
            Arm_motor.spin(directionType::rev,50,velocityUnits::rpm); // Changes motor direction
        }// End of else if statement
 
        else { //Default
            Arm_motor.stop(brakeType::hold); // No buttons pushed then stops arm
        } // End of default
        // Opening claw system
        if (Controller1.ButtonR1.pressing()) {
            Claw_motor.spin(directionType::fwd,50,velocityUnits::rpm); // Top right button opens claw
        } // End of ButtonR1
 
        else if (Controller1.ButtonR2.pressing()) {
            Claw_motor.spin(directionType::rev,50,velocityUnits::rpm); // Changes motor direction
            // Bottom right button closes claw
        }// End of buttonR2
 
        else { // Default
            Claw_motor.stop(brakeType::hold); // No buttons pushed holds motor so arm doesn't fall
        } // End of if else loop
 
        if (Controller1.ButtonA.pressing()) {
          on_off_debounce = 0;
          Brain.Screen.printAt(100, 180, "Button 1 controller hit, turning off");
          task::sleep(500);//spd
        }//end of if statement
 
   } // End of drive loop
task::sleep(200);
Brain.Screen.clearScreen();
 
   while(on_off_debounce == 0) { // Stop loop
    Brain.Screen.printAt(1, 80, "Stop loop");
    Brain.Screen.printAt(1, 100, "on_off_debounce= %d", on_off_debounce);
    Brain.Screen.printAt(1, 120, "Bumper1 = 1");
    task::sleep(20);
 
    L_motor.stop(brakeType::brake);
    R_motor.stop(brakeType::brake);
 
    if (Bumper1.pressing()) { // Button 1 hit
        // If BumperA switch presssed program waits here till it's released,
        // when release variable of on_off_Debounce changes to 1
 
        while(Bumper1.pressing()) { // BumperA switch while loop
            vex::task::sleep(100);
        } // End
 
     on_off_debounce = 1;
     Brain.Screen.printAt(1, 100, "on_off_debounce= %d", on_off_debounce);
     Brain.Screen.printAt(1, 120, "Bumper1= 0");
     Brain.Screen.printAt(100, 150, "Bumper Hit");
     vex::task::sleep(1000);
    } // End of button1 hit
 
    if (Controller1.ButtonA.pressing()) {
      on_off_debounce = 1;
      Brain.Screen.printAt(100, 180, "Turned back on");
    }// end of if controller ButtonA pressed
 
   } // End of Stop Loop
 
 } // End of Forever loop
}// End of main loop