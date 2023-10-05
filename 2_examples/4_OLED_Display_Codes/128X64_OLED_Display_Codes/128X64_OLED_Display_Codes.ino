#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "clip_arts.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {

  Serial.begin(9600); // Initialize serial communication
  Serial.println("Initializing...");
  Wire.begin();
  initializeDisplay(0x3C);
  // Clear the buffer
  display.clearDisplay();
}

void loop() {
  display.clearDisplay();
  display.drawBitmap(0, 0, myBitmapBatangas_State_Logo, SCREEN_WIDTH, SCREEN_HEIGHT, 1);
  display.display();
  delay(5000); // Delay for 5 seconds (you can adjust this)
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(10, 40); // Set the position for the text
  display.print(F("Hello, World!")); // Print the message
  display.display();
  delay(5000); // Delay for 5 seconds (you can adjust this)
}

void initializeDisplay(uint8_t my_i2c_address) {
  if (!display.begin(SSD1306_SWITCHCAPVCC, my_i2c_address)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  delay(250);
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
}
