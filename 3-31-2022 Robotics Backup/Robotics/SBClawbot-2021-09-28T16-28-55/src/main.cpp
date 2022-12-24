/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\seanbergin                                       */
/*    Created:      Tue Sep 28 2021                                           */
/*    Description:  On off debounce Clawbot with tank drive.                  */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// bumper1              bumper        A               
// L_motor              motor         1               
// R_motor              motor         21              
// Arm_motor            motor         3               
// Claw_motor           motor         8               
// L2_motor             motor         9               
// R2_motor             motor         2               
// RangeFinderC         sonar         C, D            
// Inertial             inertial      11              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

#include "robot-config.h"
  /* On Off Debounce / Tank Drive / Claw Bot
  Written by Sean Bergin for
  Coach L's Robotics class 9/28/2021*/

  // make local variables
  signed char on_off_debounce = 0;
  double initialMotorDegrees;
  

  while (1) {                   // infinitely loops
    Brain.Screen.clearScreen(); // clears info off screen
    // Print your and partner's name
    Brain.Screen.printAt(1, 60, "Sean and Chris's Program and Robot");
    // first # in line above = colums (1-470) while seond = rows (1-240)

    Brain.Screen.printAt(1, 80, "Primary Loop"); // orints "Primary Loop" to brain screen
    task::sleep(2000);          // wats 2 sec (2000 milliseconds)
    Brain.Screen.clearScreen(); // clears screen of info

    while (on_off_debounce == 1) { // drive loop
      // below line will print again on screen
      Brain.Screen.printAt(1, 80, "Manual Control Tank Drive / ClawBot Loop");
      // tank drive contol/2 joysticks
      R_motor.spin(directionType::rev, ((Controller1.Axis3.value() - Controller1.Axis1.value() - Controller1.Axis4.value()) / 3), velocityUnits::pct);
      L2_motor.spin(directionType::fwd, ((Controller1.Axis3.value() - Controller1.Axis1.value() + Controller1.Axis4.value()) / 3), velocityUnits::pct);
      L_motor.spin(directionType::fwd, ((Controller1.Axis3.value() + Controller1.Axis1.value() + Controller1.Axis4.value()) / 3), velocityUnits::pct);
      R2_motor.spin(directionType::rev, ((Controller1.Axis3.value() + Controller1.Axis1.value() - Controller1.Axis4.value()) / 3), velocityUnits::pct);
      // Update printed value on screen
      Brain.Screen.printAt(1, 100, "on_off_debounce = %d", on_off_debounce);       // prints debounce to screen
      Brain.Screen.printAt(1, 120, "Bumper1 = 1"); // prints bumper to screen
      Brain.Screen.printAt(1, 140, "ButtonB = 1"); // prints buttonB to screen

      if (RangeFinderC.distance(inches) <= 12){ //if it is less than or equal to 12 inches from wall
        Controller1.Screen.setCursor(1,1); //sets row and columb
        Controller1.Screen.print("Pot1= %d",RangeFinderC.distance(inches));//prints variable on 2,1
        Controller1.Screen.setCursor(3,1); //sets row and columb
        Controller1.Screen.print("STOP");//prints action on 3,1
        Controller1.rumble(".- . . -."); // Vibrate
      }

      if (bumper1.pressing() || Controller1.ButtonB.pressing()) { // If bumper1 switch is pressed, do
        // Otherwise continue down
        // If bumper is pressed, then program will wait here until
        // its released. Once released, debounce = 0, and display.
        while (bumper1.pressing() || Controller1.ButtonB.pressing()) { // while bumper1 switch is pressed
          // do nothing but wait in idle loop
          vex::task::sleep(100); //(SPG) slow down program
        }                        // end of while button1 loop

        // Once the bumper1 switch isn't pressed, program will continue
        // Change variable and print to screen
        on_off_debounce = 0;            // sets to end loop
        L_motor.stop(brakeType::brake); // stops motor
        R_motor.stop(brakeType::brake); // stops motor
        L2_motor.stop(brakeType::brake); // stops motor
        R2_motor.stop(brakeType::brake); // stops motor

        // UPDATE PRINTED VARIABLE TO SCREEN
        Brain.Screen.printAt(1, 100, "on_off_debounce = %d", on_off_debounce); // prints debounce to screen
        Brain.Screen.printAt(1, 120, "Bumper1 = 1");  // prints bumper to screen
        Brain.Screen.printAt(1, 140, "Bumper1 hit!"); // prints action to screen
        Brain.Screen.printAt(1, 160, "ButtonB = 1"); // prints buttonB to screen
        Brain.Screen.printAt(1, 180, "ButtonB hit!"); // prints action to screen
        vex::task::sleep(1000);                       //(SPG) Slow Down Program
      }                                               // end of if bumper1 loop

      // Arm ControlController.ButtonL1.pressing Arm is controlled by left
      // button on controller
      if (Controller1.ButtonL1.pressing()) { // top left button pressed
        Arm_motor.spin(directionType::fwd, 50, ::rpm); // raises arm
      } // end of if ButtonL1 loop

      else if (Controller1.ButtonL2.pressing()) { // bottom left button pressed
        Arm_motor.spin(directionType::rev, 50, velocityUnits::rpm); // changes motor direction
        // if bottom left button is pressed, lowering arm
      } // end of if ButtonL2 loop

      else {                             // default
        Arm_motor.stop(brakeType::hold); // if neither button is pushed
        // then stop arm where it is
      } // end of else loop

      // Claw ControlController.ButtonR1.pressing Arm is controlled by right
      // button on controller
      if (Controller1.ButtonR1.pressing()) { // top right button pressed
        Claw_motor.spin(directionType::fwd, 50, velocityUnits::rpm); // opens claw
      }                                      // end of if ButtonR1 loop

      else if (Controller1.ButtonR2.pressing()) { // bottom right button pressed
        Claw_motor.spin(directionType::rev, 50, velocityUnits::rpm); // closes claw
      }                                      // end of if ButtonR2 loop

      else {                              // default
        Claw_motor.stop(brakeType::hold); // if neither button is pushed holg
                                          // motor so arm doesn't fall
      }                                   // end of else loop
    }                                     // end on_off==1 loop

    task::sleep(200);           //(SPG) Slow Down Program
    Brain.Screen.clearScreen(); // clears screen of digits

    while (on_off_debounce == 0) { // stop loop
      // prints what loop youre in
      Brain.Screen.printAt(1, 80, "Stop Loop"); // print loop to robot's screen
      task::sleep(200);                        // SPG

      L_motor.stop(brakeType::brake); // Stops motor
      R_motor.stop(brakeType::brake); // Stops motor

      // update printed value of variable onscreen
      Brain.Screen.printAt(1, 100, "on_off_debounce = %d", on_off_debounce);       // prints debounce to screen
      Brain.Screen.printAt(1, 120, "Bumper1 = 1"); // prints bumper to screen
      Brain.Screen.printAt(1, 140, "ButtonB = 1"); // prints buttonB to screen

      if (bumper1.pressing() ||
          Controller1.ButtonB.pressing()) { // if button1 is hit
        // use a while loop to wait untile switch is released
        // if bumper1 pressed, program stalls here until
        // its release. Once released, on off debounce = 1
        while (bumper1.pressing() ||
               Controller1.ButtonB.pressing()) { // while bumper1 is hit
          // do nothing but wait
          vex::task::sleep(100); // SPG
        }                        // end of while bumper1 loop

        // once the bumper1 switch is not pressed, program continues
        // change the variable and print to screen
        Brain.Screen.clearScreen();
        on_off_debounce = 1; // change variable and send to Drive loop
        // update printed value of variable and send to drive loop
        Brain.Screen.printAt(1, 100, "on_off_debounce = %d", on_off_debounce); // prints debounce to screen
        Brain.Screen.printAt(1, 120, "Bumper1 = 1");  // prints bumper to screen
        Brain.Screen.printAt(1, 140, "Bumper1 hit!"); // prints action to screen
        Brain.Screen.printAt(1, 160, "ButtonB = 1"); // prints buttonB to screen
        Brain.Screen.printAt(1, 180, "ButtonB hit!"); // prints action to screen
        vex::task::sleep(1000);                       //(SPG) Slow Down Program
      }                                               // end of if bumper1 loop
      else if (Controller1.ButtonX.pressing()){
        Brain.Screen.clearScreen();
        on_off_debounce = 2;
      }
      
    } // end of stop loop

    while(on_off_debounce == 2){ //start ping pong (pp)
      // prints what loop youre in
      Brain.Screen.printAt(1, 80, "on_off_debounce = %d", on_off_debounce); // prints debounce to screen
      Brain.Screen.printAt(1, 100, "ButtonX = 1"); // prints buttonB to screen
      Brain.Screen.printAt(1, 120, "ButtonX hit!"); // prints action to screen
      Brain.Screen.printAt(1, 140, "Ping Pong Loop (pp)"); // print loop to robot's screen
      Brain.Screen.printAt(1, 160, "Distance from wall == %d", RangeFinderC.distance(inches)); // print loop to robot's screen
      task::sleep(200);                             // SPG

      if ((Controller1.ButtonX.pressing() || bumper1.pressing()) && on_off_debounce == 2){ //if button x is pressed, go to stop loop (stop loop escape)
        while ((Controller1.ButtonX.pressing() || bumper1.pressing())) { // while bumper1 switch is pressed
          // stop wheels and wait in idle loop
          L_motor.stop(brakeType::brake);
          L2_motor.stop(brakeType::brake);
          R_motor.stop(brakeType::brake);
          R2_motor.stop(brakeType::brake);
          vex::task::sleep(200); //(SPG) slow down program
        }                        // end of while button1 loop
        Brain.Screen.clearScreen();
        on_off_debounce = 0; //resets it to stop loop
      } //end stop loop escape
      
      if (RangeFinderC.distance(inches) > 12 && on_off_debounce == 2) { //pp drive loop
        //continue forward until robot is >= 12 inches from a wall
        L_motor.spin(directionType::fwd, 25, velocityUnits::pct);
        L2_motor.spin(directionType::fwd, 25, velocityUnits::pct);
        R_motor.spin(directionType::rev, 25, velocityUnits::pct);
        R2_motor.spin(directionType::rev, 25, velocityUnits::pct);
        Brain.Screen.clearScreen();
        Brain.Screen.printAt(1, 200, "far out"); // print loop to robot's screen
        initialMotorDegrees = L_motor.rotation(vex::rotationUnits::deg);
      } //end pp drive loop

      else if ((RangeFinderC.distance(inches) <= 12) && (on_off_debounce == 2)) { //pp stop and turn loop
        //stops all wheel movement once <= 12 inches from a wall
        L_motor.stop(brakeType::brake);
        L2_motor.stop(brakeType::brake);
        R_motor.stop(brakeType::brake);
        R2_motor.stop(brakeType::brake);


        //if ((L_motor.rotation(vex::rotationUnits::deg) - initialMotorDegrees) <= (360) && on_off_debounce == 2){ //rotates robot loop
        if (Inertial.rotation(deg) <= 180){ //rotates robot loop
          //can replace L_motor w/ inertial sensor values
          L_motor.spin(directionType::rev, 37.5, velocityUnits::pct);
          L2_motor.spin(directionType::rev, 37.5, velocityUnits::pct);
          R_motor.spin(directionType::rev, 37.5, velocityUnits::pct);
          R2_motor.spin(directionType::rev, 37.5, velocityUnits::pct);
        } //end rotate robot loop
        vex::task::sleep(2000); 

        L_motor.stop(brakeType::brake);
        L2_motor.stop(brakeType::brake);
        R_motor.stop(brakeType::brake);
        R2_motor.stop(brakeType::brake);
        Brain.Screen.clearScreen();
        Brain.Screen.printAt(1, 100, "close up"); // print loop to robot's screen
      } //end pp stop and turn loop
    } //end ping pong loop
  } // end of while1
} // end of main