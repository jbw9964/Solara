
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
