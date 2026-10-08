# Security — IoTFireSmokeMonitoringSystem

## Threat model
Threats include stolen device credentials, a spoofed broker, forged sensor wiring, unauthorized MQTT topic access, and physical tampering. This is not a certified smoke detector, fire alarm, or life-safety system.

## Controls in this repository
`WiFiClientSecure` verifies the broker chain against `MQTT_CA_CERT`; no insecure TLS bypass is used. Unique MQTT credentials and a device-specific client ID are required. The firmware has no inbound command handler. The broker must enforce publish-only ACLs for the single device topic. Invalid/out-of-range values cannot trigger the alert rule. GPIO14 drives buzzer only while the reading is valid, the TLS MQTT session is connected, and the alert condition is true.

## Provisioning and response
Copy the ignored configuration example locally; never commit passwords, tokens, private keys, or real certificates. Use a separate broker identity per device; revoke and rotate it if exposed. Restrict broker administration and subscriber accounts by least privilege. Avoid logging credentials and personal information. Report vulnerabilities privately through GitHub's private vulnerability reporting if enabled, or to the repository owner without publishing exploit details.

## Remaining risks
The firmware does not implement secure boot, flash encryption, certificate pinning, OTA updates, local persistence, or server-side rate limits. Broker operators must set payload limits, connection quotas, and per-topic ACLs. Electrical installation needs independent inspection. CI compiles pinned firmware dependencies; operators should review dependency advisories before updates.
