# HA-NeoPool-MQTT
Home Assistant MQTT integration for Tasmota NeoPool module (ESP32 and ESP8266 devices).

![image](https://github.com/alexdelprete/HA-NeoPool-MQTT/assets/7027842/e20e21c4-02b5-4e24-8453-d991c2f03f52)

Since the native tasmota integration wasn't exporting all entities (switches, selects, numbers, etc.) to HA correctly, I opened a [discussion](https://github.com/arendst/Tasmota/discussions/19811) on Tasmota's repo with NeoPool dev, and we decided for now to integrate all possible entities using purely HA's MQTT integration entities.

All the NeoPool entities will be created through the provided package via HA's native MQTT entities.

The integration is currently based on Tasmota dev release `v13.2.0.2` (that merged PR [#19973](https://github.com/arendst/Tasmota/pull/19973)). Next stable release (after `v13.2.0`, current stable version) should contain it.
Since the NeoPool driver is not contained in precompiled binaries, you need to compile your own build.

For flashing ESP32/ESP8266 I highly recommend using [ESP_Flasher](https://github.com/Jason2866/ESP_Flasher) by @Jason2866, in v2.0.1 he kindly implemented by [my request](https://github.com/Jason2866/ESP_Flasher/issues/29) support for ESP32 high-speed baud rates (1.5Mb/s) for very quick and reliable flashing and he also added support for factory images.

# Custom pre-configured Tasmota build

When you custom compile your version, make sure to choose the dev branch and verify after flashing that version is at least `v13.2.0.2`. I will update notes to specify the stable min. version once known. When you custom compile your build, you'll need to use the `user_config_override.h` provided in the `compiler` folder of this repository; this will automatically enable NeoPool and also configure all settings automatically without requiring to manually follow the manual steps of next section.

NOTE for beginners: if you have no idea about how to custom compile Tasmota, you can use the precompiled files in the `firmware` folder of the repository.

The only thing you'll have to check is if the activated template is correct, you do this from Tasmota console executing command `Module`:
```console
13:41:13.489 CMD: Module
13:41:13.491 RSL: RESULT = {"Module":{"0":"NeoPool Atom Lite + Tail485"}}
```

If the result is not the one you see above, you need to issue the command `Module 0` to activate the preconfigured template:
```console
13:43:35.087 CMD: module 0
13:43:35.090 RSL: RESULT = {"Module":{"0":"NeoPool Atom Lite + Tail485"}}
```

In case you don't use the provided `user_config_override.h` file, you'll need to follow the Manual Configuration Steps section below.


# Manual configuration steps

1. From Tasmota console, run these commands to optimize the device configuration:

    _This sets Retain flag for telemetry topic so that HA entities are immediately available_
    ```console
    SensorRetain 1
    ```
    _This ensures that Tasmota %topic% is set to `SmartPool` so you don't have to change all the topics in the package file_
    _It also sets device name, friendly name and mqtt client name (for easier identification in the broker)_
    ```console
    Backlog Topic SmartPool; DeviceName SmartPool; FriendlyName SmartPool; MqttClient SmartPool; 
    ```
    _Define a rule to keep the Sugar Valley device clock in sync with Tasmota's device clock and also sets NeoPool SENSOR topic to update every 60s for often changed (measurements) values_
    _This also disables the device from being discovered by HA so it won't create unnecessary and duplicate entities for NeoPool_
    ```console
    Rule1 ON Time#Initialized DO NPTime 0 ENDON ON Time#Set DO NPTime 0 ENDON ON System#Boot DO Backlog Discover 0; NPTeleperiod 60; ENDON
    ```
    _Configure user template for GPIO definition based on device type_
   Atom Lite + Tail485 (GPIO26: NeoPool TX / GPIO32: NeoPool RX)
    ```console
   Template {"NAME":"NeoPool Atom Lite + Tail485","GPIO":[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,0,0,6976,0,0,0,0,0,7008,1,0,0,0,0,0,0],"FLAG":0,"BASE":1}
    ```
   AtomS3 Lite + Atomic RS485 Base (GPIO19: NeoPool TX - GPIO22: NeoPool RX)
    ```console
   Template {"NAME":"AtomS3 Lite + Atomic RS485 Base","GPIO":[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6976,0,0,7008,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],"FLAG":0,"BASE":1}
    ```
    Other ESP32/ESP8266 devices (GPIO3: NeoPool TX - GPIO1: NeoPool RX):
    ```console
   Template {"NAME":"NeoPool ESP32/ESP8266","GPIO":[1,6528,1,6496,1,1,0,0,1,1,1,1,1,1],"FLAG":0,"BASE":18}
    ```
    _Activate Rule1 and User GPIO Template_
    ```console
    Backlog Rule1 4;Rule1 1; Module 0;
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
