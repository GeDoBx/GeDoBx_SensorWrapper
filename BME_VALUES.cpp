#include <BME_VALUES.h>

BME_VALUES::BME_VALUES(String pName, NTPClient* pNTPClient)
	: Sensor_VALUES(pName, pNTPClient)
{
}

boolean BME_VALUES::readSensor(Adafruit_BME280 pBME)
{
  _temperature = pBME.readTemperature();
  _humidity = pBME.readHumidity();
  _pressure = pBME.readPressure();
  if (isnan(_temperature) || isnan(_humidity) || isnan(_pressure)) {
    _isOk = false;
  } else {
    _isOk = true;
    touch();
  }
  return _isOk;
}

void BME_VALUES::toJson(JsonObject pJsonObj) {
  pJsonObj["temperature"] = truncPrecisionF(_temperature, 1);
  pJsonObj["humidity"] = truncPrecisionF(_humidity, 1);
  pJsonObj["pressure"] = truncPrecisionF(_pressure, 0);
}

void BME_VALUES::report() {
  if (_isOk) {
    Serial.println("Reporting "+ getName() + ": "
	+ _NTPClient->getFormattedDate(_lastMeasurement) + ", "
    + floatToString(_temperature, 1) + "°C, " 
	+ floatToString(_humidity, 1) + "%RH, "
	+ floatToString(_pressure, 0) + "Pa");
  } else {
    Serial.println("Measurement for "+ getName() + " sensor failed, check wiring!");
  }
}
  
float BME_VALUES::getTemperature() {
    return _temperature;
}
  
float BME_VALUES::getHumidity() {
    return _humidity;
}
  
float BME_VALUES::getPressure() {
    return _pressure;
}
