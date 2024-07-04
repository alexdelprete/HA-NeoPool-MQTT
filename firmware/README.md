# Precompiled Tasmota with NeoPool

This folder contains [Tasmota](https://github.com/arendst/Tasmota) binary files including the [driver for Sugar Valley NeoPool Controller](https://tasmota.github.io/docs/NeoPool/).

The binaries are based on Tasmota v14.1.0.3 [843dd17ae](https://github.com/arendst/Tasmota/tree/843dd17aecf37d417f302daf45512ba6aa1e9e38) of [Tasmota development](https://github.com/arendst/Tasmota/tree/development) branch.

To initial flash an ESP32/ESP8266 it is recommended using [ESP_Flasher](https://github.com/Jason2866/ESP_Flasher) and the file matching your ESP chip type (for ESP32 the files **with** `factory` in the filename):

- **NeoPool_ESP8266_tasmota.bin**  
all ESP8266 chip types
- **NeoPool_ESP32_tasmota32.factory.bin**  
all ESP32 chip types (like M5Stack [Atom Lite](https://docs.m5stack.com/en/core/ATOM%20Lite))
- **NeoPool_ESP32S3_tasmota32s3.factory.bin**  
all ESP32 S3 chip types (like M5Stack [Atom S3](https://docs.m5stack.com/en/core/AtomS3) or [Atom S3 Lite](https://docs.m5stack.com/en/core/AtomS3%20Lite))
- **NeoPool_ESP32C3_tasmota32c3.factory.bin**  
all ESP32 C3 chip types

To update an existing Tasmota device via WebUI **Firmware Upgrade**/**Upgrade by file upload** use  (for ESP32 the files **without** `factory` in the filename):

- **NeoPool_ESP8266_tasmota.bin.gz**  
all ESP8266 chip types
- **NeoPool_ESP32_tasmota32.bin**  
all ESP32 chip types (like M5Stack [Atom Lite](https://docs.m5stack.com/en/core/ATOM%20Lite))
- **NeoPool_ESP32S3_tasmota32s3.bin**  
all ESP32 S3 chip types (like M5Stack [Atom S3](https://docs.m5stack.com/en/core/AtomS3) or [Atom S3 Lite](https://docs.m5stack.com/en/core/AtomS3%20Lite))
- **NeoPool_ESP32C3_tasmota32c3.bin**  
all ESP32 C3 chip types
