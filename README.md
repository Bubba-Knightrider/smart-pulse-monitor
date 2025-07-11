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
