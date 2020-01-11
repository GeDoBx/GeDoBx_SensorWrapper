#include <Sensor_VALUES.h>

Sensor_VALUES::Sensor_VALUES(String pName, NTPClient* pNTPClient)
{
  _name = pName;
  _NTPClient = pNTPClient; 
  _isOk = false;
}

String Sensor_VALUES::getName()
{
  return _name;  
}

boolean Sensor_VALUES::isOk()
{
  return _isOk;
}

void Sensor_VALUES::checkValue(float pValue)
{
  if (isnan(pValue)) {
    _isOk = false;
  } else {
    _isOk = true;
  }

}

float Sensor_VALUES::truncPrecisionF(float pFloat, int pPrecision)
{
	float multiplier = pow(10, pPrecision);
	return truncf(pFloat * multiplier) / multiplier;
}

String Sensor_VALUES::floatToString(float pFloat, int pPrecision)
{
	return String(truncPrecisionF(pFloat, pPrecision));
}

String Sensor_VALUES::floatFormat(float pFloat, int pMinWidth, int pPrecision)
{
  char buff[pMinWidth + pPrecision];
  String valueString = "";
  dtostrf(pFloat, pMinWidth, pPrecision, buff);  //4 is mininum width, 6 is precision	
  valueString += buff;
  valueString.trim();
  return valueString;
}

void Sensor_VALUES::touch()
{
    _NTPClient->update();
    _lastMeasurement = _NTPClient->getEpochTime();
}

long Sensor_VALUES::getTimestamp()
{
    return _lastMeasurement;
}

