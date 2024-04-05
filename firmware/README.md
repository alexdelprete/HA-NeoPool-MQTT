# Precompiled Tasmota with NeoPool

This folder contains [Tasmota](https://github.com/arendst/Tasmota) binary files including the [driver for Sugar Valley NeoPool Controller](https://tasmota.github.io/docs/NeoPool/).

The binaries are based on Tasmota v13.4.0.4 development.

To flash your ESP use the file matching your ESP chip type:

- **NeoPool_ESP8266_tasmota\*** for all ESP8266 chip types
- **NeoPool_ESP32_tasmota32\*** for ESP32 chip types (like M5Stack Atom Lite)
- **NeoPool_ESP32S3_tasmota32s3\*** for ESP32 S3 chip types (like M5Stack Atom S3 Lite)

To initial flash an ESP32/ESP8266 it is recommended using [ESP_Flasher](https://github.com/Jason2866/ESP_Flasher).

For ESP8266 use the binary  `.bin` file when initial flashing.  
To update an existing Tasmota ESP8266 device (e. g. via WebUI **Firmware Upgrade**/**Upgrade by file upload**) you can use both file types (`.bin` and `.bin.gz`).

For ESP32 use the file with `factory` in the filename matching your chip type.  
For updating an existing Tasmota ESP32 device (e. g. via WebUI **Firmware Upgrade**/**Upgrade by file upload**) use the binary **without** `factory` in the filename.
