#include <Arduino.h>
#include <math.h>
#include "config.h"
#include "convert.h"
#include "stepper.h"


void setup()
{
  //Set Max Speed For Each Stepper Motor
  StepperA.setMaxSpeed(1000);
  StepperX.setMaxSpeed(1000);
  StepperY.setMaxSpeed(1000);
  StepperZ.setMaxSpeed(1000);

  //Adding Steppers A,X and Y to multiStepper 
  multiStepper.addStepper(StepperA);
  multiStepper.addStepper(StepperX);
  multiStepper.addStepper(StepperY);

  //Setting PinMode to each Limit Switch Sensor
  pinMode(FcdA, INPUT_PULLUP);
  pinMode(FcdX, INPUT_PULLUP);
  pinMode(FcdY, INPUT_PULLUP);
  pinMode(FcdZ, INPUT_PULLUP);

  initial_position();

  Serial.begin(9600);
  Serial.setTimeout(1000);
}

void loop()
{
  while(cmp < 4){
  if(Serial.available() > 0){
  if(cmp == 0){
    Serial.println("Donner x : ");
    commandeString = Serial.readString();
    commandeX = commandeString.toInt();
    Serial.println(commandeX);
    cmp ++;
  }
  if(cmp == 1){
    Serial.println("Donner y : ");
    commandeString = Serial.readString();
    commandeY = commandeString.toInt();
    Serial.println(commandeY);
    cmp ++; 
  }
  if(cmp == 2){
    Serial.println("Donner z : ");
    commandeString = Serial.readString();
    commandeZ = commandeString.toInt();
    Serial.println(commandeZ);
    cmp ++; 
  }
  if(cmp == 3){
    Serial.println("Donner theta : ");
    commandeString = Serial.readString();
    commandeTheta = commandeString.toInt();
    Serial.println(commandeTheta);
    cmp ++;
  }
  }
  }
  runToPosition(commandeX,commandeY,commandeZ);
}