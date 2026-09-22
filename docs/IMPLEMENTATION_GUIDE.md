# Smart Wi-Fi Lighting & Energy Optimization System

## Complete Step-by-Step Implementation Guide

---

# 1. Purpose of This Document

This document explains **how to build the Smart Wi-Fi Lighting & Energy Optimization System from the beginning**, assuming no prior knowledge of the project.

The implementation will be performed incrementally. Each stage will be completed and tested before moving to the next stage.

The final system will contain:

* ESP32
* PIR motion sensor
* LDR ambient-light sensor
* LED/low-voltage DC LED strip
* PWM brightness control
* Automatic presence-based lighting
* Adaptive brightness
* Wi-Fi connectivity
* IoT dashboard
* Energy-consumption estimation
* Energy-savings analysis
* Historical graphs
* Basic fault/status detection
* Optional physical energy sensor integration later

The project will use **one physical lighting zone**.

---

# 2. IMPORTANT SAFETY DISCLAIMER

## READ THIS BEFORE CONNECTING ANYTHING

This project is intended as a **low-voltage educational prototype**.

### DO NOT connect the ESP32, breadboard, PIR, LDR, transistor/MOSFET, or LED strip directly to a 230 V AC mains supply.

The initial project must use:

* USB power
* Battery power
* Appropriate low-voltage DC power supplies

The LED strip must be operated according to its rated voltage.

### Additional safety rules

1. Never connect 230 V AC to the breadboard.
2. Never connect an LED strip directly to an ESP32 GPIO pin.
3. Do not assume that the battery/power source is suitable for the LED strip. Check its voltage first.
4. Check the LED strip's voltage and approximate current requirement before connecting it.
5. The ESP32 GPIO pins are control signals, not power outputs for an LED strip.
6. Use a suitable transistor/MOSFET driver for the LED strip.
7. Disconnect USB/power before changing wiring.
8. Never change several wires while the circuit is powered.
9. Check wiring twice before applying power.
10. If a component becomes unusually hot, smells like burning plastic, or behaves unexpectedly, immediately disconnect power.
11. Do not use damaged wires, damaged batteries, or damaged power supplies.
12. Do not experiment with mains electricity as part of this project.
13. If a future version requires mains-powered lighting, use qualified supervision and appropriate electrical protection. That is outside the scope of this project.

---

# 3. Do Not Build Everything at Once

A beginner mistake would be to connect:

PIR + LDR + LED strip + MOSFET + ESP32 + Wi-Fi + dashboard

all at the same time.

Do **not** do that.

The project will be developed in this order:

```text
ESP32
  ↓
Small LED
  ↓
PWM brightness
  ↓
PIR
  ↓
LDR
  ↓
Smart lighting logic
  ↓
LED-strip driver
  ↓
Wi-Fi
  ↓
Dashboard
  ↓
Energy estimation
  ↓
Data/history
  ↓
Fault detection
  ↓
Final model
```

At every stage, we will first prove that the previous stage works.

---

# 4. Components Required

## 4.1 Components Already Available

The initial build can use:

* ESP32 DevKit
* Breadboard
* HC-SR501 PIR sensor
* LDR module
* DC LED strip
* Small LED bulbs
* 220 Ω resistors
* Male-to-male jumper wires
* Male-to-female jumper wires
* USB cable
* Low-voltage battery/power source
* Laptop/PC
* Mobile hotspot

---

# 5. Components That May Need to Be Purchased

The exact requirements will be checked before purchasing anything.

Potential additional components:

### Required for proper LED-strip control

* Logic-level N-channel MOSFET or suitable transistor
* Appropriate resistor(s)
* Optional pull-down resistor
* Appropriate external power connection for the LED strip

### Optional later upgrade

* Voltage/current/energy measurement sensor

The energy sensor should **not be purchased blindly**. The sensor will be selected after checking the LED strip's voltage and current requirements.

The additional hardware budget should remain within the planned **₹300 limit** wherever possible.

---

# 6. Software Required

The exact software stack will be selected during the Wi-Fi/dashboard phase.

The basic development environment will include:

* Arduino IDE or an equivalent ESP32-compatible development environment
* ESP32 board support
* USB serial connection
* ESP32 libraries required for sensors and networking
* IoT dashboard platform
* Data visualization/dashboard components

Do not install a large number of libraries before they are needed.

---

# 7. TEAM WORKING METHOD

Since there are four team members, the project can be developed collaboratively.

The team does not need permanent specialist roles.

For each session, assign:

### Person 1 — Hardware

Checks wiring and physical components.

### Person 2 — Firmware

Works on ESP32 code.

### Person 3 — Testing/Data

Records sensor values and test results.

### Person 4 — Documentation

Records:

* wiring
* results
* screenshots
* problems
* solutions
* test cases

Roles can rotate between sessions.

This prevents the situation where only one member understands the project.

---

# 8. SESSION 1 — ESP32 SETUP

## Objective

Make sure the ESP32 can communicate with the computer and execute a basic program.

---

## Step 1 — Inspect the ESP32

Before connecting anything:

1. Take the ESP32 development board.
2. Identify the USB port.
3. Identify the GPIO pins.
4. Identify the GND pins.
5. Identify the 3.3 V pin.
6. Identify the VIN/5 V-related pin if present.
7. Do not connect the LED strip yet.

Take a clear photograph of the ESP32 pin labels.

Save it in the project documentation.

---

## Step 2 — Connect ESP32 to Laptop

1. Keep the breadboard disconnected.
2. Connect the ESP32 to the laptop using the USB cable.
3. Wait for Windows to detect the board.
4. Open the development environment.
5. Check whether a serial/COM port appears.

If the board is not detected, do not continue to wiring.

Resolve the USB/driver/board-selection issue first.

---

## Step 3 — Install ESP32 Board Support

In the development environment:

1. Open the board-management section.
2. Search for ESP32.
3. Install the appropriate ESP32 board package.
4. Select the appropriate ESP32 DevKit board.
5. Select the detected COM port.

The exact board name may vary depending on the ESP32 DevKit version.

---

## Step 4 — Upload a Basic Test Program

Start with a simple program that prints a message through Serial Monitor.

The purpose is only to verify:

```text
Laptop
   ↓ USB
ESP32
   ↓
Program executes
   ↓
Serial Monitor
```

Open Serial Monitor and verify that the message appears.

---

## Step 5 — Record the Result

Document:

* ESP32 model
* Development environment
* Board selected
* COM port
* Successful upload
* Serial output

### Do not proceed until:

**The ESP32 successfully uploads and runs a program.**

---

# 9. SESSION 1 — BASIC LED TEST

## Objective

Control a small LED from the ESP32.

Do not use the LED strip yet.

---

## Step 1 — Understand LED Polarity

A normal LED has:

* Anode: positive side
* Cathode: negative side

The longer leg is commonly the anode.

The shorter leg is commonly the cathode.

If the LED has a flat edge, that can also help identify the cathode.

Do not rely solely on appearance if the component is unclear.

---

## Step 2 — Use the 220 Ω Resistor

The LED should be connected with an appropriate current-limiting resistor.

Basic arrangement:

```text
ESP32 GPIO
    |
    |
  220 Ω
    |
   LED
    |
   GND
```

The resistor protects the LED and limits current.

---

## Step 3 — Connect Ground

Connect:

```text
ESP32 GND → Breadboard GND rail
```

Make sure the connection is secure.

---

## Step 4 — Connect LED

Connect the GPIO output through the resistor to the LED.

The LED's other side goes to GND.

Do not connect the LED directly without the resistor.

---

## Step 5 — Upload ON/OFF Test

The program should:

1. Set the selected GPIO as an output.
2. Turn the LED ON.
3. Wait.
4. Turn the LED OFF.
5. Repeat.

---

## Step 6 — Test

Confirm:

* LED turns ON.
* LED turns OFF.
* No component becomes hot.
* ESP32 remains stable.

### If the LED does not turn on

Check:

1. LED orientation.
2. Resistor connection.
3. GPIO number.
4. GND connection.
5. Breadboard row alignment.
6. Program upload.

Do not randomly move wires while powered.

Disconnect power before changing wiring.

---

# 10. SESSION 2 — PWM BRIGHTNESS CONTROL

## Objective

Make the LED dim and brighten rather than only ON/OFF.

PWM means **Pulse Width Modulation**.

The ESP32 rapidly switches the output and controls the percentage of time the output remains ON.

Conceptually:

```text
0% duty cycle    → OFF
25%              → Dim
50%              → Medium
75%              → Bright
100%             → Full
```

---

## Step 1 — Keep the Same LED Circuit

Do not change the basic LED wiring yet.

---

## Step 2 — Implement PWM

Configure an ESP32 PWM-capable output using the appropriate ESP32 Arduino PWM method.

The program should gradually test:

```text
0%
25%
50%
75%
100%
```

---

## Step 3 — Observe

Verify that the LED visually changes brightness.

If the LED appears to flicker or behaves unexpectedly, stop and verify the PWM configuration and wiring.

---

## Step 4 — Create a Brightness Function

The final firmware should eventually have a logical function similar to:

```text
setBrightness(0)
setBrightness(50)
setBrightness(100)
```

This will make the later lighting logic easier to implement.

---

# 11. SESSION 3 — PIR SENSOR

## Objective

Detect human movement/presence.

The HC-SR501 PIR typically has:

* VCC
* GND
* OUT

The exact pin arrangement should be checked on the physical module before wiring.

---

## Step 1 — Power the PIR

Use the module's appropriate supply voltage.

Do not assume every PIR module has identical specifications.

Check the markings on the module.

---

## Step 2 — Connect

Conceptually:

```text
PIR VCC → appropriate ESP32 supply
PIR GND → ESP32 GND
PIR OUT → ESP32 digital input
```

The exact GPIO will be selected in the firmware.

---

## Step 3 — Upload PIR Test

Write a small program that prints:

```text
Motion detected
```

when the PIR output indicates motion.

Otherwise print:

```text
No motion
```

---

## Step 4 — Test

Walk in front of the sensor.

Wait for the PIR to stabilize after powering it on.

Observe the Serial Monitor.

Test:

* Walk toward sensor.
* Walk away.
* Remain still.
* Move repeatedly.

Remember that a PIR detects changes in infrared radiation and movement; it should not be treated as a perfect continuous human-presence sensor.

---

## Step 5 — Adjust PIR Module

The HC-SR501 commonly provides sensitivity and timing adjustments.

Do not immediately change them.

First understand the default behavior.

Later, tune them so the lighting does not switch unnecessarily.

---

# 12. SESSION 4 — LDR SENSOR

## Objective

Measure ambient light.

---

## Step 1 — Identify LDR Module Pins

Many LDR modules have:

* VCC
* GND
* AO
* sometimes DO

For this project, the **analog output (AO)** is the important signal because adaptive brightness requires a varying light measurement.

---

## Step 2 — Connect

Conceptually:

```text
LDR VCC → appropriate supply
LDR GND → ESP32 GND
LDR AO  → ESP32 ADC-capable input
```

Use an ADC-capable ESP32 pin appropriate for the selected board.

---

## Step 3 — Read the Analog Value

Upload a simple program that prints the LDR reading to Serial Monitor.

---

## Step 4 — Perform Calibration

Record readings under:

1. Very dark conditions.
2. Normal indoor lighting.
3. Bright phone flashlight/light.
4. Natural daylight if available.

Create a table:

| Condition   |  LDR Reading |
| ----------- | -----------: |
| Very dark   | Record value |
| Dark        | Record value |
| Indoor      | Record value |
| Bright      | Record value |
| Very bright | Record value |

The exact numbers will depend on the sensor and module.

Do not copy threshold values from an internet tutorial and assume they will work on your sensor.

---

# 13. SESSION 4 — COMBINE PIR + LDR + LED

## Objective

Create the first version of the actual smart-lighting system.

The logic is:

```text
PIR
 ↓
Is person detected?
 ↓
NO ─────────→ Light OFF
 |
YES
 ↓
Read LDR
 ↓
Determine ambient-light level
 ↓
Determine brightness
 ↓
Control LED
```

---

# 14. Implement the First Lighting Rules

Start with simple thresholds.

Example:

```text
No person
→ 0%

Person + bright
→ 0%

Person + moderate
→ 50%

Person + dark
→ 100%
```

These values are starting points only.

They will be calibrated later.

---

# 15. Test the Complete Basic Logic

Perform these tests one at a time.

### Test 1

No person + dark room.

Expected:

**Light OFF**

### Test 2

Person + dark room.

Expected:

**Light ON at high brightness**

### Test 3

Person + moderate lighting.

Expected:

**Reduced brightness**

### Test 4

Person + bright environment.

Expected:

**Light OFF or minimum brightness**

### Test 5

Person leaves.

Expected:

**Light turns OFF after the chosen PIR behavior/timing.**

Record every result.

---

# 16. SESSION 5 — IMPROVE ADAPTIVE BRIGHTNESS

The first version uses simple categories.

Now improve it.

Instead of only:

```text
Dark → 100%
Medium → 50%
Bright → OFF
```

the system can use several levels:

```text
Very dark → 100%
Dark → 80%
Moderate → 50%
Bright → 20%
Very bright → 0%
```

The exact mapping will be determined experimentally.

---

# 17. Avoid Rapid Brightness Changes

Sensor readings can fluctuate.

For example:

```text
50%
52%
49%
51%
50%
```

The light should not visibly jump between brightness levels every few milliseconds.

Implement a suitable strategy such as:

* averaging several LDR readings
* filtering
* hysteresis
* gradual brightness transitions

This makes the system appear much more polished.

---

# 18. SESSION 6 — ENERGY ESTIMATION

## Objective

Calculate estimated energy consumption before installing an actual energy sensor.

---

## Step 1 — Find LED Power Rating

Check the LED strip's label/specification.

Determine:

* voltage
* rated power
* current if available

Do not guess the power rating.

If the strip's specification is unclear, use the small LED for early software testing and determine the strip specification before final calculations.

---

## Step 2 — Calculate Basic Energy

The basic equation is:

$$
E = P \times t
$$

where:

* E = energy
* P = power
* t = time

Example:

```text
10 W light
running for 30 minutes

10 × 0.5 = 5 Wh
```

---

## Step 3 — Include Brightness

For PWM operation, the software can initially estimate power according to duty cycle.

For example, as an approximation:

```text
100% → approximately full rated power
50%  → approximately half of rated power
25%  → approximately one-quarter
```

This is an **estimate**, not a substitute for actual electrical measurement.

---

## Step 4 — Record Energy

The ESP32 should maintain values such as:

```text
Operating time
Current brightness
Estimated power
Accumulated energy
```

These values will later be sent to the dashboard.

---

# 19. SESSION 7 — LED STRIP CONTROL

## IMPORTANT SAFETY STEP

Do not connect the LED strip directly to an ESP32 GPIO.

The GPIO cannot safely supply the required strip current.

A proper switching stage is required.

---

## Basic architecture

```text
             External DC Supply
                    │
                    │
                LED Strip
                    │
                    │
                 MOSFET
                    │
                   GND

ESP32 GPIO
     │
     └────→ MOSFET control
```

The exact circuit depends on:

* LED-strip voltage
* LED-strip current
* MOSFET selected
* power-supply arrangement

---

## Before Building

Record the strip specifications.

Example:

```text
Strip voltage: ______ V
Strip power: ______ W
Strip length: ______
Approximate current: ______ A
Power source: ______ V
```

Only after these values are known should the final driver circuit be selected.

---

# 20. Test LED Strip ON/OFF

Before PWM:

1. Build the driver circuit.
2. Verify common ground where required by the chosen driver arrangement.
3. Keep ESP32 and strip power arrangements correct.
4. Test the strip at a safe operating level.
5. Confirm ON/OFF control.
6. Check for excessive heat.
7. Disconnect power before modifying anything.

Do not immediately start with complex PWM.

---

# 21. Test LED Strip PWM

After reliable ON/OFF operation:

Test:

```text
0%
25%
50%
75%
100%
```

Confirm that brightness changes correctly.

If the MOSFET or power supply becomes unusually hot, disconnect power and investigate.

---

# 22. SESSION 7–8 — WI-FI CONNECTION

## Objective

Connect the ESP32 to the internet/network through the available mobile hotspot.

---

## Step 1 — Activate Hotspot

Use the phone that will provide the network.

Record:

* Wi-Fi network name
* Wi-Fi password

Do not put real passwords into public GitHub repositories.

Use configuration methods that keep credentials out of source control where possible.

---

## Step 2 — Test ESP32 Wi-Fi

First create a very small Wi-Fi test program.

The ESP32 should:

1. Start Wi-Fi.
2. Connect to the hotspot.
3. Print connection status.
4. Print the assigned network information if appropriate.
5. Continue running.

---

## Step 3 — Test Reconnection

Turn the hotspot off temporarily.

Observe the ESP32.

Turn the hotspot back on.

The ESP32 should attempt to reconnect.

---

# 23. Important Wi-Fi Design Rule

The lighting system must **not depend on the dashboard**.

Correct architecture:

```text
             ┌─────────────┐
PIR ────────→│             │
LDR ────────→│    ESP32    │
             │             │
             └──────┬──────┘
                    │
             Local lighting
                    │
                    ↓
                  LED

                    +

             Wi-Fi connection
                    │
                    ↓
               Dashboard
```

If Wi-Fi fails:

```text
PIR + LDR → ESP32 → LED
```

must continue working.

---

# 24. SESSION 8 — SELECT AND BUILD DASHBOARD

## Objective

Create the IoT monitoring interface.

The dashboard should be browser/device-independent as far as practical.

The final platform will be selected based on:

* ESP32 compatibility
* live data support
* historical charts
* ease of integration
* free/student availability
* reliability
* mobile/browser access

Do not choose the dashboard solely because it looks attractive.

---

# 25. Dashboard Data

Create dashboard variables for:

### Sensor Data

* PIR status
* LDR value
* Ambient-light category

### Lighting

* Light status
* Brightness percentage

### Energy

* Estimated instantaneous/operating power
* Total estimated energy
* Estimated energy savings

### System

* Wi-Fi status
* ESP32 status
* Fault/status message

---

# 26. Dashboard Layout

A possible layout:

```text
┌────────────────────────────────────┐
│ SMART LIGHTING DASHBOARD           │
├────────────────────────────────────┤
│ Human Presence     DETECTED        │
│ Ambient Light      320             │
│ Light Status       ON              │
│ Brightness         50%             │
├────────────────────────────────────┤
│ Energy Consumed    0.025 kWh       │
│ Estimated Saving   32%             │
├────────────────────────────────────┤
│                                    │
│       Historical Usage Graph        │
│                                    │
├────────────────────────────────────┤
│ System Status      NORMAL          │
└────────────────────────────────────┘
```

The exact dashboard design will depend on the selected IoT platform.

---

# 27. SESSION 9 — DATA LOGGING

## Objective

Collect useful information over time.

The system should record readings at suitable intervals rather than sending data continuously at an unnecessarily high rate.

Example:

```text
Timestamp
PIR
LDR
Brightness
Light state
Estimated power
Cumulative energy
System status
```

Example:

| Time  | PIR | LDR | Brightness | Light | Energy |
| ----- | --: | --: | ---------: | ----- | -----: |
| 10:00 |   0 | 700 |         0% | OFF   |      0 |
| 10:05 |   1 | 350 |        50% | ON    |      — |
| 10:10 |   1 | 150 |       100% | ON    |      — |
| 10:15 |   0 | 150 |         0% | OFF   |      — |

---

# 28. Historical Graphs

Create graphs for:

1. Ambient light versus time.
2. Brightness versus time.
3. Lighting ON/OFF periods.
4. Energy consumption versus time.
5. Optional presence activity.

The purpose is to show that the system is doing more than merely displaying current sensor values.

---

# 29. SESSION 9 — ENERGY-SAVINGS COMPARISON

Create a baseline representing conventional lighting.

Example:

### Conventional model

The light operates at full brightness whenever the system considers the space in use.

### Smart model

The system uses:

* presence
* ambient light
* adaptive brightness

to determine the required output.

Then compare:

$$
Savings =
E_{conventional} - E_{smart}
$$

and:

$$
Savings\% =
\frac{E_{conventional}-E_{smart}}
{E_{conventional}}
\times100
$$

Clearly label these as **estimated** until actual electrical measurement is available.

---

# 30. SESSION 10 — FAULT/STATUS DETECTION

The project does not need artificial intelligence for fault detection.

Use simple rules.

Examples:

### Sensor abnormality

If an LDR reading is outside a physically reasonable range:

```text
Status = SENSOR CHECK
```

### Communication problem

If the ESP32 cannot connect to Wi-Fi:

```text
Wi-Fi = DISCONNECTED
Lighting = CONTINUE LOCALLY
```

### Unexpected condition

If a commanded lighting state cannot be maintained according to the available feedback:

```text
Status = POSSIBLE LIGHTING FAULT
```

The exact fault-detection capabilities depend on what sensors are actually available.

Do not claim that the system can detect faults that it has no hardware/software means to observe.

---

# 31. SESSION 10 — RELIABILITY TESTING

Test the system repeatedly.

## Test A — No person

Expected:

```text
PIR = No detection
Light = OFF
```

## Test B — Person enters dark environment

Expected:

```text
PIR = Detected
LDR = Dark
Light = High brightness
```

## Test C — Person enters moderately lit environment

Expected:

```text
PIR = Detected
LDR = Moderate
Light = Reduced brightness
```

## Test D — Person enters bright environment

Expected:

```text
PIR = Detected
LDR = Bright
Light = OFF/minimum
```

## Test E — Person leaves

Expected:

```text
Light = OFF
```

after the configured PIR behavior.

## Test F — Wi-Fi disconnect

Expected:

```text
Dashboard = unavailable/disconnected
Lighting = continues operating
```

## Test G — Wi-Fi reconnect

Expected:

```text
Dashboard = reconnects
Data = resumes
```

## Test H — ESP32 restart

Expected:

```text
ESP32 restarts
Sensors initialize
Lighting logic resumes
```

Record the actual results.

---

# 32. SESSION 11 — FINAL PHYSICAL MODEL

## Objective

Create a small visual representation of a smart room.

The physical model does not need to be elaborate.

A simple structure can contain:

```text
┌─────────────────────────┐
│                         │
│        LED LIGHT        │
│           💡            │
│                         │
│ PIR ●                   │
│                         │
│                  ● LDR  │
│                         │
└─────────────────────────┘
```

The breadboard containing the ESP32 and sensor connections should remain visible.

---

# 33. Final Hardware Arrangement

The final system should conceptually look like:

```text
             ┌────────────┐
             │    PIR     │
             └─────┬──────┘
                   │
             ┌─────▼──────┐
             │    ESP32   │
             │            │
LDR ────────→│  Decision  │
             │   + PWM    │
             └─────┬──────┘
                   │
                   ▼
            Driver Circuit
                   │
                   ▼
             LED / Strip
                   │
                   ▼
             Light Output


ESP32
  │
  └──── Wi-Fi ────→ IoT Dashboard
                         │
                         ├── Live Data
                         ├── History
                         ├── Energy
                         └── Status
```

---

# 34. SESSION 11 — FULL SYSTEM INTEGRATION

Connect all completed modules.

Do not change everything simultaneously.

Perform integration in this order:

### Integration 1

ESP32 + LED

Test.

### Integration 2

ESP32 + LED + PIR

Test.

### Integration 3

ESP32 + LED + PIR + LDR

Test.

### Integration 4

ESP32 + LED driver/strip

Test.

### Integration 5

Add energy calculation.

Test.

### Integration 6

Add Wi-Fi.

Test.

### Integration 7

Add dashboard.

Test.

### Integration 8

Add historical data.

Test.

### Integration 9

Add fault/status logic.

Test.

This makes it easier to identify the source of problems.

---

# 35. SESSION 12 — FINAL DEMONSTRATION TEST

The final demonstration should tell a clear story.

## Demonstration Sequence

### Step 1

Start the system.

Show:

```text
ESP32 running
Dashboard connected
```

### Step 2

Keep the area empty.

Expected:

```text
No person
→ Light OFF
```

### Step 3

Enter the detection area while it is dark.

Expected:

```text
Person detected
→ Light turns ON
→ High brightness
```

### Step 4

Increase ambient light.

Expected:

```text
Ambient light increases
→ Brightness decreases
```

### Step 5

Make the environment sufficiently bright.

Expected:

```text
Light turns OFF or reaches minimum level
```

### Step 6

Leave the area.

Expected:

```text
No person
→ Light OFF
```

### Step 7

Show the dashboard.

Demonstrate:

* PIR state
* LDR reading
* brightness
* light status
* energy
* historical graph
* system status

### Step 8

Disconnect Wi-Fi.

Show that:

```text
Lighting still operates locally.
```

This is an important demonstration point.

---

# 36. FINAL DOCUMENTATION

The team should maintain documentation throughout the project.

Do not wait until the final day.

Maintain the following:

## Hardware Documentation

* Component list
* Component specifications
* Wiring diagram
* Circuit photographs
* Final hardware photograph

## Software Documentation

* ESP32 source code
* Sensor logic
* PWM logic
* Energy calculation
* Wi-Fi communication
* Dashboard configuration

## Testing Documentation

For every test:

```text
Test ID:
Date:
Condition:
Input:
Expected Result:
Actual Result:
Pass/Fail:
Notes:
```

---

# 37. PROJECT REPORT STRUCTURE

The final report can use:

## Chapter 1 — Introduction

Explain smart lighting and energy wastage.

## Chapter 2 — Problem Statement

Explain unnecessary lighting caused by:

* empty spaces
* sufficient natural light
* fixed-brightness operation

## Chapter 3 — Objectives

List project objectives.

## Chapter 4 — Proposed System

Explain the ESP32-based architecture.

## Chapter 5 — Hardware

Explain:

* ESP32
* PIR
* LDR
* LED
* driver circuit
* power supply

## Chapter 6 — Software

Explain:

* sensor processing
* decision logic
* PWM
* Wi-Fi
* dashboard
* energy calculations

## Chapter 7 — Methodology

Explain the implementation sequence.

## Chapter 8 — Testing

Include test cases and results.

## Chapter 9 — Energy Analysis

Include:

* operating time
* estimated energy
* comparison
* estimated savings

## Chapter 10 — Results

Present final observations.

## Chapter 11 — Limitations

Examples:

* single-zone prototype
* estimated energy before physical measurement
* PIR limitations
* prototype-scale LED system

## Chapter 12 — Future Scope

Possible future improvements:

* multiple independently sensed zones
* actual energy measurement
* larger-scale deployment
* additional sensors
* advanced analytics
* integration with building-management systems

## Chapter 13 — Conclusion

Summarize the completed system.

---

# 38. OPTIONAL ENERGY SENSOR — LATER STAGE

The energy sensor is intentionally postponed.

Once the lighting system is stable:

1. Check the LED strip voltage.
2. Check its maximum current/power.
3. Determine the appropriate measurement method.
4. Select a compatible sensor.
5. Purchase it within the remaining budget if possible.
6. Study its wiring requirements.
7. Test the sensor separately.
8. Read voltage/current data with ESP32.
9. Calculate actual power.
10. Calculate actual energy.
11. Compare measured energy with software estimation.
12. Update the dashboard.

The sensor should be integrated only after its electrical compatibility is confirmed.

---

# 39. IMPORTANT: DO NOT CLAIM MEASURED ENERGY BEFORE THE SENSOR EXISTS

Until a real energy measurement device is installed, use terminology such as:

**Estimated Energy Consumption**

and:

**Estimated Energy Savings**

Do not label software calculations as:

**Actual Energy Consumption**

or:

**Measured Energy Savings**

This distinction is important in the final report and presentation.

---

# 40. COMMON PROBLEMS AND HOW TO APPROACH THEM

## Problem: ESP32 does not upload

Check:

1. USB cable.
2. COM port.
3. Board selection.
4. Driver.
5. USB connection.
6. Upload mode requirements of the board.

---

## Problem: LED does not light

Check:

1. LED polarity.
2. Resistor.
3. GPIO number.
4. GND.
5. Breadboard placement.
6. Program.

---

## Problem: PIR behaves strangely

Check:

1. Power.
2. GND.
3. Output pin.
4. Warm-up period.
5. Sensitivity.
6. Timing adjustment.
7. Detection environment.

---

## Problem: LDR values seem reversed

Some LDR modules produce higher analog values in brighter conditions while others/configurations may behave differently.

Do not assume the direction.

Test it experimentally.

Record:

```text
Dark → ______
Bright → ______
```

Then write the software logic accordingly.

---

## Problem: LED strip does not dim

Check:

1. Strip voltage.
2. Power supply.
3. MOSFET suitability.
4. Wiring.
5. Common ground requirements.
6. PWM-capable control configuration.

Do not connect the strip directly to the ESP32.

---

## Problem: ESP32 resets when LED strip turns on

Possible causes include:

* inadequate power supply
* voltage drop
* incorrect grounding
* excessive current
* unsuitable wiring

Disconnect power and investigate before continuing.

Do not repeatedly power-cycle a potentially incorrect circuit.

---

## Problem: Dashboard stops but light works

This is not necessarily a hardware failure.

If:

```text
ESP32 → lighting
```

continues working while:

```text
ESP32 → Wi-Fi → dashboard
```

fails, the local-control architecture is behaving as intended.

---

# 41. DEVELOPMENT CHECKPOINTS

The team should not move forward simply because the scheduled session has ended.

Use these checkpoints.

## Checkpoint 1

**ESP32 works**

↓

## Checkpoint 2

**LED ON/OFF works**

↓

## Checkpoint 3

**PWM works**

↓

## Checkpoint 4

**PIR works**

↓

## Checkpoint 5

**LDR works**

↓

## Checkpoint 6

**PIR + LDR + adaptive lighting works**

↓

## Checkpoint 7

**LED strip works safely**

↓

## Checkpoint 8

**Energy estimation works**

↓

## Checkpoint 9

**Wi-Fi works**

↓

## Checkpoint 10

**Dashboard works**

↓

## Checkpoint 11

**Historical data works**

↓

## Checkpoint 12

**Fault/status logic works**

↓

## Checkpoint 13

**Full system works**

↓

## Checkpoint 14

**Final testing completed**

---

# 42. FINAL SYSTEM ARCHITECTURE

The completed project will follow this architecture:

```text
                  ┌─────────────┐
                  │     PIR     │
                  │  Presence   │
                  └──────┬──────┘
                         │
                         │
                  ┌──────▼──────┐
                  │     LDR     │
                  │ Ambient     │
                  │ Light       │
                  └──────┬──────┘
                         │
                         ▼
                  ┌─────────────┐
                  │    ESP32    │
                  │             │
                  │ Sensor      │
                  │ Processing   │
                  │ Decision     │
                  │ PWM          │
                  │ Energy Calc. │
                  └──────┬──────┘
                         │
                         ▼
                  ┌─────────────┐
                  │ Driver      │
                  │ Circuit     │
                  └──────┬──────┘
                         │
                         ▼
                  ┌─────────────┐
                  │ LED / Strip │
                  └─────────────┘

                         │
                         │ Wi-Fi
                         ▼

                  ┌─────────────┐
                  │ IoT         │
                  │ Dashboard   │
                  ├─────────────┤
                  │ Live Data   │
                  │ History     │
                  │ Energy      │
                  │ Savings     │
                  │ Status      │
                  └─────────────┘
```

---

# 43. FINAL END-TO-END PROCESS

Once everything is completed, the system operates as follows:

```text
1. ESP32 starts
        ↓
2. PIR and LDR initialize
        ↓
3. ESP32 checks Wi-Fi
        ↓
4. Sensors continuously provide readings
        ↓
5. ESP32 checks human presence
        ↓
6. If nobody is present
        ↓
   Light OFF
        ↓
7. If person is present
        ↓
8. Read ambient light
        ↓
9. Determine required brightness
        ↓
10. Apply PWM
        ↓
11. Update energy estimate
        ↓
12. Send data to dashboard
        ↓
13. Store/display historical information
        ↓
14. Check system status
        ↓
15. Repeat
```

---

# 44. DEFINITION OF A SUCCESSFUL FINAL PROJECT

The project will be considered successfully completed when all of the following are demonstrated:

### Hardware

* ESP32 operates reliably.
* PIR detects movement.
* LDR provides useful ambient-light measurements.
* LED/LED strip can be safely controlled.
* PWM brightness works.

### Automation

* No person → light OFF.
* Person + dark → light ON.
* Person + moderate light → reduced brightness.
* Person + bright environment → OFF/minimum.
* Adaptive brightness operates reliably.

### IoT

* ESP32 connects to Wi-Fi.
* Dashboard receives live information.
* Historical data is displayed.
* Dashboard provides energy information.

### Energy

* Energy consumption is estimated using actual LED specifications and operating conditions.
* Estimated savings are calculated.
* If an energy sensor is later installed, measured values are compared with estimates.

### Reliability

* Local lighting continues during Wi-Fi failure.
* ESP32 can recover from restart.
* Sensor behavior is tested.
* Basic abnormal conditions are reported.

### Documentation

* Circuit documented.
* Architecture documented.
* Algorithm documented.
* Test cases documented.
* Results documented.
* Energy analysis documented.
* Limitations documented.
* Future scope documented.

---

# 45. MOST IMPORTANT RULE FOR THE TEAM

**Do not rush to the final dashboard.**

A working dashboard cannot compensate for unreliable hardware.

The correct development philosophy is:

> **Make one small part work → test it → document it → integrate it → test again.**

The project should therefore be built progressively:

**ESP32 → LED → PWM → PIR → LDR → smart logic → LED strip → energy estimation → Wi-Fi → dashboard → data analysis → fault detection → final integration → testing.**

This ensures that even if an advanced feature takes longer than expected, the team will still have a functioning core project rather than an unfinished collection of disconnected features.

---

# 46. FINAL IMPLEMENTATION CHECKLIST

## Hardware

* [ ] ESP32 tested
* [ ] Breadboard prepared
* [ ] LED tested
* [ ] PWM tested
* [ ] PIR tested
* [ ] LDR tested
* [ ] LDR calibrated
* [ ] LED-strip specifications confirmed
* [ ] Driver circuit selected
* [ ] LED strip tested
* [ ] Final wiring completed
* [ ] Physical model completed

## Firmware

* [ ] Basic ESP32 program
* [ ] LED ON/OFF
* [ ] PWM
* [ ] PIR reading
* [ ] LDR reading
* [ ] Smart decision logic
* [ ] Adaptive brightness
* [ ] Energy estimation
* [ ] Wi-Fi
* [ ] Data transmission
* [ ] Fault/status logic
* [ ] Reconnection behavior

## Dashboard

* [ ] Live PIR
* [ ] Live LDR
* [ ] Brightness
* [ ] Light status
* [ ] Energy
* [ ] Estimated savings
* [ ] Historical graphs
* [ ] System status

## Testing

* [ ] No-person test
* [ ] Dark-environment test
* [ ] Moderate-light test
* [ ] Bright-environment test
* [ ] Person-leaves test
* [ ] Wi-Fi failure test
* [ ] Wi-Fi recovery test
* [ ] ESP32 restart test
* [ ] Sensor abnormality test
* [ ] Full-system test

## Documentation

* [ ] Problem statement
* [ ] Objectives
* [ ] Component list
* [ ] Circuit diagram
* [ ] Architecture diagram
* [ ] Algorithm
* [ ] Implementation
* [ ] Dashboard screenshots
* [ ] Test results
* [ ] Energy analysis
* [ ] Limitations
* [ ] Future scope
* [ ] Conclusion
* [ ] References

---

# 47. Final Note

The implementation should remain within the project's intended scope:

**One-zone smart lighting + ESP32 + PIR + LDR + adaptive PWM + IoT dashboard + energy analysis.**

The actual energy sensor is an optional later enhancement and should not delay the core project.

No 230 V AC hardware is required for the prototype.

The system should prioritize **safe low-voltage construction, reliable operation, measurable results, and clear documentation** over adding unnecessary features.
