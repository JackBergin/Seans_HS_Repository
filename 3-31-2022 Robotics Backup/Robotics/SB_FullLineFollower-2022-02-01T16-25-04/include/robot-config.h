using namespace vex;

extern brain Brain;

// VEXcode devices
extern line RILF;
extern line MILF;
extern line LELF;
extern motor leftFM;
extern motor leftBM;
extern motor rightFM;
extern motor rightBM;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );