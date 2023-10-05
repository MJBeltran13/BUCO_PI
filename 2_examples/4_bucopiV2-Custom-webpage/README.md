## How to Use

Follow these steps for hardware and software setup.

### Hardware Setup

1. **Prepare the BUCO PI Circuit Board:**
   - Ensure you have the BUCO PI circuit board on hand.

2. **Attach the 124x64 OLED Display:**
   - Connect the 124x64 OLED Display to the BUCO PI circuit board using the provided connectors.

3. **Connect the USB-TO-TTL Converter:**
   - Plug in the USB-TO-TTL converter to your computer. Make sure the connection is secure.
   
4. **Verify Connections:**
   - Double-check all connections to ensure they are properly seated and secure. This step is crucial for the system's stability and performance.

### Software Setup

1. **Open Text Editor:**
   - Launch the `Arduino IDE`.

2. **Load the Code:**
   - Download the code from github and open it from the Arduino IDE.

3. **Choose the Board Used:**
   - Select the appropriate board from the Arduino IDE's "Tools" menu. 
   - Select `Tools` > `Board` > `Esp 8266 board` > `Generic Esp8266 Module`

4. **Choose the Port Used:**
   - In the Arduino IDE, navigate to the "Tools" menu and select the correct port for your USB-TO-TTL converter. This allows the IDE to communicate with your BUCO PI Circuit Board.
   - Select `Tools` > `Port` > `[Buco Pi Slice PORT]`

5. **Add Library**
   - Select `Tools` > `Manage Libraries` > `Add Library...`
   - Add and install `ArduinoJson` library.
   - Add and install `wifi manager by tzapu/tablatronix` library.

6. **Connect USB-TO-TTL Converter**
   - Ensure the pins are correctly connected to the BUCO PI Circuit Board.
   - Connect `TX to RX` on the BUCO PI Circuit Board.
   - Connect `RX to TX` on the BUCO PI Circuit Board.
   - Connect `GND to GND` on the BUCO PI Circuit Board.
   - Connect `5V to 5V` on the BUCO PI Circuit Board.

7. **Upload the Code and Change BUCO PI to Upload mode:**
   - In the Arduino IDE, click the `UPLOAD` button.
   - Press and hold the `reset button`, while holding down briefly press the `flash button`, then release the reset button and then the flash button.

8. **Verify Upload Success:**
   - After the code is uploaded, check the IDE's console for any error messages. If there are no errors, your code has been successfully uploaded to the BUCO PI Circuit Board.


Remember to refer to the documentation provided with your BUCO PI Circuit Board for any additional setup instructions or troubleshooting tips specific to your hardware.

Now you're ready to start using your BUCO PI Circuit Board! Enjoy exploring its capabilities and building exciting projects.