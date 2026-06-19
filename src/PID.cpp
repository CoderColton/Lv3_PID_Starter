#include "PID.h"
#include "vex.h"

void PID(double target, double maxIntegral, double tolerance){
  
  //Initialize remaining variables
  double error = target;
  double measuredValue = 0;
  const double gearRatio = 5.0/3; // Small gear = 3 and big gear = 5. 5/3 is the gear ratio
  const double wheelCircumference = M_PI * 3.25; // 3.25 is the diameter of the wheels

  const double deltaTime = 0.015; // Time between each iteration (msec)
  double derivative = 0;
  double integral = 0;
  double lastError = error;
  double outputSpeed = 0;

  // K basically means the strength of each part of PID. These are all called tuning constants
  double kP = 4;
  double kI = 0.01;
  double kD = 0.3;

  // reset the "Rototions tracker"
  leftFront.setPosition(0, degrees);

  //Main loop, when the robot is more than the desired distance from the target
  while(fabs(error) > tolerance){

    //Calculate how far the robot is from the target
    measuredValue = (leftFront.position(degrees)/360) * (wheelCircumference / gearRatio);
    lastError = error;
    error = target - measuredValue;

    //Find integral value
    integral += error * deltaTime;

    //Prevent integral windup by capping the maximum integral value
    if (integral > maxIntegral){
      integral = maxIntegral;
    }
    else if (integral < -maxIntegral){
      integral = -maxIntegral;
    }


    //Find derivative value
    derivative = ((error - lastError)/*rise*/ / deltaTime) /*run*/;
    
    //Calculate the target speed for the drivetrain
    outputSpeed = (kP * error) + (integral * kI) + (derivative * kD);

    //Spin drivetrain at the target speed
    leftBack.spin(forward, outputSpeed, percent);
    rightBack.spin(forward, outputSpeed, percent);
    leftFront.spin(forward, outputSpeed, percent);
    rightFront.spin(forward, outputSpeed, percent);
    leftMiddle.spin(forward, outputSpeed, percent);
    rightMiddle.spin(forward, outputSpeed, percent);

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