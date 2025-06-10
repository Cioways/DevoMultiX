DevoMultiX
!!!Still in Development!!!

A portable multitool for electronics and network analysis – based on the ESP32, with planned expansion via the RP2040.

What is it?
DevoMultiX is a compact diagnostic and analysis device designed for reverse engineering, signal and voltage measurement, and basic network tools. It’s intended as a universal handheld device for use in the lab or field – ideal for hobbyists, developers, and technicians.

Currently Implemented Features (ESP32-based)
Wi-Fi Scanning
Discover network devices, perform ARP scans, and analyze MAC addresses.
1.77" SPI display (AZDelivery) with navigation through 6 hardware buttons.
RS232 & RS485 Support
Communication via MAX3232 (RS232) and MAX3485 (RS485).
IR Communication
Read IR signals (TSOP4838) and transmit them – e.g., for TV codes or remote control analysis.

Planned Features
These functions are currently in development or scheduled for future revisions:

Hardware:

Battery with Charging Management
Standalone operation without constant USB power.


Sub-1 GHz RF Module (400–800 MHz)
For ASK/OOK signal analysis (e.g., garage doors, wireless switches, etc.).

RP2040 Extension
To be used as a coprocessor for precise timing and protocol handling.
Software/Firmware (RP2040):

Logic Analyzer / Sampling Mode
Support for sigrok/PulseView-compatible logic analysis.
PIO-Based Protocol Handling
I²C, SPI, 1-Wire,
Bitbanging & protocol sniffing.
Custom Signal Generation & Analysis
For reverse engineering proprietary protocols.
USB HID Simulation (Rubber Ducky Style)
Simulate keyboard input via USB, for automated keystroke injection.
SWD / JTAG Interface (planned)
For debugging and firmware analysis.

Target Audience:

Hardware hackers
Reverse engineers
Embedded developers
Network/security technicians
Makers & DIY enthusiasts
System Overview


ESP32-WROOM-32E with 8 MB Flash
RP2040 (Pi Pico or Connect variant) – planned
1.77" SPI display
RS232 via MAX3232
RS485 via MAX3485
TSOP4838 IR receiver + IR LED
6 navigation buttons
Measurement ports , IR, UART, etc.)
Power supply: USB / battery (planned)

Quickstart
Pull requests, issues, and feedback are always welcome! Especially looking for:

PCB design ideas and tips:

Menu system extensions

Code contributions for RP2040/ESP32

Ideas for new measurement features

Case/enclosure suggestions (3D printable)

Contact:
github.com/Cioways/DevoMultiX

📜 Licensing
🖥 Software & Firmware → GNU General Public License v3 (GPLv3)
🔩 Hardware & PCB Designs → CERN Open Hardware License v2
📖 Documentation & Wiki → Creative Commons Attribution-ShareAlike 4.0 (CC BY-SA 4.0)
