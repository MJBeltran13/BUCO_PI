# BUCO PI 
 BatStateU Customizable and Open Platform for IoT 

## Table of Contents

- [Project Description](#project-description)
- [Project Aim](#project-aim)
- [Installation](#installation)
- [Examples](#examples)
- [License](#license)
- [Credits](#credits)
- [troubleshooting](#troubleshooting)

## Project Description

* [Buco Pi 3D Model](https://bucopi.juantechnovations.com)

Introducing BUCO PI - an open source customizable circuit board designed for the Internet of Things (IoT) - the perfect tool for developers and makers alike. This circuit board offers a unique level of flexibility, allowing users to create and customize IoT applications tailored to their specific needs.

With its open source design, this circuit board provides a platform for experimentation and innovation in the world of IoT. It features an array of sensors and connectivity options, including Wi-Fi, Bluetooth (soon), and Ethernet (soon), enabling users to connect to a wide range of devices and networks.

The circuit board is also highly customizable, with a variety of software development tools available to help users tailor the board's functionality to their exact requirements. Whether you're a seasoned developer or a beginner, this board offers a level of versatility that makes it perfect for any IoT project.

So if you're looking to build your own IoT device, or simply want to explore the world of IoT development, this open source customizable circuit board is the perfect place to start. With its powerful capabilities and endless potential, it's sure to become an indispensable tool for makers and developers.

## Project Aim

The BUCO PI project is dedicated to provide a highly adaptable, open-source IoT circuit board designed to cater to the specific needs of developers and makers. Our primary goals include:

1. **Open-Customization and Flexibility**:

- Empower users to build IoT applications that align precisely with their requirements.
- Foster a platform for experimentation and innovation in the IoT domain.

2. **Open-Source Foundation**:

- Cultivate a collaborative, open-source community for IoT development.
- Encourage knowledge sharing and contributions from developers globally.

3. **Diverse Connectivity Options**:

- Deliver a range of connectivity choices, beginning with Wi-Fi, and expand to include Bluetooth and Ethernet capabilities in the near future.
- Facilitate seamless communication with a wide array of devices and networks.

4. **Comprehensive Sensor Integration**:

- Incorporate a diverse set of sensors to enhance the versatility and sensing capabilities of IoT applications.

5. **Accessibility for Developers of All Levels**:

- Provide a user-friendly platform suitable for both seasoned developers and beginners in IoT development.
- Offer a range of software development tools and resources to support customization.

6. **Expanding IoT Development Horizons**:

- Encourage exploration and innovation in the field of IoT by providing a powerful and adaptable platform.
- Support the creation of diverse IoT applications across industries.

7. **Community Building and Collaboration**:

- Cultivate a community of makers and developers interested in IoT, creating a space for knowledge exchange, support, and collaboration.

## Installation

To set up this project locally, follow these steps:

1. **Download Arduino IDE**:

   - Go to [Arduino IDE](https://www.arduino.cc/en/software).
   - Scroll down and download `Legacy IDE (1.8.19)`.
   - Run the installer.


2. **Install ESP8266 Module**:

   - Ensure you have the ESP8266 board library installed in your Arduino IDE. If not, refer to this [guide](https://randomnerdtutorials.com/how-to-install-esp8266-board-arduino-ide/).
   - We recommend using version 2.5.0 of the ESP8266 module.
   - The current supported IDE version is Arduino 1.8.19, but any version of the IDE will work.

3. **Install USB-To-TTL Converter Driver**
   - Download the USB-to-TTL converter driver from the provided [link](https://sparks.gogo.co.nz/ch340.html).
   - Extract the zip file.
   - Install the driver.

4. **Download Necessary Packages**:

   - Dollow the steps provided in the [3_libraries](https://github.com/MJBeltran13/BUCO_PI/tree/main/3_libraries) file. 

5. **Download Examples**:
   - Obtain the examples from the [examples directory](https://github.com/MJBeltran13/BUCO_PI/tree/main/2_examples).
   - Download the zip files from the provided link.

6. **Get BUCO PI Development Kit A**:
   - Purchase the [BUCO PI Development Kit A](https://bucopi.juantechnovations.com/buy) from the provided link.

## [Examples](https://github.com/MJBeltran13/BUCO_PI/tree/main/2_examples)

### [Smart home Application](https://github.com/MJBeltran13/BUCO_PI/tree/main/2_examples/1_Smart-Home_Application)
#### Description:
This Smart Home application utilizes the BUCO PI board to control various devices within a home environment. It enables users to remotely monitor and manage lights, temperature, and security systems using a mobile app



### [Argri Aqua Application](https://github.com/MJBeltran13/BUCO_PI/tree/main/2_examples/2_Agri-Aqua_Application)
#### Description:
This application focuses on agriculture and aquaculture monitoring. It uses the BUCO PI board to collect data from various sensors measuring soil moisture, pH levels, water temperature, and more. The data is then sent to a cloud server for analysis and visualization.


### [Robotics Application](https://github.com/MJBeltran13/BUCO_PI/tree/main/2_examples/3_Robotics_Application)
#### Description:
In this application, the BUCO PI board is integrated into a robotic system. It controls motors, reads input from various sensors, and communicates with a remote control interface. This enables the robot to perform tasks such as object detection, navigation, and manipulation.

#### Other Example Links
- [bucopi_custom_webpage](https://github.com/MJBeltran13/BUCO_PI/tree/main/2_examples/bucopi-custom-webpage)
- [bucopiV2_custom_webpage](https://github.com/MJBeltran13/BUCO_PI/tree/main/2_examples/4_bucopiV2-Custom-webpage)
- [OLED_display_codes](https://github.com/MJBeltran13/BUCO_PI/tree/main/2_examples/4_OLED_Display_Codes)


## [Troubleshooting](https://github.com/MJBeltran13/BUCO_PI/tree/main/4_troubleshooting)
Inside the troubleshooting folder, you will find detailed information and solutions for common problems that users may encounter during different phases of the project. Each section is designed to help you diagnose and resolve issues efficiently.

### Table of Contents
#### How to Use
To resolve an issue, simply click on the corresponding link to access the detailed troubleshooting guide. Each guide provides solutions, explanations, and best practices to overcome common obstacles.

1. [Installation Issues](4_troubleshooting/README.md#installation-issues)
2. [Compilation Errors](4_troubleshooting/README.md#compilation-errors)
3. [Upload Problems](4_troubleshooting/README.md#upload-problems)
3. [Board Configuration Issues](4_troubleshooting/README.md#board-configuration-issues)
4. [Serial Communication Problems](4_troubleshooting/README.md#serial-communication-problems)
5. [General Debugging Tips](4_troubleshooting/README.md#general-debugging-tips)


## License
  
The text of the Buco Pi getting started guide is licensed under a [Creative Commons Attribution-ShareAlike 3.0 License](https://creativecommons.org/licenses/by-sa/3.0/). Code samples in the guide are released into the public domain.


# Credits

We would like to extend our gratitude to the following individuals and communities for their contributions and support:

- [JC Catilo](https://github.com/jccatilo)
- [Contributor Name](Link to Contributor's Profile or Website)
- [Open Source Community Name](Link to Community Website or Profile)
- [Library/Tool Name](Link to Library/Tool Repository or Documentation)
- [Library/Tool Name](Link to Library/Tool Repository or Documentation)
- sources of pictures
- Student group with student names and student IDs