# HA-NeoPool-MQTT
Home Assistant MQTT integration for Tasmota NeoPool module.

![image](https://github.com/alexdelprete/HA-NeoPool-MQTT/assets/7027842/2da88be0-e4c1-490f-974f-470d27912890)


Since the native tasmota integration wasn't exporting all entities (switches, selects, numbers, etc.) to HA correctly, I opened a [discussion](https://github.com/arendst/Tasmota/discussions/19811) on Tasmota's repo with NeoPool dev, and we decided for now to integrate all possible entities using purely HA's MQTT integration entities.

So you can actually disable Tasmota's HA integration with `SetOption19 0` or `Discover 0` on the NeoPool device, because all the entities will be created through the package via MQTT.

Hoping one day to see Tasmota's HA integration natively creating ALL possible entity types. That will probably happen when @curzon01 switches to Home Assistant. :)

Pre-requirements:

1. This integration relies on NeoPool's extended commands for ESP32 devices, read [here](https://tasmota.github.io/docs/NeoPool/#esp32-adding-user-defined-neopool-commands-to-tasmota) for more info
2. Disable Tasmota HA discovery integration: `SetOption19 0` or `Discover 0`, and if already present in HA, delete the discovered device and entities under Tasmota integration page
3. Tasmota `%topic%` must be set to `SmartPool`
4. Home Assistant MQTT integration properly configured and working
5. The integration is released as a Home Assistant package, check HA docs on how to configure HA for package usage
6. The lovelace UI is extracted from the raw lovelace file, edit your raw lovelace config and paste the contents of the yaml file

# Credits
Big thanks to @fdebrus for inspiring me and @curzon01 for the great support.

# Coffee

If you like this integration, I'll gladly accept some quality coffee, but please don't feel obliged. :)

<a href="https://www.buymeacoffee.com/alexdelprete" target="_blank"><img src="https://www.buymeacoffee.com/assets/img/custom_images/black_img.png" alt="Buy Me A Coffee" style="height: auto !important;width: auto !important;" ></a><br>
