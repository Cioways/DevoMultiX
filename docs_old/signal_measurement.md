# ⚡ Signal Analysis

[cite_start]The **DevoMultiX** is equipped with a robust front-end for capturing and interpreting physical layer signals across various domains, from industrial wired buses to modern wireless smart home protocols[cite: 1, 151, 154]. [cite_start]By utilizing the **ESP32** as a high-speed sampler and the **Raspberry Pi Zero 2W** for data visualization, the device functions as a portable signal laboratory[cite: 78, 81].

!!! info "Work in Progress"
    This section is currently under construction as we refine the signal processing libraries for the CC1101 and industrial transceivers.

## Hardware Signal Path

The device architecture allows for direct interaction with multiple signal types:

### 🔬 Wired Signal Decoding
* [cite_start]**Logic Level Analysis**: The system primarily operates at **3.3V** logic, regulated by the **TPAP2112K-3.3TRG1**[cite: 59, 186, 196]. [cite_start]It includes level-shifting capabilities to safely interface with **5V** systems via the USB power rail[cite: 75, 85].
* [cite_start]**Industrial Bus Sniffing**: Integrated transceivers like the **SN65HVD230** for CAN-Bus and **MAX3485** for RS-485 allow for real-time frame decoding and collision analysis[cite: 227, 239, 320, 324].
* [cite_start]**Oscilloscope Features**: Upcoming firmware updates aim to utilize the ESP32’s internal ADCs to provide basic waveform visualization on the **1.77" TFT Display**[cite: 118, 151].



### 📡 Wireless & Smart Home Frequencies
* [cite_start]**Sub-GHz (433MHz / 800MHz)**: While the current module is a **CC1101 433MHz** transceiver, the hardware path is designed to support 800MHz-class frequencies commonly used in European smart home systems[cite: 154].
* **Zigbee & 2.4GHz**: Future expansions can leverage the ESP32’s native radio for Zigbee/Thread analysis or secondary 2.4GHz monitoring.
* [cite_start]**Infrared**: The **TSOP4838** captures modulated IR signals, which are then processed by the ESP32 to identify consumer electronics protocols[cite: 310, 323].

## 🔋 Power & Portability
* **Battery Operation**: The DevoMultiX is designed for field use via battery. [cite_start]The **USB Powering** circuit (USB1) allows for operation via portable power banks or integrated LiPo management modules[cite: 176, 181].
* [cite_start]**Voltage Regulation**: A dedicated **5V to 3.3V** regulation stage ensures that signal integrity is maintained even as battery voltage fluctuates[cite: 196].

## Planned Content

* **Logic Level Comparison**: Implementation of 3.3V vs 5V safety checks.
* [cite_start]**Protocol Decoding**: Advanced libraries for automated CAN-Bus and RS-485 frame identification[cite: 293, 324].
* **Smart Home Auditing**: Specific guides for sniffing 800MHz and Zigbee traffic in home automation environments.

---
*Help us expand this section! Read our [Contributing Guide](contributing.md).*