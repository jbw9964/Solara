
#include <Arduino.h>
#include <sensor/light/LightSensor.h>

LightSensor::LightSensor(int pin, int maxBrightness, int maxResistance) : Sensor(pin, false), maxBrightness(maxBrightness), maxResistance(maxResistance)
{
    if (maxBrightness <= 0 || maxResistance <= 0)
    {
        Serial.println("Error: maxBrightness and maxResistance must be greater than 0.");
        delete this;
        exit(1);
    }

    if (!ANALOG_PIN(pin))
    {
        Serial.println("Error: Pin does not support analog input.");
        delete this;
        exit(1);
    }
}

LightSensor::~LightSensor()
{
    Sensor::prepareDestroy();
}

int LightSensor::readValue()
{
    // when light becomes brighter, sensorValue becomes lower
    int sensorValue = Sensor::readValue();

    if (sensorValue < 0)
    {
        Serial.println("Error reading light sensor value.");
        return -1;
    }

    // 최대 밝기값에 맞춰 맵핑
    // sensorValue is the resistance value, which is inversely proportional to brightness, lightValue
    int lightValue = map(sensorValue, 0, this->getMaxResistance(), maxBrightness, 0);

    return lightValue;
}

int LightSensor::getMaxBrightness() const
{
    return this->maxBrightness;
}

int LightSensor::getMaxResistance() const
{
    return this->maxResistance;
}
