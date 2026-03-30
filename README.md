# DevoMultiX – Open-Source Multitool for Hardware & Network Analysis

**!!!Still in Development!!!**

DevoMultiX is a portable multitool for electronics and network analysis, based on the **ESP32**, with planned expansion via the **RP2040**. It is aimed at hobbyists, developers, technicians, and makers who want a compact tool for lab or field use.

---

## 🔍 What is DevoMultiX?

A universal diagnostic and analysis device for:  

- Reverse engineering  
- Signal and voltage measurement  
- Basic network tools  

Designed as an all-in-one handheld tool with support for multiple interfaces and sensors.

---

## ⚡ Currently Implemented Features (ESP32-based)

- **Wi-Fi Scanning**  
  Discover network devices, perform ARP scans, and analyze MAC addresses.  

- **1.77" SPI Display (AZDelivery)**  
  Navigation via 6 hardware buttons  

- **RS232 & RS485**  
  Communication via MAX3232 (RS232) and MAX3485 (RS485)  

- **IR Communication**  
  Receive IR signals (TSOP4838) and transmit – e.g., TV codes or remote control analysis

---

## 🛠 Planned Features

**Hardware:**  
- Battery with charging management (stand-alone operation without constant USB)  
- Sub-1 GHz RF module (400–800 MHz) for ASK/OOK signals (garage doors, wireless switches, etc.)  
- RP2040 extension for precise timing and protocol handling  

**Software/Firmware (RP2040):**  
- Logic Analyzer / Sampling Mode (sigrok / PulseView compatible)  
- PIO-based protocol handling: I²C, SPI, 1-Wire, Bitbanging  
- Custom signal generation & analysis for reverse engineering  
- USB HID simulation (Rubber Ducky style)  
- SWD / JTAG interface (planned)

---

## 🎯 Target Audience

- Hardware hackers & reverse engineers  
- Embedded developers  
- Network/security technicians  
- Makers & DIY enthusiasts

---

## 🖥 System Overview

- **ESP32-WROOM-32E** with 8 MB Flash  
- **RP2040** (Pi Pico or Connect variant, planned)  
- **1.77" SPI Display**  
- **RS232 & RS485** via MAX3232 / MAX3485  
- **IR Receiver TSOP4838 + IR LED**  
- **6 navigation buttons**  
- **Measurement ports** for IR, UART, etc.  
- **Power supply:** USB / Battery (planned)

---

## 🚀 Quickstart & Contributing

Pull requests, issues, and feedback are always welcome! Especially looking for:  

- PCB design tips  
- Menu system extensions  
- Code contributions for ESP32 / RP2040  
- Ideas for new measurement features  
- 3D-printable case suggestions  

**Contact & Repository:**  
[GitHub – DevoMultiX](https://github.com/Cioways/DevoMultiX)

---

## 📜 Licensing

- **Software & Firmware:** [GNU GPLv3](https://github.com/Cioways/DevoMultiX/blob/main/LICENSE)  
- **Hardware & PCB Designs:** [CERN OHL v2](https://github.com/Cioways/DevoMultiX/blob/main/LICENSE-HARDWARE)  
- **Documentation & Wiki:** [CC BY-SA 4.0](https://github.com/Cioways/DevoMultiX/blob/main/LICENSE-DOCS)

---

## 📝 Current “Good First Issues”

- Create GUI mockup for main menu  
- Write LED test script for ESP32  
- Add breadboard photos & PCB screenshots  
- Extend firmware documentation  

*(More issues will follow over time.)*

---

## 📷 Screenshots / Mockups

*(Add images here: breadboard setup, GUI mockups, PCB layout)*

---

## 🔗 Community & Communication

- **Reddit:** r/devomultix
- **Discord:** https://discord.gg/gyrREMtuS6