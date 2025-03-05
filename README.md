DevoMultiX 

⚡ Ein vielseitiges Open-Source-Multitool für Entwickler & Hardware-Enthusiasten

---

🚀 Features

✅ ESP32 & RP2040 basiertes Multitool für verschiedene Anwendungen
✅ Erweiterbar durch Community-Skripte für WLAN-Analyse, NFC, etc.
✅ Open Source & modifizierbar
✅ Platine & Gehäuse-Design als Open Hardware verfügbar


---

📜 Lizenzierung

🖥 Software & Firmware → [GNU General Public License v3 (GPLv3)](LICENSE) 
 
🔩 Hardware & PCB-Designs → [CERN Open Hardware License v2](LICENSE-HARDWARE)  

📖 Dokumentation & Wiki → [Creative Commons Attribution-ShareAlike 4.0 (CC BY-SA 4.0)](LICENSE-DOCS)  


Dieses Projekt bleibt Open Source und darf nicht in proprietäre Produkte umgewandelt werden.

---

📦 Projektstruktur

📂 HARDWARE/ → PCB-Designs & Stückliste (BOM)
📂 FIRMWARE/ → ESP32 & RP2040 Code
📂 SOFTWARE/ → Begleit-Software (z. B. für PC oder Smartphone)
📂 SCRIPTS/ → Community-Erweiterungen & Plugins
📂 DOCS/ → Anleitungen, Bilder & Tutorials
📂 LICENSE/ → Enthält alle Lizenzinformationen


---

🔧 Installation & Erste Schritte

1️⃣ Hardware aufbauen

📌 erstelle die Platine (Gerber-Files in HARDWARE/).
📌 Löte die Bauteile gemäß der Stückliste (BOM.txt).

2️⃣ Firmware flashen

📌 Installiere esptool für ESP32:

pip install esptool
esptool.py --chip esp32 write_flash 0x1000 firmware.bin

📌 Falls du die RP2040-Software flashen willst, nutze RPi Boot.


---

🤝 Mitmachen & Beiträge

Wir freuen uns über neue Ideen & Code-Beiträge! Bitte lies die CONTRIBUTING.md, bevor du Pull Requests erstellst.

💡 Möglichkeiten zum Mitmachen:
🔹 Neue Features oder Bugfixes in Issues diskutieren
🔹 Eigene Skripte in SCRIPTS/ beitragen
🔹 Hardware-Designs verbessern


---

📬 Kontakt & Community

✉ Discord-Server: Link zum Discord
🐦 Twitter/X: @DevoMultitron
💬 GitHub Discussions: Hier diskutieren


---

📅 Roadmap & To-Do

🟢 Phase 1 – Erste Beta-Version mit Basisfunktionen 🔄 In Arbeit
🟡 Phase 2 – Community-Erweiterungen & Plugin-Architektur 🚧 Geplant
🔴 Phase 3 – Kommerzielle Version mit optionalen Extras 💡 Zukünftige Idee


---

⚠ Haftungsausschluss

⚠ Dieses Projekt wird ohne jegliche Garantie bereitgestellt. Der Entwickler übernimmt keine Haftung für Schäden an Geräten oder Software.


---

🌟 Like das Projekt auf GitHub!

Wenn dir dieses Projekt gefällt, hinterlasse einen ⭐ Star und teile es mit der Community!
