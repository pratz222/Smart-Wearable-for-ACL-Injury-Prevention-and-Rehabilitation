# Smart Wearable for ACL Injury Prevention and Rehabilitation

## Project Overview

We developed a cutting-edge wearable medical device that monitors knee angles in real-time using IoT technology. Our goal? To prevent ACL injuries and aid in rehabilitation. 🦵💡

##  How It Works

This innovative device utilizes two MPU6050 accelerometer/gyroscope sensors—one attached to the femur bone and the other to the tibia bone. By combining Euler angles and vector theory, we accurately calculated the relative knee angle based on sensor data.

An EMG sensor continuously monitors ACL ligament extension and contraction, providing crucial insights. Real-time data is seamlessly transmitted to Google Firebase RTDB via the cloud. Our sleek Android app displays crisp visualizations of knee angles and issues alerts when thresholds are exceeded. 📱📈

## Instant Alerts & Vibration Feedback

To enhance user experience, we added a vibration motor to the thigh sensor setup. When knee angles exceed user-defined thresholds, the wearable vibrates—acting as a gentle reminder. 📳 The app also features a voice feature, providing real-time knee angle updates during exercise. 🗣️

## Track Your Progress

Our app not only displays real-time data but also stores historical angle values. Doctors and patients alike can download personalized reports, tracking improvements over time. 📈📉

## Hardware Requirements

- **MPU6050 Sensor** (2 units)
- **EMG Sensor**
- **Vibration Motor**
- **Microcontroller:**
  - ESP32/ESP8266 or Arduino compatible board
- **Power Supply:**
  - Rechargeable battery or suitable power source

## Software Requirements

- **Arduino IDE**
- **Libraries:**
  - `Wire.h` for I2C communication
  - `MPU6050.h` for interfacing with the MPU6050
  - `FirebaseESP32.h` for Firebase communication
  - `EMG.h` for the EMG sensor (if applicable)

## Getting Started

**Install Required Libraries:**
   - Open Arduino IDE.
   - Go to **Sketch** > **Include Library** > **Manage Libraries...** and search for the required libraries.

**Configure WiFi and Firebase:**
   - Update your WiFi credentials and Firebase database URL in the code.

**Upload Code to Microcontroller:**
   - Select the correct board and port in Arduino IDE.
   - Upload the code.

**Install the Android App:**
   - Download and install the Android app from the provided link.

**Connect the Device:**
   - Power the wearable device and connect to the app.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.


![IMG-20240622-WA0001](https://github.com/user-attachments/assets/c573706b-db25-4b2d-babc-8923c7987012)

