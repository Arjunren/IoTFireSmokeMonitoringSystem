# Software — IoTFireSmokeMonitoringSystem

Firmware is C++ with Arduino on ESP32. `src/main.cpp` implements analog_digital acquisition, bounded JSON telemetry, Wi-Fi reconnection, TLS broker connection, and output fail-safe. `include/logic.h` defines value validation and the `MQ-2 signal > 2500.0f || heat switch active > 0.5f` rule. PlatformIO pins `platformio/espressif32@6.10.0` and `knolleary/PubSubClient@2.8.0`.

No backend, frontend, or database is part of this firmware-only architecture. An operator-supplied MQTT broker enforces the device's publish ACL and TLS identity. No watchdog API is configured; a hardware watchdog and persistent configuration are future work.
