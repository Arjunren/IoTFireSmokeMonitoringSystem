# Installation — IoTFireSmokeMonitoringSystem

1. Install Python 3, PlatformIO Core, and a USB driver for the ESP32 board.
2. Assemble MQ-2 gas module with 3.3 V-safe output; heat switch; low-voltage buzzer according to [HARDWARE.md](HARDWARE.md). Check voltage levels with the board unpowered.
3. Provision a broker DNS name, TLS server certificate, and unique device credentials with publish-only access to `devices/<device-id>/telemetry`.
4. Copy `include/device_config.example.h` to `include/device_config.h` and fill the local values. Keep this file out of Git.
5. Run `python -m platformio run`. With a C++17 host compiler, run `g++ -std=c++17 -Iinclude test/logic.cpp -o logic-test && ./logic-test`.
6. Flash with `python -m platformio run -t upload` after selecting the correct serial port. Watch serial output at 115200 baud without printing secrets.
7. Subscribe to the provisioned topic using a separate, read-only broker credential and check a plausible MQ-2 signal value.

Hardware validation and broker provisioning cannot be completed from this repository alone.
