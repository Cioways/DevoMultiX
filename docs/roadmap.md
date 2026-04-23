Hier ist die aktualisierte Roadmap für dein MkDocs, die nun die spezifischen Hardware-Komponenten deines Schaltplans und die neue Software-Architektur (RPI als UI-Master, ESP32 als IC-Slave) einbezieht.

---

# 🗺️ Roadmap & Current Status

Welcome to the DevoMultiX roadmap! This document tracks our progress from the initial PCB design to a fully functional multi-tool ecosystem.

## Current Status (April 2026)

- **Hardware**: The main PCB layout (Rev 1.0) is finalized. Key components like the **MCP2515**, **CC1101**, and **ST7735 Display** have been integrated into the design.
- **Software**: We are currently establishing the **UART bridge** between the Raspberry Pi (Master) and the ESP32 (Slave) to allow bidirectional data flow for measurements and commands.



## Upcoming Milestones

### Phase 1: Core Foundation (In Progress)
- [x] Hardware architecture and component selection (ESP32 + RPI Zero 2 W).
- [x] PCB schematic design including **RS232/485**, **CAN-Bus**, and **RF** stages.
- [ ] **UI Bootstrapping**: Setting up the **ST7735 SPI Display** and the 6-button navigation directly on the Raspberry Pi.
- [ ] **The Bridge**: Developing the C++/Python UART protocol to allow the Pi to control the ESP32’s GPIOs and ICs.

### Phase 2: IC & Protocol Integration
- [ ] **Industrial Suite**: Implementation of the **MAX3485** (RS485) and **MCP2515** (CAN) drivers on the ESP32 with data streaming to the Pi's GUI.
- [ ] **Wireless Foundation**: Enabling Sub-GHz sniffing via the **CC1101** module.
- [ ] **Power Management**: Finalizing the stability of the **3.3V rail** (TPAP2112K) during high-load RF transmissions.

### Phase 3: Software Ecosystem & Security Tools
- [ ] **Linux Integration**: Automation scripts for `nmap`, `airodump-ng`, and custom Python-based signal analyzers on Debian.
- [ ] **Signal Visualizer**: Developing an "Oscilloscope-lite" mode on the Pi to visualize raw data received from the ESP32's analog pins.
- [ ] **IR Database**: Support for reading and replaying IR codes via the **TSOP4838** subsystem.

### Phase 4: Expansion & Community
- [ ] **800MHz Support**: Tuning the RF stage for European Smart Home frequencies.
- [ ] **Community Repository**: Launching a plugin system for user-contributed Python scripts and ESP32 protocol handlers.
- [ ] **Battery Optimization**: Implementing deep-sleep modes and battery monitoring for portable field use ("Akku-Betrieb").

---

## Technical Debt & Known Challenges
* **Heat Dissipation**: Monitoring the Pi Zero 2 W thermals behind the TFT display.
* **UART Latency**: Optimizing the baud rate for real-time CAN-Bus visualization without dropping frames.

---
*Help us expand this section! Read our [Contributing Guide](contributing.md).*