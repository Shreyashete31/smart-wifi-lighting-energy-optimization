  # Smart Wi-Fi Lighting & Energy Optimization System

## 1-Month Project Roadmap

### 1. Project Overview

The **Smart Wi-Fi Lighting & Energy Optimization System** is an IoT-based smart lighting prototype built using an **ESP32 microcontroller**, a **PIR motion sensor**, an **LDR ambient-light sensor**, and a controllable LED/LED strip.

The system detects human presence and measures the surrounding ambient light to automatically determine whether the light should be turned ON, OFF, or operated at a reduced brightness level. The ESP32 performs the primary lighting decisions locally, while Wi-Fi connectivity enables monitoring and analysis through an IoT dashboard.

The project will initially use **software-based energy estimation**. An actual voltage/current/energy sensor may be integrated later to measure and validate real energy consumption.

The project will consist of **one physical lighting zone** to maintain a realistic scope for the one-month development period.

---

## 2. Project Objectives

The main objectives of the project are:

1. To develop an automatic lighting system based on human presence.
2. To use ambient-light measurements to reduce unnecessary lighting.
3. To implement adaptive LED brightness using PWM.
4. To automatically switch the light OFF when no person is detected.
5. To monitor the system remotely through an IoT dashboard.
6. To calculate and analyze lighting energy consumption.
7. To estimate energy savings compared with conventional lighting operation.
8. To maintain lighting functionality even when Wi-Fi connectivity is unavailable.
9. To provide historical usage and energy-analysis data.
10. To implement basic fault/status detection.
11. To experimentally test and evaluate the performance of the system.

---

# 3. Project Scope

### 3.1 Hardware Scope

The initial prototype will use:

* ESP32 development board
* PIR motion sensor
* LDR ambient-light sensor/module
* LED or low-voltage DC LED strip
* Breadboard
* Jumper wires
* Appropriate resistors
* Appropriate transistor/MOSFET driver for LED-strip control
* Low-voltage power source
* USB cable

An actual energy measurement sensor will be added later if budget and development time permit.

### 3.2 Software Scope

The system software will include:

* ESP32 firmware
* PIR sensor processing
* LDR sensor processing
* Adaptive brightness control using PWM
* Lighting decision logic
* Energy-consumption calculation
* Wi-Fi communication
* IoT dashboard integration
* Data logging
* Historical data visualization
* Basic fault/status detection

### 3.3 Physical Scope

The project will demonstrate **one physical lighting zone**.

A small room-like physical representation may be created around the breadboard for demonstration purposes. The breadboard and electronic components will remain visible so that the hardware implementation can be clearly demonstrated.

---

# 4. System Working Principle

The overall system follows the sequence:

**Sensors → ESP32 → Decision Logic → Lighting Control → Energy Calculation → IoT Dashboard**

### Basic operating logic

1. The PIR sensor detects whether a person is present.
2. If no person is detected, the light remains OFF.
3. If a person is detected, the ESP32 reads the LDR value.
4. The ambient-light level is analyzed.
5. The ESP32 determines the required brightness.
6. PWM is used to control the LED brightness.
7. Operating time and brightness are used to estimate energy consumption.
8. Sensor and system data are transmitted through Wi-Fi.
9. The dashboard displays live and historical information.
10. If Wi-Fi is unavailable, local lighting control continues to operate.

### Adaptive lighting behavior

| Human Presence | Ambient Condition | Expected Light  |
| -------------- | ----------------- | --------------- |
| No             | Any               | OFF             |
| Yes            | Very Dark         | 100% brightness |
| Yes            | Dark              | ~80% brightness |
| Yes            | Moderate          | ~50% brightness |
| Yes            | Bright            | ~20% or OFF     |
| Yes            | Very Bright       | OFF             |

The exact LDR thresholds and brightness levels will be calibrated during implementation according to the actual sensor and prototype environment.

---

# 5. One-Month Development Roadmap

The project is planned for approximately **four weeks**, with around **three practical development sessions per week** and approximately **two hours per session**.

The roadmap consists of eight development phases.

---

## Phase 1 — Foundation and Hardware Setup

**Sessions:** 1–2
**Target:** Week 1

### Objectives

* Configure the ESP32 development environment.
* Verify ESP32 operation.
* Set up the breadboard.
* Test basic LED control.
* Implement PWM brightness control.
* Establish a safe control method for the DC LED/LED strip.

### Tasks

1. Configure the ESP32 programming environment.
2. Upload a basic test program.
3. Connect and test a small LED.
4. Verify GPIO output.
5. Implement LED ON/OFF control.
6. Implement PWM brightness control.
7. Test different brightness levels.
8. Test the LED strip separately with its appropriate low-voltage supply.
9. Integrate the required driver stage for controlling the strip.

### Expected Output

A working ESP32-based lighting output capable of:

* OFF
* ON
* Variable brightness

---

# Phase 2 — Sensor-Based Smart Lighting

**Sessions:** 3–4
**Target:** Week 1

### Objectives

* Integrate the PIR sensor.
* Integrate the LDR.
* Implement presence-based lighting.
* Implement ambient-light-based lighting decisions.

### Tasks

1. Connect the PIR sensor.
2. Test presence detection.
3. Connect the LDR module.
4. Read and record LDR values under different lighting conditions.
5. Determine suitable ambient-light thresholds.
6. Combine PIR and LDR logic.
7. Implement automatic lighting decisions.
8. Test different combinations of presence and ambient light.

### Initial Decision Logic

```text
IF person is not detected
    Light = OFF

ELSE
    Read ambient light

    IF environment is very dark
        Brightness = 100%

    ELSE IF environment is moderate
        Brightness = approximately 50%

    ELSE
        Light = OFF or minimum brightness
```

### Expected Output

A standalone smart lighting system that operates without requiring Wi-Fi or the dashboard.

---

# Phase 3 — Adaptive Lighting and Energy Estimation

**Sessions:** 5–6
**Target:** Week 2

### Objectives

* Improve the lighting logic from basic threshold control to adaptive brightness.
* Implement software-based energy estimation.
* Begin collecting energy-related data.

### Tasks

1. Calibrate LDR readings.
2. Map ambient-light levels to brightness levels.
3. Implement smooth or multi-level PWM control.
4. Record lighting operating time.
5. Record brightness/duty-cycle information.
6. Implement software-based energy estimation.
7. Calculate total energy consumption.
8. Calculate estimated energy savings.

### Energy Estimation

The initial system will use:

$$
Energy = Power \times Time
$$

For example:

$$
10W \times 0.5h = 5Wh
$$

For PWM-controlled operation, the software may incorporate the approximate duty cycle/brightness level into the estimated energy calculation.

### Expected Output

The system should provide:

* Adaptive brightness
* Lighting operating time
* Estimated energy consumption
* Estimated energy savings

---

# Phase 4 — Wi-Fi Connectivity and IoT Dashboard

**Sessions:** 7–8
**Target:** Week 2

### Objectives

* Connect the ESP32 to Wi-Fi.
* Establish communication between the ESP32 and the IoT dashboard.
* Display live system information.

### Data to be transmitted

* PIR status
* LDR reading
* Ambient-light condition
* Light status
* Brightness percentage
* Operating time
* Estimated energy consumption
* Estimated energy savings
* System/fault status

### Dashboard Requirements

The dashboard should provide:

#### Live Monitoring

* Human presence
* Ambient-light level
* Light status
* Current brightness

#### Energy Monitoring

* Current estimated energy consumption
* Total energy consumption
* Estimated energy savings

#### Historical Analysis

* Lighting usage over time
* Brightness trends
* Energy consumption trends
* Presence/activity trends

### Expected Output

A functional:

**ESP32 → Wi-Fi → IoT Dashboard**

communication pipeline.

---

# Phase 5 — Data Logging and Energy Analysis

**Session:** 9
**Target:** Week 3

### Objectives

* Collect system readings over time.
* Store or visualize historical information.
* Compare conventional and smart lighting behavior.

### Tasks

1. Log sensor readings.
2. Record lighting operating periods.
3. Record brightness levels.
4. Calculate cumulative estimated energy consumption.
5. Generate historical graphs.
6. Establish a conventional-lighting baseline.
7. Compare conventional and smart-lighting operation.
8. Calculate estimated energy savings.

### Example Data

| Time  | PIR | LDR | Brightness | Energy |
| ----- | --: | --: | ---------: | -----: |
| 10:00 |   0 | 720 |         0% |   0 Wh |
| 10:05 |   1 | 320 |        50% |      — |
| 10:10 |   1 | 150 |       100% |      — |
| 10:15 |   0 | 140 |         0% |      — |

### Expected Output

A dataset and dashboard visualization showing actual system usage and estimated energy savings.

---

# Phase 6 — Fault Detection and Reliability Testing

**Session:** 10
**Target:** Week 3

### Objectives

* Improve system reliability.
* Detect basic abnormal operating conditions.
* Verify that lighting continues to function when Wi-Fi is unavailable.

### Possible Fault/Status Conditions

The system may identify conditions such as:

* Invalid sensor readings
* Sensor disconnection
* Unexpected lighting state
* Communication failure
* Abnormal operating condition

A basic rule-based approach will be used rather than implementing complex machine learning.

### Reliability Tests

The following conditions will be tested:

1. PIR sensor response.
2. LDR response.
3. Rapid changes in human presence.
4. Rapid changes in ambient light.
5. ESP32 restart.
6. Wi-Fi disconnection.
7. Wi-Fi reconnection.
8. Invalid or abnormal sensor values.

### Important Requirement

**Wi-Fi failure must not stop the local lighting system.**

The ESP32 will continue making lighting decisions locally even when the dashboard is unavailable.

### Expected Output

A more reliable and fault-tolerant prototype.

---

# Phase 7 — Final Physical Model and System Integration

**Session:** 11
**Target:** Week 4

### Objectives

* Assemble the final prototype.
* Integrate all hardware and software components.
* Prepare the project for demonstration.

### Final Integration

The following components will be integrated:

```text
PIR Sensor
     +
LDR Sensor
     ↓
   ESP32
     ↓
Decision Logic
     ↓
PWM Control
     ↓
LED / LED Strip
     ↓
Energy Calculation
     ↓
Wi-Fi
     ↓
IoT Dashboard
```

### Physical Demonstration Model

A small room-like model may be constructed to visually demonstrate:

* Lighting area
* PIR sensor position
* LDR position
* LED/LED strip
* Breadboard
* ESP32
* Power supply

The physical model will be used as a presentation layer while keeping the actual circuit visible.

### Expected Output

A complete integrated prototype ready for final testing.

---

# Phase 8 — Final Testing, Results and Documentation

**Session:** 12
**Target:** Week 4

### Objectives

* Perform final system testing.
* Record results.
* Prepare project documentation.
* Prepare the final demonstration.

### Functional Test Cases

| Test Case                            | Expected Result          |
| ------------------------------------ | ------------------------ |
| No person detected                   | Light OFF                |
| Person detected + very dark          | 100% brightness          |
| Person detected + moderate light     | Reduced brightness       |
| Person detected + bright environment | OFF/minimum              |
| Person leaves                        | Light turns OFF          |
| Wi-Fi disconnected                   | Local lighting continues |
| Wi-Fi reconnects                     | Dashboard resumes        |
| ESP32 restarted                      | System recovers          |
| Sensor abnormality                   | Status/fault indication  |

### Energy Analysis

The project will compare:

**Conventional lighting**

versus

**Smart adaptive lighting**

using:

* Operating time
* Brightness level
* Estimated energy consumption
* Estimated energy savings

Once an actual energy sensor is available, the estimated values can be compared with measured values.

---

# 6. Future Energy Sensor Integration

An actual energy measurement sensor is **not required for the initial implementation**.

The initial system will use software-based energy estimation.

Later, a suitable voltage/current/energy measurement sensor can be integrated.

### Current System

```text
LED Power Rating
       +
Operating Time
       +
Brightness
       ↓
Estimated Energy
```

### Future System

```text
Voltage Measurement
       +
Current Measurement
       ↓
Actual Power
       ↓
Actual Energy
```

The measured energy can then be compared against the estimated energy to validate the software calculations.

---

# 7. Final Expected Features

The completed project is expected to provide:

* Automatic human-presence detection
* Ambient-light detection
* Automatic light OFF when no person is present
* Adaptive brightness control
* PWM-based LED control
* One physical lighting zone
* ESP32-based local decision-making
* Wi-Fi connectivity
* IoT dashboard
* Live sensor monitoring
* Historical data visualization
* Software-based energy estimation
* Estimated energy-savings calculation
* Basic fault/status detection
* Operation independent of Wi-Fi availability
* Experimental testing and comparison
* Expandability for future energy-sensor integration

---

# 8. Final Deliverables

At the end of the one-month development period, the team will produce:

1. **Working hardware prototype**
2. **ESP32 firmware**
3. **IoT dashboard**
4. **Energy-consumption analysis**
5. **Historical usage data/graphs**
6. **Testing and validation results**
7. **Physical demonstration model**
8. **Project report/documentation**
9. **System architecture and circuit diagrams**
10. **Final presentation/demo**

---

# 9. Four-Week Summary

| Week       | Major Activities                                                       | Expected Milestone              |
| ---------- | ---------------------------------------------------------------------- | ------------------------------- |
| **Week 1** | ESP32, LED, PWM, PIR, LDR, basic lighting logic                        | Sensor-based smart lighting     |
| **Week 2** | Adaptive brightness, energy estimation, Wi-Fi, dashboard               | Connected smart-lighting system |
| **Week 3** | Data logging, historical analysis, energy comparison, fault detection  | Tested and measurable system    |
| **Week 4** | Physical model, full integration, testing, documentation, presentation | Final working prototype         |

---

# 10. Development Philosophy

The project will follow an **incremental development approach**.

Each major feature will first be tested independently before being integrated into the complete system.

The development sequence will be:

**Basic Hardware → Sensors → Smart Logic → Adaptive Brightness → Energy Estimation → Wi-Fi → Dashboard → Data Analysis → Fault Detection → Final Integration → Testing**

This approach reduces integration problems and ensures that the core lighting system remains functional even if optional components such as the actual energy sensor are added later.

---

## Final Project Goal

The final system will demonstrate how an IoT-enabled lighting system can use **human presence and ambient-light information to automatically control lighting and reduce unnecessary energy consumption**, while providing real-time monitoring and historical analysis through a Wi-Fi dashboard.
