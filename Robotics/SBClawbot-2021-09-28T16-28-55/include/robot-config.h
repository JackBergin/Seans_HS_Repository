using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern bumper bumper1;
extern motor L_motor;
extern motor R_motor;
extern motor Arm_motor;
extern motor Claw_motor;
extern motor L2_motor;
extern motor R2_motor;
extern sonar RangeFinderC;
extern inertial Inertial;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );