/*
  user_config_override.h - user configuration overrides my_user_config.h for Tasmota

  Copyright (C) 2021  Theo Arends

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _USER_CONFIG_OVERRIDE_H_
#define _USER_CONFIG_OVERRIDE_H_

/*****************************************************************************************************\
 * USAGE:
 *   To modify the stock configuration without changing the my_user_config.h file:
 *   (1) copy this file to "user_config_override.h" (It will be ignored by Git)
 *   (2) define your own settings below
 *
 ******************************************************************************************************
 * ATTENTION:
 *   - Changes to SECTION1 PARAMETER defines will only override flash settings if you change define CFG_HOLDER.
 *   - Expect compiler warnings when no ifdef/undef/endif sequence is used.
 *   - You still need to update my_user_config.h for major define USE_MQTT_TLS.
 *   - All parameters can be persistent changed online using commands via MQTT, WebConsole or Serial.
\*****************************************************************************************************/

/*
Examples :

// -- Master parameter control --------------------
#undef  CFG_HOLDER
#define CFG_HOLDER        4617                   // [Reset 1] Change this value to load SECTION1 configuration parameters to flash

// -- Setup your own Wifi settings  ---------------
#undef  STA_SSID1
#define STA_SSID1         "YourSSID"             // [Ssid1] Wifi SSID

#undef  STA_PASS1
#define STA_PASS1         "YourWifiPassword"     // [Password1] Wifi password

// -- Setup your own MQTT settings  ---------------
#undef  MQTT_HOST
#define MQTT_HOST         "your-mqtt-server.com" // [MqttHost]

#undef  MQTT_PORT
#define MQTT_PORT         1883                   // [MqttPort] MQTT port (10123 on CloudMQTT)

#undef  MQTT_USER
#define MQTT_USER         "YourMqttUser"         // [MqttUser] Optional user

#undef  MQTT_PASS
#define MQTT_PASS         "YourMqttPass"         // [MqttPassword] Optional password

// You might even pass some parameters from the command line ----------------------------
// Ie:  export PLATFORMIO_BUILD_FLAGS='-DUSE_CONFIG_OVERRIDE -DMY_IP="192.168.1.99" -DMY_GW="192.168.1.1" -DMY_DNS="192.168.1.1"'

#ifdef MY_IP
#undef  WIFI_IP_ADDRESS
#define WIFI_IP_ADDRESS     MY_IP                // Set to 0.0.0.0 for using DHCP or enter a static IP address
#endif

#ifdef MY_GW
#undef  WIFI_GATEWAY
#define WIFI_GATEWAY        MY_GW                // if not using DHCP set Gateway IP address
#endif

#ifdef MY_DNS
#undef  WIFI_DNS
#define WIFI_DNS            MY_DNS               // If not using DHCP set DNS IP address (might be equal to WIFI_GATEWAY)
#endif

#ifdef MY_DNS2
#undef  WIFI_DNS2
#define WIFI_DNS2           MY_DNS2              // If not using DHCP set DNS IP address (might be equal to WIFI_GATEWAY)
#endif

// !!! Remember that your changes GOES AT THE BOTTOM OF THIS FILE right before the last #endif !!!
*/

// [SetOption53] Show hostname and IP address in GUI main menu
#undef GUI_SHOW_HOSTNAME
#define GUI_SHOW_HOSTNAME      true

// PROJECT is used as the default topic delimiter
#undef PROJECT
#define PROJECT                "SmartPool"

// [Template] Set JSON user template for GPIO configuration (Atom+Tail and ESP8266)

// Define Template based on chip
#ifdef USER_TEMPLATE
  #undef USER_TEMPLATE
#endif

#ifdef ESP32
  #define USER_TEMPLATE "{\"NAME\":\"NeoPool Atom Lite + Tail485\",\"GPIO\":[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,0,0,6976,0,0,0,0,0,7008,1,0,0,0,0,0,0],\"FLAG\":0,\"BASE\":1}"
#endif  // ESP32

#ifdef ESP8266
  #define USER_TEMPLATE "{\"NAME\":\"NeoPool ESP8266\",\"GPIO\":[1,6528,1,6496,1,1,0,0,1,1,1,1,1,1],\"FLAG\":0,\"BASE\":18}"
#endif  // ESP8266

// [Module] Select default model (the list is kModuleNiceList() in file tasmota_template.h) USER_MODULE is the TEMPLATE
#ifdef MODULE
  #undef MODULE
#endif
#define MODULE                 USER_MODULE

// Select the default model as FALLBACK when the user does a RESET 1
#ifdef FALLBACK_MODULE
  #undef FALLBACK_MODULE
#endif
#define FALLBACK_MODULE        USER_MODULE

// [DeviceName] Devicename up to 32 characters
#undef DEVICE_NAME
#define DEVICE_NAME            PROJECT

// [FriendlyName] Friendlyname up to 32 characters used by webpages and Alexa
#undef FRIENDLY_NAME
#define FRIENDLY_NAME          PROJECT

// [Topic] unique MQTT device topic
#undef MQTT_TOPIC
#define MQTT_TOPIC             PROJECT

// [MqttClient] Also fall back topic using last 6 characters of MAC address or use "DVES_%12X" for complete MAC address
#undef MQTT_CLIENT_ID
#define MQTT_CLIENT_ID         PROJECT

// [SensorRetain] Sensor may send retain flag (false = off, true = on)
#undef MQTT_SENSOR_RETAIN
#define MQTT_SENSOR_RETAIN     true

// Add support for rules (+8k code)
#undef USE_RULES
#define USE_RULES

// Add Rule1 data saved at initial firmware load or when command reset is executed
#undef USER_RULE1
#define USER_RULE1 "ON Time#Initialized DO NPTime 0 ENDON ON Time#Set DO NPTime 0 ENDON ON System#Boot DO Backlog Discover 0; NPTeleperiod 60; ENDON"

// Activate user Rule1, set WifiPower to dynamic and disable any device discovery protocol
#undef USER_BACKLOG
#define USER_BACKLOG "Rule1 4; Rule1 1; WifiPower 0;"

// Log modbus traffic errors: use Weblog 3 or 4 to debug and Weblog 2 to go back to normal log level
// https://github.com/arendst/Tasmota/discussions/18991#discussioncomment-6317229
// #undef DEBUG_TASMOTA_SENSOR
// #define DEBUG_TASMOTA_SENSOR

// Add support for NeoPool module
#undef USE_NEOPOOL
#define USE_NEOPOOL

#endif  // _USER_CONFIG_OVERRIDE_H_
