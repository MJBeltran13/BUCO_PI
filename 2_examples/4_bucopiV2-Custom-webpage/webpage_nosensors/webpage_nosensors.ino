#define ARDUINOJSON_ENABLE_PROGMEM 0
#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <ESP8266HTTPClient.h>
#include "clip_arts.h"
#include "my_configurations.h"
#include <WiFiManager.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ESP8266WebServer.h>
#include <Ticker.h> // Include the Ticker library for timer-based tasks
#include <sstream>


ESP8266WebServer server(80);
Ticker keepAliveTimer;

#define TRIGGER_PIN 0
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

unsigned long startTime;
unsigned long countdownDuration = 0;
bool isConnected = false; // Declare isConnected at the global scope
bool checkInternetStatus();
char wifi_ssid[32] = "";
char wifi_password[64] = "";

// Define a structure to hold Wi-Fi credentials
struct WiFiCredential {
  const char* ssid;
  const char* password;
};

// Define an array of WiFiCredentials to store multiple SSID-password pairs
WiFiCredential wifiCredentials[] = {
  {"BatStateU ICT", "Leading Innovations, Transforming Lives"},
  {"hello", "world123"},
  // Add more SSID-password pairs here if needed
};

void setup() {
  // Initialize display, connect to Wi-Fi, and set up serial communication
  Serial.begin(9600); // Initialize serial communication
  Serial.println("Initializing...");

  initializeDisplay(0x3C);
  display.clearDisplay();
  splashScreen();
  showFirmwareVersion();
  delay(2000);
  display.clearDisplay();

  // Use the stored Wi-Fi credentials to connect to Wi-Fi
  WiFi.mode(WIFI_STA);
  WiFi.begin(wifi_ssid, wifi_password);
  Serial.println("Connecting to Wi-Fi...");
  startTime = millis();
  isConnected = checkInternetStatus();
  keepAliveTimer.attach(300, checkInternetStatus);
}

void loop() {
  display.clearDisplay();
  checkResetButton();

  // If connected, display the "Connected!" status
  if (isConnected) {
    Serial.println("Connected to Wi-Fi.");
    displayConnectedStatus();
    checkResetButton();
    startWebServer();
    server.handleClient();

  } else {
    Serial.println("Not connected to Wi-Fi.");
    display.clearDisplay();
    first_menu();
    checkInternetStatus();
    checkResetButton();
    display.display();
  }

  // Other loop logic
  delay(5);
  display.display();

}

void startWebServer() {
  Serial.println("Connected to Wi-Fi.");
  // Start the web server
  server.on("/", HTTP_GET, handleRoot);
  server.begin();
  Serial.println("Web server started.");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void handleRoot() {
  std::stringstream html;
  html << R"(
    <html>
      <body>
        <h1>HELLO WORLD</h1>
        <audio controls autoplay>
          <source src='https://www.myinstants.com/media/sounds/rickrolled.mp3' type='audio/mp3'>
          Your browser does not support the audio element.
        </audio>
        <br>
        <img src='https://media.tenor.com/SSY2V0RrU3IAAAAd/rick-roll-rick-rolled.gif' alt='Rickroll GIF'>
      </body>
    </html>
  )";

  server.send(200, "text/html", html.str().c_str());
}





bool checkInternetStatus() {
  // Check if connected to WiFi
  if (WiFi.status() == WL_CONNECTED) {
    WiFiClient client;
    HTTPClient http;

    // Use Google's homepage as a test URL
    http.begin(client, "http://www.google.com");

    int httpCode = http.GET();
    http.end();

    // If the HTTP request is successful (e.g., HTTP code 200), return true
    isConnected = (httpCode == 200);
    Serial.print("Internet status: ");
    Serial.println(isConnected ? "Connected to Wi-Fi" : "Not connected to Wi-Fi");
  } else {
    isConnected = false;
    Serial.println("Internet status: Not connected to Wi-Fi");
  }

  // Return the connection status
  return isConnected;
}

void displayConnectedStatus() {
  // Display "Connected!" status and Wi-Fi IP address
  display.setTextColor(BLACK);
  interfacef1();
  homelogo1();
  settingsf1();
  display.drawBitmap(40, 4, wifi_logo_ok, 26, 26, WHITE);
  display.display();
  display.setTextColor(BLACK);
  display.setCursor(38, 36);
  display.print("Connected!");
  display.setCursor(38, 46);
  display.print(WiFi.localIP());
  display.display();
  delay(1000);
  display.drawBitmap(40, 4, wifi_logo_ok, 26, 26, BLACK);
  display.display();
  Serial.println("Displaying connected status.");
}

void second_menu() {
  // Display the second menu
  display.clearDisplay();
  interfacef2();
  homelogo2();
  settingsf2();
  display.display();
}

// Functions to display various elements on the screen
void homelogo2() {
  display.drawBitmap(5, 3, home_logo, 26, 26, WHITE);
}
void settingsf2() {
  display.drawBitmap(6, 36, settings_logo, 26, 26, BLACK);
}
void interfacef2() {
  display.drawBitmap(0, 0, Interface2, SCREEN_WIDTH, SCREEN_HEIGHT, WHITE);
}

void first_menu() {
  // Display the first menu
  display.clearDisplay();
  interfacef1();
  homelogo1();
  settingsf1();
  displayHeaderGreeting();
  display.display();
}

// Functions to display various elements on the screen
void interfacef1() {
  display.drawBitmap(0, 0, Interface, SCREEN_WIDTH, SCREEN_HEIGHT, WHITE);
}
void homelogo1() {
  display.drawBitmap(5, 3, home_logo, 26, 26, BLACK);
}
void settingsf1() {
  display.drawBitmap(6, 36, settings_logo, 26, 26, WHITE);
}

// Initialize the display
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

// Display a splash screen
void splashScreen() {
  display.drawBitmap(0, 0, splash_screen, 128, 64, WHITE);
  display.display();
}

// Display the firmware version
void showFirmwareVersion() {
  display.setTextColor(WHITE);
  display.setCursor(100, 55);
  display.print(firmware_version);
  display.display();
}

// Display a header greeting message
void displayHeaderGreeting() {
  display.setTextColor(BLACK);
  display.setCursor(40, 6);
  display.print("Greetings!");
  display.setCursor(40, 16);
  display.print("I'm BUCO PI 00.");

  display.setCursor(40, 30);
  display.print("Press reset once");
  display.setCursor(40, 40);
  display.print("to enter");
  display.setCursor(40, 50);
  display.print("config mode");
  display.display();
}

// Check the reset button and perform actions based on the button press duration
void checkResetButton() {
  static unsigned long buttonPressStartTime = 0;
  static bool inConfigurationMode = false;

  if (digitalRead(TRIGGER_PIN) == LOW) {
    if (!inConfigurationMode) {
      buttonPressStartTime = millis();
      inConfigurationMode = true;
    }

    second_menu();
    display_config_instruction();
    display.setTextColor(BLACK);
    display.display(); // Add this line to update the display

    while (digitalRead(TRIGGER_PIN) == LOW) {
      // Calculate the remaining duration
      unsigned long currentTime = millis();
      unsigned long buttonPressDuration = currentTime - buttonPressStartTime;
      unsigned long remainingDuration = 11000 - buttonPressDuration;

      // Display remaining duration
      display.setTextColor(BLACK);
      display.setCursor(40, 50);
      display.print("Time out: ");
      display.print(remainingDuration / 1000); // Convert to seconds
      display.print("s");
      display.display(); // Add this line to update the display
      delay(100); // Adjust this delay for display update rate
      display.fillRect(40, 50, SCREEN_WIDTH, 14, WHITE);
    }

    display.clearDisplay();

    // Check the button press duration
    unsigned long buttonPressDuration = millis() - buttonPressStartTime;
    if (buttonPressDuration < 10000) {
      just_configure();
    } else {
      performFactoryReset();
    }

    inConfigurationMode = false;
  }
}

// Perform a factory reset
void performFactoryReset() {
  WiFiManager wm;
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setCursor(0, 8);
  display.print("Restoring factory");
  display.setCursor(0, 16);
  display.print("settings.");
  display.display();
  wm.resetSettings();
  delay(2000);
  display.clearDisplay();
  display.setCursor(0, 32);
  display.print("Restarting the Device");
  display.display();
  delay(1000);
  ESP.restart();
}

// Function to initiate Wi-Fi configuration
void just_configure() {
  second_menu();
  display.setCursor(43, 5);
  display.print("Configuration");
  display.display();
  display.setCursor(40, 20);
  display.print("Connect to ");
  display.setCursor(40, 30);
  display.print("BUCOPI-" + device_id);
  display.setCursor(40, 40);
  display.print("Using your");
  display.setCursor(40, 50);
  display.print("phone WIFI");
  display.display();
  delay(1000);

  // Initialize Wi-FiManager
  WiFiManager wm;
  wm.setConfigPortalTimeout(timeout);

  // Loop through the array of Wi-Fi credentials
  for (size_t i = 0; i < sizeof(wifiCredentials) / sizeof(wifiCredentials[0]); i++) {
    // Set the current Wi-Fi credentials
    strcpy(wifi_ssid, wifiCredentials[i].ssid);
    strcpy(wifi_password, wifiCredentials[i].password);

    // Configure Wi-Fi and save credentials
    if (wm.autoConnect("BUCOPI-00")) {
      // Successfully connected, break out of the loop
      break;
    }

    // Failed to connect, reset and try the next set of credentials
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setCursor(35, 10);
    display.print("Connection failed");
    display.display();
    delay(2000);
    ESP.restart();
    delay(3000);
  }

  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setCursor(35, 10);
  display.print("Connected!");
  delay(500);
  display.setCursor(35, 20);
  display.print("Initializing..");
  display.display();
  delay(2000);
  display.clearDisplay();
}

void showActiveStatusLogo() {
  display.drawBitmap(110, 0, health_ok, 16, 16, WHITE);
  display.display();
  delay(1000);
  display.drawBitmap(110, 0, health_ok, 16, 16, BLACK);
  display.display();
  delay(1000);
}

void display_config_instruction() {
  display.setTextColor(BLACK);
  display.setCursor(40, 5);
  display.print(" RELEASE for");
  display.setCursor(40, 15);
  display.print(" config mode");
  display.setCursor(40, 25);
  display.print(" HOLD for");
  display.setCursor(40, 35);
  display.print(" factory reset.");
}