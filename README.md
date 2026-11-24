# 🚗 AutoCAN – Smart EV Health Monitoring and Battery Management System

## 📌 Project Overview

AutoCAN is a CAN-based Smart Electric Vehicle (EV) Health Monitoring and Battery Management System developed using the **ARM7 LPC2129 microcontroller**.

The project uses a three-node ECU architecture to monitor battery voltage, current and temperature. It implements SPI communication for interfacing the MCP3204 external ADC with the LPC2129 and CAN communication for data exchange between multiple ECUs.

The system continuously monitors important vehicle parameters and displays real-time information on a 20×4 alphanumeric LCD dashboard.

It also incorporates temperature-based cooling control and battery-level warning mechanisms using a cooling fan, buzzer and separate LED indicators.

## 🎯 Project Objectives

- Monitor battery voltage and current.
- Measure temperature using the LM35 sensor.
- Interface MCP3204 ADC with LPC2129 using SPI.
- Implement CAN communication between three ECU nodes.
- Calculate and display battery power and charge percentage.
- Display real-time vehicle parameters on a 20×4 LCD.
- Implement automatic cooling fan control.
- Provide temperature and low-battery warning indications.

## ⚙️ Hardware Components

LPC2129 (ARM7): Main microcontroller for ECU nodes.

MCP3204 ADC: Analog-to-digital conversion.

Voltage Sensor: Battery voltage measurement.

Current Sensor: Battery current measurement.

LM35: Temperature measurement.

L293D Motor Driver: DC motor control.

20×4 Alphanumeric LCD: Dashboard display.

CAN Transceiver: Communication between ECUs.

Cooling Fan: Temperature management.

Buzzer: Audio warning indication.

LEDs: Separate battery and temperature warning indications.

DC Motor: Motor control demonstration.

## 🏗️ System Architecture – Three ECU Nodes

### 🔹 ECU 1 – Node 1 (Battery Monitoring Unit)

**Function: Battery Voltage and Current Monitoring**

- Reads battery voltage through the voltage sensor.
- Measures battery current through the current sensor.
- Uses MCP3204 external ADC for analog-to-digital conversion.
- Interfaces MCP3204 with LPC2129 using SPI communication.
- Processes the acquired voltage and current values.
- Transmits battery monitoring data to ECU 2 through CAN communication.

### 🔹 ECU 2 – Node 2 (Dashboard and Control Unit)

**Function: Data Reception, Dashboard Display and Safety Control**

- Receives battery voltage and current information from ECU 1 through CAN.
- Receives temperature information from ECU 3 through CAN.
- Calculates battery power and charge percentage.
- Displays all monitored parameters on a 20×4 alphanumeric LCD.
- Controls the cooling fan based on temperature.
- Controls the buzzer and separate LED indicators based on safety conditions.

**Dashboard Parameters:**

1. Battery Voltage (V)
2. Battery Current (A)
3. Battery Power (W)
4. Temperature (°C)
5. Temperature Status (NORMAL / HIGH)
6. Cooling Fan Status (ON / OFF)
7. Battery Charge Percentage (%)
8. Low Battery Warning

**Safety Conditions Implemented:**

**1. High Temperature Warning**

- Temperature below 30°C: Displays NORMAL.
- Temperature above 30°C: Displays HIGH.
- When temperature exceeds 30°C, the cooling fan turns ON.
- The buzzer activates to provide an audible warning.
- The separate temperature warning LED blinks.

**2. Low Battery Warning**

- Battery charge percentage at or below 30% activates the low-battery warning.
- Displays LOW BATTERY on the dashboard.
- Activates the buzzer.
- Turns ON the separate battery warning LED.

### 🔹 ECU 3 – Node 3 (Temperature Monitoring Unit)

**Function: Temperature Measurement and CAN Transmission**

- Reads temperature from the LM35 sensor.
- Uses MCP3204 ADC to convert the analog temperature signal into digital data.
- Interfaces MCP3204 with LPC2129 using SPI communication.
- Processes the temperature measurement.
- Transmits temperature information to ECU 2 through CAN communication.

## 📡 Communication Protocols

### 1. SPI – Serial Peripheral Interface

SPI communication is implemented between LPC2129 and MCP3204.

- MCP3204 acts as an SPI slave device.
- LPC2129 acts as the SPI master.
- Analog sensor signals are converted into digital values.
- Node 1 uses MCP3204 for voltage and current measurements.
- Node 3 uses MCP3204 for LM35 temperature measurement.

### 2. CAN – Controller Area Network

CAN communication is implemented for data exchange between three ECU nodes.

ECU 1: Transmits battery voltage and current data.

ECU 2: Receives battery and temperature data and performs dashboard and control operations.

ECU 3: Transmits temperature data.

## 🔄 System Working Principle

1. ECU 1 acquires battery voltage and current sensor outputs.
2. MCP3204 converts the analog signals into digital values through SPI communication.
3. ECU 1 processes the readings and transmits voltage and current data to ECU 2 through CAN.
4. ECU 3 acquires the analog temperature signal from the LM35 sensor.
5. MCP3204 converts the temperature signal into a digital value through SPI communication.
6. ECU 3 transmits temperature information to ECU 2 through CAN.
7. ECU 2 receives the sensor information from both nodes.
8. ECU 2 calculates battery power and charge percentage.
9. The 20×4 LCD displays voltage, current, power, temperature, temperature status fan status and battery percentage.
10. ECU 2 controls the cooling fan, buzzer and separate LED indicators according to the configured safety thresholds.

## 🚨 Safety Monitoring Logic

**TEMPERATURE WARNING:**

Temperature below 30°C: NORMAL.

Temperature above 30°C: HIGH.

Cooling fan activated.

Buzzer activated.

Temperature LED blinks.

**LOW BATTERY WARNING:**

Battery percentage at or below 30%.

LOW BATTERY message displayed.

Buzzer activated.

Battery warning LED turned ON.

*Temperature and battery warning indications use separate LEDs.*

## 🧠 Technologies Used

- Embedded C Programming
- ARM7 LPC2129 Microcontroller
- SPI Protocol
- CAN Protocol
- MCP3204 ADC Interfacing
- LM35 Temperature Sensor Interfacing
- Voltage and Current Sensor Interfacing
- ADC Configuration
- 20×4 LCD Interfacing
- GPIO Interfacing
- DC Motor Control
- Multi-ECU Communication

## 🛠️ Development Tools

- **Keil µVision:** Embedded C programming.
- **Flash Magic:** Microcontroller programming.
- **Proteus:** Circuit simulation.

## 📚 Key Learning Outcomes

- Interfacing MCP3204 external ADC with LPC2129 using SPI.
- Understanding SPI master-slave communication.
- Implementing CAN communication between multiple ECU nodes.
- Developing a three-node automotive embedded architecture.
- Acquiring and processing voltage, current and temperature data.
- Calculating battery power and charge percentage.
- Implementing threshold-based safety monitoring.
- Controlling cooling fans, buzzers and LED indicators.
- Integrating multiple hardware peripherals using Embedded C.

## 🚀 Project Outcome

The AutoCAN project demonstrates a three-node CAN-based EV health monitoring and battery management architecture.

It integrates SPI-based ADC interfacing, CAN communication, voltage and current monitoring, temperature measurement, dashboard display and automatic safety control.

The project provides practical experience in automotive embedded systems, ARM7 microcontroller programming, communication protocols, sensor integration and multi-ECU hardware development.

---

## 📋 Project Information

Project: AutoCAN – Smart EV Health Monitoring and Battery Management System

Microcontroller: LPC2129 (ARM7)

Programming Language: Embedded C

External ADC: MCP3204

Sensors: Voltage, Current and LM35

SPI Protocol: ADC Interfacing

CAN Protocol: ECU Communication

ECU Architecture: Three Nodes

Display: 20×4 Alphanumeric LCD

Motor Driver: L293D

Application: EV Monitoring and Battery Management

---

**Author: Akash S**  
**GitHub:** https://github.com/Akash-1414
