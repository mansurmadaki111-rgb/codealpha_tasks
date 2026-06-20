# Task 3: IoT Prototype with Arduino/Raspberry Pi

##  Project: Smart Soil Moisture Monitoring System (ESP8266 + MQTT + ThingsBoard)

###  Overview
This task involves building a real IoT hardware prototype (not a simulation). I built a **Soil Moisture Monitoring System** using an **ESP8266 (NodeMCU)** and a **Soil Moisture Sensor**, which reads live soil moisture data and publishes it over **WiFi using the MQTT protocol** to a cloud dashboard built on **ThingsBoard Cloud**. The dashboard displays the live moisture percentage, historical graphs, and device status in real time, from anywhere with an internet connection.

This was approved by my mentor as a substitute for the Temperature & Humidity Monitoring System task, since I had a Soil Moisture Sensor available instead.

###  What's Inside This Folder
| File | Description |
|------|-------------|
| `hardware.png` | Photo of the physical ESP8266 + sensor wiring |
| `Task3_SoilMoisture_MQTT.ino` | Arduino sketch / source code |
| `thingBorad_Dry.png` | Live ThingsBoard Cloud dashboard -- dry soil reading|
| `thingBorad_Wet.png` | Live ThingsBoard Cloud dashboard -- wet soil reading|
| `serial_monitor_Dry.png` | Serial Monitor output -- wet soil reading |
| `serial_monitor_Wet.png` | Serial Monitor output -- dry soil reading |

###  Components Used
- ESP8266 (NodeMCU)
- Soil Moisture Sensor (analog output)
- Jumper wires & Breadboard
- USB cable (power + programming)
- WiFi network 

###  Circuit Connections
| Soil Moisture Sensor Pin | ESP8266 (NodeMCU) Pin |
|----------------------------|--------------------------|
| VCC | 3V3 |
| GND | GND |
| AO (Analog Out) | A0 |

### Cloud Stack
| Layer | Tool Used |
|-------|-----------|
| Microcontroller | ESP8266 (NodeMCU) |
| Communication Protocol | MQTT |
| Cloud Platform | ThingsBoard Cloud (Free tier) |
| Dashboard | Live gauge, time-series graph, telemetry table |

###  How It Works
1. The ESP8266 connects to WiFi and then to ThingsBoard's MQTT broker (`thingsboard.cloud`, port 1883) using the device's unique access token.
2. Every 5 seconds, it reads the analog soil moisture value (0–1023) and converts it to a 0–100% scale, where a higher percentage means wetter soil.
3. The reading is packaged as a JSON payload and published to the topic `v1/devices/me/telemetry`.
4. ThingsBoard receives the data instantly and updates the live dashboard — gauge, graph, and telemetry table — in real time.

###  Testing Results
| Condition | Raw Value | Moisture % |
|-----------|-----------|------------|
| Wet soil | ~12–20 | ~98–99% |
| Dry / open air | 1024 | 0% |

The clear swing between wet and dry readings confirmed the sensor, wiring, and code were all functioning correctly, with data successfully reaching the cloud dashboard live.

###  Key Takeaway
This project demonstrates a complete, real-world IoT pipeline - physical sensing -> microcontroller processing -> MQTT transmission -> live cloud visualization. MQTT is the same industry-standard protocol used in real commercial and industrial IoT systems, making this a genuine hands-on introduction to professional IoT engineering, beyond just a simulation.

---
**CodeAlpha IoT Internship — June Batch**
