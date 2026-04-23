# 🌐 Network and Security Analysis

The **DevoMultiX** is designed as a portable powerhouse for IT security professionals. [cite_start]By leveraging the dual-architecture of the **ESP32** (real-time processing) and the **Raspberry Pi Zero 2 W** (full Linux suite), it serves as a versatile platform for deep-packet inspection and radio frequency auditing[cite: 78, 81].

!!! info "Work in Progress"
    This section is currently under development. Software integration for the specialized network modules is ongoing.

## Architecture-Specific Capabilities

The hardware design allows for a tiered approach to security analysis:

### ⚡ ESP32: Real-Time & Physical Layer Analysis
The ESP32 manages high-speed, time-critical tasks that require direct access to the radio hardware:
* [cite_start]**WiFi Auditing**: Capable of beacon frame generation, deauthentication testing, and rapid channel hopping[cite: 78].
* [cite_start]**Sub-GHz Sniffing**: Utilizing the **CC1101 433MHz** module (U3), the ESP32 can capture and replay signals for IoT device testing[cite: 153, 154].
* [cite_start]**Industrial Protocol Analysis**: Directly interfaces with **CAN-Bus** (MCP2515/U11) and **RS485** (MAX3485/U2) to audit automotive or building automation security[cite: 227, 280].

### 🥧 Raspberry Pi Zero 2 W: Heavy Lifting & Higher Layers
[cite_start]The Pi Zero 2 W acts as the central intelligence, running complex security tools on Debian[cite: 81, 83]:
* **Packet Inspection**: Running `nmap` for network mapping or `tcpdump` for traffic analysis.
* **Advanced WiFi Tools**: Utilizing the Pi's internal radio for tools like `airodump-ng` and `reaver`.
* [cite_start]**Coordination**: Receiving processed signal data from the ESP32 via UART (**ESP_TX0 / ESP_RX0**) to visualize results on the **1.77" TFT Display**[cite: 34, 39, 118].



## Planned Content

* **ESP32 Scanning**: Beacon spamming, deauth testing, and ARP scanning implementations.
* **Bluetooth / BLE**: Sniffing BLE beacons and mapping IoT device proximities.
* [cite_start]**Industrial Auditing**: Specific guides on using the **MAX3232** (U1) and **SN65HVD230** (U4) for auditing RS232 and CAN infrastructures[cite: 212, 239].
* **Remote Management**: Setting up a WebUI or remote SSH access to monitor scans in the field.

## ⚖️ Security & Legal Guidelines

The DevoMultiX is a professional tool intended for **Whitehat / Penetration Testing** and educational purposes. 

!!! warning "Legal Disclaimer"
    Ensure you have explicit written permission before testing any network or device you do not own. Unauthorized use of these tools can violate local and international laws (e.g., Computer Fraud and Abuse Act).

---
*Help us expand this section! Read our [Contributing Guide](contributing.md).*