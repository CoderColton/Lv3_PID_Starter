//!     RA
// todo IN
//*     BO
//?     W!

#include "autonSelector.h"

// Todo list for auton selector
    // Change between autons with controller button
    // Variable to store the selected auton
    // Button to confirm the selection
    // Selector in a function

int selectedAuton = 1;
int confirmedAuton = 0;
const int numberOfAutons = 5;

void autonSelector(){
    bool prevPressed = false;
    while (!Controller.ButtonUp.pressing()){

        if (Controller.ButtonRight.pressing() && prevPressed == false && selectedAuton < numberOfAutons){
            prevPressed = true;
            selectedAuton++;
            // if (selectedAuton = numberOfAutons){
            //     selectedAuton = 1;
            // }
            // else{
            //     selectedAuton++;
            // }

        }
        else if (Controller.ButtonLeft.pressing() && prevPressed == false && selectedAuton > 1) {
            prevPressed = true;
            selectedAuton--;
            // if (selectedAuton = 1){
            //     selectedAuton = numberOfAutons;
            // }
            // else{
            //     selectedAuton--;
            // }
        }
        else if ((!Controller.ButtonLeft.pressing() && !Controller.ButtonRight.pressing()) && prevPressed == true){
            prevPressed = false;
        }
        // Print here
        Controller.Screen.clearScreen();
        Controller.Screen.setCursor(3, 1);
        Controller.Screen.print("Selected Auton: #" + selectedAuton);
        wait(20, msec);
    }
    confirmedAuton = selectedAuton; 
    Controller.Screen.clearScreen();
    Controller.Screen.setCursor(3, 1);
    Controller.Screen.print("Confirmed Auton: #" + confirmedAuton);
}