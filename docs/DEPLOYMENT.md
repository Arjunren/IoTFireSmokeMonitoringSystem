# Deployment — IoTFireSmokeMonitoringSystem

Local deployment is a PlatformIO USB flash to an ESP32 DevKit. Configure a reachable TLS MQTT broker with a valid server certificate and device-specific publish-only credentials. There is no container or cloud service in this repository. An operator can host a broker and subscribers separately, but must provide tenant isolation, quotas, backups, and retention policy independently. See [INSTALLATION.md](INSTALLATION.md) and [CONFIGURATION.md](CONFIGURATION.md).
