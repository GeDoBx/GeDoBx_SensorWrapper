/*
   BME_VALUES.h Library for storing Results from BMExx sensors
   Created by Gerd Doert-Brexel, August 13, 2019
   released into the public domain
*/
#ifndef BME_VALUES_h
#define BME_VALUES_h

#include <Adafruit_BME280.h>
#include <ArduinoJson.h>
#include <stdlib.h>
#include <Sensor_VALUES.h>

class BME_VALUES : public Sensor_VALUES
{
  public:
    BME_VALUES(String pName, NTPClient* pNTPClient);
    //String getName();
    boolean readSensor(Adafruit_BME280 pBME);
    void toJson(JsonObject pJsonObj);
    void report();
    float getTemperature();
    float getHumidity();
    float getPressure();
//	String floatFormat(float pFloat, int pMinWidth, int pPrecision);
  private:
//    boolean _isOk;
//    String _name;
    float _temperature;
	float _humidity;
    float _pressure;
};
#endif
