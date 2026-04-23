# 🧰 Hardware Overview

[cite_start]The **DevoMultiX** (Rev 1.0) is a versatile multi-tool designed by **DevoMultiX** that merges the high-level processing power of a Single Board Computer with the low-latency control of a microcontroller[cite: 160, 161].

!!! info "Work in Progress"
    This section is currently under construction as we finalize the hardware documentation.

## Architecture

[cite_start]The system utilizes a dual-core approach to separate high-level logic from real-time hardware interaction[cite: 78, 81]:

1.  [cite_start]**Microcontroller (ESP32)**: Handled by an **ESP32** module (X4/X5 headers), acting as a real-time co-processor[cite: 2, 3, 78]. [cite_start]It manages time-critical signals and interfaces directly with specialized RF and industrial modules[cite: 154, 227, 239, 280].
2.  [cite_start]**Main Host (Raspberry Pi Zero 2 W)**: A **Raspberry Pi Zero 2 W** acts as the primary controller, running a full Debian-based environment[cite: 81, 83]. [cite_start]It orchestrates the system, manages high-level scripts, and communicates with the ESP32 via a dedicated UART link (**ESP_TX0 / ESP_RX0**)[cite: 34, 39, 121, 123].

## Features & Modules

The DevoMultiX is equipped with an extensive array of communication and interface modules:

### 🖥️ User Interface
* [cite_start]**1.77" SPI Display**: An **ST7735-controlled** TFT display (128x160 resolution) connected via SPI[cite: 118, 151].
* [cite_start]**Navigation Buttons**: Six tactile switches (SW2, SW3, SW4, SW5, SW6, SW8) provide **Up, Down, Left, Right, Enter,** and **Back** functionality[cite: 87, 89, 90, 100, 104, 105, 106, 113, 114, 116].

### 📡 Wireless & Signal Processing
* [cite_start]**Sub-GHz RF**: Features a **CC1101 433MHz** transceiver (U3) for radio frequency interactions[cite: 153, 154].
* [cite_start]**Infrared (IR)**: Includes a **TSOP4838** IR receiver for signal reading and an IR LED system for signal sending[cite: 310, 323].

### 🏭 Industrial Interfaces
* [cite_start]**CAN-Bus**: Integrated via an **MCP2515** controller (U11) and an **SN65HVD230** transceiver (U4)[cite: 239, 280].
* [cite_start]**RS485**: Powered by a **MAX3485** transceiver for robust industrial serial communication[cite: 227, 324].
* [cite_start]**RS232**: Standard serial communication provided via a **MAX3232** interface (U1)[cite: 231, 303].

### ⚡ Power System
* [cite_start]**Input**: The device is powered via a **USB Powering** circuit (USB1) protected by a **LESD5D5** ESD protection diode (U18)[cite: 176, 177, 181].
* [cite_start]**Regulation**: A **TPAP2112K-3.3TRG1** (U5) voltage regulator steps down the **5V** input to a stable **3.3V** for the logic components[cite: 185, 186, 196].

---
*Help us expand this section! Read our [Contributing Guide](contributing.md).*