#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <PubSubClient.h>
#include <math.h>
#if __has_include("device_config.h")
#include "device_config.h"
#else
#include "device_config.example.h"
#endif
#include "logic.h"

WiFiClientSecure tls;
PubSubClient mqtt(tls);
unsigned long nextConnect=0, nextSample=0;
unsigned long backoff=1000;

Sample readSample() { Sample s{0,0,false}; s.value = analogRead(34); s.aux = digitalRead(27) == HIGH ? 1.0f : 0.0f; s.valid = true; return s; }

void connectNetwork() {
  if (WiFi.status()!=WL_CONNECTED) { WiFi.begin(WIFI_SSID,WIFI_PASSWORD); return; }
  if (time(nullptr)<1704067200) return; // Wait for SNTP before TLS validation.
  if (mqtt.connected()) return;
  String clientId=String("IoTFireSmokeMonitoringSystem-")+DEVICE_ID;
  if (mqtt.connect(clientId.c_str(),MQTT_USERNAME,MQTT_PASSWORD)) { backoff=1000; }
}

void setup() {
  Serial.begin(115200);
  pinMode(34, INPUT); analogReadResolution(12); pinMode(27, INPUT_PULLUP); pinMode(14,OUTPUT); digitalWrite(14,LOW);
  WiFi.mode(WIFI_STA);
  configTime(0,0,"pool.ntp.org");
  tls.setCACert(MQTT_CA_CERT);
  mqtt.setServer(MQTT_HOST,8883);
  mqtt.setBufferSize(512);
  WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
}

void loop() {
  unsigned long now=millis();
  if (WiFi.status()!=WL_CONNECTED || !mqtt.connected()) {
    digitalWrite(14,LOW);
    if ((long)(now-nextConnect)>=0) {
      connectNetwork();
      nextConnect=now+backoff;
      backoff=backoff<30000 ? backoff*2 : 60000;
    }
  } else mqtt.loop();
  if ((long)(now-nextSample)<0) return;
  nextSample=now+5000;
  Sample s=readSample();
  bool alarm=isAlert(s);
  digitalWrite(14, (s.valid && mqtt.connected() && alarm) ? HIGH : LOW);
  if (!mqtt.connected()) return;
  char topic[128], payload[256];
  snprintf(topic,sizeof(topic),"devices/%s/telemetry",DEVICE_ID);
  snprintf(payload,sizeof(payload),"{\"device_id\":\"%s\",\"measurement\":%.3f,\"secondary\":%.3f,\"valid\":%s,\"alert\":%s,\"uptime_ms\":%lu}",DEVICE_ID,s.value,s.aux,s.valid?"true":"false",alarm?"true":"false",now);
  mqtt.publish(topic,payload,false);
}
