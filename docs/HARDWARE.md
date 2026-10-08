# Hardware — IoTFireSmokeMonitoringSystem

## Parts and electrical limits
ESP32 DevKit and MQ-2 gas module with 3.3 V-safe output; heat switch; low-voltage buzzer. Power low-voltage modules from a suitable regulated supply, tie grounds together, and verify signal levels before connection. GPIO34 is input-only and ADC1 is used because ADC2 conflicts with Wi-Fi. Never apply more than 3.3 V to an ESP32 GPIO.

| ESP32 pin | Connection | Requirement |
|---|---|---|
| ESP32 3V3 | sensor VCC | Verify module supply rating |
| ESP32 GND | sensor GND | Common low-voltage ground |
| GPIO34 (ADC1) | analog signal | Never exceed 3.3 V |
| GPIO27 | digital signal | Use INPUT_PULLUP where switch wiring allows; module output must be 3.3 V |
| GPIO14 | buzzer input | Active high; MOSFET/flyback diode for inductive load |

Use a pull-down on GPIO14's driver input so the load remains off during boot. Low-voltage relays must not be connected directly to GPIO, and inductive loads need flyback protection.

## Sensor specification and calibration
The firmware accepts MQ-2 signal from 0 to 4095 ADC counts. Secondary value is heat switch active (boolean). This is not a certified smoke detector, fire alarm, or life-safety system. Use a multimeter and the sensor data sheet for the exact module revision.
