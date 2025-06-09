DevoMultiX

Ein tragbares Multitool für Elektronik- und Netzwerkanalyse – basierend auf dem ESP32, mit geplanter Erweiterung durch den RP2040.

Was ist das?

DevoMultiX ist ein kompaktes Diagnose- und Analysegerät, entwickelt für Reverse Engineering, Signal- und Spannungsmessung sowie grundlegende Netzwerktools. Es soll als universelles Handheld-Gerät in Labor oder Feld dienen – für Bastler, Entwickler und Techniker.

Aktuell implementierte Funktionen (ESP32-basiert)

WLAN- und Ethernet-Scan
Netzwerkgeräte aufspüren, ARP-Scan, MAC-Analyse.
Netzwerk-Tools
Ping, Traceroute, IP-Eingabe über Tastenmenü.
Touchscreen-Menü
1.77" SPI-Display (AZDelivery), Navigation mit 6 Hardwaretasten.
RS232 & RS485-Support
Kommunikation via MAX3232 (RS232) und MAX3485 (RS485).
IR-Kommunikation
IR-Signale lesen (TSOP4838) & senden – z. B. für TV-Codes oder Analyse von Fernbedienungen.
Spannungsmessung
DC-Messung bis 48 V geplant – aktuell einfache Durchgangsprüfung vorhanden.
Geplante Features

Diese Funktionen sind in Arbeit oder für die nächsten Revisionen vorgesehen:

Hardware:
Akku mit Lademanagement
Autarker Betrieb ohne permanente USB-Stromversorgung.
Sub-1 GHz Funkmodul (400–800 MHz)
Für z. B. ASK/OOK-Signale (Garagentor, Funktaster etc.).
RP2040-Erweiterung
Wird als Coprozessor für präzises Timing & Protokollhandling eingebunden.
Software/Firmware (RP2040):
Logikanalyse / Sampling-Modus
Unterstützung für sigrok/PulseView-kompatible Logik-Analyse.
PIO-basierte Protokolle
I²C, SPI, 1‑Wire, WS2812, Manchester usw.
Bitbanging & Protokoll-Sniffing
Generierung und Analyse proprietärer Signale, z. B. für Reverse Engineering.
USB HID Simulation (Rubber Ducky Style)
Tastatureingaben über USB simulieren, automatisierte Eingaben.
SWD / JTAG-Schnittstelle (geplant)
Für Debugging und Firmware-Analyse.
Zielgruppen

Hardware-Hacker
Reverse Engineers
Embedded-Entwickler
Netzwerk-/Security-Techniker
Makers & Bastler
Aufbau

ESP32-WROOM-32E mit 8 MB Flash
RP2040 (Pi Pico oder Connect-Variante) – geplant
SPI-Display (1.77")
RS232 über MAX3232
RS485 über MAX3485
TSOP4838 IR-Empfänger + IR-LED
6 Navigationstasten
Messanschlüsse (DC, IR, UART, etc.)
Spannungsversorgung: USB / Akku (geplant)
Quickstart

⚠️ In Entwicklung – kein fertiges Produkt!
ESP32 flashen mit main.ino (Arduino IDE empfohlen)
Menüstruktur per Tasten testen
Netzwerk-Tools ausprobieren
Seriellen Monitor zur Debug-Ausgabe verwenden
Mitmachen

Pull Requests, Issues und Feedback jederzeit willkommen. Besonders gesucht:

Erweiterungen für das Menüsystem
PIO-Code für den RP2040
Ideen für neue Messfunktionen
Gehäuse-Vorschläge (3D-Druck)
Lizenz

MIT License – Open Source, gerne weiterentwickeln.

Kontakt:
github.com/Cioways

📜 Lizenzierung

🖥 Software & Firmware → [GNU General Public License v3 (GPLv3)](LICENSE) 
 
🔩 Hardware & PCB-Designs → [CERN Open Hardware License v2](LICENSE-HARDWARE)  

📖 Dokumentation & Wiki → [Creative Commons Attribution-ShareAlike 4.0 (CC BY-SA 4.0)](LICENSE-DOCS)  


