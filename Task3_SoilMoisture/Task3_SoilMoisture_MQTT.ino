/*
  Task 3: Soil Moisture Monitoring System (IoT-enabled)
  CodeAlpha IoT Internship

  Hardware: ESP8266 (NodeMCU) + Soil Moisture Sensor
  Cloud Dashboard: ThingsBoard Cloud (MQTT Protocol)

  This sketch reads analog soil moisture data and publishes it
  to ThingsBoard via MQTT every 5 seconds, where it can be viewed
  live on a dashboard.
*/

#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// ---------- WiFi Credentials ----------
const char* ssid = "YOUR_WIFI_NAME";          // <-- replace with your WiFi name
const char* password = "YOUR_WIFI_PASSWORD";  // <-- replace with your WiFi password

// ---------- ThingsBoard MQTT Settings ----------
const char* mqtt_server = "thingsboard.cloud";
const int mqtt_port = 1883;
const char* token = "YOUR_DEVICE_ACCESS_TOKEN"; // <-- paste your access token here

// ---------- Sensor Pin ----------
const int soilPin = A0;   // Soil moisture sensor analog output

WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to WiFi: ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Connecting to ThingsBoard MQTT...");
    // token is used as the MQTT username; password is left blank
    if (client.connect("ESP8266SoilClient", token, NULL)) {
      Serial.println("connected!");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" trying again in 5 seconds");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(soilPin, INPUT);
  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // Read raw analog value (0-1023)
  int rawValue = analogRead(soilPin);

  // Convert to percentage: dry soil gives a HIGH raw value (~1023),
  // wet soil gives a LOW raw value (~0). We invert it so that
  // higher percentage = wetter soil, which is more intuitive.
  int moisturePercent = map(rawValue, 1023, 0, 0, 100);
  moisturePercent = constrain(moisturePercent, 0, 100);

  Serial.print("Raw Value: ");
  Serial.print(rawValue);
  Serial.print("  |  Moisture: ");
  Serial.print(moisturePercent);
  Serial.println("%");

  // Build the JSON payload ThingsBoard expects
  String payload = "{";
  payload += "\"moisture_raw\":" + String(rawValue) + ",";
  payload += "\"moisture_percent\":" + String(moisturePercent);
  payload += "}";

  // Publish to ThingsBoard's telemetry topic
  client.publish("v1/devices/me/telemetry", payload.c_str());

  delay(5000); // send data every 5 seconds
}
