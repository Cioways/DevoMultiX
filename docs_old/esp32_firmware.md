# ⚙️ ESP32 Firmware / Script

[cite_start]The ESP32 acts as the real-time co-processor for the DevoMultiX, controlled by the Raspberry Pi Zero 2W[cite: 78, 81]. [cite_start]It handles time-critical tasks that require precise hardware timing, which are often difficult to manage under a standard Linux OS[cite: 78].

!!! info "Work in Progress"
    This section is currently being written while the software development phase begins.

## Architecture

The ESP32 firmware is written in C++ (Arduino Core / PlatformIO). [cite_start]According to the schematics, the ESP32 serves as the central bridge between the Raspberry Pi host and various specialized communication protocols[cite: 78, 81, 83].

### Hardware Interaction & Pin Mapping

Based on the circuit design, the ESP32 is responsible for the following subsystems:

* **Host Communication (RPI Zero 2W)**:
    * [cite_start]The ESP32 communicates with the Pi via UART[cite: 34, 39, 121, 123].
    * [cite_start]**Pins**: `ESP_TX0` (Pin 9 on X5) and `ESP_RX0` (Pin 10 on X5)[cite: 34, 39].
* **Sub-GHz RF (CC1101)**:
    * [cite_start]The **CC1101 433MHz** module (U3) is controlled via the SPI bus[cite: 153, 154].
    * [cite_start]**Pins**: `SCK` (GPIO18), `MISO` (GPIO19), `MOSI` (GPIO23), and `CSN` (GPIO7)[cite: 157, 158, 159].
* **Industrial Interfaces (CAN & RS485)**:
    * [cite_start]**CAN-Bus**: Managed via the **MCP2515** controller (U11) and the **SN65HVD230** transceiver (U4)[cite: 229, 234, 239, 280].
    * [cite_start]**RS485**: Handled by the **MAX3485** (U2) for half-duplex differential signaling[cite: 222, 227].
* **Infrared (IR) Subsystem**:
    * [cite_start]Real-time decoding of IR signals via the **TSOP4838** receiver (U10) and signal transmission[cite: 310].
    * [cite_start]**Pins**: `IR Signal reading` (GPIO26) and `IR Signal sending` (GPIO27)[cite: 316, 323].
* **User Interface**:
    * [cite_start]**Display**: Drives a **1.77" TFT Display** (U10) with an ST7735 controller via SPI[cite: 118, 151].
    * [cite_start]**Navigation**: Monitors six tactile buttons (Up, Down, Enter, Left, Right, Back) for local menu interaction[cite: 96, 98, 100, 113, 114, 116].



## Power Management

[cite_start]The ESP32 operates on a **3.3V** rail[cite: 59, 190]. [cite_start]This voltage is stepped down from the **5V USB input** using a **TPAP2112K-3.3TRG1** (U5) linear regulator[cite: 184, 185, 186, 196]. 
* [cite_start]**Filtering**: High-frequency noise is suppressed by a 10uF capacitor (C15) at the input and a large 470uF reservoir capacitor (C14) at the output to handle current spikes during RF transmission[cite: 183, 191, 192].

## File Structure

*(TODO: Document the structure of `main.cpp` and specific handler files for CC1101, CAN, and RS485 once the architecture is finalized).*

## Flashing the ESP32

To update the firmware:

1.  [cite_start]**Connection**: Connect the DevoMultiX via the onboard USB port[cite: 181].
2.  [cite_start]**Power**: Ensure the power switch (SW7) is set correctly to provide the 5V bus voltage[cite: 66, 75, 76].
3.  [cite_start]**Boot Mode**: The `EN` pin (Pin 1 on X4) is used to reset the chip into flash mode if the auto-reset circuit is not triggered[cite: 4].
4.  **Tools**: Use **PlatformIO** (recommended) or the Arduino IDE. Select the `esp32dev` board profile.

---
