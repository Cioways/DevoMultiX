# ⚙️ Getting Started & Installation

Welcome to DevoMultiX! This page guides you through the initial hardware setup and software deployment for your multi-tool.

!!! info "Work in Progress"
    This section is currently under construction. Future updates will include a detailed bill of materials (BOM) and assembly instructions.

## 1. Prepare Hardware

[cite_start]The DevoMultiX is built on a custom PCB (Rev 1.0) designed to host both an ESP32 and a Raspberry Pi Zero 2 W[cite: 78, 81, 160].

* [cite_start]**Assembly**: Solder the X4 and X5 headers to mount your ESP32 module[cite: 2, 3, 78].
* [cite_start]**Power Connection**: The device is powered via the USB Powering port[cite: 181]. [cite_start]Ensure the **LESD5D5** ESD protection diode (U18) is properly seated to protect your logic from voltage spikes[cite: 176, 177, 182].
* [cite_start]**Module Check**: Verify that the **CC1101** (U3) and **MCP2515** (U11) are correctly aligned with the SPI bus pins to ensure wireless and CAN-Bus functionality[cite: 153, 154, 234, 280].

## 2. Flash ESP32

The ESP32 acts as the real-time co-processor. [cite_start]It must be flashed with the DevoMultiX firmware to handle industrial protocols like RS485 and CAN-Bus[cite: 227, 239, 293, 324].

**Flashing Steps**:
1. [cite_start]Connect the ESP32 to your PC via the USB interface[cite: 181].
2. [cite_start]Set the power switch (**SW7**) to the correct position to energize the **3.3V** rail via the **TPAP2112K** regulator[cite: 76, 186, 190].
3. Use `esptool.py` or the PlatformIO IDE to upload the firmware.

```bash
# Example command for esptool.py
esptool.py --chip esp32 --port /dev/ttyUSB0 --baud 921600 write_flash -z 0x1000 firmware.bin
```

## 3. Prepare SD Card for Pi Zero 2 W

[cite_start]The Raspberry Pi Zero 2 W serves as the main host and interface controller[cite: 81].

* **OS Selection**: Use a standard Debian-based image (Raspberry Pi OS Lite is recommended).
* **Interface Configuration**: Enable SPI and UART in `raspi-config`. [cite_start]The Pi communicates with the ESP32 using the `ESP_TX0` and `ESP_RX0` lines[cite: 121, 123].
* [cite_start]**Display Setup**: Install the drivers for the **ST7735** controller to enable the **1.77" TFT Display** (U10)[cite: 118, 151].
* [cite_start]**Dependencies**: Install `python3`, `spidev`, and `pyserial` to allow the Pi to coordinate with the hardware modules[cite: 150, 330].

---
*Help us expand this section! Read our [Contributing Guide](contributing.md).*