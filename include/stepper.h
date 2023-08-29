#ifndef STEPPER_H
#define STEPPER_H

#include <Arduino.h>
#include <AccelStepper.h>
#include <MultiStepper.h>
#include "convert.h"
#include "config.h"

// initialize stepper motors Pins
AccelStepper StepperA(1, 22, 23);
AccelStepper StepperX(1, 2, 5);
AccelStepper StepperY(1, 3, 6);
AccelStepper StepperZ(1, 4, 7);

// initializing multistepper controllers
MultiStepper multiStepper;

// MultiStepper positions variable for 3 Steppers
long MultiPositions[3];

// Arm Angles
float PsiA = 0;
float PsiX = 0;
float PsiY = 0;
float PsiZ = 0;

//Speed Variables
int SpeedA = 800;
int SpeedX = 800;
int SpeedY = 800;
int SpeedZ = 800;

//commande Angle
String commandeString;
int commande = 0;
int commandeX = 0;
int commandeY = 0;
int commandeZ = 0;
int commandeTheta = 0;
int direction = 0;
int cmp = 0;

void ResetPosition();
void SpeedSet();

// First Position
void GoToFirstPosition();
// Initialize position
void initial_position();
//  Set 2 Angles of the new target
void setJointAngles(float x, float y, float z);
void setJointAnglesWithTheta(float x,float y,float z,float theta);
void runToPosition(float x,float y,float z);
void runToPositionWithTheta(float x,float y,float z,float theta);
#endif