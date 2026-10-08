#pragma once
// Copy to device_config.h and replace every example value locally. Never commit it.
#define WIFI_SSID "example-wifi"
#define WIFI_PASSWORD "replace-locally"
#define MQTT_HOST "broker.example.org"
#define MQTT_USERNAME "unique-device-user"
#define MQTT_PASSWORD "replace-locally"
#define DEVICE_ID "example-device"
static const char MQTT_CA_CERT[] = R"EOF(-----BEGIN CERTIFICATE-----
REPLACE_WITH_BROKER_CA_PEM
-----END CERTIFICATE-----
)EOF";
