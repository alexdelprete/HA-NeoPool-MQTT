# HA-NeoPool-MQTT
Home Assistant MQTT integration for Tasmota NeoPool module (ESP32 and ESP82xx devices).

![image](https://github.com/alexdelprete/HA-NeoPool-MQTT/assets/7027842/e20e21c4-02b5-4e24-8453-d991c2f03f52)

Since the native tasmota integration wasn't exporting all entities (switches, selects, numbers, etc.) to HA correctly, I opened a [discussion](https://github.com/arendst/Tasmota/discussions/19811) on Tasmota's repo with NeoPool dev, and we decided for now to integrate all possible entities using purely HA's MQTT integration entities.

All the NeoPool entities will be created through the package via HA's native MQTT entities.

_**Pre-requirements**_:

1. The integration is currently based on Tasmota dev release `v13.2.0.2` (that merged PR [#19973](https://github.com/arendst/Tasmota/pull/19973)). Next stable release (after v13.2.0, current stable version) should contain it. When you custom compile your version, make sure to choose the dev branch and verify after flashing that version is at least `v13.2.0.2`. I will update notes to specify the stable min. version once known.
2. From Tasmota console, run these commands to optimize the device configuration:

    _This disables the device from being discovered by HA so it won't create unnecessary and duplicate entities for NeoPool_
    ```console
    Discover 0
    ```
    _This sets Retain flag for telemetry topic so that HA entities are immediately available_
    ```console
    SensorRetain 1
    ```
    _This ensures that Tasmota %topic% is set to `SmartPool` so you don't have to change all the topics in the package file_
    ```console
    Topic SmartPool
    ```
    _This rule keeps the Sugar Valley device clock in sync with Tasmota's device clock and also sets NeoPool SENSOR topic to update every 60s for often changed (measurements) values_
    ```console
    Rule1
      ON Time#Initialized DO NPTime 0 ENDON
      ON Time#Set DO NPTime 0 ENDON
      ON System#Init DO NPTeleperiod 60 ENDON
    Backlog Rule1 4;Rule1 1
    ```
3. Home Assistant MQTT integration properly configured and working
4. The integration is released as a Home Assistant package, check HA docs on how to configure HA for package usage
5. The lovelace UI is extracted from the raw lovelace file, edit your raw lovelace config and paste the contents of the yaml file. There are two lovelace files, one for pc/notebook display resolutions, the other for mobile resolutions (vertical layout). The UI makes use of the following cards, available through [HACS](https://github.com/hacs), that you need to install first:
    - [layout-card](https://github.com/thomasloven/lovelace-layout-card)
    - [mushroom](https://github.com/piitaya/lovelace-mushroom)
    - [mini-graph-card](https://github.com/kalkih/mini-graph-card)
    - [stack-in-card](https://github.com/custom-cards/stack-in-card)
    - [text-divider-row](https://github.com/iantrich/text-divider-row)
    - [custom-brand-icons](https://github.com/elax46/custom-brand-icons)

# Credits
Big thanks to @fdebrus for inspiring me and @curzon01 for the great support.

# Issues/Discussion
Please open an issue in this repo if you're sure there's a bug. For discussions/general requests, please refer to [this](https://community.home-assistant.io/t/ha-neopool-mqtt-integration-of-tasmota-neopool-for-sugar-valley-hayward-aquarite-bayrol-devices/632517?u=alexdelprete) thread in HA community.

# Coffee

If you like this integration, I'll gladly accept some quality coffee, but please don't feel obliged. :)

<a href="https://www.buymeacoffee.com/alexdelprete" target="_blank"><img src="https://www.buymeacoffee.com/assets/img/custom_images/black_img.png" alt="Buy Me A Coffee" style="height: auto !important;width: auto !important;" ></a><br>
