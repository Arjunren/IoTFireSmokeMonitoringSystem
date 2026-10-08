# Architecture — IoTFireSmokeMonitoringSystem

The analog_digital acquisition path yields a `Sample` of MQ-2 signal and heat switch active. `logic.h` validates the primary value against 0–4095 ADC counts and evaluates `s.value > 2500.0f || s.aux > 0.5f` only for valid samples. GPIO14 drives buzzer only while the reading is valid, the TLS MQTT session is connected, and the alert condition is true.

```mermaid
sequenceDiagram
  participant Sensor
  participant ESP32
  participant Broker
  Sensor->>ESP32: MQ-2 signal / heat switch active
  ESP32->>ESP32: validate and decide
  ESP32->>Broker: TLS MQTT telemetry JSON
```

Wi-Fi and broker reconnection use a backoff from one to sixty seconds. The firmware has no inbound command handler. MQTT broker provisioning, persistence, alert delivery, and visualization are outside the codebase. SNTP supplies wall time before TLS certificate validation.
