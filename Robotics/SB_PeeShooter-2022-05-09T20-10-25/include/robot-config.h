using namespace vex;

extern brain Brain;

using signature = vision::signature;

// VEXcode devices
extern motor FBM;
extern motor BBM;
extern motor LSM;
extern motor RSM;
extern signature VS10__OBALL;
extern signature VS10__SIG_2;
extern signature VS10__SIG_3;
extern signature VS10__SIG_4;
extern signature VS10__SIG_5;
extern signature VS10__SIG_6;
extern signature VS10__SIG_7;
extern vision VS10;
extern smartdrive Drivetrain;
extern controller Controller1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );