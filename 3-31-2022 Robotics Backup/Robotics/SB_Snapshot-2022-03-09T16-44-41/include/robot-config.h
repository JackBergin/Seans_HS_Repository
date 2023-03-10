using namespace vex;

extern brain Brain;

using signature = vision::signature;

// VEXcode devices
extern signature CAM__SIG_1;
extern signature CAM__SIG_2;
extern signature CAM__SIG_3;
extern signature CAM__SIG_4;
extern signature CAM__SIG_5;
extern signature CAM__SIG_6;
extern signature CAM__SIG_7;
extern vision CAM;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );