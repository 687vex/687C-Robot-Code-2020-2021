// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// frontLeft            motor         1               
// frontRight           motor         10              
// backLeft             motor         11              
// backRight            motor         20                         
// ---- END VEXCODE CONFIGURED DEVICES ----
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Miguel VF                                                 */
/*    Created:      Sun Apr 26 2020                                           */
/*    Description:  X-drive go  brrr!!!                                       */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*Drive used: Holonomic Drive/X Drive
  X-drive configuration:
        X FRONT X
      X           X
    X  FL       FR  X
            X
           AXIS
            X
    X  BL       BR  X
      X           X
        X  BACK  X
*/

#include "vex.h"
using namespace vex;

// Competition
competition Competition;

void pre_auton(void) {}
// Autonomous Robot Movement
void autonomous(void) {
  while (true) // While true is true, repeat the commands in the next {}
  {
    while (!Brain.Screen.pressing()) {} // while the screen is not being pressed, do nothing
    Brain.Screen.printAt(Brain.Screen.xPosition(), Brain.Screen.yPosition(), "Ouch"); // print 'Ouch' where the screen was pressed
  }
}

void drivercontrol(void) {
  while (true) {
    // spin to win 
    frontLeft.spin(directionType::fwd,Controller1.Axis3.value()  + Controller1.Axis4.value() + Controller1.Axis1.value(), velocityUnits::pct);
    frontRight.spin(directionType::rev,Controller1.Axis3.value() - Controller1.Axis4.value() - Controller1.Axis1.value(), velocityUnits::pct);
    backLeft.spin(directionType::fwd,Controller1.Axis3.value()   - Controller1.Axis4.value() + Controller1.Axis1.value(), velocityUnits::pct);
    backRight.spin(directionType::rev,Controller1.Axis3.value()  + Controller1.Axis4.value() - Controller1.Axis1.value(), velocityUnits::pct);
  }
}

// Set up  competition and callbacks
int main() {
  Brain.Screen.print("Hello World!\n");
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  // Callbacks for autonomous and driver control
  // Run pre-autonomous function.
  pre_auton();
  Competition.autonomous(autonomous);
  Competition.drivercontrol(drivercontrol);
}