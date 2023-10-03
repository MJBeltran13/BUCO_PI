// Include the Wire library for I2C communication
#include <Wire.h>

// Define a variable to store received data as a String
String received;

// Setup function runs once when the microcontroller starts
void setup(){
  // Initialize the I2C communication with SDA pin 4 and SCL pin 5
  Wire.begin(4, 5);

  // Initialize serial communication at a baud rate of 115200
  Serial.begin(115200);
}

// Loop function runs repeatedly after setup
void loop(){
  // Begin a transmission to device with address 8 on the I2C bus
  Wire.beginTransmission(8); // 0x08 = 8;

  // Write the string "WORKING \n" to the device
  Wire.write("WORKING \n");

  // End the transmission
  Wire.endTransmission();

  // Request 10 bytes of data from the device with address 8
  Wire.requestFrom(8, 10); // 0x08 = 8;

  // Define a String variable to store received data locally in this loop iteration
  String received;

  // Loop while there is data available to read
  while (0 < Wire.available()){
    // Read a character from the I2C bus
    char c = Wire.read();

    // Append the character to the received String
    received += c;
  }

  // Print the received data to the serial monitor
  Serial.println(received);

  // Delay for 3 seconds before starting the loop again
  delay(3000);
}