#ifndef CONVERT_H
#define CONVERT_H

#include "config.h"

// Convert radians to degrees
float radToDeg(double rad);
// Convert DEGREES to RADIANS
float degToRad(double deg);
// Convert Deg to Steps
int degToStep(int stepperNumber, double deg);
//Convert Steps To Deg
int StepToDeg(int stepperNumber, double step);

#endif