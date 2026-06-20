# Task 2: Sensor-Based Simulation

## Project: PIR Motion Sensor Controlled LED System

###  Overview
This task involves simulating an IoT system using Tinkercad (no physical hardware required). I built a **motion-activated LED alert system** using a **PIR (Passive Infrared) Motion Sensor** connected to an **Arduino Uno**. When motion is detected within the sensor's range, the LED automatically turns ON. When no motion is detected, the LED turns OFF.

This simulates real-world IoT applications such as automatic security lighting, smart home occupancy detection, and intruder alert systems.

###  What's Inside This Folder
| File | Description |
|------|-------------|
| `Code Explanation.pdf` | Line-by-line explanation of the code logic |
| `No Motion detact.png` | Screenshot — no motion detected, LED off |
| `Motion detected.png` | Screenshot — motion detected, LED on |
| `The output inside the Serial Monitor.png` | Screenshot — live Serial Monitor readings |

###  Components Used
- Arduino Uno
- PIR Motion Sensor (HC-SR501)
- LED (Red)
- 220Ω Resistor
- Breadboard & Jumper Wires

###  Circuit Connections
| PIR Sensor Pin | Arduino Pin |
|----------------|-------------|
| VCC | 5V |
| GND | GND |
| OUT | Digital Pin 2 |

| LED | Arduino Pin |
|-----|-------------|
| Anode (+) via 220Ω resistor | Digital Pin 8 |
| Cathode (−) | GND |

### How It Works
1. The PIR sensor continuously monitors infrared radiation changes in its surroundings.
2. When motion is detected, the sensor outputs a `HIGH` signal on its OUT pin.
3. The Arduino reads this signal via `digitalRead()` and turns the LED `ON`.
4. When no motion is present, the sensor outputs `LOW`, and the LED turns `OFF`.
5. All state changes are logged in real-time via the Serial Monitor.

###  Key Takeaway
This project demonstrates the core principle of event-driven IoT automation — a sensor detects a real-world change, a microcontroller processes it, and an actuator responds instantly without human input. This same logic powers real-world smart security systems, automatic lighting, and occupancy-based automation.

---
**CodeAlpha IoT Internship — June Batch**
