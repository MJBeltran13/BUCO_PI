# Library

## How To Install
Follow these steps to install the ESP8266 Library on your Arduino:

1. **Download the Library Folder**:
    - Click the [library.zip](https://github.com/MJBeltran13/BUCO_PI/blob/main/3_libraries/libraries.rar) file.
    - Click the "Download Raw File" option.
   
2. **Go to Package**
    - Search RUN app
    - Type `localappdata` and press Enter
    - go to `Arduino15` 
    - go to `Packages`

2. **Over Write ESP8266 Library**:
   - Drag and drop the `esp8266` folder into the package folder.

3. **Verify the Installation**:
   - Create a new sketch (`File > New`).
   - Go to `Sketch > Include Library` and you should see "library_samplename" listed.

4. **Use the Library in Your Sketch**:
   - In your Arduino sketch, include the library_samplename header file:
     ```cpp
     #include <library_samplename.h>
     ```

5. **Upload Your Sketch**:
   - Write your code using the library_samplename functions.
   - Upload the sketch to your Arduino board.

6. **Verify Operation**:
   - Check the serial monitor or any other output method to verify that library_samplename is working as expected.

## CONTENTS

### ArduinoJson
- GitHub Repository: [ArduinoJson](https://github.com/bblanchon/ArduinoJson)

### ESP8266WiFi
- GitHub Repository: [ESP8266WiFi](https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266WiFi)

### WiFiClientSecure
- GitHub Repository: [WiFiClientSecure](https://github.com/espressif/arduino-esp32/tree/master/libraries/WiFiClientSecure)

### ESP8266HTTPClient
- GitHub Repository: [ESP8266HTTPClient](https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266HTTPClient)

### WiFiManager
- GitHub Repository: [WiFiManager](https://github.com/tzapu/WiFiManager)

### Adafruit_SSD1306
- GitHub Repository: [Adafruit_SSD1306](https://github.com/adafruit/Adafruit_SSD1306)

### Adafruit_BME280
- GitHub Repository: [Adafruit_BME280_Library](https://github.com/adafruit/Adafruit_BME280_Library)

### Ticker
- GitHub Repository: [Ticker](https://github.com/sstaub/Ticker)
