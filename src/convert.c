#include "convert.h"


// Convert radians to degrees
float radToDeg(double rad)
{
  return (rad * 360 / (2 * PI));
}
// Convert DEGREES to RADIANS
float degToRad(double deg)
{
  return (deg * (2 * PI) / 360);
}

// Convert Deg to Steps
int degToStep(int stepperNumber, double deg)
{
  if (stepperNumber == 1)
    return (int(deg / JOINT1_RESOLUTION));
  if (stepperNumber == 2)
    return (int(deg / JOINT2_RESOLUTION));
  if (stepperNumber == 3)
    return (int(deg / JOINT3_RESOLUTION));
  if (stepperNumber == 4)
    return (int(deg / JOINT4_RESOLUTION));
}

//Convert Steps To Deg
int StepToDeg(int stepperNumber, double Step)
{
  if (stepperNumber == 1)
    return (int(Step * JOINT1_RESOLUTION));
  if (stepperNumber == 2)
    return (int(Step * JOINT2_RESOLUTION));
  if (stepperNumber == 3)
    return (int(Step * JOINT3_RESOLUTION));
  if (stepperNumber == 4)
    return (int(Step * JOINT4_RESOLUTION));
}
