
#include <Arduino.h>
#include <light/LightSensor.h>

LightSensor::LightSensor(int pin, int maxBrightness, int maxResistance) : Sensor(pin, false), maxBrightness(maxBrightness), maxResistance(maxResistance)
{
}

LightSensor::~LightSensor()
{
    Sensor::prepareDestroy();
}

int LightSensor::readValue()
{
    int sensorValue = Sensor::readValue();

    if (sensorValue < 0)
    {
        Serial.println("Error reading light sensor value.");
        return -1;
    }

    // 빛 센서 읽은 값은 저항값. 밝을수록 낮고 어두울수록 높음.
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
