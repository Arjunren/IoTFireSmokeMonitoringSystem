# Testing — IoTFireSmokeMonitoringSystem

Run `g++ -std=c++17 -Iinclude test/logic.cpp -o logic-test && ./logic-test` with a host C++ compiler for simulated alert, normal, out-of-range, and invalid-sample cases. Run `python -m platformio run` for firmware compilation. Test values are software simulations only.

On hardware, inspect MQ-2 signal against a reference, disconnect Wi-Fi to observe reconnect behavior, revoke broker credentials to confirm publish failure, and inspect broker ACLs with a separate test account. Verify GPIO14 falls low during a disconnected session and invalid sample. Record actual readings and firmware hash before claiming field validation. No physical hardware test evidence is included.
