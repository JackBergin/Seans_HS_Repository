using namespace vex;

extern brain Brain;

using signature = vision::signature;

// VEXcode devices
extern signature VS10__GBALL;
extern signature VS10__PINK;
extern signature VS10__PURP;
extern signature VS10__SIG_4;
extern signature VS10__SIG_5;
extern signature VS10__SIG_6;
extern signature VS10__SIG_7;
extern vision VS10;
extern signature AM__SIG_1;
extern signature AM__SIG_2;
extern signature AM__SIG_3;
extern signature AM__SIG_4;
extern signature AM__SIG_5;
extern signature AM__SIG_6;
extern signature AM__SIG_7;
extern vision AM;
extern motor CM;
extern drivetrain Drivetrain;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );