
#include <Arduino.h>
#include <light/LightSensor.h>

LightSensor::LightSensor(int pin, int maxBrightness) : Sensor(pin, false)
{
    this->maxBrightness = maxBrightness;
}

LightSensor::~LightSensor()
{
    Sensor::prepareDestroy();
    this->maxBrightness = -1;
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
    int lightValue = map(sensorValue, 0, MAX_LIGHT_RESISTANCE, maxBrightness, 0);

    return lightValue;
}
