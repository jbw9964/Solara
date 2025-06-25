
#ifndef LIGHT_SENSOR_H
#define LIGHT_SENSOR_H

#include <Sensor.h>

#ifndef MAX_LIGHT_RESISTANCE
#define MAX_LIGHT_RESISTANCE 1023
#endif

class LightSensor : public Sensor
{
private:
    const int maxBrightness;
    const int maxResistance;

public:
    LightSensor(int pin, int maxBrightness, int maxResistance = MAX_LIGHT_RESISTANCE);
    ~LightSensor() override;

    int readValue() override;

    int getMaxBrightness() const;
    int getMaxResistance() const;
};

#endif
