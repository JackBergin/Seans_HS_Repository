#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
limit LimitSwitchF = limit(Brain.ThreeWirePort.F);
limit LimitSwitchH = limit(Brain.ThreeWirePort.H);
controller Controller1 = controller(primary);
motor29 Wiper = motor29(Brain.ThreeWirePort.G, false);

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