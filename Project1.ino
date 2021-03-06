//      ******************************************************************
//      *                                                                *
//      *                            Project 1                           *
//      *      Project name: Robot Arm_________________________          *
//      *      Student name: Bonnie Dawson_____________________          *
//      *                                                                *
//      *      Copyright (c) Dos Pueblos Engineering Academy, 2017       *
//      *                                                                *
//      ******************************************************************


//
// declare IO pins below, ie: const byte LIMIT_SWITCH_1_PIN = 21;
//
const byte ARM_HOMING_PROX = 23; 
const byte PROXIMITY_PIN = 24;

const byte microStepping = 4;
const float accelerationInRpsps = 0.5;
const float stepperSpeed = 0.5;

//
// declare objects below, ie:  RCServo servo1;  or  SpeedyStepper stepper1;
//
SpeedyStepper stepper1;


const int transmissionRatio = 2;

byte project1WorkingFlag = true;

bool project1InitializedFlag;

void moveArmToTower(){
 stepper1.moveToPositionInRevolutions(0.25);
}

void towerToTower(){
  stepper1.moveToPositionInRevolutions(0);
  //stepper1.moveToPositionInRevolutions(0.4);

  bool senorDoesNotSeeMetal = digitalRead(PROXIMITY_PIN);

  if(senorDoesNotSeeMetal){
    stepper1.moveToPositionInRevolutions(0.4);
  }
}


// ---------------------------------------------------------------------------------

//
// setup for the project, typically used to configure its IO pins, this is only called 
// once when the arduino is first powered on
// Note: Things done here should take no time.  Setup procedures that take time (such as
// homing stepper motors) should be done in initializeProject1()
//
void setupProject1()
{ 


  //
  // start with flags indicate the project is working, but not yet initialized
  //
  project1WorkingFlag = true;
  project1InitializedFlag = false;


  //
  // configure IO pins below, ie: pinMode(24, OUTPUT);  or  pinMode(25, INPUT_PULLUP);
  //

  
  
  //
  // connect objects to pins below, ie: stepper1.connectToPort(1);  or  servo1.connectToPin(8);) 
  //
stepper1.connectToPort(1);

  //
  // set to true to indicate that this project is working
  //
  project1WorkingFlag = true;
}



//
// initialize the project, this includes setup steps that take time, such as homing a
// stepper motor.
//
void initializeProject1(void)
{
  //
  // return if not already initialized
  //
  if (project1InitializedFlag ==  true)
    return;


  //
  // initialize things that take time here
  //
  stepper1.setStepsPerRevolution(200 * microStepping * transmissionRatio);
  stepper1.setSpeedInRevolutionsPerSecond(stepperSpeed);
  stepper1.setAccelerationInRevolutionsPerSecondPerSecond(accelerationInRpsps);

  stepper1.moveToHomeInRevolutions(-1, stepperSpeed, 1, ARM_HOMING_PROX);
  

  project1InitializedFlag = true;
}



//
// enable the project, this is a good place to "enable" stepper motors or other high
// current devices, it is called everytime before the project runs
//
void enableProject1(void)
{
  //
  // enable high current devices below, ie: stepper1.enableStepper();
  //

  stepper1.enableStepper();
}



//
// disable the project, this is a good place to "disable" stepper motors or other high
// current devices, it is called after the project runs
//
void disableProject1(void)
{
  //
  // disable high current devices below, ie: stepper1.disableStepper();
  //
stepper1.disableStepper();
}



//
// run the project, return when the project completes
//
void runProject1(byte databyte)
{ 
  delay(500);
  moveArmToTower();
  delay(500);
  towerToTower();
  delay(500);
}



//
// call to deterime if this project is working
//    Exit:  true returned if working
//
bool isWorkingProject1(void)
{
  return(project1WorkingFlag);
}


// -------------------------------------- End --------------------------------------


