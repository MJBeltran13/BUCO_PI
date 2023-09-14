#define ARDUINOJSON_ENABLE_PROGMEM 0
#include <ArduinoJson.h> //for haptics
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <ESP8266HTTPClient.h>
#include "clip_arts.h"
#include "my_configurations.h"
#include <WiFiManager.h> // https://github.com/tzapu/WiFiManager   current installed: wifimanger by tablatronix version 2.0.15-rc.1
#define TRIGGER_PIN 0 //this is the pin for entering AP mode and reconfuging the device
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int counter_reset_button = 0;

void setup() {
  pinMode(TRIGGER_PIN, INPUT_PULLUP);
  initializeDisplay(0x3C); // initializeDisplay(i2c address of the chosen display
  splashScreen();
  showFirmwareVersion();
  delay(2000);
  display.clearDisplay();
  displayHeaderGreeting();
  WiFi.mode(WIFI_STA); // explicitly set mode, esp defaults to STA+AP
  Serial.begin(9600);
  Serial.println("\n Starting");
}

void loop() {
  checkResetButton(); // this if for checking if reset button pressed
  checkInternetStatus(); //this is for the oled to display IP status
  showActiveStatusLogo();
  delay(5);
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
void splashScreen() {
  display.drawBitmap(0, 0, splash_screen, 128, 64, WHITE);
  display.display();
}

void showFirmwareVersion() {
  display.setTextColor(WHITE);
  display.setCursor(100, 55);
  display.print(firmware_version);
  display.display();
}

void displayHeaderGreeting() {

  display.setCursor(0, 0);
  display.print("Greetings!");
  display.setCursor(0, 10);
  display.print("I'm BUCO PI 00.");
  display.display();
}

void checkResetButton() {
  if ( digitalRead(TRIGGER_PIN) == LOW) {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print("Release to enter");
    display.setCursor(0, 10);
    display.print("config mode.");
    display.setCursor(0, 30);
    display.print("Hold longer then");
    display.setCursor(0, 40);
    display.print("release to do");
    display.setCursor(0, 50);
    display.print("a factory reset.");
    display.display();
    while (digitalRead(TRIGGER_PIN) == LOW) {
      counter_reset_button++;
      delay(1000);
    }
    if (counter_reset_button <= 3) {
      just_configure();
    }
    else {
      WiFiManager wm;
      display.clearDisplay();
      display.setCursor(0, 0);
      display.print("Restoring factory");
      display.setCursor(0, 10);
      display.print("settings...");
      display.display();
      delay(1000);
      wm.resetSettings();
      delay(5000);
      display.clearDisplay();
      display.setCursor(0, 0);
      display.print("Reset Done!");
      display.setCursor(0, 10);
      display.print("Kindly turn off and");
      display.setCursor(0, 20);
      display.print("then power on the");
      display.setCursor(0, 30);
      display.print("device again.");
      display.display();
      ESP.restart();
      delay(3000);
    }
    counter_reset_button = 0;
  }
}

void just_configure() {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("-Configuration Mode-");
  display.display();
  display.setCursor(0, 20);
  display.print("Connect to BUCOPI-" + device_id);
  display.setCursor(0, 30);
  display.print("using your phone to");
  display.setCursor(0, 40);
  display.print("configure the device.");
  display.display();
  delay(1000);
  WiFiManager wm;
  //wm.resetSettings();
  // set configportal timeout
  wm.setConfigPortalTimeout(timeout);
  if (!wm.startConfigPortal("BUCOPI-00")) {
    Serial.println("failed to connect and hit timeout");
    delay(3000);
    //reset and try again, or maybe put it to deep sleep
    ESP.restart();
    delay(3000);
  }
  //if you get here you have connected to the WiFi
  display.clearDisplay();
  display.setCursor(35, 10);
  display.print("Connected!");
  display.display();
  delay(2000);
  display.clearDisplay();
  displayHeaderGreeting();
}

void showActiveStatusLogo() {
  display.drawBitmap(110, 0, health_ok, 16, 16, WHITE);
  display.display();
  delay(1000);
  display.drawBitmap(110, 0, health_ok, 16, 16, BLACK);
  display.display();
  delay(1000);
}

void checkInternetStatus() {
  display.setTextColor(WHITE);
  if (WiFi.localIP()) {
    display.drawBitmap(0, 20, wifi_logo_ok, 24, 24, WHITE);
    display.display();
    display.setCursor(30, 30);
    display.print(WiFi.localIP());
    display.display();
    delay(500);
    display.drawBitmap(0, 20, wifi_logo_ok, 24, 24, BLACK);
    display.display();
  }
  else {
    display.drawBitmap(0, 20, wifi_logo_not_ok, 24, 24, WHITE);
    display.display();
    delay(500);
    display.drawBitmap(0, 20, wifi_logo_not_ok, 24, 24, BLACK);
    display.display();
  }
}
