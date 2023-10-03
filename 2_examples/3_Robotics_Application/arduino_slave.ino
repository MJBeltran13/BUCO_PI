// Include the Wire library for I2C communication
#include <Wire.h>
const int xPin = A0;  // Analog pin for X-axis
const int yPin = A1;  // Analog pin for Y-axis
const int buttonPin = 2;  // Digital pin for button

int xValue = 0;
int yValue = 0;
int buttonState = 0;

void setup() {
  // Initialize I2C communication with the device address 8
  Wire.begin(8);  // 0x08 = 8
  Wire.onReceive(receiveEvent);
  Wire.onRequest(sendEvent);
  Serial.begin(9600);
}

// Loop function runs repeatedly after setup
void loop() {
  xValue = analogRead(xPin);
  yValue = analogRead(yPin);
  buttonState = digitalRead(buttonPin);
  delay(1000);
}

// Function to handle received data
void receiveEvent(int howMany) {
  // Define a String variable to store received data
  String received;

  // Loop to read all available data from the I2C bus
  while (0 < Wire.available()) {
    // Read a character from the I2C bus
    char c = Wire.read();
    // Append the character to the received String
    received += c;
  }

  // Print the received data to the serial monitor
  Serial.print(received);
}

// Function to handle data requests
void sendEvent(int howmany) {
  // Send the string "uno to mcu" over the I2C bus
  String data = String(xValue) + "," + String(yValue) + "," + String(buttonState);
  Wire.write(data.c_str()); //send data to node mcu

}