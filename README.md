# Robotic Arm Servo Position and Movement Controller

This repository contains code for controlling a robotic arm using servo motors and joystick inputs. The system provides real-time feedback of servo angles and executes predefined movements, such as a Fool's Mate sequence in chess.

## Table of Contents
- [Hardware Setup](#hardware-setup)
- [Installation](#installation)
- [Usage](#usage)
- [Code Overview](#code-overview)
- [Functions](#functions)

## Hardware Setup

### Components
- 4 Servo Motors
- 2 Joysticks
- Push Button
- Red LED
- Blue LED
- Arduino Board
- Breadboard and Connecting Wires

### Pin Connections
- Servo Motors:
  - Servo 1: D3
  - Servo 2: D5
  - Servo 3: D6
  - Servo 4: D9
- Joystick 1:
  - X-axis: A2
  - Y-axis: A5
  - Z-axis: Pin 7
- Joystick 2:
  - X-axis: A3
  - Y-axis: A4
  - Z-axis: Pin 8
- Push Button: Pin 2
- Red LED: Pin 12
- Blue LED: Pin 13

## Installation

1. **Open the project in the Arduino IDE:**
    - Navigate to the project directory and open the `.ino` files with the Arduino IDE.

2. **Install the required libraries:**
    - Go to `Sketch` > `Include Library` > `Manage Libraries...`
    - Search for `Servo` and install it.
    - Search for `VarSpeedServo` and install it.

## Usage

1. **Upload the angle determination code:**
    - Connect your Arduino board to your computer.
    - Open `Angle_Determination.ino` in the Arduino IDE.
    - Select the appropriate board and port.
    - Click the Upload button.
    - Use the joysticks to control the robotic arm and view the servo angles in the Serial Monitor (set the baud rate to 9600).

2. **Upload the movement sequence code:**
    - Connect your Arduino board to your computer.
    - Open `Movement_Sequence.ino` in the Arduino IDE.
    - Select the appropriate board and port.
    - Click the Upload button.
    - Press the button to toggle the robot's activation state and execute the predefined movement sequence (Fool's Mate in chess).
    - Observe the LED feedback and robotic arm movements.

## Code Overview

### Angle Determination Code (`Angle_Determination.ino`)

The purpose of this code is to read joystick inputs and control the robotic arm, displaying the current servo angles in the Serial Monitor. This helps in determining the desired positions and predefined coordinates for the robotic arm movements.

### Movement Sequence Code (`Movement_Sequence.ino`)

This code uses the predefined coordinates obtained from the angle determination code to execute specific movements, such as a Fool's Mate sequence in chess. The system includes activation control via a push button and feedback through LEDs.

## Functions

### Angle Determination Code Functions

- **claw()**
  - Controls the opening and closing of the robotic arm's claw based on joystick inputs.
  
- **turn()**
  - Rotates the base of the robotic arm left or right.

- **lower_arm()**
  - Controls the movement of the lower arm.

- **upper_arm()**
  - Controls the movement of the upper arm.

### Movement Sequence Code Functions

- **Predefined Movements**
  - Executes specific moves, such as moving a pawn from C6 to C5 and the queen from D8 to A5.
  
- **LED Feedback**
  - Blinks the blue LED to signal the end of the robot's turn and if the robot wins.
