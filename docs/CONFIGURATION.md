# Configuration — IoTFireSmokeMonitoringSystem

Create ignored `include/device_config.h` from the example. `WIFI_SSID` and `WIFI_PASSWORD` select the network; `MQTT_HOST` is the broker DNS name on port 8883; `MQTT_USERNAME`/`MQTT_PASSWORD` are unique per device; `MQTT_CA_CERT` is the PEM CA chain; `DEVICE_ID` is a short broker-approved identifier. Do not put secrets in `platformio.ini`, command-line build flags, or GitHub Actions.

The sampling interval is five seconds. The alert rule is `MQ-2 signal > 2500.0f || heat switch active > 0.5f` and the accepted primary range is 0–4095 ADC counts. Change thresholds in `include/logic.h` after calibration. During Wi-Fi or broker loss, GPIO14 is driven low.  SNTP access is needed before TLS broker connection. Rotate credentials at the broker, update the local ignored header, rebuild, and reflash securely.
