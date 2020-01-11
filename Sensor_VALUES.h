/*
   Sensor_VALUES.h Library for storing Results from Adafruit sensors
   Created by Gerd Doert-Brexel, August 13, 2019
   released into the public domain
*/
#ifndef Sensor_VALUES_h
#define Sensor_VALUES_h

#include <ArduinoJson.h>
#include <stdlib.h>
#include <NTPClient.h>

class Sensor_VALUES
{
  public:
    Sensor_VALUES(String pName, NTPClient* pNTPClient);
    String getName();
	boolean isOk();
    virtual void toJson(JsonObject pJsonObj) = 0; // rein virtuelle Funktion
    virtual void report() = 0; // rein virtuelle Funktion
  protected:
    boolean _isOk;
    NTPClient* _NTPClient;
    long _lastMeasurement;
	String floatFormat(float pFloat, int pMinWidth, int pPrecision);
	float truncPrecisionF(float pFloat, int pPrecision);
	String floatToString(float pFloat, int pPrecision);
	void checkValue(float pValue);
    void touch();
    long getTimestamp();
  private:
    String _name;
};
#endif
