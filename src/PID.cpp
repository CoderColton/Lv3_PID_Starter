#include "PID.h"
#include "vex.h"

void PID(double target, double maxIntegral, double tolerance){
  
  //Initialize remaining variables
  double error = target;
  double measuredValue = 0;
  const double gearRatio = 3.0/5; // Small gear = 3 and big gear = 5. 3/5 is the gear ratio
  const double wheelCircumference = M_PI * 3.25; // 3.25 is the diameter of the wheels
  double outputSpeed = 0;

  double derivative = 0;
  double integral = 0;
  double lastError = error;
  double total = 0;

  // K basically means the strength of each part of PID
  double kP = 0;
  double kI = 0;
  double kD = 0;

  leftFront.setPosition(0, turns);
  leftFront.setPosition(0, degrees);

  //Main loop, when the robot is more than the desired distance from the target
  while(error > tolerance){

    //Calculate how far the robot is from the target
    measuredValue = wheelCircumference * leftFront.position(turns) * gearRatio;
    error = target - measuredValue;

    //Find integral value

    
    //Prevent integral windup by capping the maximum integral value


    //Find derivative value

    
    //Calculate the target speed for the drivetrain
    outputSpeed = kP * error;

    //Spin drivetrain at the target speed
    /*
    leftBack.spin();
    rightBack.spin();
    leftFront.spin();
    rightFront.spin();
    leftMiddle.spin();
    rightMiddle.spin();
    */


    //Short wait to save resources
    wait(15, msec);
  }
  //Brake motors after driving is finished
  leftBack.stop(brake);
  rightBack.stop(brake);
  rightFront.stop(brake);
  leftFront.stop(brake);
  leftMiddle.stop(brake);
  rightMiddle.stop(brake);
  //Short delay to come to a full stop
  wait(50, msec);
}