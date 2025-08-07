#include <Servo.h>

// Motor Pin Assignments 
// Motor A (Left Front)
const int motorA_in1 = 3;
const int motorA_in2 = 2;
const int motorA_en  = 4;

// Motor B (Right Front)
const int motorB_in1 = A3;
const int motorB_in2 = A4;
const int motorB_en  = A5;

// Ultrasonic Sensor
const int pingPin = A0;

// Servo Motor 
const int servoPin = A1;
Servo myServo;

void setup() {
  // Set motor pins as output
  pinMode(motorA_in1, OUTPUT);
  pinMode(motorA_in2, OUTPUT);
  pinMode(motorA_en,  OUTPUT);

  pinMode(motorB_in1, OUTPUT);
  pinMode(motorB_in2, OUTPUT);
  pinMode(motorB_en,  OUTPUT);

  // Enable motors
  digitalWrite(motorA_en, HIGH);
  digitalWrite(motorB_en, HIGH);

  // Initialize servo
  myServo.attach(servoPin);
  myServo.write(90); // Center position
}

void moveForward() {
  digitalWrite(motorA_in1, HIGH);
  digitalWrite(motorA_in2, LOW);
  digitalWrite(motorB_in1, LOW);
  digitalWrite(motorB_in2, HIGH);
}

void moveBackward() {
  digitalWrite(motorA_in1, LOW);
  digitalWrite(motorA_in2, HIGH);
  digitalWrite(motorB_in1, HIGH);
  digitalWrite(motorB_in2, LOW);
}

void turnRight() {
  digitalWrite(motorA_in1, HIGH);
  digitalWrite(motorA_in2, LOW);
  digitalWrite(motorB_in1, LOW);
  digitalWrite(motorB_in2, LOW);
}

void stopMotors() {
  digitalWrite(motorA_in1, LOW);
  digitalWrite(motorA_in2, LOW);
  digitalWrite(motorB_in1, LOW);
  digitalWrite(motorB_in2, LOW);
}

long readDistanceCM() {
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin, LOW);

  pinMode(pingPin, INPUT);
  long duration = pulseIn(pingPin, HIGH);

  // Calculate distance in cm (speed of sound = 343 m/s)
  long distance = duration * 0.034 / 2;
  return distance;
}

void scanWithServo() {
  myServo.write(0);
  delay(300);
  myServo.write(90);
  delay(300);
  myServo.write(180);
  delay(300);
  myServo.write(90);
  delay(300);
}

void loop() {
  long distance = readDistanceCM();

  if (distance > 0 && distance < 10) {
    stopMotors();
    delay(500);

    scanWithServo();  // Scan area

    moveBackward();
    delay(3000);       // Move back for 3 seconds
	  turnRight();
	  delay(2000);	     // Move Right for 2 second
  } else {
    moveForward();     // Keep moving forward
  }

  delay(100);          // Small delay for stability
}