#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
bumper Bumper1 = bumper(Brain.ThreeWirePort.A);
motor L_motor = motor(PORT1, ratio18_1, false);
motor R_motor = motor(PORT21, ratio18_1, false);
motor Arm_motor = motor(PORT3, ratio18_1, false);
motor Claw_motor = motor(PORT8, ratio18_1, false);
motor L2_motor = motor(PORT9, ratio18_1, false);
motor R2_motor = motor(PORT2, ratio18_1, false);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}