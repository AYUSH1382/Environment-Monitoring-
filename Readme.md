# 				Environment Monitoring



Environment Monitoring system help a user to get the temperature and humidity of their surrounding.

This projects aims to see how temperature and humidity of the surrounding environment are recorded using the ESP32 wifi module over a wifi connection. In this project we using the BLYNK app to view and record the temperature and humidity of the surrounding along with a DHT11 is the sensor.



## Features

- We can view the temperature and humidity on an app known as *BLYNK*
- Wifi module ESP32(with a camera) is used to monitor the temperature and Humidity
- Connections are simple
- The app even shows a graph to see how much change has occured in the temperature and humidity of the surrounding

> Note: For this project to work user has to install BLYNK app on their smartphones and create a project to connect with the ESP32 module.



## Component used

1. ESP32-CAM
2. DHT11 sensor
3. USB to TTL connector
4. Bread-Board(optional)
5. Jumper Wires



## Libraries

- `Wifi.h` - This helps the ESP32 module connect over a network which is being used for viewing on a device.
- `WifiClient ` - Helps a device to connect over the same network and record the data
- `BlynkSimpleEsp32.h` - To use the Blynk app to view the data
- `DHT.h` - Helps to read the temperature and humidity provided by the DHT11 sensor

> Note : To install the above mentioned libraries go to **Sketch > Include Library > Manage Libraries** and install. Along with the above mentioned libraries install `Adafruit unified Sensor` as DHT uses this too.



## Setup

1. Install all the above mentioned libraries
2. Enter your wifi details where *ssid* is the wifi name and *pass* is the password
3. In  the `auth[]` part enter the auth code received over the mail.
4. Go to the **Blynk** app and make a module which can display temperature and humidity
5. Connect all the sensors 
6. Compile and Upload 
7. Click the play button on the app to view the data



## Connections

**<u>Before uploading the code</u>**

*Between TTL connector and ESP32*

- `5V`(ESP32) <------> `5V`(USB-TTL connector)
- `GND`(ESP32) <-----> `GND`(USB-TTL connector)
- `U0T`(ESP32) <-----> `RX`(USB-TTL connector)
- `U0R`(ESP32) <-----> `TX`(USB-TTL connector)
- `GPIO 0`(ESP32) <-----> `GND`(USB-TTL connector)

*Between ESP32 and* DHT11

- `3v3`(ESP32) <------> `Vcc`(DHT11)
- `GND`(ESP32) <-----> `GND`(DHT11)
- `GPIO13`(ESP32) <-----> `Data`(DHT11)

**<u>After uploading the code</u>**

*Between TTL connector and ESP32*

- `5V`(ESP32) <------> `5V`(USB-TTL connector)
- `GND`(ESP32) <-----> `GND`(USB-TTL connector)
- `U0T`(ESP32) <-----> `RX`(USB-TTL connector)
- `U0R`(ESP32) <-----> `TX`(USB-TTL connector)

> Note: We need to disconnect the GPIO 0 and GND

*Between ESP32 and* DHT11

- `3v3`(ESP32) <------> `Vcc`(DHT11)
- `GND`(ESP32) <-----> `GND`(DHT11)
- `GPIO13`(ESP32) <-----> `Data`(DHT11)

## Working

Upload the code on to the ESP32 module. Next disconnect the GPIO 0 and GND . Open the serial monitor and then click the reset button on the ESP32 module. Then go to the  BLYNK app and run the module. The temperature and humidity data recorded will be displayed along with a graph.

