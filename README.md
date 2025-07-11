# Smart Pulse Monitor

A real-time heart rate monitoring system built using Arduino and a Pulse Sensor. This project displays live BPM on an LCD screen and indicates each heartbeat with an LED. It includes optional IoT support via ThingSpeak and Python-based data logging over serial.

## Overview

This project is designed to help beginners and enthusiasts learn about real-time embedded systems, analog signal processing, serial communication, and IoT integration. It works both as a standalone monitor and as a connected device that can log or transmit heart rate data for remote monitoring or analysis.

## Features

- Real-time heart rate detection using a Pulse Sensor
- Live BPM display on a 16x2 LCD
- LED pulse indicator
- IoT support using Wi-Fi (ESP8266 and ThingSpeak)
- Optional Bluetooth support (HC-05 module)
- Python script for data logging and serial monitoring
- Compatible with Tinkercad for virtual simulation

## Hardware Requirements

| Component        | Purpose                            |
|------------------|------------------------------------|
| Arduino Uno/Nano | Microcontroller                    |
| Pulse Sensor     | Heartbeat detection                |
| 16x2 LCD         | Displays BPM                       |
| LED + Resistor   | Indicates heartbeat with blink     |
| ESP8266          | Upload BPM to ThingSpeak via Wi-Fi |
| HC-05 (optional) | Bluetooth data transmission        |
| Breadboard       | Circuit assembly                   |
| Jumper Wires     | Connections                        |
| Battery (9V)     | Optional portable power source     |


## ThingSpeak Integration

1. Create a free account at [thingspeak.com](https://thingspeak.com).
2. Create a new channel and enable "Field 1" as BPM.
3. Copy the **Channel ID** and **Write API Key**.
4. In the `send_to_thingspeak.ino` sketch:
   - Enter your Wi-Fi SSID and password
   - Paste your ThingSpeak credentials
5. Upload the code to an ESP8266 board (like NodeMCU).
6. View live BPM values on your ThingSpeak dashboard.

## Python Serial Logging

The Python script provided reads data from the Arduino or HC-05 Bluetooth module and logs it to a CSV file with timestamps.

**How to use:**

1. Set your serial port in `pulse_receiver.py` (e.g., `COM4` or `/dev/ttyUSB0`).
2. Run the script using Python 3:
3. Output will be saved in `bpm_log.csv` automatically.

## How It Works

- The Pulse Sensor outputs an analog waveform representing heartbeats.
- An Arduino interrupt routine reads the signal every 2 milliseconds.
- It detects heartbeat peaks, measures time between beats (IBI), and calculates BPM.
- BPM is averaged over the last 10 readings to improve accuracy.
- The result is shown on an LCD, sent via serial, or uploaded to the cloud.

## Possible Extensions

- OLED display for waveform visualization
- Mobile app using MIT App Inventor or Python Kivy
- Firebase integration or REST API endpoint
- SD card-based offline data logging
- Machine learning on logged data for health monitoring
