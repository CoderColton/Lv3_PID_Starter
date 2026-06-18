#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;

// Drive Motors
motor rightBack = motor(PORT6, ratio18_1, true);
motor rightFront = motor(PORT4, ratio18_1, true);
motor rightMiddle = motor(PORT5, ratio18_1, true);

motor leftFront = motor(PORT3, ratio18_1, false);
motor leftBack = motor(PORT1, ratio18_1, false);
motor leftMiddle = motor(PORT2, ratio18_1, false);

// Controller
controller Controller = controller(primary);

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
  // Nothing to initialize
}