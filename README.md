# Smart Wi-Fi Lighting & Energy Optimization System

An IoT-based smart lighting prototype that automatically controls lighting based on **human presence** and **ambient light conditions**, while monitoring energy usage through a Wi-Fi dashboard.

---

## Project Overview

The **Smart Wi-Fi Lighting & Energy Optimization System** uses an **ESP32** as the main controller.

The system combines:

* PIR sensor for human presence detection
* LDR sensor for ambient light measurement
* PWM-based adaptive brightness control
* LED/LED strip lighting
* Wi-Fi connectivity
* IoT monitoring dashboard
* Energy consumption estimation
* Historical data analysis
* Basic system status and fault monitoring

The goal is to provide lighting only when it is required and adjust brightness according to the surrounding light conditions.

---

## How It Works

```text
PIR Sensor ───────┐
                  │
LDR Sensor ───────┤
                  ▼
             ┌─────────┐
             │  ESP32  │
             │         │
             │ Decision│
             │  Logic  │
             │   PWM   │
             │  Wi-Fi  │
             └────┬────┘
                  │
                  ▼
             LED Lighting
                  │
                  ▼
           Wi-Fi Dashboard
```

### Basic Logic

```text
IF no person is detected
        ↓
     Light OFF

IF person is detected
        ↓
Check ambient light
        ↓
Determine required brightness
        ↓
Control LED using PWM
```

Expected behavior:

| Human Presence | Ambient Light | Light       |
| -------------- | ------------- | ----------- |
| No             | Any           | OFF         |
| Yes            | Very Dark     | 100%        |
| Yes            | Dark          | ~80%        |
| Yes            | Moderate      | ~50%        |
| Yes            | Bright        | ~20% or OFF |
| Yes            | Very Bright   | OFF         |

The exact thresholds will be determined through experimental calibration.

---

## Main Features

* Automatic presence-based lighting
* Ambient-light-based brightness adjustment
* PWM brightness control
* Automatic light OFF when no person is present
* Wi-Fi monitoring
* Real-time system status
* Energy consumption estimation
* Historical data logging
* Energy comparison and analysis
* Basic fault/status detection
* Local operation even if Wi-Fi disconnects
* Future support for actual energy measurement

---

## Hardware

Currently planned/available hardware includes:

* ESP32 DevKit
* HC-SR501 PIR sensor
* LDR module
* LED / LED strip
* Breadboard
* Jumper wires
* Resistors
* USB cable
* Low-voltage power source
* LED driver/MOSFET for the LED strip

An appropriate energy/current sensor will be added later after confirming the LED strip's electrical requirements.

> **Safety:** This project is designed as a low-voltage prototype. The current prototype will not use 230V AC mains.

---

## Software

The project will use:

* ESP32 firmware
* Arduino IDE
* C/C++ for ESP32 programming
* Wi-Fi communication
* Web-based IoT dashboard
* Data logging and analysis tools

The exact dashboard technology will be finalized during development.

---

## Energy Optimization

Initially, energy consumption will be **estimated through software** using the lighting operating conditions.

For example:

```text
No person       → 0% lighting
Very bright     → 0–20%
Bright          → ~20%
Moderate        → ~50%
Dark            → ~80%
Very dark       → 100%
```

Later, an actual energy/current sensor will be integrated.

This will allow comparison between:

```text
Estimated Energy
        vs
Measured Energy
```

The final project will clearly distinguish estimated values from sensor-measured values.

---

## Project Roadmap

The complete development plan is available here:

📋 **[Project Roadmap](docs/PROJECT_ROADMAP.md)**

The roadmap covers:

* Hardware setup
* Sensor integration
* Adaptive lighting
* Energy estimation
* Wi-Fi dashboard
* Data logging
* Energy analysis
* Fault detection
* Physical prototype
* Testing
* Documentation

---

## Implementation Guide

A detailed beginner-friendly implementation guide is available here:

🔧 **[Implementation Guide](docs/IMPLEMENTATION_GUIDE.md)**

It explains the project step by step, including:

* ESP32 setup
* LED control
* PWM
* PIR integration
* LDR integration
* Automatic lighting logic
* Adaptive brightness
* Energy estimation
* LED driver integration
* Wi-Fi
* Dashboard
* Data logging
* Testing
* Final integration

---

## Project Structure

```text
smart-wifi-lighting-energy-optimization/
│
├── README.md
│
├── docs/
│   ├── PROJECT_ROADMAP.md
│   └── IMPLEMENTATION_GUIDE.md
│
├── firmware/
│   └── esp32/
│
├── dashboard/
│
├── hardware/
│   ├── circuit/
│   └── images/
│
├── data/
│
└── .gitignore
```

Additional folders will be added as development progresses.

---

## Development Timeline

The project is planned for approximately **4 weeks**.

| Week   | Main Focus                                             |
| ------ | ------------------------------------------------------ |
| Week 1 | ESP32, LED, PWM, PIR, LDR                              |
| Week 2 | Adaptive lighting, energy estimation, Wi-Fi, dashboard |
| Week 3 | Data logging, energy analysis, fault detection         |
| Week 4 | Physical model, integration, testing, documentation    |

---

## Future Improvements

Possible future improvements include:

* Actual energy/current sensing
* More accurate energy calculations
* Improved lighting calibration
* Multiple lighting zones
* Advanced analytics
* Predictive energy optimization
* Larger-scale deployment

These features are outside the initial prototype scope and will only be considered after the core system is stable.

---

## Project Status

**Current Status:** Project setup and documentation

The repository is currently being prepared before hardware and firmware development begins.

### Planned Development Stages

* [ ] Project repository setup
* [ ] ESP32 setup
* [ ] LED control
* [ ] PWM brightness control
* [ ] PIR integration
* [ ] LDR integration
* [ ] Automatic lighting
* [ ] Adaptive brightness
* [ ] Energy estimation
* [ ] Wi-Fi connectivity
* [ ] IoT dashboard
* [ ] Data logging
* [ ] Energy analysis
* [ ] Fault detection
* [ ] Physical prototype
* [ ] Actual energy sensor integration
* [ ] Final testing
* [ ] Final documentation

---

## Team

This project is being developed as a college project by a **4-member team**.

Team member details will be added as the project progresses.

---

## License

This project is developed for educational and academic purposes.
