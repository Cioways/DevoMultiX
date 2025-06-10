#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>
#include <WiFi.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRsend.h>
#include <IRutils.h>
#include <Preferences.h>
Preferences prefs;

// TFT Display Pins ---
#define TFT_CS     5
#define TFT_DC     2
#define TFT_RST    17
#define TFT_SCLK   18
#define TFT_MOSI   23

SPIClass mySPI(VSPI);
Adafruit_ST7735 tft = Adafruit_ST7735(&mySPI, TFT_CS, TFT_DC, TFT_RST);

// --- Tastenbelegung ---

#define BTN_UP     33
#define BTN_DOWN   26 
#define BTN_RIGHT  27
#define BTN_LEFT   38//keine funktion
#define BTN_OK     25
#define BTN_BACK   32  

bool readButton(uint8_t pin) {
return digitalRead(pin) == LOW;
}

// IR Empfangen ---

const uint16_t IR_RECEIVE_PIN = 19;
IRrecv irrecv(IR_RECEIVE_PIN);
decode_results results;

// IR Senden ---

const uint16_t IR_SEND_PIN = 4;
IRsend irsend(IR_SEND_PIN);
uint32_t savedIRCode;
decode_type_t codeType;


// Wifi Scan ---

uint32_t lastScanTime = 0;
const uint32_t scanInterval = 30000; // 30 Sekunden
bool inWLANScan = false;

// --- Menüstruktur ---

const char* mainMenu[] = {"1. WLAN", "2. Bluetooth", "3. RS232", "4. Infrarot", "5. RS485"};
const char* wlanMenu[] = {"Portscan", "dB-Messung"};
const char* btMenu[] = {"Scan", "Verbinden"};
const char* rs232Menu[] = {"Monitor", "Baudrate"};
const char* irMenu[] = {"Senden", "Empfangen"};
const char* rs485Menu[] = {"Lesen", "Senden"};

enum MenuLevel { MAIN, WLAN, BT, RS232, IR, RS485 };
MenuLevel currentMenu = MAIN;
int selectedItem = 0;
void drawMenu(const char* items[], int num) {
tft.fillScreen(ST77XX_BLACK);
tft.setTextSize(1);

for (int i = 0; i < num; i++) {
int y = 20 + i * 15;
  if (i == selectedItem) {
    tft.fillRect(5, y - 2, 120, 12, ST77XX_BLUE);
    tft.setTextColor(ST77XX_WHITE, ST77XX_BLUE);
  } else {
    tft.setTextColor(ST77XX_WHITE, ST77XX_BLACK);
  }

  tft.setCursor(10, y);
  tft.print(items[i]);
}

// Ausgabe im Serial Monitor:

Serial.print("Menüanzeige: ");
switch (currentMenu) {
case MAIN: Serial.println(mainMenu[selectedItem]); break;
case WLAN: Serial.println(wlanMenu[selectedItem]); break;
case BT: Serial.println(btMenu[selectedItem]); break;
case RS232: Serial.println(rs232Menu[selectedItem]); break;
case IR: Serial.println(irMenu[selectedItem]); break;
case RS485: Serial.println(rs485Menu[selectedItem]); break;
}
}

void showWLANScan() {

tft.fillScreen(ST77XX_BLACK);
tft.setTextColor(ST77XX_GREEN);
tft.setTextSize(1);
tft.setCursor(0, 0);
tft.println("WLAN-Scan...");
uint16_t darkGrey = tft.color565(50, 50, 50);
int n = WiFi.scanNetworks();

if (n == 0) {
tft.println("Keine Netzwerke gefunden");
Serial.println("Keine Netzwerke gefunden");
} else {
Serial.printf("%d Netzwerke gefunden:\n", n);

String uniqueSSIDs[20]; // max 20 unique SSIDs
int uniqueCount = 0;

for (int i = 0; i < n && uniqueCount < 8; ++i) {
  String ssid = WiFi.SSID(i);

  // Prüfen, ob SSID schon in uniqueSSIDs drin ist

  bool isNew = true;
  for (int u = 0; u < uniqueCount; u++) {
    if (uniqueSSIDs[u] == ssid) {
      isNew = false;
      break;
    }
  }
  if (!isNew) continue;

  uniqueSSIDs[uniqueCount++] = ssid;

  int rssi = WiFi.RSSI(i);
  int barWidth = constrain(rssi + 100, 1, 120);

  uint16_t barColor;
  if (rssi > -50) barColor = ST77XX_GREEN;
  else if (rssi > -70) barColor = ST77XX_YELLOW;
  else barColor = ST77XX_RED;

  int y = 16 + uniqueCount * 14;

  // Balkenhintergrund etwas unter Text

  tft.fillRect(5, y + 10, 120, 4, darkGrey);
  tft.fillRect(5, y + 10, barWidth, 4, barColor);



  String shortSSID = ssid;

  if (ssid.length() > 15) shortSSID = ssid.substring(0, 15) + "..";

  tft.setCursor(5, y);
  tft.setTextColor(ST77XX_WHITE);
  tft.print(shortSSID);
  tft.setCursor(85, y);
  tft.print(String(rssi));
  tft.print(" dBm");
  Serial.printf("%d: SSID: %s, RSSI: %d dBm\n", uniqueCount, ssid.c_str(), rssi);
}
}

inWLANScan = true;

}

void updateMenu() {
switch (currentMenu) {
case MAIN: drawMenu(mainMenu, 5); break;
case WLAN: drawMenu(wlanMenu, 2); break;
case BT: drawMenu(btMenu, 2); break;
case RS232: drawMenu(rs232Menu, 2); break;
case IR: drawMenu(irMenu, 2); break;
case RS485: drawMenu(rs485Menu, 2); break;
}

}

void irEmpfangen() {
  tft.fillScreen(ST77XX_BLACK);
  tft.setCursor(0, 10);
  tft.setTextColor(ST77XX_WHITE);
  tft.println("Warte auf IR-Signal...");

  unsigned long start = millis();
  while (millis() - start < 10000) { // max. 10 Sekunden warten
    if (irrecv.decode(&results)) {
      Serial.println(resultToSourceCode(&results)); // sendbares Format
      tft.println("Signal empfangen:");
      tft.setTextSize(1);
      tft.println(resultToSourceCode(&results));
      irrecv.resume();

      // Optional: als Beispiel merken
      if (results.decode_type == decode_type_t::NEC) {
        savedIRCode = results.value;
        codeType = decode_type_t::NEC;

      // Im Flash speichern:
      prefs.begin("ir", false); // "false" = write mode
      prefs.putULong("code", savedIRCode);
      prefs.putUChar("type", (uint8_t)codeType);
      prefs.end();

      Serial.printf("IR-Code gespeichert: 0x%08X (Typ: %d)\n", savedIRCode, codeType);
    }   
      return;
    }
    delay(100);
  }
  tft.println("Kein Signal erkannt.");
}

void irSenden() {
  tft.fillScreen(ST77XX_BLACK);
  tft.setCursor(0, 10);
  tft.setTextColor(ST77XX_WHITE);
  tft.println("Sende IR-Code...");

  if (codeType == decode_type_t::NEC) {
    irsend.sendNEC(0xE0E0E01F, 32);
    Serial.printf("Sende NEC: 0x%08X\n", savedIRCode);
    tft.println("NEC-Code gesendet!");
  } else {
    tft.println("Kein gültiger Code gespeichert!");
  }
}

void handleOK() {
  if (currentMenu == MAIN) {
    switch (selectedItem) {
      case 0: currentMenu = WLAN; break;
      case 1: currentMenu = BT; break;
      case 2: currentMenu = RS232; break;
      case 3: currentMenu = IR; break;
      case 4: currentMenu = RS485; break;
    }
    selectedItem = 0;
    Serial.println("OK gedrückt → Untermenü geöffnet");
    updateMenu();

  } else if (currentMenu == WLAN && selectedItem == 0) {
    Serial.println("WLAN-Scan gestartet");
    showWLANScan();

  } else if (currentMenu == IR) {
    if (selectedItem == 0) {
      Serial.println("IR senden");
      irSenden();
    } else if (selectedItem == 1) {
      Serial.println("IR empfangen");
      irEmpfangen();
    }

  } else {
    Serial.print("Aktion gewählt: ");
    switch (currentMenu) {
      case WLAN: Serial.println(wlanMenu[selectedItem]); break;
      case BT: Serial.println(btMenu[selectedItem]); break;
      case RS232: Serial.println(rs232Menu[selectedItem]); break;
      case RS485: Serial.println(rs485Menu[selectedItem]); break;
      default: Serial.println("Unbekannt"); break;
    }
  }
}

void handleBack() {

  if (inWLANScan) {
    Serial.println("BACK gedrückt – zurück vom WLAN-Scan");
    inWLANScan = false;
    updateMenu();
  return;
  }

  if (currentMenu != MAIN) {
    currentMenu = MAIN;
    selectedItem = 0;
    Serial.println("Zurück zum Hauptmenü");
    updateMenu();
  }

}


void setup() {

Serial.begin(115200);
delay(300);
WiFi.mode(WIFI_STA);
WiFi.disconnect(true);
delay(1000);

mySPI.begin(TFT_SCLK, -1, TFT_MOSI, TFT_CS);
tft.initR(INITR_BLACKTAB);
tft.setRotation(2);

updateMenu();

irrecv.enableIRIn();  // IR-Empfänger starten
irsend.begin();

prefs.begin("ir", true); // "true" = read-only
savedIRCode = prefs.getULong("code", 0x20DF40BF); // Fallback auf Beispielcode
codeType = (decode_type_t)prefs.getUChar("type", (uint8_t)decode_type_t::NEC);
prefs.end();

// Tasten als Eingänge mit Pullup

pinMode(BTN_UP, INPUT_PULLUP);
pinMode(BTN_DOWN, INPUT_PULLUP);
pinMode(BTN_RIGHT, INPUT_PULLUP);
pinMode(BTN_LEFT, INPUT_PULLUP);
pinMode(BTN_OK, INPUT_PULLUP);
pinMode(BTN_BACK, INPUT_PULLUP);

}

void loop() {

  static uint32_t lastPress = 0;
  const uint16_t debounceDelay = 150;
  uint32_t now = millis();

// Automatischer WLAN-Scan alle 30 Sekunden, wenn in WLAN Scan Menü

  if (inWLANScan && (now - lastScanTime > scanInterval)) {
  Serial.println("Automatischer WLAN-Scan (30s)");
  showWLANScan(); 
  lastScanTime = now;
  }

  if (now - lastPress > debounceDelay) {
  int maxItems = 0;

  switch (currentMenu) {
    case MAIN: maxItems = 5; break;
    case WLAN: maxItems = 2; break;
    case BT: maxItems = 2; break;
    case RS232: maxItems = 2; break;
    case IR: maxItems = 2; break;
    case RS485: maxItems = 2; break;
  }

  if (readButton(BTN_UP)) {
    selectedItem = (selectedItem - 1 + maxItems) % maxItems;
    Serial.println("UP gedrückt");
    updateMenu();
    lastPress = now;
  }

  if (readButton(BTN_DOWN)) {
    selectedItem = (selectedItem + 1) % maxItems;
    Serial.println("DOWN gedrückt");
    updateMenu();
    lastPress = now;
  }

  if (readButton(BTN_LEFT)) {
    Serial.println("LEFT gedrückt");
    lastPress = now;
  }

  if (readButton(BTN_RIGHT)) {
    Serial.println("RIGHT gedrückt");
    lastPress = now;
  }

  if (readButton(BTN_OK)) {
    handleOK();
    lastPress = now;
  }

  if (readButton(BTN_BACK)) {
    Serial.println("BACK gedrückt");
    handleBack();
    lastPress = now;
  }
}
}



