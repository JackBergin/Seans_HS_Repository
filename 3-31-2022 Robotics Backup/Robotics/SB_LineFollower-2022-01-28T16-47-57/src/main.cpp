/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Student                                          */
/*    Created:      Fri Jan 28 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  while(1){
    Brain.Screen.printAt(10,60, "AR:"); //analog raw 
    Brain.Screen.printAt(100,60, "LLF = %d", LLF.value(analogUnits::pct));
    Brain.Screen.printAt(200,60, "MLF = %d", MLF.value(analogUnits::pct));
    Brain.Screen.printAt(300,60, "RLF = %d", RLF.value(analogUnits::pct));

    Brain.Screen.printAt(10,90, "R:"); //reflectivity
    Brain.Screen.printAt(100,90, "LLF = %d", LLF.reflectivity());
    Brain.Screen.printAt(200,90, "MLF = %d", MLF.reflectivity());
    Brain.Screen.printAt(300,90, "RLF = %d", RLF.reflectivity());

    Brain.Screen.printAt(10,120, "P:"); //normal percent
    Brain.Screen.printAt(100,120, "LLF = %d", LLF.value(pct)); 
    Brain.Screen.printAt(200,120, "MLF = %d", MLF.value(pct));
    Brain.Screen.printAt(300,120, "RLF = %d", RLF.value(pct));

    Brain.Screen.printAt(10,150, "12B:"); //12 bit range
    Brain.Screen.printAt(100,150, "LLF = %d", LLF.value(analogUnits::range12bit)); 
    Brain.Screen.printAt(220,150, "MLF = %d", MLF.value(analogUnits::range12bit));
    Brain.Screen.printAt(340,150, "RLF = %d", RLF.value(analogUnits::range12bit));
    
    vex::task::sleep(5);
  }
}
