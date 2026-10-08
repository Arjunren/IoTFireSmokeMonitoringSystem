# MQTT contract — IoTFireSmokeMonitoringSystem

No REST endpoint or inbound control topic is implemented. Firmware publishes QoS 0, non-retained JSON to `devices/<DEVICE_ID>/telemetry` over TLS port 8883. The broker must reject a device publishing to another device ID.

```json
{"device_id":"example-device","measurement":1.0,"secondary":0.0,"valid":true,"alert":false,"uptime_ms":5000}
```

`measurement` is MQ-2 signal in ADC counts; `secondary` is heat switch active in boolean; `valid` records sensor and range validation; `alert` is false on invalid samples; `uptime_ms` is a monotonic counter that wraps. There is no server-side schema enforcement in this repository. Subscribers should verify topic ownership, device ID equality, number finiteness, and message size. No actuator command is accepted remotely.
