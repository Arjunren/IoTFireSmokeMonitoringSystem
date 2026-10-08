# Data storage — IoTFireSmokeMonitoringSystem

This firmware has no database, schema, migration, or retained local queue. A broker subscriber may persist `MQ-2 signal`, `heat switch active`, validity, alert flag, and timestamp in an external store, but that service is not implemented here. The example publisher uses non-retained QoS 0, so offline readings are lost. An external deployment should define tenant ownership, time-series indexes, and a retention policy before storing data.
