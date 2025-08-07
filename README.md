# Arduino Motor Control & Obstacle Avoidance Robot

## Overview

This project includes two tasks:

### Task 1:  
Control **four DC motors** using the **L293D motor driver** to perform timed directional movements (forward, backward, turn right/left in sequence).

### Task 2:  
Build an **autonomous robot** using:
- **L293D motor driver**
- **Ultrasonic distance sensor**
- **Servo motor**  
that **detects obstacles** and changes direction to avoid them dynamically.

---

## Components Used

- Arduino Uno
- L293D Motor Driver IC
- 4 × DC Motors
- 1 × Servo Motor (SG90 or similar)
- 1 × Ultrasonic Sensor (PING-style or HC-SR04)
- External 9V/12V power supply for motors
- Breadboard + jumper wires

---

## Task 1: Four DC Motors Direction Control

### Wiring

- **L293D** is used to control **two DC motors per side** (left & right) via IN1–IN4.
- **EN1/EN2** pins are tied to **5V or Arduino digital pins** to enable the motor channels.
- Motors wired to `OUT1–OUT4`, powered by an external supply (VS), logic powered by Arduino (VSS = 5V).
- Pins used:
  - `IN1 = D3`, `IN2 = D2`, `EN1 = D4`
  - `IN3 = A3`, `IN4 = A4`, `EN2 = A5`

### Logic

The robot performs:
1. **Forward** for 30 seconds
2. **Backward** for 1 minute
3. **Turn right and left alternately** for 1 minute (5-second intervals)

### Code Behavior

- `moveForward()`, `moveBackward()`, `turnLeft()`, `turnRight()` functions define direction.
- The loop runs each movement for a defined time using `delay()`.

---

## Task 2: Obstacle Avoidance Robot with Servo + Ultrasonic

### Pin Assignments

- **Motors (same as Task 1)**:
  - Left: `IN1 = D3`, `IN2 = D2`, `EN1 = D4`
  - Right: `IN3 = A3`, `IN4 = A4`, `EN2 = A5`

- **Ultrasonic Sensor**:
  - SIG (trigger/echo) = `A0`  
    (Parallax-style PING sensor with single pin)

- **Servo Motor**:
  - Signal pin = `A1`

### Behavior

1. Robot moves **forward** as default.
2. If an obstacle is detected within **10 cm**:
   - **Stops**
   - Scans using **servo** (sweep: 0° → 90° → 180° → 90°)
   - **Moves backward** for 3 seconds
   - **Turns right** for 2 seconds
3. If the path is still blocked, it repeats step 2 until the path is clear.

### Logic Explained

- `readDistanceCM()` uses `pulseIn()` to measure echo duration and converts it to cm.
- `scanWithServo()` sweeps the servo to simulate object scanning.
- Inside `loop()`, the code checks distance:
  - If obstacle: execute escape routine
  - Else: continue moving forward
- Uses a `while` loop to **keep retrying escape motion** until no obstacle is detected.

---

## Full circuit connections
![image alt](https://github.com/EyadShami/L293D-Control-Motors/blob/27e8efd64c9b103af66464e5b82e7a80578ac3ef/L293D_Control_Motors.png)

## Circuit Simulation (Task #1)
![image alt](https://github.com/EyadShami/L293D-Control-Motors/blob/27e8efd64c9b103af66464e5b82e7a80578ac3ef/Simulation1.gif)

## Circuit Simulation (Task #2)
![image alt](https://github.com/EyadShami/L293D-Control-Motors/blob/27e8efd64c9b103af66464e5b82e7a80578ac3ef/Simulation2.gif)


