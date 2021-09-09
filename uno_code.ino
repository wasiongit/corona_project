
#include <BoltIoT-Arduino-Helper.h>
#include <SimpleDHT.h>

/*
 * This code monitors the status of pin 2, 
 * and sends the status fo the same to the cloud,
 * when the Bolt sends the RD\r command
 */

#ifndef API_KEY
#define API_KEY   "7bcb7374-afb7-4ddb-b177-269ae2f488c9"
#endif
#ifndef DEVICE_ID
#define DEVICE_ID "BOLT292289"
#endif


// for DHT11, 
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 2
int pinDHT11 = 2;
SimpleDHT11 dht11(pinDHT11);


int sensorPin = A0; 
void setup(){
	boltiot.begin(Serial);
}

void loop(){
  delay(250);

        byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
    return;
  }
  
 
  
  // DHT11 sampling rate is 1HZ.
  delay(1500);

int humi=(int)humidity;
  
	boltiot.processPushDataCommand(humi);
delay(200);
}
