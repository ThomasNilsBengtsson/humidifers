# Arduino-Driven Scent-Diffusion Sequencer

A set of Arduino sketches that turn ordinary 5 V ultrasonic humidifiers into an **interactive scent machine**.  
Different sensors (buttons, potentiometers, distance and vibration sensors, accelerometer, etc.) modulate how—and when—the humidifiers fire, letting you create spatial scent “animations” for art installations, UX testing, or just a DIY smart home.

---

## Features

* **Modular sketches** – each `.ino` file demonstrates a different control scheme  
* **Any number of humidifiers** – add as many outputs as your MOSFETs (or relays) and power supply can handle  
* **Sensor-driven patterns** – distance-based bursts, knock-to-spray, tilt tempo, continuous fade-in/out, and more  
* **Serial debug output** – every sketch prints its key state variables so you can tune timings live  

---

## Hardware

| Part | Qty | Notes |
|------|-----|-------|
| 5 V USB ultrasonic humidifier | 1–n | Each draws ≈ 500 mA when on. Cut the USB cable and run VCC + GND through a logic-level N-MOSFET. |
| Arduino board of choice. |
| Sensors (pick & mix) |  |  |
| – Momentary push-button | 1 | Debounced in code |
| – Latching toggle switch | 1 | For on/off hold |
| – 10 kΩ potentiometer | 1 | Controls duty cycle or cross-fades |
| – Piezo disc knock sensor | 1 | Reads vibration hits |
| – HC-SR04 ultrasonic distance sensor | 1 | Triggers mist when someone approaches |
| – Accelerometer (Arduino Nano 33 BLE Sense or LSM9DS1 breakout) | 1 | Sets pulse rate via tilt/movement |

Power the Arduino from its USB jack; power the humidifiers from a separate 5 V supply rated for the combined current, **common ground shared**.

---

## 🗂 Repository Layout

