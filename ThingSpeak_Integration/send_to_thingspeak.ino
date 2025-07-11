#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

const char* ssid = "YOUR_WIFI_SSID";          // Replace with your Wi-Fi SSID
const char* password = "YOUR_WIFI_PASSWORD";  // Replace with your Wi-Fi password
unsigned long channelID = YOUR_CHANNEL_ID;    // Replace with your ThingSpeak channel ID
const char* writeAPIKey = "YOUR_WRITE_API_KEY"; // Replace with your ThingSpeak write API key

WiFiClient client;

int pulsePin = A0;
int BPM = 0;
int IBI = 600;
int Signal;
boolean Pulse = false;
unsigned long lastBeatTime = 0;
unsigned long sampleCounter = 0;
int thresh = 512;
int P = 512;
int T = 512;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  ThingSpeak.begin(client);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi Connected");
}

void loop() {
  Signal = analogRead(pulsePin);
  sampleCounter += 2;
  int N = sampleCounter - lastBeatTime;

  if ((Signal > thresh) && (Pulse == false) && (N > (IBI / 5) * 3)) {
    Pulse = true;
    IBI = sampleCounter - lastBeatTime;
    lastBeatTime = sampleCounter;
    BPM = 60000 / IBI;

    Serial.print("BPM: ");
    Serial.println(BPM);

    int res = ThingSpeak.writeField(channelID, 1, BPM, writeAPIKey);
    if (res == 200) {
      Serial.println("Sent to ThingSpeak");
    } else {
      Serial.print("Failed, code: ");
      Serial.println(res);
    }

    delay(15000); // ThingSpeak rate limit = 15 seconds per update
  }

  if (Signal < thresh) {
    Pulse = false;
  }

  delay(2);
}
