#include "stepper.h"

// Reset Position For All Steppers
void ResetPosition()
{
  StepperA.setCurrentPosition(0);
  StepperX.setCurrentPosition(0);
  StepperY.setCurrentPosition(0);
  StepperZ.setCurrentPosition(0);
}

// set speeds of steppers
void SpeedSet()
{
  StepperA.setSpeed(SpeedA);
  StepperX.setSpeed(SpeedX);
  StepperY.setSpeed(SpeedY);
  StepperZ.setSpeed(SpeedZ);
}

// First Position
void GoToFirstPosition()
{
  SpeedA = -SpeedA;
  SpeedX = -SpeedX;
  SpeedY = -SpeedY;
  SpeedZ = -SpeedZ;

  MultiPositions[0] = degToStep(1,95);
  MultiPositions[1] = degToStep(2,150);
  MultiPositions[2] = degToStep(3,30);

  StepperZ.moveTo(degToStep(4,60));
  multiStepper.moveTo(MultiPositions);

  SpeedSet();

  while (multiStepper.run() || (StepperZ.distanceToGo()!=0))
  {
    //SpeedSet(); ////for test
    multiStepper.run();//runspeedtoposition
    StepperZ.runSpeed(); //run
  }

  ResetPosition();

  SpeedX = -SpeedX;
  SpeedY = -SpeedY;

  MultiPositions[0] = int(degToStep(1, 0));
  MultiPositions[1] = int(degToStep(2, 90));
  MultiPositions[2] = int(degToStep(3, 0));

  StepperZ.moveTo(degToStep(4,-90));
  multiStepper.moveTo(MultiPositions);

  SpeedSet();

  while (multiStepper.run() || (StepperZ.distanceToGo()!=0))
  {
    //SpeedSet();   //for test
    multiStepper.run();//runspeedtoposition
    StepperZ.runSpeed(); //run
  }
}

// Initialize position
void initial_position()
{
  SpeedA = -SpeedA;
  SpeedY = -SpeedY;
  SpeedSet();

  // Run while not Reading Steppers
  while (digitalRead(FcdA))
    StepperA.runSpeed();
  while (digitalRead(FcdX))
    StepperX.runSpeed();
  while (digitalRead(FcdY))
    StepperY.runSpeed();
  while (digitalRead(FcdZ))
    StepperZ.runSpeed();

  //ResetPosition();

  GoToFirstPosition();

}

//  Set 2 Angles of the new target //////////////////////NOT TESTED/////////////////////
void setJointAngles(float x, float y, float z)
{

  float a = sqrt(pow(x, 2) + pow(y, 2));
  float sphereRadius1 = sqrt(a * a + pow((z + l4), 2));
  float alpha1 = (a * a + pow((z + l4), 2) + pow(l3, 2) - pow(l2, 2)) / (2 * l3);
  float beta1 = atan((z + l4) / a);

  // Verifying that the new target is in the range of the arm
  if (sphereRadius1 <= MAX_ARM_RANGE)
  {

    if (x == 0)
      PsiA = 0;
    else
      PsiA = atan(y / x); // if(xt==0) O1_t=PI/2*sign(yt); else  O1_t=atan(yt/xt);
    PsiX = acos(alpha1 / sphereRadius1) + beta1;
    PsiY = acos((a - l3 * cos(PsiX)) / l2);

    // Converting angles from radians to degrees
    PsiA = radToDeg(PsiA);
    PsiX = radToDeg(PsiX);
    PsiY = radToDeg(PsiY);
    PsiZ = -90.00;
  }
}

void setJointAnglesWithTheta(float x,float y,float z,float theta)
{
  theta = degToRad(theta);
  float a = sqrt(pow(x, 2) + pow(y, 2));
  float A = sqrt(pow(x, 2) + pow(y, 2)) - (l4*cos(theta));
  float B = z - (l4*sin(theta));
  float granda = sqrt(pow(A, 2) + pow(B, 2));
  float alpha = (a*a + pow(z, 2) + pow(l4, 2) + pow(l3, 2) - pow(l2, 2) - (2*l4*cos(theta)*a) - (2*l4*sin(theta)*z)) / (2 * l3);
  float sphereRadius = sqrt(a * a + pow((z + l4), 2));
  float beta = atan(B / A);

  // Verifying that the new target is in the range of the arm
  if (sphereRadius <= MAX_ARM_RANGE)
  {

    if (x == 0)
      PsiA = 0;
    else
    PsiA = atan(y / x); // if(xt==0) O1_t=PI/2*sign(yt); else  O1_t=atan(yt/xt);
    PsiX = acos(alpha / granda) + beta;
    PsiY = acos((granda - l3 * cos(PsiX) - l4*cos(theta)) / l2);

    // Converting angles from radians to degrees
    PsiA = radToDeg(PsiA);
    PsiX = radToDeg(PsiX);
    PsiY = radToDeg(PsiY);
    PsiZ = radToDeg(theta);
  }

}