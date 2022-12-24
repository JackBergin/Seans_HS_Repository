#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
line RILF = line(Brain.ThreeWirePort.F);
line MILF = line(Brain.ThreeWirePort.G);
line LELF = line(Brain.ThreeWirePort.H);
motor leftFM = motor(PORT1, ratio18_1, false);
motor leftBM = motor(PORT9, ratio18_1, false);
motor rightFM = motor(PORT21, ratio18_1, false);
motor rightBM = motor(PORT2, ratio18_1, false);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}