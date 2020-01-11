#include <DHT_VALUES.h>

DHT_VALUES::DHT_VALUES(String pName, NTPClient* pNTPClient)
	: Sensor_VALUES(pName, pNTPClient)
{
}

boolean DHT_VALUES::readSensor(DHT pDHT)
{
  _humidity = pDHT.readHumidity();
  _temperature = pDHT.readTemperature();
  if (isnan(_humidity) || isnan(_temperature)) {
    _isOk = false;
  } else {
    _isOk = true;
    touch();
  }
  return _isOk;
}

void DHT_VALUES::toJson(JsonObject pJsonObj) {
  pJsonObj["temperature"] = truncPrecisionF(_temperature, 1);
  pJsonObj["humidity"] = truncPrecisionF(_humidity, 1);
}

void DHT_VALUES::report() {
  if (_isOk) {
    Serial.println("Reporting "+ getName() + ": "
	+ _NTPClient->getFormattedDate(_lastMeasurement) + ", "
	+ floatToString(_temperature, 1) + "°C, " 
	+ floatToString(_humidity, 1) + "% humidity");
  } else {
    Serial.println("Measurement for "+ getName() + " sensor failed, check wiring!");
  }
}
  
float DHT_VALUES::getTemperature() {
    return _temperature;
}
  
float DHT_VALUES::getHumidity() {
    return _humidity;
}
