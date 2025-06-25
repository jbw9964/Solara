
#ifndef LIGHT_SENSOR_H
#define LIGHT_SENSOR_H

#include <Sensor.h>

#ifndef MAX_LIGHT_RESISTANCE
#define MAX_LIGHT_RESISTANCE 1023
#endif

class LightSensor : public Sensor
{
private:
    int maxBrightness = 1023;

public:
    LightSensor(int pin, int maxBrightness = 1023);
    ~LightSensor() override;

    int readValue() override;
    bool isInitialized() { return Sensor::isInitialized(); }
};

#endif
