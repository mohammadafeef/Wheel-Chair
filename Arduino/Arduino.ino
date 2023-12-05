// Motor A connections
int motorPin1A = 2; // Pin 2 for motor A input 1
int motorPin2A = 3; // Pin 3 for motor A input 2

// Motor B connections
int motorPin1B = 4; // Pin 4 for motor B input 1
int motorPin2B = 5; // Pin 5 for motor B input 2

// Joystick connections
int joyPinX = A0; // Joystick X-axis connected to analog pin A0
int joyPinY = A1; // Joystick Y-axis connected to analog pin A1

void setup() {
  pinMode(motorPin1A, OUTPUT);
  pinMode(motorPin2A, OUTPUT);
  pinMode(motorPin1B, OUTPUT);
  pinMode(motorPin2B, OUTPUT);
}

void loop() {
  int xAxis = analogRead(joyPinX); // Read X-axis of joystick
  int yAxis = analogRead(joyPinY); // Read Y-axis of joystick

  int motorSpeedA = map(yAxis, 0, 1023, -255, 255); // Map joystick Y-axis to motor speed
  int motorSpeedB = map(xAxis, 0, 1023, -255, 255); // Map joystick X-axis to motor speed

  // Control Motor A
  if (motorSpeedA > 0) {
    analogWrite(motorPin1A, motorSpeedA);
    analogWrite(motorPin2A, 0);
  } else {
    analogWrite(motorPin1A, 0);
    analogWrite(motorPin2A, abs(motorSpeedA));
  }

  // Control Motor B
  if (motorSpeedB > 0) {
    analogWrite(motorPin1B, motorSpeedB);
    analogWrite(motorPin2B, 0);
  } else {
    analogWrite(motorPin1B, 0);
    analogWrite(motorPin2B, abs(motorSpeedB));
  }
}
