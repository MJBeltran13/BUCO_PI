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

5. **Verify and Upload the Code:**
   - In the Arduino IDE, click the "verify" button.
   - Then click the "Upload" button in the Arduino IDE to upload the code to your BUCO PI Circuit Board.
   
6. **Verify Upload Success:**
   - After the code is uploaded, check the IDE's console for any error messages. If there are no errors, your code has been successfully uploaded to the BUCO PI Circuit Board.


Remember to refer to the documentation provided with your BUCO PI Circuit Board for any additional setup instructions or troubleshooting tips specific to your hardware.

Now you're ready to start using your BUCO PI Circuit Board! Enjoy exploring its capabilities and building exciting projects.