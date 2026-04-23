# 💻 Software & Firmware Architecture

The DevoMultiX architecture utilizes a tiered software stack based on a **Master-Slave principle**. The **Raspberry Pi Zero 2 W** acts as the system's "Brain" and User Interface host, while the **ESP32** serves as a specialized "Hardware Engine" for real-time tasks.

!!! info "Work in Progress"
    This section is currently under construction. We are finalizing the Python-based UI framework for the Pi and the UART command set for the ESP32.

## 🧠 Core Logic & Responsibility Split

The system is designed to separate high-level application logic from low-level hardware timing. This ensures that the user interface remains fluid while no critical data packets from industrial buses or RF modules are lost.

### 1. ESP32: The Hardware Specialist (I/O Layer)
The ESP32 manages all tasks that require precise timing or direct interaction with integrated circuits (ICs).

* **IC Control**: The ESP32 communicates directly with specialized peripherals via SPI and UART. It manages the **CC1101** (RF), the **MCP2515** (CAN-Bus), and the transceivers for **RS485/RS232**.
* **Real-Time Data Acquisition**: It reads sensor data and protocol frames (e.g., CAN messages or IR signals) with microsecond precision.
* **Pre-Processing**: Raw signals are filtered and converted into simple data packets to prevent overloading the serial bridge.
* **Data Transmission**: Once measurements or events are captured, the ESP32 proactively pushes this data to the Raspberry Pi via the UART bridge.



### 2. Raspberry Pi Zero 2W: The Brain (Application Layer)
Running **Raspberry Pi OS Lite** (or Minimal Debian), the Pi handles the coordinative logic and all user-facing features.

* **System Orchestration**: The Pi controls the ESP32 by sending high-level commands (e.g., "Start scanning at 433 MHz" or "Send CAN frame ID 0x123").
* **User Interface (GUI)**: Since the **ST7735 Display** and the **6 Navigation Buttons** (Up, Down, Left, Right, Enter, Back) are wired directly to the Pi's GPIOs, the Pi is solely responsible for rendering menus and status screens.
* **Data Analysis & Processing**: The Pi receives raw values from the ESP32, performs complex calculations, compares them with local databases, and logs them to the SD card.
* **Advanced Tooling**: This layer runs "heavy" security applications such as `nmap`, Webservers for remote access, or Python-based protocol analyzers.



---

## 🔄 Data Flow Summary

To understand how DevoMultiX operates, follow the path of a single signal:

1.  **Input**: A physical signal hits an IC (e.g., a radio wave captured by the **CC1101**).
2.  **Handling**: The **ESP32** detects the interrupt, reads the data from the IC, and packages it.
3.  **Transport**: The data is streamed via **UART** (`ESP_TX0` / `ESP_RX0`) to the Raspberry Pi.
4.  **Processing**: The **Pi** processes the data (calculates statistics, checks for known patterns).
5.  **Output**: The **Pi** updates the **TFT Display** to show the results to the user in real-time.

---

## 🛠️ Development Environment

* **ESP32 Firmware**: Written in **C/C++** using **PlatformIO** or **Arduino Core** for low-level performance.
* **Raspberry Pi Software**: Primarily written in **Python** and **Bash**, leveraging the vast library ecosystem of Debian/Raspberry Pi OS.

---
*Help us expand this section! Read our [Contributing Guide](contributing.md).*