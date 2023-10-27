# HA-NeoPool-MQTT
Home Assistant MQTT integration for Tasmota NeoPool module

Since the native tasmota integration wasn't exporting all entities (switches, selects, numbers, etc.) to HA correctly, I decided to integrate all possible entities using purely HA's MQTT integration entities.

Hoping one day to see Tasmota's HA integration natively creating ALL possible entity types. :)

Pre-requirements:

1. Tasmota `%topic%` must be set to `SmartPool`
2. Home Assistant MQTT integration properly working
3. The integration is released as a Home Assistant package, check HA docs on how to configure HA for package usage
4. The lovelace UI is extracted from the raw lovelace file, edit your raw lovelace config and paste the contents of the yaml file

# Coffee

If you like this integration, I'll gladly accept some quality coffee, but please don't feel obliged. :)

<a href="https://www.buymeacoffee.com/alexdelprete" target="_blank"><img src="https://www.buymeacoffee.com/assets/img/custom_images/black_img.png" alt="Buy Me A Coffee" style="height: auto !important;width: auto !important;" ></a><br>

![image](https://github.com/alexdelprete/HA-NeoPool-MQTT/assets/7027842/fd404be8-448e-441a-8352-a875f178dfd1)
