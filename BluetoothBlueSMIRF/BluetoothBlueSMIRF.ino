void setup()
{
  // Open a serial connection with a baud rate of 115200.
  // This is the default for this bluetooth module.
  Serial.begin(115200);
  // Wait a second to let the module load.
  delay(1000);
  // Enter command mode.
  // This allows for configuration of the module
  // without transmitting any data.
  Serial.print("$$$");
  // Allow the command to be processed
  delay(100);
  // Enter slave mode.
  // This configures the module to listen for new connections
  Serial.println("SM,0");
  // Allow the command to be processed
  delay(100);
  // Exit command mode.
  // All data sent over the serial port will now be transmitted.
  Serial.println("---"); 
}

void loop()
{
  // Write a "Hello" message to the serial
  Serial.println("Hello!");
  // Wait a second before sending the next message
  delay(1000);
}
