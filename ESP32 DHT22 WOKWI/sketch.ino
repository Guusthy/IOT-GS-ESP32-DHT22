#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

#define DHTPIN 15
#define DHTTYPE DHT22

const char* ssid = "Wokwi-GUEST";
const char* password = "";

const char* mqtt_server = "broker.hivemq.com";
const char* mqtt_topic = "fiap/gs/desastre/dispositivo1";
const char* client_id = "esp32-weather-demo-1";

WiFiClient espClient;
PubSubClient client(espClient);
DHT dht(DHTPIN, DHTTYPE);

String prevMessage = "";

void setup_wifi() {
  Serial.print("Connecting to WiFi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
  Serial.println(" Connected!");
}

void reconnect_mqtt() {
  while (!client.connected()) {
    Serial.print("Connecting to MQTT... ");
    if (client.connect(client_id)) {
      Serial.println("Connected!");
    } else {
      Serial.print("Failed. State=");
      Serial.print(client.state());
      Serial.println(" Trying again...");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  dht.begin();
  setup_wifi();
  client.setServer(mqtt_server, 1883);
}

void loop() {
  if (!client.connected()) {
    reconnect_mqtt();
  }
  client.loop();

  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  if (isnan(temp) || isnan(hum)) {
    Serial.println("Sensor error");
    return;
  }

  String message = "{\"id\":\"pessoa1\",\"temp\":" + String(temp) + ",\"humidity\":" + String(hum) + "}";

  if (message != prevMessage) {
    Serial.println("New data: " + message);
    client.publish(mqtt_topic, message.c_str());
    prevMessage = message;
  } else {
    Serial.println("No change");
  }

  delay(1000);
}
