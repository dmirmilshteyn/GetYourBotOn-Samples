int motorPin1 =  3; // This needs to be on a PWM pin
int motorPin2 =  5; // This needs to be on a PWM pin
int pwmPin = 6; // This needs to be on a PWM pin
int sensorPin = 0; // This needs to be on an analog pin

int moving = 0;

void setup()
{
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(pwmPin, OUTPUT);
  
  // This controls the speed of the motor. Use a high value for a higher speed.
  // Maximum is 255, minimum is 0
  analogWrite(pwmPin, 255);
  
  // Enable the motor!
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
}

void loop()
{
  // Read the value reported by the IR sensor
  int distance = analogRead(sensorPin);
  // The reported values range from 0 to ~700.
  // When 700 is reported, the sensor is fully obstructed
  // When 0 is reported, the sensor is fully unobstructed.
  // Test to see if something is blocking the sensor, allowing for some tolerance
  if (distance > 400) {
    // Check: is the dinosaur moving? If it is, stop! If it's not, start moving again!
    if (moving == 0) {
      // Set the first motor pin to LOW and the second pin to HIGH
      // The first pin acts as ground, the second acts as the voltage source
      // This enables the motor
      digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin2, HIGH);
      // Set the flag to indicate the dinosaur is moving
      moving = 1;
    } else if (moving == 1) {
      // Set both pins to LOW - they both act as ground and no voltage is supplied to the motor
      // This disables the motor
      digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin2, LOW);
      // Set the flag to indicate the dinosaur is not moving
      moving = 0;
    }
    
    // Wait for a short time
    delay(1500);
  }
}
