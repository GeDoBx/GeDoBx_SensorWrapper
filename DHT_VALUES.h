/*
   DHT_VALUES.h Library for storing Results from DHTxx sensors
   Created by Gerd Doert-Brexel, August 13, 2019
   released into the public domain
*/
#ifndef DHT_VALUES_h
#define DHT_VALUES_h

#include <DHT.h>
#include <ArduinoJson.h>
#include <Sensor_VALUES.h>

class DHT_VALUES : public Sensor_VALUES
{
  public:
    DHT_VALUES(String pName, NTPClient* pNTPClient);
    boolean readSensor(DHT pDHT);
    void toJson(JsonObject pJsonObj);
    void report();
    float getTemperature();
    float getHumidity();
  private:
    float _temperature;
    float _humidity;
};
#endif
