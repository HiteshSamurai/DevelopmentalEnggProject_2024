// Define pin connections & motor's steps per revolution
const int dirPin = 6;
const int stepPin = 7;
const int slp = 9;
const int rst = 10;
const int stepsPerRevolution = 400;

void setup() {
  // Declare pins as Outputs
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(slp, OUTPUT);
  pinMode(rst, OUTPUT);
}

void loop() {
  // Set motor direction clockwise
  digitalWrite(slp, HIGH);
  digitalWrite(rst, HIGH);
  digitalWrite(dirPin, HIGH);
  delay(4000);
  // Spin motor slowly
  for(int x = 0; x < stepsPerRevolution; x++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(1000);

  }
 
  digitalWrite(rst, LOW);
  delay(4000); // Wait a second

  // Set motor direction counterclockwise
  digitalWrite(dirPin, LOW);
  delay(4000);
  digitalWrite(rst, HIGH);

  // Spin motor quickly
  for(int x = 0; x < stepsPerRevolution; x++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(1000);
  }
  digitalWrite(rst, LOW);
  delay(4000); // Wait a second
}