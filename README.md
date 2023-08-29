# Robotic Arm Control

## Project Overview

This project is designed to control a robotic arm with four joints, each driven by a NEMA17 stepper motor. The implementation leverages reverse kinematics equations to compute joint angles based on desired end effector positions in three-dimensional space.

## Key Components and Features

- **NEMA17 Stepper Motors:** Each of the four robotic arm joints is powered by a NEMA17 stepper motor, providing controlled and accurate rotational motion.

- **Reverse Kinematics Equations:** The heart of the project lies in the reverse kinematics equations implemented in the `stepper.c` source file. These equations determine the joint angles necessary to achieve desired end effector positions.

- **Arduino Mega Control:** The robotic arm's behavior is controlled by an Arduino Mega, which processes incoming X, Y, and Z position commands via serial communication.

- **Static Parameters in `config.h`:** The `config.h` header file contains static parameters that define the physical properties of the robotic arm. These parameters can be customized to match the specific characteristics of the arm.

- **Movement Algorithm in `main.cpp`:** The `main.cpp` source file uses the reverse kinematics equations implemented in `stepper.c` to calculate joint angles. It then implements an algorithm to move the robotic arm to the desired position based on the received X, Y, and Z positions sent over the serial port.

## Getting Started

To explore and adapt this project for your needs, follow these steps:

1. Set up the Arduino Mega with the necessary libraries and tools.
2. Study the reverse kinematics equations in the `stepper.c` source file.
3. Customize the parameters in the `config.h` header file to match the specifications of your robotic arm.
4. Examine the `main.cpp` source file to understand how the algorithm for moving the arm is implemented.
5. Upload the code to the Arduino Mega and connect the robotic arm.
6. Send X, Y, and Z position commands over the serial port to see the robotic arm move to desired positions.

## Contributions and Acknowledgments

This project has benefited from contributions and insights from various individuals. Special thanks to:

- Ahmed Blekhiri ([@ahmed](https://github.com/AHMED-BELKHIRI))

## License

This project is licensed under the [MIT License](LICENSE). Feel free to explore, modify, and adapt the code to suit your needs.

For questions or assistance, contact me at marouene.kaaniche@insat.ucar.tn .
