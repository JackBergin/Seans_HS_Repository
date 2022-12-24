#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
/*vex-vision-config:begin*/
signature VS10__GBALL = signature (1, -4097, -3239, -3668, -4025, -2657, -3341, 3.8, 0);
signature VS10__PINK = signature (2, 5769, 6213, 5991, 221, 633, 427, 5.2, 0);
signature VS10__PURP = signature (3, 1137, 1639, 1388, 3459, 4297, 3878, 2.4, 0);
vision VS10 = vision (PORT10, 76, VS10__GBALL, VS10__PINK, VS10__PURP);
/*vex-vision-config:end*/
/*vex-vision-config:begin*/
vision AM = vision (PORT8, 50);
/*vex-vision-config:end*/
motor CM = motor(PORT3, ratio18_1, false);
motor leftMotorA = motor(PORT1, ratio18_1, false);
motor leftMotorB = motor(PORT9, ratio18_1, false);
motor_group LeftDriveSmart = motor_group(leftMotorA, leftMotorB);
motor rightMotorA = motor(PORT21, ratio18_1, true);
motor rightMotorB = motor(PORT2, ratio18_1, true);
motor_group RightDriveSmart = motor_group(rightMotorA, rightMotorB);
drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 319.19, 295, 40, mm, 1);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}