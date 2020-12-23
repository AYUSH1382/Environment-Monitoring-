#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>


#include "DHT.h"        // including the library of DHT11 temperature and humidity sensor
#define DHTTYPE DHT11   // DHT 11


#define dht_dpin 13
DHT dht(dht_dpin, DHTTYPE); 


// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "4NF5qCiaf56_lkOLHn1R4A-KNS5qKV5I";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "2003";
char pass[] = "2003anriya8284";

BlynkTimer timer;

// This function sends Arduino's up time every second to Virtual Pin (5).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  //Blynk.virtualWrite(V5, millis() / 1000);


  dht.begin();
  float h = dht.readHumidity();
  float t = dht.readTemperature();  
  delay(100);
  Blynk.virtualWrite(V4, t);
  Blynk.virtualWrite(V5, h);
//  Blynk.virtualWrite(V4, humidity);
  delay(100);
//  Blynk.virtualWrite(V5, temperature);
}






void setup()
{
  // Debug console
  Serial.begin(115200);

  
  


  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8442);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8442);

  // Setup a function to be called every second
  timer.setInterval(5000L, myTimerEvent);
}

void loop()
{
  Blynk.run();
  timer.run(); // Initiates BlynkTimer
}
