#ifndef CONFIG_H
#define CONFIG_H

#define PI 3.141592653
#define JOINT1_RESOLUTION 0.060944641 /*  Joint1 resolution in degree  */
#define JOINT2_RESOLUTION 0.055333713 /*  Joint2 resolution in degree  */
#define JOINT3_RESOLUTION 0.055301333 /*  Joint3 resolution in degree  */
#define JOINT4_RESOLUTION 0.055301333 /*  Joint4 resolution in degree  */
#define X_INIT 132.86198              /*  x value of the initial position */
#define Y_INIT 0.00                   /*  y value of the initial position */
#define Z_INIT -25.3336658            /*  z value of the initial position */
#define SENS_SWITCH_DELAY 100         /*  Short delay, When switching the sens of the stepper */
#define MAX_ARM_RANGE 324             /*  The maximum range that the effector can reach */
#define l2 162.00                     /*  Length of the arm 2  */
#define l3 162.00                     /*  Length of the arm 3  */
#define l4 122.5                      /*  Length of the arm 4  */

// initialize Limit Switch Sensor
#define FcdA A8
#define FcdX A10
#define FcdY A9
#define FcdZ A11

#endif