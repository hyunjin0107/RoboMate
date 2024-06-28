#include <VarSpeedServo.h> // Add Servo library

const int buttonPin = 2;  
const int redLEDPin = 12;
const int blueLEDPin = 13;

VarSpeedServo servo1; // Create object Servos 1, 2, 3, and 4
VarSpeedServo servo2;
VarSpeedServo servo3;
VarSpeedServo servo4;

int valAng1 = 90; // Define and initialize variable angles for servos
int valAng2 = 130;
int valAng3 = 90;
int valAng4 = 90;

void setup() {
    pinMode(buttonPin, INPUT); // Set button pin as input
    pinMode(redLEDPin, OUTPUT); // Set red LED pin as output
    pinMode(blueLEDPin, OUTPUT); // Set blue LED pin as output

    servo1.attach(3); // Attaches Servos to corresponding PWM Pins 3, 6, 5, and 9
    servo2.attach(6);
    servo3.attach(5);
    servo4.attach(9);
}

bool robotActive = false; // Boolean variable to track the state of the robot
bool lastButtonState = false; // Boolean variable to track the last (most recent) button state
bool buttonState = false; // Boolean variable to track the current button state

void loop() {

    buttonState = digitalRead(buttonPin); // Read the current state of the button

    // Check if the button state has changed
    if (buttonState != lastButtonState) {
        // Check if the button is pressed
        if (buttonState == LOW) {
            // Toggle the state of the robot
            robotActive = true;  
        }
        // Update the lastButtonState
        lastButtonState = buttonState;
    }

    // Check if robot is active (if condition)
    if (robotActive) { 
        
        servo1.write(120, 20, true); // Rotate robot to position C7 (int angle, int speed, bool wait)
        delay(1000);
        
        // Move down to grab C7 piece 
        servo2.write(46, 20, true); // Move upper arm down
        delay(1000);
        servo3.write(96, 20, true); // Move lower arm away from base
        delay(1000);
        servo4.write(0, 20, true); // Close end-effector to grab piece
        delay(1000);
        
        // Move up with the piece
        servo3.write(90, 20, true); // Move lower arm towards base
        delay(1000);
        servo2.write(130, 20, true); // Move upper arm up
        delay(1000);
        
        // Move to position C6 
        servo1.write(114, 20, true); // Rotate to C6
        delay(1000);
        
        // Move down to place the piece on C6
        servo2.write(66, 20, true); // Move upper arm down
        delay(1000);
        servo3.write(110, 20, true); // Move lower arm away from base
        delay(1000);
        servo4.write(90, 20, true); // Open end-effector to release piece
        delay(1000);
        
        // Move up to end position
        servo3.write(90, 20, true); // Move lower arm towards base
        delay(1000);
        servo2.write(130, 20, true); // Move upper arm up
        delay(1000);
        servo1.write(90, 20, true); // Rotate to initial position
        
        // Blink blue LED after pawn moves to signal the end of robot's turn
        for (int i = 0; i < 3; i++) { // Blink LED 3 times (for-loop)
            digitalWrite(blueLEDPin, HIGH); // Turn blue LED on
            delay(500);
            digitalWrite(blueLEDPin, LOW); // Turn blue LED off
            delay(500);
        }



        delay(4000); // Wait 4 seconds for other player to move



        // Move down without knocking down Queen piece
        servo2.write(48, 20, true); // Move upper arm down
        delay(1000);
        servo3.write(70, 20, true); // Move lower arm towards base
        delay(1000);
        servo1.write(140, 20, true); // Rotate robot to position D8
        delay(1000);

        // Adjust arm to grab D8 piece
        servo3.write(90, 20, true); // Move lower arm away from base
        delay(1000);
        servo4.write(0, 20, true); // Close end-effector to grab piece
        delay(1000);
        
        // Move up with the piece
        servo2.write(130, 20, true); // Move upper arm up
        delay(1000);
        
        // Rotate to position A5 (high enough not to touch other pieces)
        servo1.write(88, 20, true); 
        delay(1000);
        
        // Move down to place the piece at A5
        servo2.write(79, 20, true); // Move upper arm down
        delay(1000);
        servo3.write(120, 20, true); // Move lower arm away from base
        delay(1000);
        servo4.write(90, 20, true); // Open end-effector to release piece
        delay(1000);
        
        // Move up to end position (same as inital position)
        servo3.write(90, 20, true); // Move lower arm towards base
        delay(1000);
        servo2.write(130, 20, true); // Move upper arm up
        delay(1000);
        servo1.write(90, 20, true); // Rotate to initial position

        // Blink blue LED after Queen move
        for (int i = 0; i < 10; i++) {
            digitalWrite(blueLEDPin, HIGH);
            delay(500);
            digitalWrite(blueLEDPin, LOW);
            delay(500);
        }
        
        // Ensure red LED never turns on
        digitalWrite(redLEDPin, LOW);
        
        // Wait for next button press to start again
        while (digitalRead(buttonPin) == LOW) {
            delay(10);
        }
    }
}