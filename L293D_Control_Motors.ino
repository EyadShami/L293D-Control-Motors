// === Motor Pin Assignments ===

// Motor A (Left Front)
const int motorA_in1 = 3;
const int motorA_in2 = 2;
const int motorA_en  = 4;

// Motor B (Right Front)
const int motorB_in1 = A3;
const int motorB_in2 = A4;
const int motorB_en  = A5;

void setup() {
  // Set all motor control pins as OUTPUT
  pinMode(motorA_in1, OUTPUT);
  pinMode(motorA_in2, OUTPUT);
  pinMode(motorA_en,  OUTPUT);
  
  pinMode(motorB_in1, OUTPUT);
  pinMode(motorB_in2, OUTPUT);
  pinMode(motorB_en,  OUTPUT);
  
  // Enable the motors (set EN pins HIGH)
  digitalWrite(motorA_en, HIGH);
  digitalWrite(motorB_en, HIGH);
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

void turnLeft() {
  digitalWrite(motorA_in1, LOW);
  digitalWrite(motorA_in2, LOW);
  digitalWrite(motorB_in1, LOW);
  digitalWrite(motorB_in2, HIGH);
}

void loop() {
  // 1. Move forward for 30 seconds
  moveForward();
  delay(30000);  // 30,000 ms = 30 sec

  // 2. Move backward for 1 minute
  moveBackward();
  delay(6000);  // 60,000 ms = 1 minute

  // 3. Alternate between left and right for 1 minute (6 cycles)
  for (int i = 0; i < 6; i++) {
    turnRight();
    delay(5000);  // 5 seconds

    turnLeft();
    delay(5000);  // 5 seconds
  }
}
