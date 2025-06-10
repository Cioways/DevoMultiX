# Contributing to DevoMultiX

Thank you for your interest in contributing to DevoMultiX.

This project is still under active development. Contributions of all kinds are welcome: firmware improvements, PCB layout feedback, hardware design, documentation, issue reports, and ideas for new features or tools.

---

## About the Project

DevoMultiX is an open-source, modular multitool for hardware reverse engineering, protocol analysis, and embedded development.  
It combines an ESP32 and an RP2040 on a single board and provides support for:

- UART, RS232, RS485 communication
- IR signal reception and transmission
- Logic analysis (sigrok-compatible)
- Wi-Fi and Bluetooth tools
- USB HID emulation
- 433/868 MHz RF communication
- SD card storage for scripts and logs
- Planned: CAN bus, RFID/NFC, ESP32-S3 with native USB and external antenna

---

## Ways to Contribute

You can contribute in multiple ways:

- Submitting bug reports or feature requests
- Writing or improving firmware (ESP32 or RP2040)
- Prototyping new menu items or tool modules
- Testing hardware features and reporting results
- Extending or optimizing the PCB layout (currently using EasyEDA with OpenGL3)
- Adding usage examples or technical documentation
- Reviewing code or schematics

---

## Development Setup

1. Fork the repository
2. Create a new branch:  
   `git checkout -b feature/your-feature`
3. Make your changes
4. Commit with a clear message  
   `git commit -m "Add new RS485 tool"`
5. Push your branch and open a Pull Request

Please keep changes modular and documented where necessary. If unsure, open a discussion or issue before starting.

---

## Project Structure

/firmware/esp32 -> Firmware for the ESP32 (Arduino/PlatformIO) ### soon
/firmware/rp2040 -> RP2040 code (Pico SDK or Arduino) ### soon
/hardware/ -> EasyEDA project files (schematic, PCB)
/docs/ -> Technical documentation, diagrams
/scripts/ -> Example scripts or tools


---

## Code and Design Guidelines

- Use English for code, comments, UI strings, and documentation
- Keep code readable and functions well-separated
- Document any new menu entries, hardware components, or interfaces
- Avoid hardcoding hardware pins or device-specific logic where possible

For EasyEDA:
- Maintain consistent footprint and layer naming
- Include a short changelog or design notes in Pull Requests if working on hardware

---

## License

DevoMultiX is licensed under the MIT License.  
By contributing, you agree that your work may be distributed under this license.

---

## Contact and Help

If you are unsure where to start or would like to coordinate on a specific topic, feel free to open an issue or contact the repository owner.

Thanks again for your interest in helping build DevoMultiX.
